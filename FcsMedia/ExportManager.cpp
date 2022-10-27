// ExportManager.cpp : Implementation of CExportManager

#include "stdafx.h"
#include "ExportManager.h"
#include "AMux.h"
//#include "DecklinkInterface.h"

// CExportManager
STDMETHODIMP CExportManager::PackAvi(BSTR bstrVideo, BSTR bstrAudio1, BSTR bstrAudio2, BSTR bstrAudio3, BSTR bstrOutAvi)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	IFileSinkFilter* pSinkFilter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IBaseFilter* pDemultiplexer = NULL;
	IBaseFilter* pSource = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAudioMixer = NULL;
	IBaseFilter* pMuxer = NULL;
	IBaseFilter* pAudioSource1 = NULL;
	IBaseFilter* pAudioSource2 = NULL;
	IBaseFilter* pAudioSource3 = NULL;
	CString szGraphName;
	BOOL bIsSource = FALSE;
	CString str, str1;

	hr = InitializeGraph();
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("pack1.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		//WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(bstrOutAvi, NULL);
		//m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//Find Video Source Filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}
	//03-11
	//find avi splitter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	SAFE_RELEASE(pOutPin);

	// find avi muxer	
	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("Stream 00"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMuxer);
	}

	SAFE_RELEASE(pOutPin);

	// find audio mixer	
	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("Stream 01"), &pOutPin);
	}
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	SAFE_RELEASE(pOutPin);


	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add video source filter
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, bstrVideo, CLSID_AsyncReader, &pSource);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}


	//add audio filter
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, bstrAudio1, CLSID_AsyncReader, &pAudioSource1);
	}
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, bstrAudio2, CLSID_AsyncReader, &pAudioSource2);
	}
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, bstrAudio3, CLSID_AsyncReader, &pAudioSource3);
	}

	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("Stream 00"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pOutPin, pMuxer);
	}

	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioSource1, pAudioMixer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioSource2, pAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioSource3, pAudioMixer);
	}

	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}


#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	

	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pAudioSource1);
	SAFE_RELEASE(pAudioSource2);
	SAFE_RELEASE(pAudioSource3);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pMuxer);
	return hr;
}

STDMETHODIMP CExportManager::GetVideoSize(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	hr = m_pWindowless->GetNativeVideoSize(lpWidth, lpHeight, lpARWidth, lpARHeight);
	return hr;
}

STDMETHODIMP CExportManager::State(UINT* state)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*state = m_state;
	return S_OK;
}

STDMETHODIMP CExportManager::SetWindow(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_hwndVideo = hWnd;
	return S_OK;
}

HRESULT CExportManager::ChangeWriter()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;
	hr = TC_Stop();
	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}
	hr = TC_Run();
	return hr;
}

STDMETHODIMP CExportManager::SetRange(long nStart, long nEnd, long nSeg)
{
	HRESULT hr = S_OK;
	IBaseFilter* pOldSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	m_nBeginFrame = nStart;
	m_nEndFrame = nEnd;
	m_nSeg = nSeg;
	LONGLONG timeNow;
	if (m_pSeek == NULL)
		return S_FALSE;
	hr = GetDuration(&timeNow);
	if (nSeg == 0)
	{
		m_nBeginFrame = 0;
		m_nEndFrame = (long)timeNow - 1;
		return S_OK;
	}
	BOOL bRenderedAnyPin = FALSE;

	// find source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pOldSource);
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);

		}
	}
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
	LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

	if (SUCCEEDED(hr))
	{
		SAFE_RELEASE(m_pSeek);
		hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
	}
	if (SUCCEEDED(hr) && m_pSeek != NULL)
	{
		hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);


	return hr;
}




STDMETHODIMP CExportManager::SetPosition(LONGLONG pos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_pControl == NULL || m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr = S_OK;

	//hr = m_pSeek->SetPositions(&pos, AM_SEEKING_AbsolutePositioning,
	//	NULL, AM_SEEKING_NoPositioning);
	hr = m_pSeek->SetPositions(&pos, AM_SEEKING_AbsolutePositioning,
		NULL, AM_SEEKING_NoPositioning);

	if (SUCCEEDED(hr))
	{
		// If playback is stopped, we need to put the graph into the paused
		// state to update the video renderer with the new frame, and then stop 
		// the graph again. The IMediaControl::StopWhenReady does this.
		if (m_state == STATE_STOPPED)
		{
			hr = m_pControl->StopWhenReady();
		}
	}

	return hr;
}

STDMETHODIMP CExportManager::GetDuration(LONGLONG* pDuration)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	return m_pSeek->GetDuration(pDuration);
}

HRESULT CExportManager::NotifyEnd()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_pEventSink == NULL)
	{
		return S_FALSE;
	}
	LONG_PTR L1 = 0;
	LONG_PTR L2 = 0;
	return m_pEventSink->Notify(EC_COMPLETE, L1, L2);
}

STDMETHODIMP CExportManager::Repaint(HDC hdc)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pWindowless)
	{
		return m_pWindowless->RepaintVideo(m_hwndVideo, hdc);
	}
	else
	{
		return S_OK;
	}
}


STDMETHODIMP CExportManager::UpdateVideoWindow(const LPRECT prc)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	RECT rc;
	CRect rcVolumeIndicator;
	CRect srcRect;
	// TODO: Add your implementation code here
	if (m_pWindowless == NULL)
	{
		return S_OK; // no-op
	}

	if (prc)
	{
		//adjust window size to match video size
		long nWidth, nHeight, nARWidth, nARHeight;
		GetClientRect(m_hwndVideo, &rc);
		GetVideoSize(&nWidth, &nHeight, &nARWidth, &nARHeight);
		srcRect = CRect(0, 0, nWidth, nHeight);
		return m_pWindowless->SetVideoPosition(&srcRect, &rc);
	}
	else
	{

		GetClientRect(m_hwndVideo, &rc);
		return m_pWindowless->SetVideoPosition(NULL, &rc);

	}
}


STDMETHODIMP CExportManager::HasVideo(BOOL* bHasVideo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	BOOL bInclude;
	if (m_pWindowless == NULL)
		bInclude = FALSE;
	else
		bInclude = TRUE;
	*bHasVideo = bInclude;
	return S_OK;
}

STDMETHODIMP CExportManager::CanSeek(BOOL* bCanSeek)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	const DWORD caps = AM_SEEKING_CanSeekAbsolute | AM_SEEKING_CanGetDuration;
	if ((m_seekCaps & caps) == caps)
		*bCanSeek = TRUE;
	else
		*bCanSeek = FALSE;

	return S_OK;
}

//-----------------------------------------------------------------------------
// CExportManager::InitializeGraph
// Description: Create a new filter graph. (Tears down the old graph.) 
//-----------------------------------------------------------------------------

HRESULT CExportManager::InitializeGraph()
{
	HRESULT hr = S_OK;

	TearDownGraph();

	// Create the Filter Graph Manager.
	hr = CoCreateInstance(
		CLSID_FilterGraph,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder,
		(void**)&m_pGraph
	);

	// Query for graph interfaces.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaControl, (void**)&m_pControl);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaEventEx, (void**)&m_pEvent);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IBasicAudio, (void**)&m_pAudio);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IMediaEventSink, (void**)&m_pEventSink);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->SetDefaultSyncSource();
	}


	m_pSGCallback = new CSGCallbackHandler;

	return hr;
}

//-----------------------------------------------------------------------------
// CExportManager::TearDownGraph
// Description: Tear down the filter graph and release resources. 
//-----------------------------------------------------------------------------

void CExportManager::TearDownGraph()
{
	HRESULT hr = S_OK;
	ULONG n;

	if (m_pControl != NULL)
		m_pControl->Stop();

#ifdef _DEBUG
	RemoveGraphFromRot(m_ROTRegister);
#endif	
	if (m_pEvent)
	{
		m_pEvent->SetNotifyWindow((OAHWND)NULL, NULL, NULL);
	}
	if (m_pGraph != NULL)
	{
		DisconnectAllPins(m_pGraph);
		RemoveUnconnectedFilters(m_pGraph);
	}

	if (m_pSGCallback != NULL)
	{
		delete m_pSGCallback;
		m_pSGCallback = NULL;
	}


	SAFE_RELEASE(m_pControl);
	SAFE_RELEASE(m_pEvent);
	SAFE_RELEASE(m_pSeek);
	SAFE_RELEASE(m_pWindowless);
	SAFE_RELEASE(m_pAudio);
	SAFE_RELEASE(m_pEventSink);

	if (m_pGraph != NULL)
	{
		n = m_pGraph->Release();
		if (n != 0)
		{
			CString szMsg;
			szMsg.Format(_T("執行緒沒完全退出， 鏈接數=%ld\n"), (long)n);
			AfxMessageBox(szMsg);
		}
		else
		{
			CString szMsg;
			szMsg.Format(_T("執行緒完全退出\n"), (long)n);
			//AfxMessageBox(szMsg);
		}
		m_pGraph = NULL;
	}

	m_state = STATE_CLOSED;
	m_seekCaps = 0;
	m_bAudioStream = FALSE;
	m_ROTRegister = 0;

}

STDMETHODIMP CExportManager::SetEventWindow(HWND hWnd, UINT msg)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_hwndEvent = hWnd;
	m_EventMsg = msg;

	return S_OK;
}

STDMETHODIMP CExportManager::Run(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_state != STATE_PAUSED && m_state != STATE_STOPPED)
	{
		return S_FALSE;
	}
	assert(m_pGraph); // If state is correct, the graph should exist.


	HRESULT hr = m_pControl->Run();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_RUNNING;
	}

	return hr;
}

HRESULT CExportManager::BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// Create the System Device Enumerator.
	HRESULT hr;
	ICreateDevEnum *pSysDevEnum = NULL;
	IBaseFilter* pFilter1 = NULL;
	IEnumMoniker *pEnumCat = NULL;
	CString szRegFilterName;
	CString lpFilterName = CString(szFilterName);
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void **)&pSysDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	// Obtain a class enumerator for the video compressor category.
	hr = pSysDevEnum->CreateClassEnumerator(CLSID_LegacyAmFilterCategory, &pEnumCat, 0);

	if (hr == S_OK)
	{
		// Enumerate the monikers.
		IMoniker *pMoniker = NULL;
		ULONG cFetched;
		while (pEnumCat->Next(1, &pMoniker, &cFetched) == S_OK)
		{
			IPropertyBag *pPropBag;
			hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag,
				(void **)&pPropBag);
			if (SUCCEEDED(hr)) {
				// To retrieve the filter's friendly name, do the following:
				ULONG nCountProp = 0;
				//pPropBag->CountProperties(&nCountProp);
				VARIANT varName;
				VariantInit(&varName);
				hr = pPropBag->Read(L"FriendlyName", &varName, 0);
				if (SUCCEEDED(hr)) {
					szRegFilterName = CString(varName);
					if (szRegFilterName == lpFilterName) {
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pFilter1);

						hr = m_pGraph->AddFilter(pFilter1, szRegFilterName);
						*pFilter = pFilter1;
						VariantClear(&varName);
						pPropBag->Release();
						pMoniker->Release();
						//SAFE_RELEASE(pFilter1);
						break;
					}
				}
				VariantClear(&varName);
			}
			pPropBag->Release();
			pMoniker->Release();
		}// while
		SAFE_RELEASE(pEnumCat);
	}
	pSysDevEnum->Release();

	return hr;
}


STDMETHODIMP CExportManager::TC_SetWindow(long hParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	HWND hWnd = reinterpret_cast<HWND>(hParent);
	CRect rect;

	CWnd n;
	n.Attach(hWnd);
	n.GetClientRect(&m_windowRect);
	n.Detach();
	m_hwndVideo = hWnd;

	return hr;
}

STDMETHODIMP CExportManager::TC_SetSourceFile(BSTR szSourceName, long nFormat, long nSeg, long nStart, long nEnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szSourceName = CString(szSourceName);
	m_nInputFormat = nFormat;
	m_nBeginFrame = nStart;
	m_nEndFrame = nEnd;
	m_nSeg = nSeg;
	if (m_nInputFormat == FCS_MEDIA_MXF_P2)
	{
		if (!p2Paser.Load(m_szSourceName))
			return S_FALSE;
	}

	return S_OK;
}

STDMETHODIMP CExportManager::TC_SetSinkFile(BSTR szSinkName, long nFormat)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szSinkName = CString(szSinkName);
	m_nOutputFormat = nFormat;
	return S_OK;
}

STDMETHODIMP CExportManager::TC_GetLength(LONG* nLength)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = S_OK;
	LONGLONG nDuration;
	long n = 0;
	hr = m_pSeek->GetDuration(&nDuration);
	n = (long)((double)nDuration / (double)ONE_SECOND * m_dFps);
	if (m_nSeg)
	{
		n = m_nEndFrame - m_nBeginFrame + 1;
	}
	else
	{
		hr = m_pSeek->GetDuration(&nDuration);
		n = (long)((double)nDuration / (double)ONE_SECOND * m_dFps);
	}
	*nLength = n;
	//if (m_pSeek->IsUsingTimeFormat(&TIME_FORMAT_MEDIA_TIME))
	//{
	//	int a = 1;
	//}
	//else if  (m_pSeek->IsUsingTimeFormat(&TIME_FORMAT_FRAME))
	//	int a = 1;
	return hr;
}

STDMETHODIMP CExportManager::TC_Run(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;
	// TODO: Add your implementation code here
	if (m_state == STATE_RUNNING)
	{
		return S_FALSE;
	}

	assert(m_pGraph); // If state is correct, the graph should exist.

	hr = m_pControl->Run();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_RUNNING;
	}

	return hr;
}

STDMETHODIMP CExportManager::TC_GetPosition(LONG* iPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	//if (m_pSeek == NULL)
	//{
	//	return S_FALSE;
	//}
	if (m_pSGCallback == NULL)
	{
		*iPos = 0;
		return S_FALSE;
	}
	HRESULT hr = S_FALSE;
	//long n = m_pSGCallback->GetImageIndex();
	//*iPos = n;

	LONGLONG timeNow;
	hr = m_pSeek->GetCurrentPosition((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	if (m_nSeg == 1)
	{
		if (n < m_nBeginFrame)
		{
			n = 0;
		}
		else
			n = n - m_nBeginFrame;
	}
	*iPos = n;

	return hr;
}

STDMETHODIMP CExportManager::TC_Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_state == STATE_STOPPED)
	{
		return S_FALSE;
	}

	assert(m_pGraph); // If state is correct, the graph should exist.

	HRESULT hr = m_pControl->Stop();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	return hr;
}

STDMETHODIMP CExportManager::GetEvent(long* iEvent, long* L1, long* L2)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pEvent == NULL)
		return S_FALSE;
	HRESULT hr = S_OK;
	hr = m_pEvent->GetEvent(iEvent, (LONG_PTR*)L1, (LONG_PTR*)L2, 10);
	hr = m_pEvent->FreeEventParams(*iEvent, *L1, *L2);
	return hr;
}

STDMETHODIMP CExportManager::TC_ShowConfig(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CExportManager::TC_Init(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = InitializeGraph();
	return hr;
}


STDMETHODIMP CExportManager::GetP2AudioCount(long* nCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nInputFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	long n = p2Paser.GetAudioCount();
	*nCount = n;
	return S_OK;
}

STDMETHODIMP CExportManager::GetP2VideoName(BSTR bstrVideoName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nInputFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	CString str = p2Paser.GetVideoName();
	bstrVideoName = str.AllocSysString();
	return S_OK;
}

STDMETHODIMP CExportManager::GetP2AudioName(long nIndex, BSTR* bstrAudioName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nInputFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	CString str = p2Paser.GetAudioName(nIndex);
	*bstrAudioName = str.AllocSysString();
	return S_OK;
}

STDMETHODIMP CExportManager::SetP2AudioName(BSTR bstrAudioName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nInputFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	m_szAudioName = CString(bstrAudioName);
	return S_OK;
}

// build graph
STDMETHODIMP CExportManager::TC_Render(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: Add your implementation code here
	//// Create the Filter Graph.
	HRESULT hr = S_OK;

	if (m_nInputFormat == FCS_MEDIA_MXF_P2)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = P2Mxf2Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			hr = P2Mxf2Avi100();
			break;
		case FCS_MEDIA_AVI_DV_50:
			hr = P2Mxf2Avi50();
			break;
		case FCS_MEDIA_AVI_DV_25:
			hr = P2Mxf2Avi25();
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			hr = P2Mxf2AviMj();
			break;
		case FCS_MEDIA_MPEG2:
			hr = P2Mxf2Mpeg2();
			break;
		case FCS_MEDIA_MOV:
			hr = P2Mxf2Mov();
			break;

		}
	}

	if (m_nInputFormat == FCS_MEDIA_MXF_SONY)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = SonyMxf2Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			hr = SonyMxf2Avi100();
			break;
		case FCS_MEDIA_AVI_DV_50:
			hr = SonyMxf2Avi50();
			break;
		case FCS_MEDIA_AVI_DV_25:
			hr = SonyMxf2Avi25();
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			hr = SonyMxf2AviMj();
			break;
		case FCS_MEDIA_MPEG2:
			hr = SonyMxf2Mpeg2();
			break;
		case FCS_MEDIA_MOV:
			hr = SonyMxf2Mov();
			break;

		}
	}

	if (m_nInputFormat == FCS_MEDIA_AVI)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = Avi2Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			hr = Avi2Avi100();
			break;
		case FCS_MEDIA_AVI_DV_50:
			hr = Avi2Avi50();
			break;
		case FCS_MEDIA_AVI_DV_25:
			hr = Avi2Avi25();
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			hr = Avi2AviMj();
			break;
		case FCS_MEDIA_MPEG2:
			hr = Avi2Mpeg2();
			break;
		case FCS_MEDIA_MOV:
			hr = Avi2Mov();
			break;

		}
	}

	if (m_nInputFormat == FCS_MEDIA_MPEG2)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = Mpeg22Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			hr = Mpeg22Avi100();
			break;
		case FCS_MEDIA_AVI_DV_50:
			hr = Mpeg2Avi50();
			break;
		case FCS_MEDIA_AVI_DV_25:
			hr = Mpeg22Avi25();
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			hr = Mpeg22AviMj();
			break;
		case FCS_MEDIA_MPEG2:
			hr = Mpeg22Mpeg2();
			break;
		case FCS_MEDIA_MOV:
			hr = Mpeg22Mov();
			break;

		}
	}

	if (m_nInputFormat == FCS_MEDIA_MPEG2_HD)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = HDMpeg22Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			break;
		case FCS_MEDIA_AVI_DV_50:
			break;
		case FCS_MEDIA_AVI_DV_25:
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			break;
		case FCS_MEDIA_MPEG2:
			break;
		case FCS_MEDIA_MOV:
			break;

		}
	}
	if (m_nInputFormat == FCS_MEDIA_MTS)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			hr = Mts2Wmv();
			break;
		case FCS_MEDIA_AVI_DV_100:
			hr = Mts2Avi100();
			break;
		case FCS_MEDIA_AVI_DV_50:
			hr = Mts2Avi50();
			break;
		case FCS_MEDIA_AVI_DV_25:
			hr = Mts2Avi25();
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			hr = Mts2AviMj();
			break;
		case FCS_MEDIA_MPEG2:
			hr = Mts2Mpeg2();
			break;
		case FCS_MEDIA_MOV:
			hr = Mts2Mov();
			break;

		}
	}

	if (m_nInputFormat == FCS_MEDIA_MPEG4)
	{
		switch (m_nOutputFormat) {
		case FCS_MEDIA_WMV:
			break;
		case FCS_MEDIA_AVI_DV_100:
			break;
		case FCS_MEDIA_AVI_DV_50:
			break;
		case FCS_MEDIA_AVI_DV_25:
			break;
		case FCS_MEDIA_AVI_DV_MJ:
			break;
		case FCS_MEDIA_MPEG2:
			break;
		case FCS_MEDIA_MOV:
			break;

		}
	}

	if (m_nInputFormat == -1)
		hr = SmartSave();
	if (m_nInputFormat == -2)
		hr = HDSmartSave();
	if (m_nInputFormat == -3)
		hr = SmartSave2();

	if (m_nInputFormat == -4)
		hr = Encode1();   //sddvavi.GRF
	if (m_nInputFormat == -5)
		hr = Encode2();  //sddv50avi.GRF
	if (m_nInputFormat == -6)
		hr = Encode3();  //sdavi.GRF
	if (m_nInputFormat == -7)
		hr = Encode4();  //sddv50mxf.GRF
	if (m_nInputFormat == -8)
		hr = Encode5();  //hdAVI.GRF
	if (m_nInputFormat == -9)
		hr = Encode6();  //hdDV100AVI.GRF
	if (m_nInputFormat == -10)
		hr = Encode7();  //hdDV100mxf.GRF
	if (m_nInputFormat == -11)
		hr = Encode8();  //avicut.GRF
	if (m_nInputFormat == -12)
		hr = Encode9();  //mpgcut.GRF

	if (m_nInputFormat == -13)
		hr = Encode10();  //blinkCounter.GRF

	if (m_nInputFormat == 57411)
	{
		hr = Encode11(); //mpeg2 to mp4 + blinkCounter
	}
	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}
	//Set time format
	if (m_pSeek->IsFormatSupported(&TIME_FORMAT_MEDIA_TIME))
		m_pSeek->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME);
	else if (m_pSeek->IsFormatSupported(&TIME_FORMAT_FRAME))
		m_pSeek->SetTimeFormat(&TIME_FORMAT_FRAME);
	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}


#ifdef _DEBUG
	//	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
	hr = SaveGraphFile(m_pGraph, _T("C://tmp.grf"));
#endif	

	hr = SetRange(m_nBeginFrame, m_nEndFrame, m_nSeg);

	return hr;

}

STDMETHODIMP CExportManager::TC_Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	TearDownGraph();
	return S_OK;
}

HRESULT CExportManager::CreateWmvGraph(const WCHAR* szPathName, const WCHAR* szDestName)
{
	// Create the System Device Enumerator.
	HRESULT hr = S_OK;
	IBaseFilter *pSource = NULL;
	IBaseFilter *pAudioFilter = NULL;
	IBaseFilter *pVideoFilter = NULL;
	IBaseFilter *pAudioRender = NULL;
	IBaseFilter *pVideoRender = NULL;
	IBaseFilter *pSampleFilter = NULL;
	IBaseFilter* pWmvParser = NULL;
	IFileSourceFilter* pSourceFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	ICreateDevEnum *pSysDevEnum = NULL;
	CString szRegFilterName;


	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void **)&pSysDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	// create sample grabber and add to graph
	CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
		IID_IBaseFilter, (LPVOID   *)&pSampleFilter);
	pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);

	hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
	AM_MEDIA_TYPE mt;
	ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
	mt.majortype = MEDIATYPE_Video;
	mt.subtype = MEDIASUBTYPE_RGB24;
	hr = pSampleGrabber->SetMediaType(&mt);
	pSampleGrabber->SetOneShot(FALSE);
	pSampleGrabber->SetCallback(m_pSGCallback, 1);

	// Obtain a class enumerator for the video compressor category.
	IEnumMoniker *pEnumCat = NULL;
	hr = pSysDevEnum->CreateClassEnumerator(CLSID_LegacyAmFilterCategory, &pEnumCat, 0);

	if (hr == S_OK)
	{
		// Enumerate the monikers.
		IMoniker *pMoniker = NULL;
		ULONG cFetched;
		while (pEnumCat->Next(1, &pMoniker, &cFetched) == S_OK)
		{
			IPropertyBag *pPropBag;
			hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag,
				(void **)&pPropBag);
			if (SUCCEEDED(hr))
			{
				// To retrieve the filter's friendly name, do the following:
				ULONG nCountProp = 0;
				//pPropBag->CountProperties(&nCountProp);
				VARIANT varName;
				VariantInit(&varName);
				hr = pPropBag->Read(L"FriendlyName", &varName, 0);
				if (SUCCEEDED(hr))
				{
					szRegFilterName = CString(varName);
					if (szRegFilterName == _T("GDCL WMV/WMA Parser"))
					{
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pWmvParser);
						hr = m_pGraph->AddFilter(pWmvParser, _T("GDCL WMV/WMA Parser"));
					}

					if (szRegFilterName == _T("WMAudio Decoder DMO"))
					{
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pAudioFilter);
						hr = m_pGraph->AddFilter(pAudioFilter, _T("WMAudio Decoder DMO"));
					}
					if (szRegFilterName == _T("WMVideo Decoder DMO"))
					{
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pVideoFilter);
						hr = m_pGraph->AddFilter(pVideoFilter, _T("WMVideo Decoder DMO"));
					}
				}  //success to read friendly name
				if (pWmvParser != NULL && pAudioFilter != NULL && pVideoFilter != NULL)
				{
					VariantClear(&varName);
					pPropBag->Release();
					pMoniker->Release();
					break;
				}
				VariantClear(&varName);
				pPropBag->Release();
			} //success to bind to storage
			pMoniker->Release();
		}  //while
		pEnumCat->Release();
	}
	pSysDevEnum->Release();
	hr = AddSourceFilter(m_pGraph, szPathName, CLSID_AsyncReader, &pSource);

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
	}

	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
	}

	// Add the DSound Renderer to the graph.
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_DSoundRender, &pAudioRender, L"Audio Renderer");
	}

	//connect filter
	IPin *outPin, *inPin;
	hr = ConnectFilters(m_pGraph, pSource, pWmvParser);
	hr = pWmvParser->FindPin(_T("video 2"), &outPin);
	hr = pVideoFilter->FindPin(_T("in0"), &inPin);
	hr = m_pGraph->ConnectDirect(outPin, inPin, NULL);
	//	hr = ConnectFilters(m_pGraph, pWmvParser, pVideoFilter);
	hr = ConnectFilters(m_pGraph, pVideoFilter, pSampleFilter);
	hr = ConnectFilters(m_pGraph, pSampleFilter, pVideoRender);

	hr = ConnectFilters(m_pGraph, pWmvParser, pAudioFilter);
	hr = ConnectFilters(m_pGraph, pAudioFilter, pAudioRender);
	m_bAudioStream = TRUE;
	//

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pWmvParser);
	SAFE_RELEASE(pAudioFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pVideoFilter);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pSampleFilter);
	return hr;
}

HRESULT CExportManager::UpdateVolume()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;

	if (m_bAudioStream && m_pAudio)
	{
		// If the audio is muted, set the minimum volume. 
		if (m_bMute)
		{
			hr = m_pAudio->put_Volume(MIN_VOLUME);
		}
		else
		{
			// Restore previous volume setting
			hr = m_pAudio->put_Volume(m_lVolume);
		}
	}

	return hr;
}



HRESULT CExportManager::LoadRun(BSTR bstrGrfName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;

	hr = InitializeGraph();

	CString szGraphName = CString(bstrGrfName);
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		//szGraphName = m_szGraphPath + szGraphName;
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = TC_Run();
	//}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::SmartSave2(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pDeMultiplexer = NULL;
	IBaseFilter* pVMR = NULL;
	IBaseFilter* pAudioDecoder = NULL;
	IBaseFilter* m_pNullRenderer = NULL;
	IBaseFilter* m_pSampleGrabber = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Add Asf Writer
	if (SUCCEEDED(hr))
	{
		WCHAR* szDestFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = AddWriterFilter(m_pGraph, szDestFile, CLSID_WMAsfWriter, TRUE, &pWriter);
		m_szSinkName.ReleaseBuffer();
	}
	////Add NULL render
	//if (SUCCEEDED(hr))
	//{
	//	hr = AddFilterByCLSID(m_pGraph, CLSID_SampleGrabber, &m_pSampleGrabber, L"SampleGrabber");
	//}

	////Add NULL render
	//if (SUCCEEDED(hr))
	//{
	//	hr = AddFilterByCLSID(m_pGraph, CLSID_NullRenderer, &m_pNullRenderer, L"Null Renderer");
	//}
	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	//hr = m_pControl->Run();

#ifdef _DEBUG
	AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	return hr;
}

HRESULT CExportManager::KF_KeyFrame(BSTR bstrName)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IPin* pOutPin = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IBaseFilter* pColorTransFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IPin* pVDecoderOutPin = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	m_szSourceName = CString(bstrName);
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("wmv9keyframe.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find Wmv Decoder filter

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoDecoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVDecoderOutPin);
	}

	//Find Color transform filter

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVDecoderOutPin, &pColorTransFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pColorTransFilter, PINDIR_OUTPUT, &pOutPin);
	}
	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVDecoderOutPin);
	}
	SAFE_RELEASE(pVDecoderOutPin);
	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_WMAsfReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}


	//connect filters
	IPin* inPin, *outPin;
	hr = pSource->FindPin(_T("Raw Video 0"), &outPin);
	if (hr != S_OK)
	{
		hr = pSource->FindPin(_T("Raw Video 1"), &outPin);
	}
	hr = pVideoDecoder->FindPin(_T("in0"), &inPin);
	hr = m_pGraph->ConnectDirect(outPin, inPin, NULL);
	//if (SUCCEEDED(hr))
	//{
	//	hr = ConnectFilters(m_pGraph, pSource, pVideoDecoder);
	//}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pColorTransFilter);
	}

	SAFE_RELEASE(inPin);
	SAFE_RELEASE(outPin);
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			AM_MEDIA_TYPE mt;
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			hr = m_pSGCallback->InitKeyFrameProcessor(&m_pKeyFrameParams);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nBitPerPixel = 24;
			m_pSGCallback->SetOption(0);
			m_pSGCallback->SetMode(FCS_Encode_Mode);
			m_pSGCallback->RestImageCounter();
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nWidth = m_pKeyFrameParams.nWidth;
			m_pSGCallback->m_nHeight = m_pKeyFrameParams.nHeight;
			pSampleGrabber->SetCallback(m_pSGCallback, 1);
		}
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = SetRange(50, 100, 1);
	//}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pVDecoderOutPin);
	SAFE_RELEASE(pColorTransFilter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	return hr;
}


STDMETHODIMP CExportManager::SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	m_pKeyFrameParams.nWidth = nWidth;
	m_pKeyFrameParams.nHeight = nHeight;
	m_pKeyFrameParams.bOcr = bOcr;
	m_pKeyFrameParams.nOcrY1 = nOcrY1;
	m_pKeyFrameParams.nOcrY2 = nOcrY2;
	CString str = CString(szExportPath);
	TCHAR* sPath = str.GetBuffer(MAX_PATH);
	_stprintf(m_pKeyFrameParams.pszPath, _T("%s"), sPath);
	str.ReleaseBuffer();
	_stprintf(m_pKeyFrameParams.pszDbConnectStr, _T("%s"), _T(""));
	_stprintf(m_pKeyFrameParams.pszParentID, _T("%s"), _T(""));
	_stprintf(m_pKeyFrameParams.pszRootID, _T("%s"), _T(""));
	_stprintf(m_pKeyFrameParams.pszCreator, _T("%s"), _T(""));
	m_bSetBasicParams = TRUE;
	return hr;

}


STDMETHODIMP CExportManager::SaveKFInfo(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pSGCallback != NULL)
	{
		m_pSGCallback->SaveDataFile();
		hr = S_OK;
	}
	else
		hr = S_FALSE;
	return hr;
}



HRESULT CExportManager::ChnageSourceFilter(const WCHAR* szSrcName)
{
	HRESULT hr = S_OK;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pSecondFilter;
	IPin* pOutPin = NULL;
	IEnumFilters* pEnumFilter = NULL;
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;
	BOOL bSourceFilter;
	IFilterGraph2 *pGraph2 = NULL;
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//Find source filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = IsSourceFilter(pOldSource, &bSourceFilter);
			if (bSourceFilter)
				break;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find connected filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSecondFilter);
	}

	//Find connected pin
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSecondFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}


	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//add new source filter
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, szSrcName, CLSID_AsyncReader, &pSource);
	}

	// Enumerate the pins on the source filter.
	IEnumPins *pEnum = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();
		}
	}

	return hr;
}

HRESULT CExportManager::HDMpeg22Wmv(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Mpeg22Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg22Wmv(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("SDMpeg22Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

STDMETHODIMP CExportManager::SetGraphPath(BSTR bstrGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szGraphPath = CString(bstrGraphPath);
	return S_OK;
}

STDMETHODIMP CExportManager::Save(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	WCHAR* sSrcFile = m_szTempWmv.GetBuffer(MAX_PATH);
	WCHAR* sDestFile = m_szSinkName.GetBuffer(MAX_PATH);
	BOOL hr = ::CopyFile((LPCTSTR)sSrcFile, (LPCTSTR)sDestFile, FALSE);
	m_szSinkName.ReleaseBuffer();
	m_szTempWmv.ReleaseBuffer();
	return S_OK;
}

HRESULT CExportManager::ChangeP2SourceFilter(const WCHAR* szVideoName)
{
	HRESULT hr = S_OK;


	return hr;
}

HRESULT CExportManager::P2Mxf2Wmv()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	if (m_nInputFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	hr = InitializeGraph();

	if (p2Paser.m_szCodec == _T("DV100_1080/50i"))
	{
		hr = P2Dv1002Wmv();

	}
	if (p2Paser.m_szCodec == _T("AVC-I_1080/50i"))
	{
		hr = P2Avc1002Wmv();
	}
	if (p2Paser.m_szCodec == _T("DV50_422"))
	{
		hr = P2Dv502Wmv();
	}

	if (p2Paser.m_szCodec == _T("DV25_420") || p2Paser.m_szCodec == _T("DV25_411"))
	{
		hr = P2Dv252Wmv();
	}

	return hr;
}

HRESULT CExportManager::P2Mxf2Avi100()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::P2Mxf2Avi50()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::P2Mxf2Avi25()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::P2Mxf2AviMj()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::P2Mxf2Mpeg2()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::P2Mxf2Mov()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}




HRESULT CExportManager::SonyMxf2Avi100(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	return hr;
}

HRESULT CExportManager::SonyMxf2Wmv(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("XDCAM2WMV9.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}

	//find demultipixeler
	IPin* pOutPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	IBaseFilter* pDemultiplexer = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	IPin* pVideoPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("MPEG Video ID1"), &pVideoPin);
	}

	IBaseFilter* pVideoDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("AES3/PCM Audio ID2"), &pAudioPin);
	}

	IBaseFilter* pAudioDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioDecoder);
	}
	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	IBaseFilter* pSource = NULL;
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pAudioDecoder);
	}

	IBaseFilter* pVideoSampleFilter = NULL;
	ISampleGrabber* pVideoSampleGrabber = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pVideoSampleFilter, 0) == S_OK)
		{
			hr = pVideoSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pVideoSampleGrabber);
			if (SUCCEEDED(hr))
			{
				hr = pVideoSampleFilter->QueryFilterInfo(pInfo);
				CString str = CString(pInfo->achName);
				if (str == _T("SampleGrabber"))
					break;
			}
		}
	}

	if (pVideoSampleGrabber != NULL)
	{
		AM_MEDIA_TYPE mt;
		ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
		mt.majortype = MEDIATYPE_Video;
		mt.subtype = MEDIASUBTYPE_RGB24;
		hr = pVideoSampleGrabber->SetMediaType(&mt);
		pVideoSampleGrabber->SetOneShot(FALSE);
		m_pSGCallback->m_pPlayer = (void*)this;
		m_pSGCallback->RestImageCounter();
		pVideoSampleGrabber->SetCallback(m_pSGCallback, 1);

	}

	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pVideoSampleFilter);
	SAFE_RELEASE(pVideoSampleGrabber);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CExportManager::SonyMxf2Avi50(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::SonyMxf2Avi25(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::SonyMxf2AviMj(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::SonyMxf2Mpeg2(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}


HRESULT CExportManager::SonyMxf2Mov(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	//if (SUCCEEDED(hr))
	//{
	//	WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
	//	hr = ChnageSourceFilter(sFile);
	//	m_szSourceName.ReleaseBuffer();
	//}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}








HRESULT CExportManager::Avi2Wmv(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, szGraphName);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	//if (SUCCEEDED(hr))
	//{
	//	WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
	//	hr = ChnageSourceFilter(sFile);
	//	m_szSourceName.ReleaseBuffer();
	//}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}


HRESULT CExportManager::Avi2Avi100()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CExportManager::Avi2Avi50()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}


HRESULT CExportManager::Avi2Avi25()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}


HRESULT CExportManager::Avi2AviMj()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}


HRESULT CExportManager::Avi2Mpeg2()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}



HRESULT CExportManager::Avi2Mov()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}




HRESULT CExportManager::Mpeg22Avi100(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg2Avi50(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg22Avi25(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg22AviMj(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg22Mpeg2(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mpeg22Mov(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}


HRESULT CExportManager::Mts2Wmv(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mts2Avi100(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mts2Avi50(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mts2Avi25(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mts2AviMj(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

HRESULT CExportManager::Mts2Mpeg2(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs1.Wmv"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Wmv.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}


HRESULT CExportManager::Mts2Mov(void)
{
	HRESULT hr = S_OK;
	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Sony2Avi100.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// change source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = ChnageSourceFilter(sFile);
		m_szSourceName.ReleaseBuffer();
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr))
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}

STDMETHODIMP CExportManager::Pause(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_state != STATE_RUNNING)
	{
		return S_FALSE;
	}

	assert(m_pGraph); // If state is correct, the graph should exist.

	HRESULT hr = m_pControl->Pause();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_PAUSED;
	}

	return hr;
}

STDMETHODIMP CExportManager::TC_Seek(long iPos)
{
	HRESULT hr;
	LONGLONG timeNow = (LONGLONG)((double)iPos * (double)ONE_SECOND / m_dFps);
	hr = SetPosition((LONGLONG)timeNow);
	return hr;
}


HRESULT CExportManager::HDSmartSave(void)
{
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IBaseFilter* pMultiplexer = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IPin* pOutPin = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	HRESULT hr = S_OK;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter

	BOOL bIsSource = FALSE;
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find IMAGE conveter 2 filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find multiplexer filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMultiplexer);
	}
	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}
	SAFE_RELEASE(pOutPin);

	// find medialooks audio mixer
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}
	SAFE_RELEASE(pAudioPin);

	// find audio encoder filter
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->FindPin(_T("Out 1"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioEncoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = pOutPin->Disconnect();
	}
	SAFE_RELEASE(pOutPin);

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}


	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}
	SAFE_RELEASE(pEnum);


	IBaseFilter* pFilter = NULL;
	IEnumPins *pAudioMixerEnum = NULL;
	IPin *pAudioMixerPin = NULL;

	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->EnumPins(&pAudioMixerEnum);
	}

	while (S_OK == pAudioMixerEnum->Next(1, &pAudioMixerPin, 0))
	{
		hr = GetConnectedFilter(pAudioMixerPin, &pFilter);
	
		if (pFilter != pAudioEncoder)
		{
			hr = RemoveFiltersDownstreamOfPin(m_pGraph, pAudioMixerPin);
		}

		SAFE_RELEASE(pFilter);
		SAFE_RELEASE(pAudioMixerPin);
	}
	SAFE_RELEASE(pAudioMixerEnum);

	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		AM_MEDIA_TYPE mt;
		ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
		mt.majortype = MEDIATYPE_Video;
		mt.subtype = MEDIASUBTYPE_RGB24;
		hr = pSampleGrabber->SetMediaType(&mt);
		pSampleGrabber->SetOneShot(FALSE);
		m_pSGCallback->m_pPlayer = (void*)this;
		m_pSGCallback->RestImageCounter();
		pSampleGrabber->SetCallback(m_pSGCallback, 1);
	}

	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pGraph2);

	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pMultiplexer);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pOutPin);

	return hr;
}

HRESULT CExportManager::SmartSave(void)
{
	HRESULT hr = S_OK;

	IBaseFilter* pWriter = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;

	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;

	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IPin* pOutPin = NULL;

	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVideoEncoder = NULL;

	IBaseFilter* pAudioEncoder = NULL;
	IBaseFilter* pMultiplexer = NULL;
	IFileSinkFilter* pSinkFilter = NULL;

	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;

	BOOL bRenderedAnyPin = FALSE;

	ULONG res = -1;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	//m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sdwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}


	SAFE_RELEASE(pOutPin);

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);


	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);


	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find IMAGE conveter 2 filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find multiplexer filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMultiplexer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	// find medialooks audio mixer
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pOutPin);

	// find audio encoder filter
	//IBaseFilter* pAudioEncoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->FindPin(_T("Out 1"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioEncoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = pOutPin->Disconnect();
	}

	SAFE_RELEASE(pOutPin);
	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}
	SAFE_RELEASE(pEnum);
	// 断掉 audio mixer 后的 PIN
	IBaseFilter* pFilter = NULL;
	IEnumPins *pAudioMixerEnum = NULL;
	IPin *pAudioMixerPin = NULL;

	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->EnumPins(&pAudioMixerEnum);
	}

	if (SUCCEEDED(hr))
	{
		while (S_OK == pAudioMixerEnum->Next(1, &pAudioMixerPin, 0))
		{
			hr = GetConnectedFilter(pAudioMixerPin, &pFilter);
		
			if (pFilter != pAudioEncoder)
			{
				hr = RemoveFiltersDownstreamOfPin(m_pGraph, pAudioMixerPin);
			}

			SAFE_RELEASE(pFilter);
			SAFE_RELEASE(pAudioMixerPin);
		}

	}
	SAFE_RELEASE(pAudioMixerEnum);

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			AM_MEDIA_TYPE mt;
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);
		}
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);

	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);

	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pSampleFilter);

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pVideoEncoder);

	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pMultiplexer);
	SAFE_RELEASE(pSinkFilter);

	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pImageConverter2);
	//SAFE_RELEASE(spAudioMixer);

	return hr;
}
HRESULT CExportManager::P2Dv252Wmv(void)
{
	IFileSinkFilter* pSinkFilter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter* pDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IBaseFilter* pSource = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAcmPaser = NULL;
	IBaseFilter* pAudioMixer = NULL;

	HRESULT hr = S_OK;
	CString szGraphName;
	BOOL bIsSource = FALSE;
	CString str;

	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("P2dv25WMV.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//Find Video Source Filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dv25\\CONTENTS\\VIDEO\\00012I.MXF") ||
					str == _T("File Source (Async.)"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pVideoPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pVideoDecoder);
	}


	if (m_nSeg == 1)
	{
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
		}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
		SAFE_RELEASE(pOutPin);

	}


	//Find Audio Source Filter
	SAFE_RELEASE(pOldSource);
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dv25\\CONTENTS\\AUDIO\\00012I00.MXF") ||
					str == _T("File Source (Async.) 0001"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	SAFE_RELEASE(pDemultiplexer);
	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	//find acm paser filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAcmPaser);
	}

	//find medialooks filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAcmPaser, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	SAFE_RELEASE(pSource);
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pAcmPaser);
	}



	SAFE_RELEASE(pSource);
	int nCount = p2Paser.GetAudioCount();
	IBaseFilter* pDemultiplexer1 = NULL;
	IBaseFilter* pAcmPaser1 = NULL;
	pInfo = new FILTER_INFO;
	pDemultiplexer->QueryFilterInfo(pInfo);
	CString szDeMultiPlexer = CString(pInfo->achName);
	wchar_t* lpszDeMultiPlexer = szDeMultiPlexer.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	pInfo = new FILTER_INFO;
	pAcmPaser->QueryFilterInfo(pInfo);
	CString szAcmPaser = CString(pInfo->achName);
	wchar_t* lpszAcmPaser = szAcmPaser.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);

	for (int i = 1; i < nCount; i++)
	{
		str = p2Paser.GetAudioName(i);
		//add source filter
		if (SUCCEEDED(hr))
		{
			WCHAR* szSrcFile = str.GetBuffer(MAX_PATH);
			hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
			str.ReleaseBuffer();
		}

		//copy demultiplexer
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszDeMultiPlexer, &pDemultiplexer1);
		}
		//copy acm paser decoder
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszAcmPaser, &pAcmPaser1);
		}

		//conect all of filters till audiomixer
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pDemultiplexer1, pAcmPaser1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pAcmPaser1, pAudioMixer);
		}
		//release filters and pins
		SAFE_RELEASE(pDemultiplexer1);
		SAFE_RELEASE(pAcmPaser1);
		SAFE_RELEASE(pSource);
	}
	szDeMultiPlexer.ReleaseBuffer();
	szAcmPaser.ReleaseBuffer();

	SAFE_RELEASE(pDemultiplexer1);
	SAFE_RELEASE(pAcmPaser1);
	SAFE_RELEASE(pSource);

	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAcmPaser);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CExportManager::P2Dv1002Wmv(void)
{
	IFileSinkFilter* pSinkFilter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter* pDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IBaseFilter* pSource = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAcmPaser = NULL;
	IBaseFilter* pAudioMixer = NULL;

	HRESULT hr = S_OK;
	CString szGraphName;
	BOOL bIsSource = FALSE;
	CString str;

	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("P2dv100WMV9.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	SAFE_RELEASE(pSinkFilter);

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//Find Video Source Filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dvcpro100\\CONTENTS\\VIDEO\\000126.MXF") ||
					str == _T("File Source (Async.)"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);

		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pVideoPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pVideoDecoder);
	}

	//Set Range
	//int n = szVideoName.ReverseFind('.');
	//str = szVideoName.Mid(n+1, 3);
	//str.MakeUpper();
	//if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
	//	goto A1;
	if (m_nSeg == 1)
	{
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
		}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
		SAFE_RELEASE(pOutPin);

	}

	//Find Audio Source Filter
	SAFE_RELEASE(pOldSource);
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dvcpro100\\CONTENTS\\AUDIO\\00012600.MXF") ||
					str == _T("File Source (Async.) 0002"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	SAFE_RELEASE(pDemultiplexer);
	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	//find acm paser filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAcmPaser);
	}

	//find medialooks filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAcmPaser, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	SAFE_RELEASE(pSource);
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pAcmPaser);
	}


	SAFE_RELEASE(pSource);
	int nCount = p2Paser.GetAudioCount();
	IBaseFilter* pDemultiplexer1 = NULL;
	IBaseFilter* pAcmPaser1 = NULL;

	pInfo = new FILTER_INFO;
	pDemultiplexer->QueryFilterInfo(pInfo);
	CString szDeMultiPlexer = CString(pInfo->achName);
	wchar_t* lpszDeMultiPlexer = szDeMultiPlexer.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	pInfo = new FILTER_INFO;
	pAcmPaser->QueryFilterInfo(pInfo);
	CString szAcmPaser = CString(pInfo->achName);
	wchar_t* lpszAcmPaser = szAcmPaser.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);

	for (int i = 1; i < nCount; i++)
	{
		str = p2Paser.GetAudioName(i);
		//add source filter
		if (SUCCEEDED(hr))
		{
			WCHAR* szSrcFile = str.GetBuffer(MAX_PATH);
			hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
			str.ReleaseBuffer();
		}

		//copy demultiplexer
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszDeMultiPlexer, &pDemultiplexer1);
		}

		//copy acm paser decoder
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszAcmPaser, &pAcmPaser1);
		}

		//conect all of filters till audiomixer
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pDemultiplexer1, pAcmPaser1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pAcmPaser1, pAudioMixer);
		}

		//release filters and pins
		SAFE_RELEASE(pDemultiplexer1);
		SAFE_RELEASE(pAcmPaser1);
		SAFE_RELEASE(pSource);
	}

	szDeMultiPlexer.ReleaseBuffer();
	szAcmPaser.ReleaseBuffer();

	SAFE_RELEASE(pDemultiplexer1);
	SAFE_RELEASE(pAcmPaser1);
	SAFE_RELEASE(pSource);

	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAcmPaser);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);

	return hr;
}


HRESULT CExportManager::P2Dv502Wmv(void)
{
	IFileSinkFilter* pSinkFilter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter* pDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IBaseFilter* pSource = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAcmPaser = NULL;
	IBaseFilter* pAudioMixer = NULL;

	HRESULT hr = S_OK;
	CString szGraphName;
	BOOL bIsSource = FALSE;
	CString str;

	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("P2dv50Wmv.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}
	SAFE_RELEASE(pSinkFilter);

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//Find Video Source Filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dvcpro50\\CONTENTS\\VIDEO\\0001BY.MXF") ||
					str == _T("File Source (Async.)"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pVideoPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pVideoDecoder);
	}


	if (m_nSeg == 1)
	{
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
		}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
		SAFE_RELEASE(pOutPin);

	}

	//Find Audio Source Filter
	SAFE_RELEASE(pOldSource);
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2dvcpro50\\CONTENTS\\AUDIO\\0001BY00.MXF") ||
					str == _T("File Source (Async.) 0001"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	SAFE_RELEASE(pDemultiplexer);
	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	//find acm paser filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAcmPaser);
	}

	//find medialooks filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAcmPaser, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	SAFE_RELEASE(pSource);
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pAcmPaser);
	}


	SAFE_RELEASE(pSource);
	int nCount = p2Paser.GetAudioCount();
	IBaseFilter* pDemultiplexer1 = NULL;
	IBaseFilter* pAcmPaser1 = NULL;
	if (pInfo != NULL)
	{
		SAFE_RELEASE(pInfo->pGraph);
		SAFE_DELETE(pInfo);
	}
	pInfo = new FILTER_INFO;
	pDemultiplexer->QueryFilterInfo(pInfo);
	CString szDeMultiPlexer = CString(pInfo->achName);
	wchar_t* lpszDeMultiPlexer = szDeMultiPlexer.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	pInfo = new FILTER_INFO;
	pAcmPaser->QueryFilterInfo(pInfo);
	CString szAcmPaser = CString(pInfo->achName);
	wchar_t* lpszAcmPaser = szAcmPaser.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);

	for (int i = 1; i < nCount; i++)
	{
		str = p2Paser.GetAudioName(i);
		//add source filter
		if (SUCCEEDED(hr))
		{
			WCHAR* szSrcFile = str.GetBuffer(MAX_PATH);
			hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
			str.ReleaseBuffer();
		}

		//copy demultiplexer
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszDeMultiPlexer, &pDemultiplexer1);
		}
		//copy acm paser decoder
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszAcmPaser, &pAcmPaser1);
		}

		//conect all of filters till audiomixer
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pDemultiplexer1, pAcmPaser1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pAcmPaser1, pAudioMixer);
		}
		//release filters and pins
		SAFE_RELEASE(pDemultiplexer1);
		SAFE_RELEASE(pAcmPaser1);
		SAFE_RELEASE(pSource);
	}
	szDeMultiPlexer.ReleaseBuffer();
	szAcmPaser.ReleaseBuffer();

	SAFE_RELEASE(pDemultiplexer1);
	SAFE_RELEASE(pAcmPaser1);
	SAFE_RELEASE(pSource);

	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAcmPaser);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}



HRESULT CExportManager::P2Avc1002Wmv(void)
{
	IFileSinkFilter* pSinkFilter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter* pDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IBaseFilter* pSource = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAcmPaser = NULL;
	IBaseFilter* pAudioMixer = NULL;

	HRESULT hr = S_OK;
	CString szGraphName;
	BOOL bIsSource = FALSE;
	CString str;

	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("P2dh1WMV9.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//Find Video Source Filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2avc\\CONTENTS\\VIDEO\\00011R.MXF") ||
					str == _T("File Source (Async.)"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pVideoPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pVideoDecoder);
	}


	if (m_nSeg == 1)
	{
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
		}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
		SAFE_RELEASE(pOutPin);

	}


	//Find Audio Source Filter
	SAFE_RELEASE(pOldSource);
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				//check video source or audio source
				if (pInfo == NULL)
					pInfo = new FILTER_INFO;
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				if (str == _T("C:\\9fcs\\p2avc\\CONTENTS\\AUDIO\\00011R00.MXF") ||
					str == _T("File Source (Async.) 0001"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
			}
			bIsSource = FALSE;
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	SAFE_RELEASE(pDemultiplexer);
	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	//find acm paser filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pDemultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAcmPaser);
	}

	//find medialooks filter
	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAcmPaser, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	SAFE_RELEASE(pSource);
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pAcmPaser);
	}



	SAFE_RELEASE(pSource);
	int nCount = p2Paser.GetAudioCount();
	IBaseFilter* pDemultiplexer1 = NULL;
	IBaseFilter* pAcmPaser1 = NULL;
	pInfo = new FILTER_INFO;
	pDemultiplexer->QueryFilterInfo(pInfo);
	CString szDeMultiPlexer = CString(pInfo->achName);
	wchar_t* lpszDeMultiPlexer = szDeMultiPlexer.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	pInfo = new FILTER_INFO;
	pAcmPaser->QueryFilterInfo(pInfo);
	CString szAcmPaser = CString(pInfo->achName);
	wchar_t* lpszAcmPaser = szAcmPaser.GetBuffer(MAX_PATH);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);

	for (int i = 1; i < nCount; i++)
	{
		str = p2Paser.GetAudioName(i);
		//add source filter
		if (SUCCEEDED(hr))
		{
			WCHAR* szSrcFile = str.GetBuffer(MAX_PATH);
			hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
			str.ReleaseBuffer();
		}

		//copy demultiplexer
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszDeMultiPlexer, &pDemultiplexer1);
		}
		//copy acm paser decoder
		if (SUCCEEDED(hr))
		{
			hr = BindAMRegFilter(lpszAcmPaser, &pAcmPaser1);
		}

		//conect all of filters till audiomixer
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pSource, pDemultiplexer1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pDemultiplexer1, pAcmPaser1);
		}

		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pAcmPaser1, pAudioMixer);
		}
		//release filters and pins
		SAFE_RELEASE(pDemultiplexer1);
		SAFE_RELEASE(pAcmPaser1);
		SAFE_RELEASE(pSource);
	}
	szDeMultiPlexer.ReleaseBuffer();
	szAcmPaser.ReleaseBuffer();

	SAFE_RELEASE(pDemultiplexer1);
	SAFE_RELEASE(pAcmPaser1);
	SAFE_RELEASE(pSource);

	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAcmPaser);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


STDMETHODIMP CExportManager::ChangeWindow(long hWndHandle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	HWND hWnd = reinterpret_cast<HWND>(hWndHandle);
	CRect rect;

	CWnd n;
	n.Attach(hWnd);
	n.GetClientRect(&m_windowRect);
	n.Detach();
	hr = ChangeHWnd(hWnd);
	return hr;
}

STDMETHODIMP CExportManager::ChangeHWnd(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pGraph == NULL)
		return S_FALSE;
	m_hwndVideo = hWnd;
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pVideoRenderer = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IPin* pInputPin = NULL;
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
				break;
		}

		// find connected pin
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pInputPin);
		}

		// find connected filter with this pin
		if (SUCCEEDED(hr))
		{
			hr = GetConnectedFilter(pInputPin, &pVMR);
		}

		if (SUCCEEDED(hr))
		{
			hr = DisconnectPin(m_pGraph, pInputPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = RemoveFilter(m_pGraph, pOldRender);
		}

		if (SUCCEEDED(hr))
		{
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);


	return hr;
}

HRESULT CExportManager::Encode1(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVmr = NULL;
	IBaseFilter* pAudioDevice = NULL;
	IEnumFilters* pnewEnumFilter = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	//FILTER_INFO* pInfo = new FILTER_INFO;	
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;
	int nCount = 0;
	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sddvavi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find avi mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	// find medialooks audio mixer
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//remove avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}


	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}



	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}


	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);


	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviDest, &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioMixer, pNewAviMuxer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}


	//
	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pAudioDevice);
	SAFE_RELEASE(pnewEnumFilter);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);

	return hr;
}



HRESULT CExportManager::Encode2(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAudioDevice = NULL;
	IEnumFilters* pnewEnumFilter = NULL;
	IBaseFilter* pVmr = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	//FILTER_INFO* pInfo = new FILTER_INFO;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sddv50avi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find avi mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	// find medialooks audio mixer
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}

	//remove muxer filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}

	CComPtr<IMLAudioMixer>	spAudioMixer;
	int nCount = 0;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);

	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviDest, &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioMixer, pNewAviMuxer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pAudioDevice);
	SAFE_RELEASE(pnewEnumFilter);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);

	return hr;
}


HRESULT CExportManager::Encode3(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAudioDevice = NULL;
	IEnumFilters* pnewEnumFilter = NULL;
	IBaseFilter* pVmr = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sdavi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find avi mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	// find medialooks audio mixer
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//remove avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	int nCount = 0;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);

	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}
	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviDest, &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pImageConverter2, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioMixer, pNewAviMuxer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:


	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pAudioDevice);
	SAFE_RELEASE(pnewEnumFilter);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);

	return hr;
}


HRESULT CExportManager::Encode4(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pAudioMixer = NULL; //medialooks audio mixer
	IBaseFilter* pAudioWriter = NULL;
	IBaseFilter* pWavDest = NULL;
	IFileSinkFilter* pVideoSinkFilter = NULL;
	IFileSinkFilter* pAudioSinkFilter = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	IBaseFilter* pNewWavDest = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;
	int nCount = 0;
	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sddv50mxf.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find mxf mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	//find audio file filter
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWavDest);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWavDest, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioWriter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pVideoSinkFilter);
		if (SUCCEEDED(hr))
		{
			sFile = m_szSinkName.GetBuffer(MAX_PATH);
			hr = pVideoSinkFilter->SetFileName(sFile, NULL);
			m_szSinkName.ReleaseBuffer();
		}

	}

	if (SUCCEEDED(hr))
	{
		//get audio name
		int n = m_szSinkName.Find('.');
		CString str = m_szSinkName.Left(n);
		str = str + CString(_T(".wav"));

		hr = pAudioWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pAudioSinkFilter);
		if (SUCCEEDED(hr))
		{
			sFile = str.GetBuffer(MAX_PATH);
			hr = pAudioSinkFilter->SetFileName(sFile, NULL);
			m_szSinkName.ReleaseBuffer();
		}

	}

	//remove mxf mux filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//remove Wav Dest filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pWavDest);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}

	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();

	}

	//disconnect In-pin of pAudiowriter
	IBaseFilter* pVmr = NULL;
	IPin* pInPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	//add new wave dest filter
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("WAV Dest"), &pNewWavDest);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->FindPin(_T("Out 1"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindUnconnectedPin(pNewWavDest, PINDIR_INPUT, &pInPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pOutPin, pInPin, NULL);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewWavDest, pAudioWriter);
	}

	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept MXF Multiplexer"), &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	int n = m_szSourceName.ReverseFind('.');
	CString str = m_szSourceName.Mid(n + 1, 3);
	str.MakeUpper();
	if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
		goto A1;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	//}

	LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
	LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

	//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
	}
	if (SUCCEEDED(hr) && m_pSeek != NULL)
	{
		hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
	}


A1:


	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioWriter);
	SAFE_RELEASE(pVideoSinkFilter);
	SAFE_RELEASE(pAudioSinkFilter);
	SAFE_RELEASE(pWavDest);
	SAFE_RELEASE(pNewWavDest);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pVmr);

	return hr;
}

HRESULT CExportManager::Encode5(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAudioDevice = NULL;
	IEnumFilters* pnewEnumFilter = NULL;
	IBaseFilter* pVmr = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	//FILTER_INFO* pInfo = new FILTER_INFO;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdavi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find avi mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	// find medialooks audio mixer
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//remove avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	int nCount = 0;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);

	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}
	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviDest, &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pImageConverter2, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioMixer, pNewAviMuxer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:


	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pAudioDevice);
	SAFE_RELEASE(pnewEnumFilter);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);

	return hr;
}



HRESULT CExportManager::Encode6(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAudioDevice = NULL;
	IEnumFilters* pnewEnumFilter = NULL;
	IBaseFilter* pVmr = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdDV100AVI.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find avi mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	// find medialooks audio mixer
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioMixer);
	}

	//remove muxer filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	int nCount = 0;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);

	}

	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviDest, &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAudioMixer, pNewAviMuxer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pAudioDevice);
	SAFE_RELEASE(pnewEnumFilter);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);
	return hr;
}



HRESULT CExportManager::Encode7(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pAviMuxer = NULL;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pAudioMixer = NULL; //medialooks audio mixer
	IBaseFilter* pAudioWriter = NULL;
	IBaseFilter* pWavDest = NULL;
	IFileSinkFilter* pVideoSinkFilter = NULL;
	IFileSinkFilter* pAudioSinkFilter = NULL;
	IBaseFilter* pNewAviMuxer = NULL;
	IBaseFilter* pNewWavDest = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter* pVmr = NULL;
	IPin* pInPin = NULL;
	AM_MEDIA_TYPE mt;
	BOOL bRenderedAnyPin = FALSE;
	int nCount = 0;
	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdDV100mxf.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sample grabber filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find second image converter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find mxf mux filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviMuxer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviMuxer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find sink file filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);
	//find audio file filter
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioMixer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWavDest);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWavDest, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioWriter);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pVideoSinkFilter);
		if (SUCCEEDED(hr))
		{
			sFile = m_szSinkName.GetBuffer(MAX_PATH);
			hr = pVideoSinkFilter->SetFileName(sFile, NULL);
			m_szSinkName.ReleaseBuffer();
		}

	}

	if (SUCCEEDED(hr))
	{
		//get audio name
		int n = m_szSinkName.Find('.');
		CString str = m_szSinkName.Left(n);
		str = str + CString(_T(".wav"));

		hr = pAudioWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pAudioSinkFilter);
		if (SUCCEEDED(hr))
		{
			sFile = str.GetBuffer(MAX_PATH);
			hr = pAudioSinkFilter->SetFileName(sFile, NULL);
			m_szSinkName.ReleaseBuffer();
		}

	}

	//remove mxf mux filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviMuxer);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//remove Wav Dest filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pWavDest);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}


	CComPtr<IMLAudioMixer>	spAudioMixer;
	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->QueryInterface(&spAudioMixer);
	}
	if (SUCCEEDED(hr))
	{
		hr = spAudioMixer->GetOutputPinCount(&nCount);
	}


	for (int i = 0; i < nCount; i++)
	{
		FindConnectedPin(pAudioMixer, PINDIR_OUTPUT, &pOutPin);
		if (pOutPin != NULL)
			pOutPin->Disconnect();
		SAFE_RELEASE(pOutPin);

	}

	//disconnect In-pin of pAudiowriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	SAFE_RELEASE(pOutPin);
	//disconnect In-pin of pwriter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pWriter, PINDIR_INPUT, &pOutPin);
	}

	if (SUCCEEDED(hr) && pOutPin != NULL)
	{
		hr = GetConnectedFilter(pOutPin, &pVmr);
		hr = RemoveFilter(m_pGraph, pVmr);
	}

	SAFE_RELEASE(pOutPin);
	//add new wave dest filter
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("WAV Dest"), &pNewWavDest);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAudioMixer->FindPin(_T("Out 1"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindUnconnectedPin(pNewWavDest, PINDIR_INPUT, &pInPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pOutPin, pInPin, NULL);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewWavDest, pAudioWriter);
	}

	SAFE_RELEASE(pOutPin);
	// add new avi muxer filter
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept MXF Multiplexer"), &pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pNewAviMuxer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pNewAviMuxer, pWriter);
	}

	//
	if (m_nSeg == 1)
	{
		int n = m_szSourceName.ReverseFind('.');
		CString str = m_szSourceName.Mid(n + 1, 3);
		str.MakeUpper();
		if (str == _T("XML") || str == _T("MXF") || str == _T("MTS"))
			goto A1;
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pSource, PINDIR_OUTPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(pAviSplitter);
			hr = GetConnectedFilter(pOutPin, &pAviSplitter);
		}

		SAFE_RELEASE(pOutPin);
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pOutPin);
		}

		//if (SUCCEEDED(hr))
		//{
		//	hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
		//}

		LONGLONG timeBegin = (LONGLONG)((double)m_nBeginFrame * (double)ONE_SECOND / m_dFps);
		LONGLONG timeEnd = (LONGLONG)((double)m_nEndFrame * (double)ONE_SECOND / m_dFps);

		//	CComQIPtr<IMediaSeeking>pSeek(pOutPin);
		if (SUCCEEDED(hr))
		{
			SAFE_RELEASE(m_pSeek);
			hr = pOutPin->QueryInterface(IID_IMediaSeeking, (void**)&m_pSeek);
		}
		if (SUCCEEDED(hr) && m_pSeek != NULL)
		{
			hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning, &timeEnd, AM_SEEKING_AbsolutePositioning);
		}
	}

A1:

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->RestImageCounter();
			pSampleGrabber->SetCallback(m_pSGCallback, 1);

		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter2);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAviMuxer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pNewAviMuxer);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioWriter);
	SAFE_RELEASE(pVideoSinkFilter);
	SAFE_RELEASE(pAudioSinkFilter);
	SAFE_RELEASE(pWavDest);
	SAFE_RELEASE(pNewWavDest);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pVmr);
	SAFE_RELEASE(pInPin);

	return hr;
}

HRESULT CExportManager::Encode8(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter* pFileSrc = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IPin* pOutPin = NULL;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("avicut.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}


	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pSinkFilter);

	return hr;
}



HRESULT CExportManager::Encode9(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter* pFileSrc = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IPin* pOutPin = NULL;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("mpgcut.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}


	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pSinkFilter);

	return hr;
}


STDMETHODIMP CExportManager::WaitForCompletion(long nTimeOut, long* pEvCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pEvent == NULL)
		return S_FALSE;
	HRESULT hr = m_pEvent->WaitForCompletion(nTimeOut, pEvCode);
	return hr;
}

HRESULT CExportManager::Encode10(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter* pAviSplitter = NULL;
	IPin* pOutPin = NULL;
	IBaseFilter* pImageConverter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVideoEncoder = NULL;
	IBaseFilter* pAudioEncoder = NULL;
	IBaseFilter* pMultiplexer = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pImageConverter2 = NULL;
	IBaseFilter* pAudioMixer = NULL;
	IPin* pAudioPin = NULL;
	BOOL bRenderedAnyPin = FALSE;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	//m_szTempWmv = m_szGraphPath + CString(_T("9fcs3.avi"));
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("blinkcounter.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find IMAGE conveter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find blink counter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	//Find IMAGE conveter 2 filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pImageConverter2);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	//Find video encoder filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pVideoEncoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	//Find multiplexer filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	// find audio encoder filter
	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 01"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioEncoder);
	}

	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//remove avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}
	if (SUCCEEDED(hr))
	{
		WCHAR* sFile = m_szSinkName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szSinkName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = pSource->EnumPins(&pEnum);
	}

	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		IPin *pPin = NULL;

		while (S_OK == pEnum->Next(1, &pPin, NULL))
		{
			// Try to render this pin. 
			// It's OK if we fail some pins, if at least one pin renders.
			HRESULT hr2 = pGraph2->RenderEx(pPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);

			pPin->Release();

			if (SUCCEEDED(hr2))
			{
				bRenderedAnyPin = TRUE;
			}
		}
	}

	//disconnect pwriter and mpeg multiplexer
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
		//hr = pOutPin->Disconnect();
	}

	//disconnect mpeg multiplexer and video encoder
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoEncoder, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	//disconnect image converter 2 and video encoder
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pImageConverter2, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	// disconnect blinkcounter filter and image convert2 filter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	// connect image converter and blilnk counter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pImageConverter, pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindUnconnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}
	//connect blink counter and image converter 2
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pOutPin, pImageConverter2);
		//hr = ConnectFilters(m_pGraph, pSampleFilter, pImageConverter2);
		//hr = pGraph2->RenderEx(pOutPin, AM_RENDEREX_RENDERTOEXISTINGRENDERERS, NULL);
	}

	//connect video encoder and image converter 2
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pImageConverter2, pVideoEncoder);
	}

	//connect video encoder and pMultiplexer
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoEncoder, pMultiplexer);
	}

	//connect pMultiplexer and pwriter
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMultiplexer, pWriter);
	}

	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pGraph2);

	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pImageConverter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pVideoEncoder);
	SAFE_RELEASE(pAudioEncoder);
	SAFE_RELEASE(pMultiplexer);
	SAFE_RELEASE(pSinkFilter);
	SAFE_RELEASE(pAudioMixer);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pImageConverter2);
	return hr;
}

HRESULT CExportManager::Encode11(void)
{
	HRESULT hr = S_OK;
	IBaseFilter* pWriter = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pOldSource = NULL;
	IFilterGraph2 *pGraph2 = NULL;
	IEnumPins *pEnum = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IPin* pOutPin = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	IBaseFilter* pMp4Multiplexer = NULL;
	IBaseFilter* pH264Encoder = NULL;
	IBaseFilter* pColorSpaceConverter = NULL;
	IBaseFilter* pBlinkCounter = NULL;
	IBaseFilter* pMpegDecoder = NULL;
	IBaseFilter* pMpegDemultiplexer = NULL;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("57411.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}


	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	ULONG nFetched = 0;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;

	BOOL bIsSource = FALSE;

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldSource, 0) == S_OK)
		{
			hr = pOldSource->QueryInterface(IID_IAMFilterMiscFlags, (void**)&pFlags);
			if (SUCCEEDED(hr))
			{

				ULONG flags = pFlags->GetMiscFlags();
				if (flags &  AM_FILTER_MISC_FLAGS_IS_SOURCE)
				{
					bIsSource = TRUE;
				}
			}
			else
			{
				// Next, look for IFileSourceFilter. 
				hr = pOldSource->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
				if (SUCCEEDED(hr))
				{
					bIsSource = TRUE;
				}
			}
			if (bIsSource)
			{
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
			SAFE_RELEASE(pFlags);
			SAFE_RELEASE(pFileSrc);
			SAFE_RELEASE(pOldSource);
		}
	}

	/************************************************************************/
	/* step 1: find all filter and disconnect all pins */
	/************************************************************************/

	// find MPEG Demultiplexer filter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMpegDemultiplexer);
	}

	SAFE_RELEASE(pOutPin);

	// find MPEG Decoder
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMpegDemultiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMpegDecoder);
	}

	SAFE_RELEASE(pOutPin);

	// find Blink counter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMpegDecoder, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pBlinkCounter);
	}

	SAFE_RELEASE(pOutPin);

	// find Color Space Converter filter 
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pBlinkCounter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pColorSpaceConverter);
	}

	SAFE_RELEASE(pOutPin);

	// find H264 encoder
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pColorSpaceConverter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pH264Encoder);
	}

	SAFE_RELEASE(pOutPin);

	// find MP4 Multiplexer
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pH264Encoder, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMp4Multiplexer);
	}

	SAFE_RELEASE(pOutPin);

	// find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMp4Multiplexer, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	SAFE_RELEASE(pOutPin);

	// disconnect all pins
	if (SUCCEEDED(hr))
	{
		DisconnectAllPins(m_pGraph);
	}

	/************************************************************************/
	/* step 2: Remove undesired filter */
	/************************************************************************/
	//remove  old source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	/************************************************************************/
	/* step 3: Add desired filter */
	/************************************************************************/
	//Add source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szSourceName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szSourceName.ReleaseBuffer();
	}

	/************************************************************************/
	/* step 4: Rename writer filter */
	/************************************************************************/

	if (SUCCEEDED(hr))
	{
		hr = pWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pSinkFilter);
		if (SUCCEEDED(hr))
		{
			sFile = m_szSinkName.GetBuffer(MAX_PATH);
			hr = pSinkFilter->SetFileName(sFile, NULL);
			m_szSinkName.ReleaseBuffer();
		}
	}

	/************************************************************************/
	/* step 5: Connect all filter */
	/************************************************************************/

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pMpegDemultiplexer);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMpegDemultiplexer, pMpegDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMpegDecoder, pBlinkCounter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pBlinkCounter, pColorSpaceConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pColorSpaceConverter, pH264Encoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pH264Encoder, pMp4Multiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMp4Multiplexer, pWriter);
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pMpegDemultiplexer);
	SAFE_RELEASE(pMpegDecoder);
	SAFE_RELEASE(pBlinkCounter);
	SAFE_RELEASE(pColorSpaceConverter);
	SAFE_RELEASE(pH264Encoder);
	SAFE_RELEASE(pMp4Multiplexer);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}


