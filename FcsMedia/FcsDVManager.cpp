// FcsDVManager.cpp : Implementation of CFcsDVManager

#include "stdafx.h"
#include "FcsDVManager.h"


// CFcsDVManager

HRESULT CFcsDVManager::InitializeGraph()
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
	m_pAudioSample = new CAudioSample();

	return hr;
}

void CFcsDVManager::TearDownGraph()
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
	SAFE_RELEASE(m_pVideoCapture);
	SAFE_RELEASE(m_pAudioCapture);
	SAFE_RELEASE(m_pVideoRenderer);
	SAFE_RELEASE(m_pSmartT);
	SAFE_RELEASE(m_pAudioSample);
	SAFE_RELEASE(m_pInputFileFilter);
	SAFE_RELEASE(m_pDeviceFilter);
	SAFE_RELEASE(m_pIAMTCReader);
	SAFE_RELEASE(m_pIAMExtTransport);
	SAFE_RELEASE(m_pIAMExtDevice);
	SAFE_RELEASE(m_pGraph);
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

STDMETHODIMP CFcsDVManager::SetWindow(long hParent)
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

STDMETHODIMP CFcsDVManager::Pause(void)
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

STDMETHODIMP CFcsDVManager::Stop(void)
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

STDMETHODIMP CFcsDVManager::GetPosition(long* iPos)
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

STDMETHODIMP CFcsDVManager::Seek(long iPos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	LONGLONG timeNow = (LONGLONG)((double)iPos * (double)ONE_SECOND / m_dFps);
	hr = SetPosition((LONGLONG)timeNow);
	return hr;
}

STDMETHODIMP CFcsDVManager::Run(void)
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

STDMETHODIMP CFcsDVManager::SetWindowPosition(long top, long left, long Width, long Height)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
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

STDMETHODIMP CFcsDVManager::Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	TearDownGraph();
	return S_OK;
}

STDMETHODIMP CFcsDVManager::Init(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = BuildBasicGraph();
	return hr;
}

STDMETHODIMP CFcsDVManager::SetFile(BSTR szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	m_szPathName = CString(szPathName);
	return hr;
}

STDMETHODIMP CFcsDVManager::Render(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = InitializeGraph();
#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	switch (m_nTemplateID) {
	case 1121313: //c1394dvavi.grf
		hr = Capture1();
		break;
		//1394
	case 1321117: //chdmjpegaviwmv9.grf
		hr = Capture30();
		break;
	case 1321517: //c1394dvaviwmv9.grf
		hr = Capture31();
		break;
	case 1321119: //c1394dv50avi.grf
		hr = Capture32();
		break;
	case 1321519: //c1394dv50aviwmv9.grf
		hr = Capture33();
		break;
	case 1341115: //c1394dv100avi.grf
		hr = Capture34();
		break;
	case 1341515: //c1394dv100aviwmv9.grf
		hr = Capture35();
		break;
	case 1231111: //c1394hdvm2t.grf
		hr = Capture36();
		break;
	case 1231511: //c1394hdvm2twmv9.grf
		hr = Capture37();
		break;
	case 27411: //27411.grf DV Capture to Mpeg
		hr = DVCaptureMpeg2();
		break;
	case 27412: //27412.grf DV Play
		hr = DVCapturePlay();
		break;
	}

	// find sample grabber filter
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVideoSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	ISampleGrabber* pVideoSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	FILTER_INFO* pInfo = NULL;
	WAVEFORMATEX m_wformatEx;
	CString str;
	IEnumFilters* pEnumFilter = NULL;
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	//if (SUCCEEDED(hr))
	//{
	//}

	if (m_nFileNo == 1)
	{
		if (SUCCEEDED(hr))
		{
			while (pEnumFilter->Next(1, &pSampleFilter, 0) == S_OK)
			{
				hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
				if (SUCCEEDED(hr))
					break;
				SAFE_RELEASE(pSampleFilter);
			}
		}
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			m_wformatEx.wFormatTag = WAVE_FORMAT_PCM;
			m_wformatEx.nChannels = 2;
			m_wformatEx.nSamplesPerSec = 48000;
			m_wformatEx.wBitsPerSample = 16;
			m_wformatEx.nBlockAlign = m_wformatEx.nChannels * m_wformatEx.wBitsPerSample / 8;
			m_wformatEx.nAvgBytesPerSec = m_wformatEx.nSamplesPerSec * m_wformatEx.nBlockAlign;

			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Audio;
			mt.subtype = MEDIASUBTYPE_PCM;
			mt.formattype = FORMAT_WaveFormatEx;
			mt.pbFormat = (BYTE *)&m_wformatEx;
			hr = pSampleGrabber->SetMediaType(&mt);
			//pSampleGrabber->SetBufferSamples(TRUE);
			pSampleGrabber->SetOneShot(FALSE);
			m_pAudioSample->wfex = m_wformatEx;
			//m_pAudioSample->m_szPathName = m_szPathName;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);

		}
	}

	if (m_nFileNo == 2)
	{
		if (SUCCEEDED(hr))
		{
			while (pEnumFilter->Next(1, &pSampleFilter, 0) == S_OK)
			{
				hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
				if (SUCCEEDED(hr))
				{
					pInfo = new FILTER_INFO;
					hr = pSampleFilter->QueryFilterInfo(pInfo);
					str = CString(pInfo->achName);
					if (str == _T("SampleGrabber"))
					{
						pInfo->pGraph->Release();
						SAFE_DELETE(pInfo);
						break;
					}
					pInfo->pGraph->Release();
					SAFE_DELETE(pInfo);
					SAFE_RELEASE(pSampleFilter);
				}
			}
		}
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			m_wformatEx.wFormatTag = WAVE_FORMAT_PCM;
			m_wformatEx.nChannels = 2;
			m_wformatEx.nSamplesPerSec = 48000;
			m_wformatEx.wBitsPerSample = 16;
			m_wformatEx.nBlockAlign = m_wformatEx.nChannels * m_wformatEx.wBitsPerSample / 8;
			m_wformatEx.nAvgBytesPerSec = m_wformatEx.nSamplesPerSec * m_wformatEx.nBlockAlign;

			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Audio;
			mt.subtype = MEDIASUBTYPE_PCM;
			mt.formattype = FORMAT_WaveFormatEx;
			mt.pbFormat = (BYTE *)&m_wformatEx;
			hr = pSampleGrabber->SetMediaType(&mt);
			pSampleGrabber->SetOneShot(FALSE);
			m_pAudioSample->wfex = m_wformatEx;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);

		}

		if (SUCCEEDED(hr))
		{
			pEnumFilter->Reset();
			while (pEnumFilter->Next(1, &pVideoSampleFilter, 0) == S_OK)
			{
				hr = pVideoSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pVideoSampleGrabber);
				if (SUCCEEDED(hr))
				{
					pInfo = new FILTER_INFO;
					hr = pVideoSampleFilter->QueryFilterInfo(pInfo);
					str = CString(pInfo->achName);
					if (str == _T("SampleGrabber 0001"))
					{
						pInfo->pGraph->Release();
						SAFE_DELETE(pInfo);
						break;
					}
					pInfo->pGraph->Release();
					SAFE_DELETE(pInfo);
					SAFE_RELEASE(pVideoSampleFilter);
				}
			}
		}
		if (pVideoSampleGrabber != NULL)
		{
			hr = m_pSGCallback->InitKeyFrameProcessor(&m_pKeyFrameParams);
			m_pSGCallback->m_nBitPerPixel = 24;
			m_pSGCallback->SetOption(2);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->m_nWidth = m_pKeyFrameParams.nWidth;
			m_pSGCallback->m_nHeight = m_pKeyFrameParams.nHeight;

			ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
			mt.majortype = MEDIATYPE_Video;
			mt.subtype = MEDIASUBTYPE_RGB24;
			hr = pVideoSampleGrabber->SetMediaType(&mt);
			pVideoSampleGrabber->SetOneShot(FALSE);
			m_pSGCallback->m_pPlayer = (void*)this;
			m_pSGCallback->SetMode(FCS_Grab_Mode);
			m_pSGCallback->RestImageCounter();
			pVideoSampleGrabber->SetCallback(m_pSGCallback, 1);

		}

	}

	pEnumFilter->Reset();
	while (pEnumFilter->Next(1, &m_pDeviceFilter, 0) == S_OK)
	{
		pInfo = new FILTER_INFO;
		m_pDeviceFilter->QueryFilterInfo(pInfo);
		str = CString(pInfo->achName);
		if (str == _T("Microsoft DV Camera and VCR"))
		{
			pInfo->pGraph->Release();
			SAFE_DELETE(pInfo);
			hr = S_OK;
			break;
		}
		pInfo->pGraph->Release();
		SAFE_DELETE(pInfo);
		SAFE_RELEASE(m_pDeviceFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMExtTransport,
			(void **)&m_pIAMExtTransport);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMExtDevice, (void **)&m_pIAMExtDevice);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMTimecodeReader, (void **)&m_pIAMTCReader);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetDVMode(&m_SubunitMode);
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

	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pVideoSampleFilter);
	SAFE_RELEASE(pVideoSampleGrabber);
	return hr;
}

STDMETHODIMP CFcsDVManager::GetLength(long* nLength)
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

STDMETHODIMP CFcsDVManager::SetOption(long nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_nTemplateID = nOption;
	return S_OK;
}

STDMETHODIMP CFcsDVManager::GetAudio(long nChannelID, long* nVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsDVManager::SetPosition(LONGLONG pos)
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

STDMETHODIMP CFcsDVManager::SetGraphPath(BSTR bstrGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szGraphPath = CString(bstrGraphPath);

	return S_OK;
}

STDMETHODIMP CFcsDVManager::SetSinkFile(BSTR bstrPathName, BSTR bstrPathName1, long nTemplateID, long nFileNo)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szPathName = CString(bstrPathName);
	m_szPathName1 = CString(bstrPathName1);
	m_nTemplateID = nTemplateID;
	m_nFileNo = nFileNo;
	return S_OK;
}


STDMETHODIMP CFcsDVManager::SetHWnd(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_hwndVideo = hWnd;
	return S_OK;
}

STDMETHODIMP CFcsDVManager::UpdateVideoWindow(const LPRECT prc)
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

STDMETHODIMP CFcsDVManager::GetVideoSize(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	hr = m_pWindowless->GetNativeVideoSize(lpWidth, lpHeight, lpARWidth, lpARHeight);
	return hr;
}

STDMETHODIMP CFcsDVManager::Repaint(HDC hdc)
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
STDMETHODIMP CFcsDVManager::Record(void)
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

HRESULT CFcsDVManager::Record2Files(void)
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
			if (str == _T("c:\\9fcs\\9fcs1.wmv"))
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
			if (str == _T("c:\\9fcs\\9fcs.m2p"))
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

STDMETHODIMP CFcsDVManager::UpdateWindow(long left, long top, long right, long bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CRect rect = CRect(left, top, right, bottom);
	UpdateVideoWindow(&rect);
	return S_OK;
}

STDMETHODIMP CFcsDVManager::State(long* state)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*state = m_state;
	return S_OK;
}

STDMETHODIMP CFcsDVManager::GetAudioLevel(long nChannel, long* nVolume)
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


STDMETHODIMP CFcsDVManager::SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath)
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


STDMETHODIMP CFcsDVManager::SaveKFInfo(void)
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


HRESULT CFcsDVManager::UpdateVolume()
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
STDMETHODIMP CFcsDVManager::RemoteControl(long nFunctionID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pIAMExtTransport == NULL)
		return S_FALSE;
	HRESULT hr = S_OK;
	if (nFunctionID == ED_MEDIA_UNLOAD)
		hr = m_pIAMExtTransport->put_MediaState(nFunctionID);
	else
		hr = m_pIAMExtTransport->put_Mode(nFunctionID);
	return hr;
}

/*-----------------------------------------------------------------------------
|   Function:   CFcsDVManager::AddDeviceFilter
|   Purpose:    Load (not add) a filter of the name "Microsoft DV Camera and VCR"
|               which connects to the specified filter
|   Arguments:  None
|   Returns:    HRESULT
|   Notes:      This method adds the device filter to the filtergraph
\----------------------------------------------------------------------------*/
HRESULT CFcsDVManager::AddDeviceFilter()
{
	HRESULT hr = S_OK;
	ICreateDevEnum * pCreateDevEnum = NULL;
	IEnumMoniker *   pEnumMoniker = NULL;
	IMoniker *       pMoniker = NULL;
	ULONG            nFetched = 0;
	FILTER_INFO* pInfo = new FILTER_INFO;

	// Create Device Enumerator
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER,
		IID_ICreateDevEnum, reinterpret_cast<PVOID *>(&pCreateDevEnum));

	// Create the enumerator of the monikers for the specified Device Class & reset them 
	if (SUCCEEDED(hr))
	{
		hr = pCreateDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnumMoniker, 0);
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumMoniker->Reset();
	}

	// Loop through to the last moniker
	while (SUCCEEDED(pEnumMoniker->Next(1, &pMoniker, &nFetched)) && pMoniker)
	{

		// get the device friendly name:
		IPropertyBag *pPropBag;
		if (SUCCEEDED(hr))
		{
			hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag, (void **)&pPropBag);
		}
		//Friendly name
		VARIANT varFriendlyName;
		varFriendlyName.vt = VT_BSTR;
		if (SUCCEEDED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &varFriendlyName, 0);
		}

		//#ifdef UNICODE      
		//        (void)StringCchCopy( m_DeviceName, NUMELMS(m_DeviceName), varFriendlyName.bstrVal );
		//#else
		//        WideCharToMultiByte( CP_ACP, 0, varFriendlyName.bstrVal, -1, m_DeviceName, sizeof(m_DeviceName), 0, 0 );
		//#endif      

		// detect DV device by search media type of its output pins for DV type
		IBaseFilter *pDeviceFilter;

		hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pDeviceFilter);
		if (pDeviceFilter == NULL)
			return E_FAIL;

		if (IsDeviceOutputDV(pDeviceFilter))
		{
			//hr = pDeviceFilter->QueryFilterInfo(pInfo);
			CString str = CString(varFriendlyName);
			if (str == _T("Microsoft DV Camera and VCR"))
			{
				hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&m_pDeviceFilter);

				hr = m_pGraph->AddFilter(m_pDeviceFilter, L"Filter");
			}
			SAFE_RELEASE(pMoniker);
			SAFE_RELEASE(pDeviceFilter);
			break;
		}
		else
			hr = E_FAIL;

		VariantClear(&varFriendlyName);

		SAFE_RELEASE(pMoniker);
		SAFE_RELEASE(pDeviceFilter);
	}//end of while

	SAFE_RELEASE(pEnumMoniker);
	SAFE_RELEASE(pCreateDevEnum);

	return hr;
}



HRESULT CFcsDVManager::BuildBasicGraph()
{
	HRESULT hr = S_OK;

	hr = InitializeGraph();

	if (SUCCEEDED(hr))
	{
		hr = AddDeviceFilter();
	}

	ASSERT(m_pDeviceFilter);

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMExtTransport,
			(void **)&m_pIAMExtTransport);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMExtDevice, (void **)&m_pIAMExtDevice);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->QueryInterface(IID_IAMTimecodeReader, (void **)&m_pIAMTCReader);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetDVMode(&m_SubunitMode);
	}

	return hr;
}


BOOL CFcsDVManager::IsDeviceOutputDV(IBaseFilter * pFilter)
{
	if (!pFilter) return FALSE;

	IEnumPins *pEnum = 0;
	IPin *pPin = 0;
	ULONG            ul;
	BOOL bFound = FALSE;

	HRESULT hr = pFilter->EnumPins(&pEnum);
	if (FAILED(hr)) return FALSE;

	while (S_OK == pEnum->Next(1, &pPin, 0))
	{
		// See if this pin matches the specified direction.
		PIN_DIRECTION ThisPinDir;
		hr = pPin->QueryDirection(&ThisPinDir);
		if (FAILED(hr)) {
			SAFE_RELEASE(pPin);
			break;
		}

		if (ThisPinDir == PINDIR_OUTPUT)
		{
			IEnumMediaTypes* pTypeEnum;
			hr = pPin->EnumMediaTypes(&pTypeEnum);

			AM_MEDIA_TYPE* pMediaType;
			// Loop thru' media type list for a match
			do {
				hr = pTypeEnum->Next(1, &pMediaType, &ul);
				if (FAILED(hr) || 0 == ul) {
					SAFE_RELEASE(pPin);
					break;
				}

				if (pMediaType->subtype == MEDIASUBTYPE_dvsd ||
					pMediaType->subtype == MEDIASUBTYPE_DVSD ||
					pMediaType->subtype == MEDIASUBTYPE_UYVY) {
					bFound = TRUE;
					SAFE_RELEASE(pPin);
					DeleteMediaType(pMediaType);

					pTypeEnum->Release();
					SAFE_RELEASE(pEnum);

					return TRUE;
				}

				DeleteMediaType(pMediaType);

			} while (!bFound);  // until the reqd one is found

			pTypeEnum->Release();
		}
	}

	SAFE_RELEASE(pPin);
	SAFE_RELEASE(pEnum);

	// Did not find a matching filter.
	return FALSE;
}

/*-------------------------------------------------------------------------
Routine:        CDVGraph::DV_GetDVMode
Purpose:        Determines camera mode using IAMExtDevice::GetCapability()
Arguments:      None
Returns:        Subunit mode of camera device
Notes:
------------------------------------------------------------------------*/
HRESULT CFcsDVManager::GetDVMode(long* nDvMode)
{
	HRESULT hr = S_OK;
	LONG    lDeviceType = 0;

	ASSERT(m_pDeviceFilter);
	if (!m_pIAMExtDevice)
		return E_NOINTERFACE;

	//  Query the Device Type Capability
	hr = m_pIAMExtDevice->GetCapability(ED_DEVCAP_DEVICE_TYPE, &lDeviceType, 0);

	switch (lDeviceType)
	{
	case 0:
		//device type is unknown
		*nDvMode = UnknownMode;
		break;

	case ED_DEVTYPE_VCR:
		*nDvMode = VcrMode;
		break;

	case ED_DEVTYPE_CAMERA:
		*nDvMode = CameraMode;
		break;

	default:
		*nDvMode = UnknownMode;
		break;
	}

	return hr;
}

HRESULT CFcsDVManager::Capture1(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dvavi.grf"));
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

	// find old source filter
	IBaseFilter* pOldSource = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;

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
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}

	IPin* pOutPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	IBaseFilter* pAviSplitter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find Dv demultiplexer filter
	IBaseFilter* pDvDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDvDemultiplexer);
	}


	if (SUCCEEDED(hr))
	{
		hr = pDvDemultiplexer->FindPin(_T("DV Video"), &pVideoPin);
		hr = pDvDemultiplexer->FindPin(_T("PCM Audio"), &pAudioPin);
	}

	//find video smart tee.
	IBaseFilter* pVideoSmartTee = NULL;
	IPin* pVideoSmartInPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoSmartTee);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoSmartTee, PINDIR_INPUT, &pVideoSmartInPin);
	}

	//Find Avi Mux Filter
	IBaseFilter* pMuxFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pVideoSmartTee->FindPin(_T("Capture"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMuxFilter);
	}

	//Find Writer filter
	IBaseFilter* pWriter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMuxFilter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	//find audio smart tee.
	IBaseFilter* pAudioSmartTee = NULL;
	IPin* pAudioSmartInPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioSmartTee);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioSmartTee, PINDIR_INPUT, &pAudioSmartInPin);
	}

	////Find sample grabber filter
	IBaseFilter* pSampleFilter;
	if (SUCCEEDED(hr))
	{
		hr = pAudioSmartTee->FindPin(_T("Preview"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//add Dv Capture sourcefilter.
	IBaseFilter* pDvCapture = NULL;
	IPin* pDvCapturePin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddDvCaptureSourceFilter(m_pGraph, _T("Microsoft DV Camera and VCR"), &m_pDeviceFilter);
	}

	IEnumPins* pDvPinEnum = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->EnumPins(&pDvPinEnum);
	}

	PIN_INFO pinInfo;
	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		while (S_OK == pDvPinEnum->Next(1, &pDvCapturePin, NULL))
		{
			LPWSTR pinID;
			HRESULT hr2 = pDvCapturePin->QueryId(&pinID);
			if (SUCCEEDED(hr2))
			{
				pDvCapturePin->QueryPinInfo(&pinInfo);
				if (CString(pinInfo.achName) == _T("DV A/V Out"))
					break;
			}
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDvCapturePin, pDvDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = pDvDemultiplexer->FindPin(_T("DV Video"), &pVideoPin);
		hr = pDvDemultiplexer->FindPin(_T("PCM Audio"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pVideoPin, pVideoSmartInPin, NULL);
	}


	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pAudioPin, pAudioSmartInPin, NULL);
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pDvDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pVideoSmartTee);
	SAFE_RELEASE(pVideoSmartInPin);
	SAFE_RELEASE(pAudioSmartTee);
	SAFE_RELEASE(pAudioSmartInPin);
	SAFE_RELEASE(pDvCapture);
	SAFE_RELEASE(pDvCapturePin);
	SAFE_DELETE(pInfo);
	return hr;
}

STDMETHODIMP CFcsDVManager::ChangeWindow(long hWndHandle)
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

STDMETHODIMP CFcsDVManager::ChangeHWnd(HWND hWnd)
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

STDMETHODIMP CFcsDVManager::PowerOn(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = m_pIAMExtDevice->put_DevicePower(ED_POWER_ON);
	return hr;
}

STDMETHODIMP CFcsDVManager::PowerOff(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = m_pIAMExtDevice->put_DevicePower(ED_POWER_OFF);
	return hr;
}

STDMETHODIMP CFcsDVManager::StandBy(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	hr = m_pIAMExtDevice->put_DevicePower(ED_POWER_STANDBY);
	return hr;
}

HRESULT CFcsDVManager::Capture30(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dvavi.grf"));
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


HRESULT CFcsDVManager::Capture31(void)
{
	HRESULT hr = S_OK;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IPin* pInputPin = NULL;
	IBaseFilter* pOldSource = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dvaviwmv9.grf"));
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

	// find old source filter

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
				hr = S_OK;
				SAFE_RELEASE(pFlags);
				SAFE_RELEASE(pFileSrc);
				break;
			}
		}
	}

	IPin* pOutPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	//Find AVI splitter filter
	IBaseFilter* pAviSplitter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pAviSplitter->FindPin(_T("Stream 00"), &pOutPin);
	}

	//Find Dv demultiplexer filter
	IBaseFilter* pDvDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDvDemultiplexer);
	}


	if (SUCCEEDED(hr))
	{
		hr = pDvDemultiplexer->FindPin(_T("DV Video"), &pVideoPin);
		hr = pDvDemultiplexer->FindPin(_T("PCM Audio"), &pAudioPin);
	}

	//find video smart tee.
	IBaseFilter* pVideoSmartTee = NULL;
	IPin* pVideoSmartInPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoSmartTee);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoSmartTee, PINDIR_INPUT, &pVideoSmartInPin);
	}

	//Find Avi Mux Filter
	IBaseFilter* pMuxFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pVideoSmartTee->FindPin(_T("Capture"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pMuxFilter);
	}

	//Find Writer filter
	IBaseFilter* pWriter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pMuxFilter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pWriter);
	}

	//find audio smart tee.
	IBaseFilter* pAudioSmartTee = NULL;
	IPin* pAudioSmartInPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pAudioSmartTee);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioSmartTee, PINDIR_INPUT, &pAudioSmartInPin);
	}

	////Find sample grabber filter
	IBaseFilter* pSampleFilter;
	if (SUCCEEDED(hr))
	{
		hr = pAudioSmartTee->FindPin(_T("Preview"), &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pAviSplitter);
	}

	//add Dv Capture sourcefilter.
	IBaseFilter* pDvCapture = NULL;
	IPin* pDvCapturePin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddDvCaptureSourceFilter(m_pGraph, _T("Microsoft DV Camera and VCR"), &m_pDeviceFilter);
	}

	IEnumPins* pDvPinEnum = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pDeviceFilter->EnumPins(&pDvPinEnum);
	}

	PIN_INFO pinInfo;
	if (SUCCEEDED(hr))
	{
		// Loop through all the pins
		while (S_OK == pDvPinEnum->Next(1, &pDvCapturePin, NULL))
		{
			LPWSTR pinID;
			HRESULT hr2 = pDvCapturePin->QueryId(&pinID);
			if (SUCCEEDED(hr2))
			{
				pDvCapturePin->QueryPinInfo(&pinInfo);
				if (CString(pinInfo.achName) == _T("DV A/V Out"))
					break;
			}
		}
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = m_pDeviceFilter->FindPin(_T("DV A/V Out"), &pDvCapturePin);
	//}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDvCapturePin, pDvDemultiplexer);
	}

	if (SUCCEEDED(hr))
	{
		hr = pDvDemultiplexer->FindPin(_T("DV Video"), &pVideoPin);
		hr = pDvDemultiplexer->FindPin(_T("PCM Audio"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pVideoPin, pVideoSmartInPin, NULL);
	}


	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->ConnectDirect(pAudioPin, pAudioSmartInPin, NULL);
	}

	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pDvDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pVideoSmartTee);
	SAFE_RELEASE(pVideoSmartInPin);
	SAFE_RELEASE(pAudioSmartTee);
	SAFE_RELEASE(pAudioSmartInPin);
	SAFE_RELEASE(pDvCapture);
	SAFE_RELEASE(pDvCapturePin);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsDVManager::Capture32(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dv50avi.grf"));
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


HRESULT CFcsDVManager::Capture33(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dv50aviwmv9.grf"));
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


HRESULT CFcsDVManager::Capture34(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dv100avi.grf"));
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


HRESULT CFcsDVManager::Capture35(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394dv100aviwmv9.grf"));
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


HRESULT CFcsDVManager::Capture36(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394hdvm2t.grf"));
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


HRESULT CFcsDVManager::Capture37(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394hdvm2twmv9.grf"));
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

STDMETHODIMP CFcsDVManager::SetDvRate(long nRate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pIAMExtTransport == NULL)
		return S_FALSE;
	hr = m_pIAMExtTransport->put_Mode(nRate);
	return hr;
}

STDMETHODIMP CFcsDVManager::GetDvRate(double* dRate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pIAMExtTransport == NULL)
		return S_FALSE;
	double n = 0.0;
	hr = m_pIAMExtTransport->get_Rate(&n);
	*dRate = n;
	return hr;
}

HRESULT CFcsDVManager::DVCaptureMpeg2(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("c1394hdvm2twmv9.grf"));
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

HRESULT CFcsDVManager::DVCapturePlay(void)
{
	HRESULT hr = S_OK;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = NULL;
	//IVMRFilterConfig* pConfig = NULL; 
	IPin* pInputPin = NULL;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("27412.grf"));
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
				pInfo->pGraph->Release();
				SAFE_DELETE(pInfo);
				break;
			}
			pInfo->pGraph->Release();
			SAFE_DELETE(pInfo);
			SAFE_RELEASE(pOldRender);

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
	return hr;
}

STDMETHODIMP CFcsDVManager::GetGraphPath(BSTR* strGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*strGraphPath = m_szGraphPath.AllocSysString();
	return S_OK;
}


STDMETHODIMP CFcsDVManager::IsMute(SHORT* bMute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*bMute = m_bMute;
	return S_OK;
}


STDMETHODIMP CFcsDVManager::GetVideoFps(DOUBLE* dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*dFps = m_dFps;
	return S_OK;
}


STDMETHODIMP CFcsDVManager::SnapImage(BSTR bstrImagename, LONG nNewWidth, LONG nNewHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return S_OK;
}


STDMETHODIMP CFcsDVManager::MP_GetPosition(LONG* nIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr;
	LONGLONG timeNow;
	hr = GetCurrentPosition((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*nIndex = n;
	return hr;
}


STDMETHODIMP CFcsDVManager::GetCurrentPosition(LONGLONG* pTimeNow)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	return m_pSeek->GetCurrentPosition(pTimeNow);
}


STDMETHODIMP CFcsDVManager::GetFaceRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	return m_pBlinkCounter->GetFaceRect(left, top, right, bottom);
}


STDMETHODIMP CFcsDVManager::GetFaceWidth(LONG* nWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nWidth = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetFaceWidth(nWidth);
}


STDMETHODIMP CFcsDVManager::GetFaceHeight(LONG* nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nHeight = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetFaceWidth(nHeight);
}


STDMETHODIMP CFcsDVManager::GetLEyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	return m_pBlinkCounter->GetLEyeRect(left, top, right, bottom);
}


STDMETHODIMP CFcsDVManager::GetREyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	return m_pBlinkCounter->GetREyeRect(left, top, right, bottom);
}


STDMETHODIMP CFcsDVManager::GetLEyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	return m_pBlinkCounter->GetLEyeballRect(left, top, right, bottom);
}


STDMETHODIMP CFcsDVManager::GetREyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	return m_pBlinkCounter->GetREyeballRect(left, top, right, bottom);
}


STDMETHODIMP CFcsDVManager::GetFaceImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetFaceImg(pImage, nSize);
}


STDMETHODIMP CFcsDVManager::GetLEyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLEyeImg(pImage, nSize);
}


STDMETHODIMP CFcsDVManager::GetREyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetREyeImg(pImage, nSize);
}


STDMETHODIMP CFcsDVManager::GetLEyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLEyeballImg(pImage, nSize);
}


STDMETHODIMP CFcsDVManager::GetREyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetREyeballImg(pImage, nSize);
}


STDMETHODIMP CFcsDVManager::GetLeadFace(BYTE* pLeadFace)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL || pLeadFace == NULL)
	{
		pLeadFace = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetLeadFace(pLeadFace);
}


STDMETHODIMP CFcsDVManager::GetActivativedValue(DOUBLE* dActivation)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*dActivation = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetActivativedValue(dActivation);
}


STDMETHODIMP CFcsDVManager::GetBlinkCount(LONG* nCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nCount = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetBlinkCount(nCount);
}


STDMETHODIMP CFcsDVManager::GetCurTimeMs(LONG* MilliSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*MilliSec = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTimeMs(MilliSec);
}


STDMETHODIMP CFcsDVManager::GetCurTime(LONGLONG* NSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*NSec = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTime(NSec);
}


STDMETHODIMP CFcsDVManager::ResetCounter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->ResetCounter();
}


STDMETHODIMP CFcsDVManager::SetCheck(SHORT nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetCheck(nCheck);
}


STDMETHODIMP CFcsDVManager::GetCheck(SHORT* nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		*nCheck = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCheck(nCheck);
}


STDMETHODIMP CFcsDVManager::SetFaceRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return S_OK;
}


STDMETHODIMP CFcsDVManager::GetFaceRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return S_OK;
}


STDMETHODIMP CFcsDVManager::SetEyeRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return S_OK;
}


STDMETHODIMP CFcsDVManager::GetEyeRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	return S_OK;
}
