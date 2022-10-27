// JbuCapturer.cpp : CJbuCapturer 的实现

#include "stdafx.h"
#include "JbuCapturer.h"


//private function
HRESULT CJbuCapturer::UpdateVolume()
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
HRESULT CJbuCapturer::BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// Create the System Device Enumerator.
	HRESULT hr;
	ICreateDevEnum *pSysDevEnum = NULL;
	IBaseFilter* pFilter1 = NULL;
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
	hr = pSysDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnumCat, 0);

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
					if (szRegFilterName == lpFilterName)
					{
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pFilter1);
						hr = m_pGraph->AddFilter(pFilter1, szRegFilterName);
						*pFilter = pFilter1;
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

	return hr;
}
HRESULT CJbuCapturer::BuildGraph(void)
{
	HRESULT hr = S_OK;

	return hr;
}

HRESULT CJbuCapturer::InitializeGraph()
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


	// Set up event notification.
	if (SUCCEEDED(hr))
	{
		hr = m_pEvent->SetNotifyWindow((OAHWND)m_hwndEvent, m_EventMsg, NULL);
	}
	m_pSGCallback = new CSGCallbackHandler();
	return hr;
}
HRESULT CJbuCapturer::SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath)
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
	return hr;

}
void CJbuCapturer::TearDownGraph()
{
	// Stop sending event messages
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
	SAFE_RELEASE(m_pVideoRenderer);
	SAFE_RELEASE(m_pControl);
	SAFE_RELEASE(m_pEvent);
	SAFE_RELEASE(m_pSeek);
	SAFE_RELEASE(m_pWindowless);
	SAFE_RELEASE(m_pAudio);
	if (m_pGraph != NULL)
	{
		n = m_pGraph->Release();
	
		m_pGraph = NULL;
	}
	//	SAFE_RELEASE(m_pGraph);

	m_ROTRegister = 0;
	m_state = STATE_CLOSED;
	m_seekCaps = 0;
}
// CJbuCapturer

STDMETHODIMP CJbuCapturer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] =
	{
		&IID_IJbuCapturer
	};

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i], riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CJbuCapturer::SetWindow(LONG hParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::Pause()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::Stop()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::SetWindowPosition(LONG top, LONG left, LONG Width, LONG Height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RECT rc;
	CRect srcRect;
	// TODO: Add your implementation code here
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


STDMETHODIMP CJbuCapturer::Free()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	TearDownGraph();

	return S_OK;
}


STDMETHODIMP CJbuCapturer::Init()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return InitializeGraph();
}

STDMETHODIMP CJbuCapturer::SetGraphPath(BSTR bstrGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_szGraphPath = CString(bstrGraphPath);

	return S_OK;
}


STDMETHODIMP CJbuCapturer::SetSinkFile(BSTR bstrPathName, BSTR bstrPathName1, LONG nTemplateID, LONG nFileNo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_szPathName = CString(bstrPathName);
	m_szPathName1 = CString(bstrPathName1);
	m_nTemplateID = nTemplateID;
	m_nFileNo = nFileNo;

	return S_OK;
}


STDMETHODIMP CJbuCapturer::GetVideoSize(LONG* lpWidth, LONG* lpHeight, LONG* lpARwidth, LONG* lpARHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	hr = m_pWindowless->GetNativeVideoSize(lpWidth, lpHeight, lpARwidth, lpARHeight);
	return hr;
}


STDMETHODIMP CJbuCapturer::UpdateWindow(LONG left, LONG top, LONG right, LONG bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CRect rect = CRect(left, top, right, bottom);
	UpdateVideoWindow(&rect);

	return S_OK;
}


STDMETHODIMP CJbuCapturer::State(LONG* nState)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*nState = m_state;

	return S_OK;
}


STDMETHODIMP CJbuCapturer::ChangeWindow(LONG hWndHandle)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::Play()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::SnapImage(BSTR ImageName, LONG Width, LONG Height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return S_OK;
}


STDMETHODIMP CJbuCapturer::ChangeHWnd(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

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


STDMETHODIMP CJbuCapturer::UpdateVideoWindow(const LPRECT prc)
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

STDMETHODIMP CJbuCapturer::Render()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	int nValue = 1;
	KF_CreateObject1(&nValue);
	if (nValue == 0)
		return S_FALSE;

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	//hr = InitializeGraph();

	switch (m_nTemplateID) {
	case 0: //CMPEG.grf
		hr = DShowFace();
		break;
	}
	if (hr == E_FAIL)
	{
		return S_FALSE;
	}
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
#ifdef _DEBUG
	hr = SaveGraphFile(m_pGraph, _T("c:\\tmp.grf"));
#endif	
	return hr;
}

HRESULT CJbuCapturer::DShowFace()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//if the format is blue-ray, do another function
	IBaseFilter *pSource = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pDeMpeg = NULL;
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
		hr = BindAMRegFilter(m_szPathName, &pSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoRendererDefault, &pVMR, L"Video Renderer");
		//hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRenderer, L"VMR-9");
	}
	//add mjpg decompressor
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_MjpegDec, &pDeMpeg, L"MJpeg 2 RGB");
	}

	//add sampleGrabber
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_SampleGrabber, &pSampleFilter, L"face sample");
	}
	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVMR, m_hwndVideo, &m_pWindowless);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pDeMpeg);
	}
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDeMpeg, pSampleFilter);
	}
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSampleFilter, pVMR);
	}
	// Get the seeking capabilities.
	if (SUCCEEDED(hr))
	{
		hr = m_pSeek->GetCapabilities(&m_seekCaps);
	}

	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			AM_MEDIA_TYPE mt;
			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB32;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			hr = pSampleGrabber->SetBufferSamples(TRUE);
			pSampleGrabber->GetConnectedMediaType(&m_pSGCallback->g_StillMediaType);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nBitPerPixel = 32;
			m_pSGCallback->RestImageCounter();
			m_pSGCallback->SetOption(0);
			m_pSGCallback->SetMode(JBU_FACE_DETECTION_MODE);
			m_pSGCallback->SetExportDir(_T("d:\\a2\\"));
			hr = GetVideoSize(&m_pSGCallback->m_nWidth, &m_pSGCallback->m_nHeight, &m_pSGCallback->m_nArWidth, &m_pSGCallback->m_nArHeight);
			pSampleGrabber->SetCallback(m_pSGCallback, 1);
		}
	}

	//// Set the volume.
	//if (SUCCEEDED(hr))
	//{
	//	hr = UpdateVolume();
	//}

	// Update our state.
	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	// add video sample
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pDeMpeg);
	//SAFE_DELETE(pInfo);


	return hr;

}