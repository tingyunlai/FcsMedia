// FcsGrabber.cpp : Implementation of CFcsGrabber

#include "stdafx.h"
#include "FcsGrabber.h"
using namespace std;
using namespace cv;
// CFcsGrabber
HRESULT CFcsGrabber::BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter, int nFilterMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// Create the System Device Enumerator.
	HRESULT hr, hRet = S_FALSE;
	ICreateDevEnum *pSysDevEnum = NULL;
	IBaseFilter* pFilter1 = NULL;
	IMoniker *pMoniker = NULL;
	IPropertyBag *pPropBag;
	unsigned long cFetched;
	CString szRegFilterName;
	CString lpFilterName = CString(szFilterName);
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void **)&pSysDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	// Obtain a class enumerator for the video compressor category.
	IEnumMoniker *pEnumCat = NULL;
	if (nFilterMode == Filter_VideoCaptureSource)
		hr = pSysDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnumCat, 0);
	if (nFilterMode == Filter_Directshow)
		hr = pSysDevEnum->CreateClassEnumerator(CLSID_LegacyAmFilterCategory, &pEnumCat, 0);
	int i = 0;
	if (hr == S_OK)
	{
		// Enumerate the monikers.
		while (pEnumCat->Next(1, &pMoniker, &cFetched) == S_OK)
		{
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
					if (szRegFilterName == lpFilterName)
					{
						if (m_nFileNo == 3)
							if (i == 0) {
								i++;
								continue;
							}
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pFilter1);
						hr = m_pGraph->AddFilter(pFilter1, szRegFilterName);
						*pFilter = pFilter1;
						hRet = S_OK;
						VariantClear(&varName);
						pPropBag->Release();
						pMoniker->Release();
						break;
					}
				}
				VariantClear(&varName);
			}
			pPropBag->Release();
			pMoniker->Release();
		}
		pEnumCat->Release();
	}
	pSysDevEnum->Release();
	SAFE_RELEASE(pFilter1);
	return hRet;
}

HRESULT CFcsGrabber::BindCameraById(int nCamerano, IBaseFilter** pFilter, int nFilterMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// Create the System Device Enumerator.
	HRESULT hr, hRet = S_FALSE;
	ICreateDevEnum *pSysDevEnum = NULL;
	IBaseFilter* pFilter1 = NULL;
	IMoniker *pMoniker = NULL;
	IPropertyBag *pPropBag;
	unsigned long cFetched;
	CString szRegFilterName;
	int nStockCamerano = -1;
	VARIANT varName;
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, (void **)&pSysDevEnum);
	if (FAILED(hr))
	{
		return hr;
	}

	// Obtain a class enumerator for the video compressor category.
	IEnumMoniker *pEnumCat = NULL;
	if (nFilterMode == Filter_VideoCaptureSource)
		hr = pSysDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnumCat, 0);
	if (nFilterMode == Filter_Directshow)
		hr = pSysDevEnum->CreateClassEnumerator(CLSID_LegacyAmFilterCategory, &pEnumCat, 0);
	//if (nFilterMode == Filter_VideoCaptureSource)
	//	hr = pSysDevEnum->CreateClassEnumerator(CLSID_VideoCompressorCategory, &pEnumCat, 0);
	int i = 0;
	if (hr == S_OK)
	{
		// Enumerate the monikers.
		while (pEnumCat->Next(1, &pMoniker, &cFetched) == S_OK)
		{
			nStockCamerano++;
			hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag,
				(void **)&pPropBag);
			if (SUCCEEDED(hr))
			{
				if (nStockCamerano == nCamerano)
				{
					// To retrieve the filter's friendly name, do the following:
					ULONG nCountProp = 0;
					//pPropBag->CountProperties(&nCountProp);
					VariantInit(&varName);
					hr = pPropBag->Read(L"FriendlyName", &varName, 0);
					szRegFilterName = CString(varName);
					hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
						(void**)&pFilter1);
					hr = m_pGraph->AddFilter(pFilter1, szRegFilterName);
					*pFilter = pFilter1;
					hRet = S_OK;
					VariantClear(&varName);
					pPropBag->Release();
					pMoniker->Release();
					break;
				}
				VariantClear(&varName);
			}
			pPropBag->Release();
			pMoniker->Release();
		}
	}
	pEnumCat->Release();
	pSysDevEnum->Release();
	SAFE_RELEASE(pFilter1);
	return hRet;
}


HRESULT CFcsGrabber::BuildGraph(void)
{
	HRESULT hr = S_OK;

	return hr;
}


HRESULT CFcsGrabber::UpdateVolume()
{
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
HRESULT CFcsGrabber::InitializeGraph()
{
	HRESULT hr = S_OK;
	HRESULT hRes = CoInitialize(NULL);

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


	// Set up event notification.
	if (SUCCEEDED(hr))
	{
		hr = m_pEvent->SetNotifyWindow((OAHWND)m_hwndEvent, m_EventMsg, NULL);
	}
	m_pSGCallback = new CSGCallbackHandler();
	m_pAudioSample = new CAudioSample();
	CoUninitialize();

	return hr;
}

void CFcsGrabber::TearDownGraph()
{
	// Stop sending event messages
	HRESULT hr = S_OK;
	ULONG n;

	Stop();
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
	}

	if (m_pSGCallback != NULL)
	{
		delete m_pSGCallback;
		m_pSGCallback = NULL;
	}

	SAFE_RELEASE(m_pVideoRenderer);
	SAFE_RELEASE(m_pControl);
	SAFE_RELEASE(m_pEvent);
	SAFE_RELEASE(m_pSeek);
	SAFE_RELEASE(m_pVideoCapture);
	SAFE_RELEASE(m_pAudioCapture);
	SAFE_RELEASE(m_pSmartT);
	SAFE_RELEASE(m_pAudioSample);
	SAFE_RELEASE(m_pBlinkCounter);
	SAFE_RELEASE(m_pOverlay);
	SAFE_RELEASE(m_pWindowless);
	//SAFE_RELEASE(m_pAudio);

	if (m_pGraph != NULL)
	{
		n = m_pGraph->Release();
		//if (n != 0)
		//{
		//	CString szMsg;
		//	szMsg.Format(_T("failed to release Graph， count=%ld\n"), (long)n);
		//	AfxMessageBox(szMsg);
		//}else
		//{
		//	CString szMsg;
		//	szMsg.Format(_T("successed to release Graph=%ld\n"), (long)n);
		//	//AfxMessageBox(szMsg);
		//}
		m_pGraph = NULL;
	}
	SAFE_RELEASE(m_pGraph);

	m_ROTRegister = 0;
	m_state = STATE_CLOSED;
	m_seekCaps = 0;
	m_bAudioStream = FALSE;
	m_pGraph = NULL;
}

STDMETHODIMP CFcsGrabber::SetWindow(long hParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	HWND hWnd = reinterpret_cast<HWND>(hParent);
	if (hWnd == NULL)
		return S_FALSE;
	CRect rect;

	CWnd n;
	n.Attach(hWnd);
	n.GetClientRect(&m_windowRect);
	n.Detach();
	m_hwndVideo = hWnd;
	return hr;
}

STDMETHODIMP CFcsGrabber::Pause(void)
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

STDMETHODIMP CFcsGrabber::Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_state != STATE_RUNNING && m_state != STATE_PAUSED)
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

STDMETHODIMP CFcsGrabber::GetPosition(long* iPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr;
	LONGLONG timeNow;
	hr = m_pSeek->GetCurrentPosition((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*iPos = n;
	return hr;
}

STDMETHODIMP CFcsGrabber::Seek(long iPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	LONGLONG timeNow = (LONGLONG)((double)iPos * (double)ONE_SECOND / m_dFps);
	hr = SetPosition((LONGLONG)timeNow);
	return hr;
}

STDMETHODIMP CFcsGrabber::Run(void)
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

STDMETHODIMP CFcsGrabber::SetWindowPosition(long top, long left, long Width, long Height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT rc;
	CRect srcRect;
	if (m_pWindowless == NULL)
	{
		return S_FALSE; // no-op
	}
	GetClientRect(m_hwndVideo, &rc);
	long bottom = top + Height;
	long right = left + Width;
	srcRect = CRect(top, left, bottom, right);
	return m_pWindowless->SetVideoPosition(&srcRect, &rc);
}

STDMETHODIMP CFcsGrabber::Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	TearDownGraph();
	return S_OK;
}

STDMETHODIMP CFcsGrabber::Init(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return InitializeGraph();
}

STDMETHODIMP CFcsGrabber::SetFile(BSTR szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	m_szPathName = CString(szPathName);
	return hr;
}

STDMETHODIMP CFcsGrabber::Render(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int nValue = 1;

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	//hr = InitializeGraph();

	switch (m_nTemplateID) {
	case 1001: //render file
		hr = File1001();
		break;
	case 9001: //render file
		hr = Avi2Mp4();
		break;
	case 900: //render webcamera
		hr = Capture1();
		break;
	case 4004:
		hr = RunIrisCamera(); 
		break;
	case 4005:
		hr = RunIris4005(); 
		break;
	case 5001:
		hr = Capture5001(); 
		break;
	case 5002:
		hr = Capture5002(); 
		break;
	case 6001:
		hr = Capture6001(); 
		break;
	case 6002:
		hr = Capture6002(); 
		break;
	case 7001:
		hr = Capture7001(); 
		break;
	case 7002:
		hr = Capture7002(); 
		break;
	case 7003:
		hr = Capture7003(); 
		break;
	case 8001:
		hr = Capture8001(); 
		break;
	case 8002:
		hr = Capture8002(); 
		break;
	case 8004:
		hr = Video2Dump(); // video 2 dump , it is for snapshot
		break;
	}
	if (FAILED(hr))
	{
		return S_FALSE;
	}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
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

	if (SUCCEEDED(hr))
	{
#ifdef _DEBUG
		SaveGraphFile(m_pGraph, _T("c:\\a5\\tmp.grf"));
#endif	
	}

	return hr;
}

STDMETHODIMP CFcsGrabber::GetLength(long* nLength)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr;
	LONGLONG timeNow;
	hr = m_pSeek->GetDuration((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*nLength = n;
	return hr;
}

STDMETHODIMP CFcsGrabber::SetOption(long nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_nTemplateID = nOption;
	return S_OK;
}

STDMETHODIMP CFcsGrabber::GetAudio(long nChannelID, long* nVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsGrabber::SetPosition(LONGLONG pos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pControl == NULL || m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr = S_OK;

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

STDMETHODIMP CFcsGrabber::SetGraphPath(BSTR bstrGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szGraphPath = CString(bstrGraphPath);

	return S_OK;
}

STDMETHODIMP CFcsGrabber::SetSinkFile(BSTR bstrPathName, BSTR bstrPathName1, long nTemplateID, long nFileNo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szPathName = CString(bstrPathName);
	m_szPathName1 = CString(bstrPathName1);
	m_nTemplateID = nTemplateID;
	m_nFileNo = nFileNo;
	return S_OK;
}

HRESULT CFcsGrabber::Capture2(void)
{
	HRESULT hr = S_OK;
	// locate video screen renderer for the preview window
	hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");

	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	if (SUCCEEDED(hr))
	{
		// locate the video capture devices
		PWSTR pVideoName = _T("Decklink Video Capture");
		hr = AddFilter2(m_pGraph, CLSID_VideoInputDeviceCategory, pVideoName, &m_pVideoCapture);
		PWSTR pAudioName = _T("Decklink Audio Capture");
		hr = AddFilter2(m_pGraph, CLSID_AudioInputDeviceCategory, pAudioName, &m_pAudioCapture);
	}
	hr = CreatePreviewGraph();
	return hr;
}

HRESULT CFcsGrabber::Capture3(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cmpgdvd8m.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsGrabber::Capture4(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cdv50avi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture5(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cdvavi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture6(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Chddv100avi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture7(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Chddvdmpeg.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture8(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cmjpegavi.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture9(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Chdmjpegavi.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture10(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cmpgdvd8mwmv9.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture11(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cdv50aviwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture12(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cdvaviwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsGrabber::Capture13(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("chddvdmpegwmv9.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::Capture14(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("cmjpegaviwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsGrabber::Capture15(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Chdmjpegaviwmv9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsGrabber::Capture16(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("Chddv100aviWMV9.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
		}

	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsGrabber::CreatePreviewGraph(void)
{
	HRESULT hr = S_OK;

	// locate smart-T
	// NOTE: The smart-T appears to hold references to its upstream connections even when its input pin
	// is diconnected.  The smart-T has to be removed from the graph in order to clear these references which
	// is why the filter is enumerated and added every time the preview graph is built and removed whenever
	// it is destroyed.
	ASSERT(!m_pSmartT);
	hr = AddFilter(m_pGraph, CLSID_SmartTee, L"Smart Tee", &m_pSmartT);
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, m_pVideoCapture, NULL, m_pSmartT, NULL);
		if (SUCCEEDED(hr))
		{
			// now connect the preview pin of the smart-T to the video renderer
			hr = ConnectFilters(m_pGraph, m_pSmartT, L"Preview", m_pVideoRenderer, NULL);
		}
	}

	if (SUCCEEDED(hr))
	{
		// optionally connect the audio path
		if (FALSE == m_bAudioMute)
		{
			// connect the Decklink audio capture pin to the mux
			hr = RenderFilter(m_pGraph, m_pAudioCapture, L"Capture");
		}

	}

	return hr;
}

STDMETHODIMP CFcsGrabber::SetHWnd(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_hwndVideo = hWnd;
	return S_OK;
}

STDMETHODIMP CFcsGrabber::UpdateVideoWindow(const LPRECT prc)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT rc;
	CRect rcVolumeIndicator;
	CRect srcRect;
	// TODO: Add your implementation code here
	if (m_pWindowless == NULL)
	{
		return S_FALSE; // no-op
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

STDMETHODIMP CFcsGrabber::GetVideoSize(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	if (m_pWindowless == NULL)
		return S_FALSE;
	hr = m_pWindowless->GetNativeVideoSize(lpWidth, lpHeight, lpARWidth, lpARHeight);
	return hr;
}

STDMETHODIMP CFcsGrabber::Repaint(HDC hdc)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pWindowless)
	{
		return m_pWindowless->RepaintVideo(m_hwndVideo, hdc);
	}
	else
	{
		return S_FALSE;
	}
}
STDMETHODIMP CFcsGrabber::Record(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = Stop();
	m_pSGCallback->SetOption(0);
	m_pSGCallback->RestImageCounter();
	CString szOldHighFile, szOldLowFile;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += _T("\\");
	szOldHighFile = m_szGraphPath + CString(_T("9fcs.m2p"));
	szOldLowFile = m_szGraphPath + CString(_T("9fcs1.wmv"));
	if (m_nFileNo == 1)
	{
		////Find writer filter
		AM_MEDIA_TYPE mt;
		mt.lSampleSize = 1;
		IFileSinkFilter* pSinkFilter = NULL;
		if (SUCCEEDED(hr))
		{
			hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
		}
		WCHAR* sFile;
		if (SUCCEEDED(hr))
		{
			sFile = m_szPathName.GetBuffer(MAX_PATH);
			hr = pSinkFilter->SetFileName(sFile, NULL);
			m_szPathName.ReleaseBuffer();
		}

	}
	if (m_nFileNo == 2)
	{
		hr = Record2Files();
	}
	//Sleep(1000);
	hr = Run();
	if (m_nFileNo == 1)
		::DeleteFile((LPCTSTR)szOldLowFile);
	if (m_nFileNo == 2)
	{
		::DeleteFile((LPCTSTR)szOldLowFile);
		::DeleteFile((LPCTSTR)szOldHighFile);
	}
	return hr;
}

STDMETHODIMP CFcsGrabber::UpdateWindow(long left, long top, long right, long bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CRect rect = CRect(left, top, right, bottom);
	UpdateVideoWindow(&rect);
	return S_OK;
}

STDMETHODIMP CFcsGrabber::State(long* state)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*state = m_state;
	return S_OK;
}

STDMETHODIMP CFcsGrabber::GetAudioLevel(long nChannel, long* nVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pAudioSample == NULL)
	{
		*nVolume = 0;
		return S_FALSE;
	}
	m_pAudioSample->GetAudiolevel(nChannel, nVolume);
	return S_OK;

}

HRESULT CFcsGrabber::Record2Files(void)
{
	HRESULT hr = S_OK;
	IFileSinkFilter* pHighSinkFilter = NULL;
	IFileSinkFilter* pLowSinkFilter = NULL;
	IBaseFilter* pHighFilter = NULL;
	IBaseFilter* pLowFilter = NULL;
	IBaseFilter* pNewHighFilter = NULL;
	IBaseFilter* pNewLowFilter = NULL;
	IEnumFilters *pEnumFilter = NULL;
	IBaseFilter* pUpStreamFilter = NULL;
	IPin* pInPin = NULL;
	AM_MEDIA_TYPE mt;

	BSTR bstrHighFile;
	WCHAR* sFile;
	CString str;
	mt.lSampleSize = 1;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	CString szLowFile = m_szGraphPath + CString(_T("9fcs1.wmv"));
	CString szHighFile = m_szGraphPath + CString(_T("9fcs.m2p"));
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	while (pEnumFilter->Next(1, &pLowFilter, 0) == S_OK)
	{
		hr = pLowFilter->QueryInterface(IID_IFileSinkFilter, (void**)&pLowSinkFilter);
		if (SUCCEEDED(hr))
		{	
			hr = pLowSinkFilter->GetCurFile(&bstrHighFile, NULL);
			str = CString(bstrHighFile);
			str.MakeLower();
			if (str == szLowFile)
			{
				sFile = m_szPathName1.GetBuffer(MAX_PATH);
				hr = pLowSinkFilter->SetFileName(sFile, &mt);
				m_szPathName1.ReleaseBuffer();
				break;
			}
		}
	}

	pEnumFilter->Reset();

	while (pEnumFilter->Next(1, &pHighFilter, 0) == S_OK)
	{
		hr = pHighFilter->QueryInterface(IID_IFileSinkFilter, (void**)&pHighSinkFilter);
		if (SUCCEEDED(hr))
		{
			hr = pHighSinkFilter->GetCurFile(&bstrHighFile, NULL);
			str = CString(bstrHighFile);
			str.MakeLower();
			if (str == szHighFile)
			{
				hr = FindConnectedPin(pHighFilter, PINDIR_INPUT, &pInPin);
				if (SUCCEEDED(hr))
				{
					hr = GetConnectedFilter(pInPin, &pUpStreamFilter);
				}

				if (SUCCEEDED(hr))
				{
					hr = RemoveFilter(m_pGraph, pHighFilter);
				}
				if (SUCCEEDED(hr))
				{
					sFile = m_szPathName.GetBuffer(MAX_PATH);
					hr = AddFilterByCLSID(m_pGraph, CLSID_FileWriter, &pNewHighFilter);
					hr = pNewHighFilter->QueryInterface(IID_IFileSinkFilter, (void**)&pHighSinkFilter);
					hr = pHighSinkFilter->SetFileName(sFile, NULL);
					m_szPathName.ReleaseBuffer();
				}

				if (SUCCEEDED(hr))
				{
					hr = ConnectFilters(m_pGraph, pUpStreamFilter, pNewHighFilter);
				}

				break;
			}
		}
	}

	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pHighFilter);
	SAFE_RELEASE(pHighSinkFilter);
	SAFE_RELEASE(pLowFilter);
	SAFE_RELEASE(pLowSinkFilter);
	SAFE_RELEASE(pNewHighFilter);
	SAFE_RELEASE(pUpStreamFilter);
	SAFE_RELEASE(pInPin);


	return hr;
}

STDMETHODIMP CFcsGrabber::SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath)
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

STDMETHODIMP CFcsGrabber::SaveKFInfo(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	if (m_pSGCallback != NULL && m_nFileNo == 2)
	{
		m_pSGCallback->SaveDataFile();
		hr = S_OK;
	}
	else
		hr = S_FALSE;
	return hr;
}


STDMETHODIMP CFcsGrabber::ChangeWindow(long hWndHandle)
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

STDMETHODIMP CFcsGrabber::ChangeHWnd(HWND hWnd)
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
	SAFE_DELETE(pInfo);


	return hr;
}

HRESULT CFcsGrabber::Capture47411(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pVideoRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pAudioRender = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("47411.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
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

		SAFE_RELEASE(pInputPin);

		if (SUCCEEDED(hr))
		{
			hr = RemoveFilter(m_pGraph, pOldRender);
		}

		if (SUCCEEDED(hr))
		{
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
		}

		//// connected new render filter 
		if (SUCCEEDED(hr))
		{
			hr = ConnectFilters(m_pGraph, pVMR, pVideoRender);
		}

	}
	
	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}
	//Find audio render 
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pAudioRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pAudioRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Audio Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			else
			{
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				SAFE_RELEASE(pAudioRender);
				hr = S_FALSE;
			}
		}
	}


	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pVideoRender);
	return hr;
}

HRESULT CFcsGrabber::Capture47412(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = NULL;
	IVMRFilterConfig* pConfig = NULL;
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("47411.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
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

	SAFE_RELEASE(pInputPin);

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}


	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pConfig);
	return hr;
}

HRESULT CFcsGrabber::Capture47413(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pBlinkCouter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("47413.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	// find blink couter filter
	if (SUCCEEDED(hr))
	{
		SAFE_RELEASE(pEnumFilter);
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pBlinkCouter, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pBlinkCouter->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs BlinkCounter"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pBlinkCouter);
			hr = S_FALSE;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = pBlinkCouter->QueryInterface(IID_IFcsBlinkCounter, (void**)&m_pBlinkCounter);
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pBlinkCouter);
	return hr;
}

HRESULT CFcsGrabber::Capture2001(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pBlinkCouter = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("2001.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	// find blink couter filter
	if (SUCCEEDED(hr))
	{
		SAFE_RELEASE(pEnumFilter);
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pBlinkCouter, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pBlinkCouter->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs BlinkCounter"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pBlinkCouter);
			hr = S_FALSE;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = pBlinkCouter->QueryInterface(IID_IFcsBlinkCounter, (void**)&m_pBlinkCounter);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pBlinkCouter);
	SAFE_RELEASE(pOverLay);
	return hr;
}

HRESULT CFcsGrabber::Capture2002(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pBlinkCouter = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("2002.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	// find blink couter filter
	if (SUCCEEDED(hr))
	{
		SAFE_RELEASE(pEnumFilter);
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pBlinkCouter, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pBlinkCouter->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs BlinkCounter"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pBlinkCouter);
			hr = S_FALSE;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = pBlinkCouter->QueryInterface(IID_IFcsBlinkCounter, (void**)&m_pBlinkCounter);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pBlinkCouter);
	SAFE_RELEASE(pOverLay);
	return hr;
}

HRESULT CFcsGrabber::Capture3001(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("3001.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}

HRESULT CFcsGrabber::Capture3002(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("3002.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}

HRESULT CFcsGrabber::Capture3003(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("3003.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}

HRESULT CFcsGrabber::Capture3004(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("3004.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}

HRESULT CFcsGrabber::Capture4001(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("4001.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
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

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer9, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR9(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}



	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	//SAFE_RELEASE(pSinkFilter);
	return hr;
}

HRESULT CFcsGrabber::Capture4002(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("4002.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
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
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	IFileSinkFilter* pSinkFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	return hr;
}


HRESULT CFcsGrabber::Capture4003(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("4003.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	// find connected pin
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin， ColorSpace
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}


	//find fcs face detector filter
	IBaseFilter* pFacedetecorFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVMR, PINDIR_INPUT, &pInputPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pInputPin, &pFacedetecorFilter);
	}

	SAFE_RELEASE(pInputPin);
	//if (SUCCEEDED(hr))
	//{
	//	hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	//}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pFacedetecorFilter);
	return hr;
}


HRESULT CFcsGrabber::Capture5001(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	//	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pVideoRenderer = NULL;
	IBaseFilter *pConverter = NULL;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("FcsDump"), &pConverter, Filter_Directshow);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pConverter);
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr) && pSource)
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr) && pSource)
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr) && pSource)
	{
		m_state = STATE_STOPPED;
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pConverter);
	return hr;
}


HRESULT CFcsGrabber::Capture5002(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	//IFileSinkFilter* pSinkFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("5002.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	// find connected pin
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin， ColorSpace
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	return hr;
}


HRESULT CFcsGrabber::Capture6001(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IFileSinkFilter* pSinkFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("6001.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	// find connected pin
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin， ColorSpace
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	//Find writer filter
	if (SUCCEEDED(hr))
	{
		hr = FindFilterInterface(m_pGraph, IID_IFileSinkFilter, (void**)&pSinkFilter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName.GetBuffer(MAX_PATH);
		hr = pSinkFilter->SetFileName(sFile, NULL);
		m_szPathName.ReleaseBuffer();
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	SAFE_RELEASE(pSinkFilter);
	return hr;
}


HRESULT CFcsGrabber::Capture6002(void)
{
	HRESULT hr = S_OK;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pOverLay = NULL;
	IEnumFilters* pEnumFilter = NULL;
	//IFileSinkFilter* pSinkFilter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	// Load graph
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("6002.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//find render filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Video Renderer"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	// find connected pin
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin， ColorSpace
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// connected new render filter 
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pVideoRenderer);
	}

	//find fcsOverlay filter
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pOverLay, 0) == S_OK)
		{
			pInfo = new FILTER_INFO;
			pOverLay->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			if (str == _T("Fcs Overlay"))
			{
				hr = S_OK;
				SAFE_RELEASE(pInfo->pGraph);
				SAFE_DELETE(pInfo);
				break;
			}
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOverLay);
			hr = S_FALSE;
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumFilter->Reset();
	}

	if (SUCCEEDED(hr))
	{
		hr = pOverLay->QueryInterface(IID_IFcsOverlay, (void**)&m_pOverlay);
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOverLay);
	return hr;
}

STDMETHODIMP CFcsGrabber::GetGraphPath(BSTR* strGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*strGraphPath = m_szGraphPath.AllocSysString();
	return S_OK;
}


STDMETHODIMP CFcsGrabber::IsMute(SHORT* bMute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*bMute = m_bMute;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::GetVideoFps(DOUBLE* dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*dFps = m_dFps;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetFullScreen(SHORT* nResult, SHORT nState)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (nState != 0 && nState != 1)
		*nResult = 0;

	return S_OK;
}


STDMETHODIMP CFcsGrabber::SnapImage(BSTR bstrImagename, LONG nNewWidth, LONG nNewHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;
	long nWidth;
	long nHeight;

	BYTE* lbuf = NULL;
	if (m_pWindowless == NULL)
		return S_FALSE;
	hr = m_pWindowless->GetCurrentImage(&lbuf);
	if (lbuf == NULL)
		return S_FALSE;
	BITMAPINFO bmpInfo;
	RGBQUAD bmiColor;
	bmiColor.rgbBlue = 255;
	bmiColor.rgbGreen = 255;
	bmiColor.rgbRed = 255;
	bmiColor.rgbReserved = 0;
	BITMAPINFOHEADER *pBMIH = (BITMAPINFOHEADER*)lbuf;
	bmpInfo.bmiHeader = *pBMIH;
	//bmpInfo.bmiColors = (RGBQUAD)bmiColor[1];
	hr = GetVideoSize(&nWidth, &nHeight, NULL, NULL);
	int m_nBitPerPixel = pBMIH->biBitCount;
	int nPitch = pBMIH->biXPelsPerMeter;
	CImage im;
	CString path = CString(bstrImagename);
	BOOL hr1 = im.Create(nWidth, nHeight, m_nBitPerPixel,1);
	HDC dc = im.GetDC();
	SetDIBitsToDevice(dc, 0, 0, nWidth, nHeight, 0, 0, 0, nHeight, lbuf, &bmpInfo, DIB_RGB_COLORS);
	im.ReleaseDC();
	im.Save(path, Gdiplus::ImageFormatJPEG);
	CoTaskMemFree(lbuf);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::MP_GetPosition(LONG* nIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONGLONG timeNow;
	hr = GetCurrentPosition((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*nIndex = n;
	return hr;
}


STDMETHODIMP CFcsGrabber::GetCurrentPosition(LONGLONG* pTimeNow)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}
	return m_pSeek->GetCurrentPosition(pTimeNow);
}


STDMETHODIMP CFcsGrabber::GetFaceRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*left = 0;
		*top = 0;
		*right = 0;
		*bottom = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetFaceRect(left, top, right, bottom);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetFaceWidth(LONG* nWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nWidth = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetFaceWidth(nWidth);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetFaceHeight(LONG* nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nHeight = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetFaceHight(nHeight);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetLEyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*left = 0;
		*top = 0;
		*right = 0;
		*bottom = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetLEyeRect(left, top, right, bottom);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetREyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*left = 0;
		*top = 0;
		*right = 0;
		*bottom = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetREyeRect(left, top, right, bottom);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetLEyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*left = 0;
		*top = 0;
		*right = 0;
		*bottom = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetLEyeballRect(left, top, right, bottom);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetREyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*left = 0;
		*top = 0;
		*right = 0;
		*bottom = 0;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetREyeballRect(left, top, right, bottom);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetFaceImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	HRESULT hr = m_pBlinkCounter->GetFaceImg(pImage, nSize);
	return hr;
}


STDMETHODIMP CFcsGrabber::GetLEyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLEyeImg(pImage, nSize);
}


STDMETHODIMP CFcsGrabber::GetREyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetREyeImg(pImage, nSize);
}


STDMETHODIMP CFcsGrabber::GetLEyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLEyeballImg(pImage, nSize);
}


STDMETHODIMP CFcsGrabber::GetREyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetREyeballImg(pImage, nSize);
}


STDMETHODIMP CFcsGrabber::GetLeadFace(BYTE* pLeadFace)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pLeadFace == NULL)
	{
		pLeadFace = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLeadFace(pLeadFace);
}


STDMETHODIMP CFcsGrabber::GetActivativedValue(DOUBLE* dActivation)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*dActivation = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetActivativedValue(dActivation);
}


STDMETHODIMP CFcsGrabber::GetBlinkCount(LONG* nCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nCount = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetBlinkCount(nCount);
}


STDMETHODIMP CFcsGrabber::GetCurTimeMs(LONG* MilliSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*MilliSec = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTimeMs(MilliSec);
}


STDMETHODIMP CFcsGrabber::GetCurTime(LONGLONG* NSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*NSec = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTime(NSec);
}


STDMETHODIMP CFcsGrabber::ResetCounter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->ResetCounter();
}


STDMETHODIMP CFcsGrabber::SetCheck(SHORT nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		nCheck = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->SetCheck(nCheck);
}


STDMETHODIMP CFcsGrabber::GetCheck(SHORT* nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nCheck = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCheck(nCheck);
}


STDMETHODIMP CFcsGrabber::SetFaceRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetFaceRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::GetFaceRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetFaceRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetEyeRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetEyeRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::GetEyeRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetEyeRectLineWidth(fLineWidth);
	return S_OK;
}



STDMETHODIMP CFcsGrabber::DisPlayOverlay(LONG nID, SHORT IsVisible)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->DisPlayOverlay(nID, IsVisible);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::GetCountOfArray(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->GetCountOfArray();
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetOverlayPosition(LONG nId, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayPosition(nId, nLeft, nTop, nRight, nBottom);
	return S_OK;
}




STDMETHODIMP CFcsGrabber::SetOverlayColor(LONG nID, COLORREF nColor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayColor(nID, nColor);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetOverlayFontSize(LONG nID, LONG nFontSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFontSize(nID, nFontSize);
	return S_OK;
}




STDMETHODIMP CFcsGrabber::SetOverlayFont(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFont(nID, nFontStyle, bUnderLine, bWrap, bVertical, bRightAlign);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetOverlayText(LONG nID, BSTR szText)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayText(nID, szText);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetOverlayFontName(LONG nID, BSTR szFontName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFontName(nID, szFontName);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetOverlayImgPosition(BSTR szImgName, LONG left, LONG top, LONG right, LONG bottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->put_ImageOverlay(szImgName, left, top, right, bottom, bDisplay, bScaleFit, nTranspency);
	return S_OK;
}



STDMETHODIMP CFcsGrabber::EnableRoi(SHORT Enable)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_bEnableRoi = Enable;

	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetRoi(LONG left, LONG top, LONG right, LONG bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_Roi.SetRect(left, top, right, bottom);

	return S_OK;
}


STDMETHODIMP CFcsGrabber::ShowRoi(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (!m_bEnableRoi)
		return S_FALSE;
	long nWidth, nHeight;
	HRESULT hr;
	hr = GetVideoSize(&nWidth, &nHeight, NULL, NULL);
	//CWnd wndVideo;
	//wndVideo.Attach(m_hwndVideo);
	CRect rt;
	::GetClientRect(m_hwndVideo, &rt);
	//	wndVideo.GetClientRect(&rt);
	float dXScale = (double)nWidth / (double)rt.Width();
	float dYScale = (double)nHeight / (double)rt.Height();
	CRect rtRoi;
	m_Roi.GetRect(&rtRoi);
	CRect rtTmpRoi;
	rtTmpRoi.left = rtRoi.left * dXScale;
	rtTmpRoi.right = rtRoi.right * dXScale;
	rtTmpRoi.top = rtRoi.top * dYScale;
	rtTmpRoi.bottom = rtRoi.bottom * dYScale;
	m_Roi.SetRect(&rtTmpRoi);
	HDC hDC = ::GetDC(m_hwndVideo);
	m_Roi.Draw(hDC);
	m_Roi.SetRect(&rtRoi);
	//	wndVideo.Detach();
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetRoiProp(LONG nColor, LONG PenStyle, LONG LineWidth, LONG ShapeType)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_Roi.SetColor((COLORREF)nColor);
	m_Roi.SetPenStyle(PenStyle);
	m_Roi.SetLineWidth(LineWidth);
	m_Roi.SetShapeType(ShapeType);

	return S_OK;
}

HRESULT CFcsGrabber::RunIrisCamera(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}

HRESULT	CFcsGrabber::RenderStreams(IBaseFilter *pSource)
{
	HRESULT hr = S_OK;

	BOOL bRenderedAnyPin = FALSE;

	IEnumPins *pEnum = NULL;
	//IBaseFilter *pVMR = NULL;
	IBaseFilter *pAudioRenderer = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IFilterGraph2 *pGraph2 = NULL;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	// Add the VMR-7 to the graph.
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoRendererDefault, &pVideoRenderer, L"Video Renderer");
		//hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRenderer, L"VMR-9");
	}

	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//// Add the DSound Renderer to the graph.
	//if (SUCCEEDED(hr))
	//{
	//	hr = AddFilterByCLSID(m_pGraph, CLSID_DSoundRender, &pAudioRenderer, L"Audio Renderer");
	//}

	// Enumerate the pins on the source filter.
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


	// Remove un-used renderers.

	// Try to remove the VMR.
	if (SUCCEEDED(hr))
	{
		BOOL bRemoved = FALSE;
		hr = RemoveUnconnectedRenderer(m_pGraph, pVideoRenderer, &bRemoved);

		// If we removed the VMR, then we also need to release our 
		// pointer to the VMR's windowless control interface.
		if (bRemoved)
		{
			SAFE_RELEASE(m_pWindowless);
		}
	}

	// Try to remove the audio renderer.
	//if (SUCCEEDED(hr))
	//{
	//	BOOL bRemoved = FALSE;
	//	hr = RemoveUnconnectedRenderer(m_pGraph, pAudioRenderer, &bRemoved);

	//	if (bRemoved)
	//	{
	//		m_bAudioStream = FALSE;
	//	}
	//	else
	//	{
	//		m_bAudioStream = TRUE;
	//	}
	//}

	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pAudioRenderer);
	SAFE_RELEASE(pGraph2);

	// If we succeeded to this point, make sure we rendered at least one 
	// stream.
	if (SUCCEEDED(hr))
	{
		if (!bRenderedAnyPin)
		{
			hr = VFW_E_CANNOT_RENDER;
		}
	}

	return hr;
}

HRESULT CFcsGrabber::RunIris4005(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter *pConverter = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	int n;
	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
	}
	if (pSource == NULL)
	{
		hr = E_FAIL;
		goto there;
	}
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Pinnacle Image Converter"), &pConverter, Filter_Directshow);
	}
	if (pConverter == NULL)
	{
		n = m_pGraph->Release();
		hr = E_FAIL;
		goto there;
	}
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoRendererDefault, &m_pVideoRenderer, L"Video Renderer");
	}

	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}

	//add sampleGrabber
	if (SUCCEEDED(hr))
	{
		CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (LPVOID   *)&pSampleFilter);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pSampleFilter);
	}

	//if (SUCCEEDED(hr))
	//{
	//	//hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	//	hr = ConnectFilters(m_pGraph, pConverter, pSampleFilter);
	//}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSampleFilter, pConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pConverter, m_pVideoRenderer);
	}

	// Get the seeking capabilities.
	if (SUCCEEDED(hr) && pSource)
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	// Set the volume.
	if (SUCCEEDED(hr) && pSource)
	{
		hr = UpdateVolume();
	}

	// Update our state.
	if (SUCCEEDED(hr) && pSource)
	{
		m_state = STATE_STOPPED;
	}
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_YUY2;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			hr = pSampleGrabber->SetBufferSamples(TRUE);
			pSampleGrabber->GetConnectedMediaType(&m_pSGCallback->g_StillMediaType);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nBitPerPixel = 32;
			m_pSGCallback->RestImageCounter();
			m_pSGCallback->SetOption(0);
			m_pSGCallback->SetMode(JBU_IRIS_DETECTION_MODE);
			m_pSGCallback->SetExportDir(m_szExportDir);
			m_pSGCallback->m_szExportName = m_szExportName;
			m_pSGCallback->m_nExportWidh = m_nExportWidh;
			m_pSGCallback->m_nExportHeight = m_nExportHeight;
			m_pSGCallback->m_nCompressRatio = m_nCompressRatio;
			m_pSGCallback->m_nCaptureFreq = m_nCaptureFreq;
			m_pSGCallback->m_nFramePerSec = m_nFramePerSec;
			hr = GetVideoSize(&m_pSGCallback->m_nWidth, &m_pSGCallback->m_nHeight, &m_pSGCallback->m_nArWidth, &m_pSGCallback->m_nArHeight);
			pSampleGrabber->SetCallback(m_pSGCallback, 1);
		}
	}

there:
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pConverter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pSampleGrabber);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}

STDMETHODIMP CFcsGrabber::SnapGrayImage(BSTR bstrImagename, LONG nNewWidth, LONG nNewHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;
	long nWidth;
	long nHeight;

	BYTE* lbuf = NULL;
	hr = m_pWindowless->GetCurrentImage(&lbuf);
	if (lbuf == NULL)
		return S_FALSE;
	BITMAPINFO bmpInfo;
	RGBQUAD bmiColor;
	bmiColor.rgbBlue = 255;
	bmiColor.rgbGreen = 255;
	bmiColor.rgbRed = 255;
	bmiColor.rgbReserved = 0;
	BITMAPINFOHEADER *pBMIH = (BITMAPINFOHEADER*)lbuf;
	bmpInfo.bmiHeader = *pBMIH;
	//bmpInfo.bmiColors = (RGBQUAD)bmiColor[1];
	hr = GetVideoSize(&nWidth, &nHeight, NULL, NULL);
	int m_nBitPerPixel = pBMIH->biBitCount;
	CString path = CString(bstrImagename);
	wchar_t* szFile = path.GetBuffer(0);

	if (nNewWidth == 0 && nNewHeight == 0)
	{
		nNewHeight = nHeight;
		nNewWidth = nWidth;
	}
	CImage im;
	im.Attach((HBITMAP)lbuf);
	im.Save(path);
	CoTaskMemFree(lbuf);
	return S_OK;
}

STDMETHODIMP CFcsGrabber::SetExportDir(BSTR ExportDir)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_szExportDir = CString(ExportDir);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetExportName(BSTR ImageName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_szExportName = CString(ImageName);
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetExportImageWidth(LONG Width)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_nExportWidh = Width;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetExportImageHeight(LONG Height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_nExportHeight = Height;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetCompressRatio(LONG Ratio)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_nCompressRatio = Ratio;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetCaptureFreq(LONG Freq)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_nCaptureFreq = Freq;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::SetCaneraFps(LONG FramePerSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_nFramePerSec = FramePerSec;
	return S_OK;
}


STDMETHODIMP CFcsGrabber::EnableCapture(LONG Enable)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pSGCallback == NULL) return S_FALSE;
	m_pSGCallback->EnableCapture(Enable);
	return S_OK;
}


HRESULT CFcsGrabber::Capture7001(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pAvidescFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
																				 
	}
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AVIDec, &pAvidescFilter, L"AVI Desc");
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAvidescFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAvidescFilter, m_pVideoRenderer);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pAvidescFilter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}


HRESULT CFcsGrabber::Capture1(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pDump = NULL;
	IBaseFilter *pMjpegCompress = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	AM_MEDIA_TYPE mt;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindCameraById(m_nFileNo, &pSource, Filter_VideoCaptureSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
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

	SAFE_RELEASE(pSource);
	return hr;
}
HRESULT CFcsGrabber::Capture7002(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pDump = NULL;
	IBaseFilter *pMjpegCompress = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	AM_MEDIA_TYPE mt;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		//		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
		hr = BindCameraById(m_nFileNo, &pSource, Filter_VideoCaptureSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("FcsDump"), &pDump, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MJPEG Decompressor"), &pMjpegCompress, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (LPVOID   *)&pSampleFilter);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pMjpegCompress);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMjpegCompress, pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSampleFilter, pDump);
	}

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_YUY2;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			hr = pSampleGrabber->SetBufferSamples(TRUE);
			pSampleGrabber->GetConnectedMediaType(&m_pSGCallback->g_StillMediaType);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nBitPerPixel = 32;
			m_pSGCallback->RestImageCounter();
			m_pSGCallback->SetOption(0);
			m_pSGCallback->SetMode(JBU_IRIS_DETECTION_MODE);
			m_pSGCallback->SetExportDir(m_szExportDir);
			m_pSGCallback->m_szExportName = m_szExportName;
			m_pSGCallback->m_nExportWidh = m_nExportWidh;
			m_pSGCallback->m_nExportHeight = m_nExportHeight;
			m_pSGCallback->m_nCompressRatio = m_nCompressRatio;
			m_pSGCallback->m_nCaptureFreq = m_nCaptureFreq;
			m_pSGCallback->m_nFramePerSec = m_nFramePerSec;
			hr = GetVideoSize(&m_pSGCallback->m_nWidth, &m_pSGCallback->m_nHeight, &m_pSGCallback->m_nArWidth, &m_pSGCallback->m_nArHeight);
			m_pSGCallback->m_nWidth = 640;
			m_pSGCallback->m_nHeight = 360;
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

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pDump);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pMjpegCompress);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}

HRESULT CFcsGrabber::Capture7003(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pDump = NULL;
	IBaseFilter *pMjpegCompress = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	AM_MEDIA_TYPE mt;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		//		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
		hr = BindCameraById(m_nFileNo, &pSource, Filter_VideoCaptureSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
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

	SAFE_RELEASE(pSource);
	return hr;
}


HRESULT CFcsGrabber::Capture8001(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pXvid = NULL;
	IBaseFilter *pMjpegCompress = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	AM_MEDIA_TYPE mt;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
																				 
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Xvid MPEG-4 Codec"), &pXvid, Filter_VideoCompressor);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Mpeg4s Decoder DMO"), &pMjpegCompress, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pXvid);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pXvid, pMjpegCompress);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMjpegCompress, m_pVideoRenderer);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pXvid);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pMjpegCompress);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}


HRESULT CFcsGrabber::Capture8002(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pXvid = NULL;
	IBaseFilter *pMjpegCompress = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	AM_MEDIA_TYPE mt;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;

	hr = InitializeGraph();


	// Add the camera filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(m_szPathName, &pSource, Filter_VideoCaptureSource);
																				 
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Xvid MPEG-4 Codec"), &pXvid, Filter_VideoCompressor);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Mpeg4s Decoder DMO"), &pMjpegCompress, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &m_pVideoRenderer, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoRenderer, m_hwndVideo, &m_pWindowless);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pXvid);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pXvid, pMjpegCompress);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMjpegCompress, m_pVideoRenderer);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pXvid);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pMjpegCompress);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);


	return hr;
}

HRESULT CFcsGrabber::File1001()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pAudioRender = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;

	HRESULT hr = S_OK;
	m_ROTRegister = 0;
	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(m_szPathName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	return hr;
}

HRESULT CFcsGrabber::Avi2Mp4()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pEncoder = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	IBaseFilter *pSplitter = NULL;
	IBaseFilter *pMultiplexer = NULL;
	IBaseFilter *pFileWriter = NULL;
	IFileSinkFilter* pFileSinker = NULL;
	FILTER_INFO* pInfo = NULL;
	IPin* pInputPin = NULL;
	wchar_t* sFile = NULL;
	HRESULT hr = S_OK;
	m_ROTRegister = 0;
	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	hr = InitializeGraph();



	// Add the source filter to the graph.
 	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(m_szPathName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviSplitter, &pSplitter, L"AVI Splitter");
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept AVC/H.264 Video Encoder"), &pEncoder, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept MP4 Multiplexer"), &pMultiplexer, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_FileWriter, &pFileWriter);
	}

	if (SUCCEEDED(hr))
	{
		sFile = m_szPathName1.GetBuffer(MAX_PATH);
		hr = pFileWriter->QueryInterface(IID_IFileSinkFilter, (void**)&pFileSinker);
		hr = pFileSinker->SetFileName(sFile, NULL);
		m_szPathName1.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSplitter, pEncoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pEncoder, pMultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pMultiplexer, pFileWriter);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSplitter);
	SAFE_RELEASE(pEncoder);
	SAFE_RELEASE(pMultiplexer);
	SAFE_RELEASE(pFileWriter);
	SAFE_RELEASE(pFileSinker);
	SAFE_RELEASE(pEnumFilter);
	//SAFE_RELEASE(pInfo->pGraph);
	//SAFE_DELETE(pInfo);

	return hr;
}


HRESULT CFcsGrabber::Video2Dump()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IBaseFilter *pSplitter = NULL;
	IBaseFilter *pDecoder = NULL;
	IBaseFilter *pFrameEater = NULL;
	IBaseFilter *pFileWriter = NULL;
	wchar_t* sFile = NULL;
	HRESULT hr = S_OK;
	m_ROTRegister = 0;
	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(m_szPathName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept MP4 Demultiplexer"), &pSplitter, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("MainConcept AVC/H.264 Video Decoder"), &pDecoder, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Fcs Face Counter"), &pFrameEater, Filter_Directshow);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("FcsDump"), &pFileWriter, Filter_Directshow);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pSplitter);
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSplitter, pDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDecoder, pFrameEater);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pFrameEater, pFileWriter);
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

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSplitter);
	SAFE_RELEASE(pDecoder);
	SAFE_RELEASE(pFrameEater);
	SAFE_RELEASE(pFileWriter);
	return hr;
}


STDMETHODIMP CFcsGrabber::WaitForCompletion(LONG nTimeout, LONG* evtCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pEvent == NULL)
		return S_FALSE;
	HRESULT hr = m_pEvent->WaitForCompletion(nTimeout, evtCode);
	return hr;
}
