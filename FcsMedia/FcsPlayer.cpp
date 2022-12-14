// FcsPlayer.cpp : Implementation of CFcsPlayer

#include "stdafx.h"
#include "FcsPlayer.h"
#include "RmfFile.h"
#include "FcsOverlay.h"
#include "FcsOverlay_i.c"
#include "FcsBlinkcounter_i.c"
#include "MediaInfoDLL.h"
// CFcsPlayer


STDMETHODIMP CFcsPlayer::SetWindow(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_hwndVideo = hWnd;
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetEventWindow(HWND hwnd, UINT msg)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_hwndEvent = hwnd;
	m_EventMsg = msg;

	return S_OK;
}

STDMETHODIMP CFcsPlayer::State(UINT* state)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*state = m_state;
	return S_OK;
}
STDMETHODIMP CFcsPlayer::OpenBlueRay(const WCHAR* sFileName)
{
	HRESULT hr = S_OK;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter* pVideoRenderer = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	IPin* pOutPin = NULL;
	IBaseFilter* pDemultiplexer = NULL;
	IPin* pVideoPin = NULL;
	IBaseFilter* pVideoDecoder = NULL;
	IPin* pAudioPin = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pAudioRender = NULL;

	BOOL bIsSource = FALSE;

	hr = InitializeGraph();

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("XDCAM.grf"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
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

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pDemultiplexer);
	}

	SAFE_RELEASE(pOutPin);
	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("MPEG Video ID1"), &pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	SAFE_RELEASE(pVideoPin);

	if (SUCCEEDED(hr))
	{
		hr = pDemultiplexer->FindPin(_T("AES3/PCM Audio ID2"), &pAudioPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pSampleFilter);
	}

	SAFE_RELEASE(pAudioPin);

	// find audio render
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAudioRender);
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

	//change video render

	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pOldRender, 0) == S_OK)
		{
			pOldRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			if (str == _T("Video Renderer"))
				break;
			pInfo = new FILTER_INFO;
			SAFE_RELEASE(pOldRender);
		}

		// find connected pin
		if (SUCCEEDED(hr))
		{
			hr = FindConnectedPin(pOldRender, PINDIR_INPUT, &pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = DisconnectPin(m_pGraph, pOutPin);
		}

		if (SUCCEEDED(hr))
		{
			hr = RemoveFilter(m_pGraph, pOldRender);
		}

		SAFE_RELEASE(pOutPin);

		if (SUCCEEDED(hr))
		{
			hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRenderer, L"VMR-9");
		}
		//Set windowless mode on the VMR. This must be done before the VMR is connected.
		if (SUCCEEDED(hr))
		{
			hr = InitWindowlessVMR(pVideoRenderer, m_hwndVideo, &m_pWindowless);
		}

	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, sFileName, CLSID_AsyncReader, &pSource);
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
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRenderer);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pDemultiplexer, pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
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

	pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	if (pSampleGrabber != NULL)
	{
		ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
		//m_wformatEx.cbSize = sizeof(WAVEFORMATEX);
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
		m_pAudioSample->m_szPathName = m_szpathName;
		pSampleGrabber->SetCallback(m_pAudioSample, 0);
	}

	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pDemultiplexer);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}

STDMETHODIMP CFcsPlayer::OpenFile(const WCHAR* sFileName)
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
	CString s = CString(sFileName);
	int n = s.ReverseFind('.');
	CString s1 = s.Right(3);
	s1.MakeLower();
	if (s1 == _T("mxf"))
	{
		HRESULT hr1 = OpenBlueRay(sFileName);
		return hr1;
	}
	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(sFileName, NULL, &pSource);
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

HRESULT CFcsPlayer::BlinkPlay(const WCHAR* sFileName)
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
	CString s = CString(sFileName);
	int n = s.ReverseFind('.');
	CString s1 = s.Right(3);
	s1.MakeLower();
	if (s1 == _T("mxf"))
	{
		HRESULT hr1 = OpenBlueRay(sFileName);
		return hr1;
	}
	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(sFileName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	//Find audio render 

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pAudioRender, 0) == S_OK)
		{
			if (pInfo == NULL)
				pInfo = new FILTER_INFO;
			pAudioRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			if (str == _T("Audio Renderer"))
			{
				hr = S_OK;
				break;
			}
			else
			{
				SAFE_RELEASE(pAudioRender);
				hr = S_FALSE;
				pInfo = new FILTER_INFO;
			}
		}
	}

	// find connected pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = FindConnectedPin(pAudioRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		//// create sample grabber and add to graph
		CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (LPVOID*)&pSampleFilter);

		hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
		AM_MEDIA_TYPE mt;
		//m_pAudio->GetMediaType(&mt1);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			//m_wformatEx.cbSize = sizeof(WAVEFORMATEX);
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
			m_pAudioSample->m_szPathName = m_szpathName;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);
		}
		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pVMR, pSampleFilter);
		}

		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
		}
	}

	// add blinkCounter filter
	SAFE_RELEASE(pVMR);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(m_pVideoFilter, PINDIR_INPUT, &pInputPin);
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

	if (m_pBlinkCounterFilter == NULL)
	{
		hr = BindAMRegFilter(_T("Fcs BlinkCounter"), &m_pBlinkCounterFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pBlinkCounterFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, m_pBlinkCounterFilter, m_pVideoFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pBlinkCounterFilter->QueryInterface(IID_IFcsBlinkCounter, (void**)&m_pBlinkCounter);
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

STDMETHODIMP CFcsPlayer::GetVideoSize(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr;
	hr = m_pWindowless->GetNativeVideoSize(lpWidth, lpHeight, lpARWidth, lpARHeight);
	return hr;
}

STDMETHODIMP CFcsPlayer::Play(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	assert(m_pGraph); // If state is correct, the graph should exist.

	if (m_state == STATE_RUNNING || m_state == STATE_CLOSED)
	{
		return S_FALSE;
	}

	HRESULT hr = m_pControl->Run();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_RUNNING;
	}

	return hr;
}

STDMETHODIMP CFcsPlayer::Pause(void)
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

STDMETHODIMP CFcsPlayer::Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_state != STATE_RUNNING && m_state != STATE_PAUSED)
	{
		return S_FALSE;
	}

	assert(m_pGraph); // If state is correct, the graph should exist.
	HRESULT hr;
	FILTER_STATE fs;
	hr = m_pControl->GetState(10, (OAFilterState*)&fs);


	hr = m_pControl->Stop();

	if (SUCCEEDED(hr))
	{
		m_state = STATE_STOPPED;
	}

	return hr;
}

STDMETHODIMP CFcsPlayer::SetRate(double dSpeed)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = m_pSeek->SetRate(dSpeed);
	return hr;
}

STDMETHODIMP CFcsPlayer::GetTMFormat(GUID* tmFormat)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	HRESULT hr = m_pSeek->GetTimeFormat(tmFormat);
	return hr;
}

STDMETHODIMP CFcsPlayer::HasVideo(BOOL* bHasVideo)
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

STDMETHODIMP CFcsPlayer::UpdateVideoWindow(const LPRECT prc)
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

STDMETHODIMP CFcsPlayer::Repaint(HDC hdc)
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

STDMETHODIMP CFcsPlayer::DisplayModeChanged(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pWindowless)
	{
		return m_pWindowless->DisplayModeChanged();
	}
	else
	{
		return S_OK;
	}
}

STDMETHODIMP CFcsPlayer::CanSeek(BOOL* bCanSeek)
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

STDMETHODIMP CFcsPlayer::SetPosition(LONGLONG pos)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_pControl == NULL || m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr = S_OK;
	hr = m_pSeek->SetPositions(&pos, AM_SEEKING_AbsolutePositioning, NULL, AM_SEEKING_NoPositioning);

	if (SUCCEEDED(hr))
	{

		if (m_state == STATE_STOPPED)
		{
			hr = m_pControl->StopWhenReady();
		}
	}

	return hr;
}

STDMETHODIMP CFcsPlayer::GetDuration(LONGLONG* pDuration)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	return m_pSeek->GetDuration(pDuration);
}

STDMETHODIMP CFcsPlayer::GetCurrentPosition(LONGLONG* pTimeNow)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pSeek == NULL)
	{
		return S_FALSE;
	}

	return m_pSeek->GetCurrentPosition(pTimeNow);
}

STDMETHODIMP CFcsPlayer::Mute(BOOL bMute)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	m_bMute = bMute;
	return UpdateVolume();
}

STDMETHODIMP CFcsPlayer::IsMuted(BOOL* bMuted)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*bMuted = m_bMute;
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetVolume(long lVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	m_lVolume = lVolume;
	return UpdateVolume();
}

STDMETHODIMP CFcsPlayer::GetVolume(long* lVolume)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	*lVolume = m_lVolume;
	return S_OK;
}

//-----------------------------------------------------------------------------
// CFcsPlayer::UpdateVolume
// Description: Update the volume after a call to Mute() or SetVolume().
//-----------------------------------------------------------------------------

HRESULT CFcsPlayer::UpdateVolume()
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
//-----------------------------------------------------------------------------
// CFcsPlayer::InitializeGraph
// Description: Create a new filter graph. (Tears down the old graph.) 
//-----------------------------------------------------------------------------

HRESULT CFcsPlayer::InitializeGraph()
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
		hr = m_pGraph->QueryInterface(IID_IBasicVideo, (void**)&m_pVideo);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->QueryInterface(IID_IVideoWindow, (void**)&m_pVideoWindow);
	}

	// Set up event notification.
	if (SUCCEEDED(hr))
	{
		hr = m_pEvent->SetNotifyWindow((OAHWND)m_hwndEvent, m_EventMsg, NULL);
	}
	m_pAudioSample = new CAudioSample();
	m_pSGCallback = new CSGCallbackHandler();
	return hr;
}

//-----------------------------------------------------------------------------
// CFcsPlayer::TearDownGraph
// Description: Tear down the filter graph and release resources. 
//-----------------------------------------------------------------------------

void CFcsPlayer::TearDownGraph()
{
	HRESULT hr = S_OK;
	ULONG n;

	if (m_pControl != NULL)
		Stop();

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
	if (m_pAudioSample != NULL)
	{
		delete m_pAudioSample;
		m_pAudioSample = NULL;
	}
	if (m_pVideoWindow != NULL)
	{
		m_pVideoWindow->put_Visible(OAFALSE);
		m_pVideoWindow->put_Owner(NULL);
	}
	SAFE_RELEASE(m_pVideoWindow);

	SAFE_RELEASE(m_pImageConverter);   //for blink counter use
	SAFE_RELEASE(m_pBlinkCounterFilter);
	SAFE_RELEASE(m_pControl);
	SAFE_RELEASE(m_pEvent);
	SAFE_RELEASE(m_pSeek);
	SAFE_RELEASE(m_pWindowless);
	SAFE_RELEASE(m_pAudio);
	SAFE_RELEASE(m_pVideo);
	SAFE_RELEASE(m_pVideoFilter);
	SAFE_RELEASE(m_pOverlayFilter);
	SAFE_RELEASE(m_pOverlay);
	SAFE_RELEASE(m_pBlinkCounter);
	SAFE_RELEASE(m_pFaceDetectorFilter);
	//	SAFE_RELEASE(m_pFrameEaterFilter);
#ifdef _DEBUG
	RemoveGraphFromRot(m_ROTRegister);
#endif	

	if (m_pGraph != NULL)
	{
		n = m_pGraph->Release();
		if (n != 0)
		{
			CString szMsg;
			szMsg.Format(_T("failed to release Graph=%ld\n"), (long)n);
			//AfxMessageBox(szMsg);
		}
		else
		{
			CString szMsg;
			szMsg.Format(_T("Successed to release Graph=%ld"), (long)n);
			//AfxMessageBox(szMsg);
		}
		m_pGraph = NULL;
	}

	m_state = STATE_CLOSED;
	m_seekCaps = 0;
	m_bAudioStream = FALSE;
	m_ROTRegister = 0;
	// Stop sending event messages
}

//-----------------------------------------------------------------------------
// CFcsPlayer::RenderStreams
// Description: Render the streams from a source filter. 
//-----------------------------------------------------------------------------

HRESULT	CFcsPlayer::RenderStreams(IBaseFilter *pSource)
{
	HRESULT hr = S_OK;

	BOOL bRenderedAnyPin = FALSE;

	IEnumPins *pEnum = NULL;
	//IBaseFilter *pVMR = NULL;
	IBaseFilter *pAudioRenderer = NULL;
	IFilterGraph2 *pGraph2 = NULL;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	// Add the VMR-7 to the graph.
	if (SUCCEEDED(hr))
	{
		//hr = AddFilterByCLSID(m_pGraph, CLSID_VideoRendererDefault, &pVMR, L"Video Renderer");
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoRendererDefault, &m_pVideoFilter, L"VMR-9");
	}

	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(m_pVideoFilter, m_hwndVideo, &m_pWindowless);
	}

	// Add the DSound Renderer to the graph.
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_DSoundRender, &pAudioRenderer, L"Audio Renderer");
	}

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
		hr = RemoveUnconnectedRenderer(m_pGraph, m_pVideoFilter, &bRemoved);

		// If we removed the VMR, then we also need to release our 
		// pointer to the VMR's windowless control interface.
		if (bRemoved)
		{
			SAFE_RELEASE(m_pWindowless);
		}
	}

	// Try to remove the audio renderer.
	if (SUCCEEDED(hr))
	{
		BOOL bRemoved = FALSE;
		hr = RemoveUnconnectedRenderer(m_pGraph, pAudioRenderer, &bRemoved);

		if (bRemoved)
		{
			m_bAudioStream = FALSE;
		}
		else
		{
			m_bAudioStream = TRUE;
		}
	}

	SAFE_RELEASE(pEnum);
	//SAFE_RELEASE(pVMR);
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





STDMETHODIMP CFcsPlayer::ReFresh(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_hwndVideo == NULL)
		return S_FALSE;
	HDC hdc = ::GetDC(m_hwndVideo);
	Repaint(hdc);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetVideoWindow(long hParent)
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
	hr = SetWindow(hWnd);

	return hr;
}

STDMETHODIMP CFcsPlayer::MP_GetPosition(long* nIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	LONGLONG timeNow;
	hr = GetCurrentPosition((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*nIndex = n;
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_Pause(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	hr = Pause();
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	hr = Stop();
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_Seek(long nIndex)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	LONGLONG timeNow = (LONGLONG)((double)nIndex * (double)ONE_SECOND / m_dFps);
	hr = SetPosition((LONGLONG)timeNow);
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_Run(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	hr = Play();

	return hr;
}

STDMETHODIMP CFcsPlayer::MP_Initial(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// do nothing

	return S_OK;
}

STDMETHODIMP CFcsPlayer::MP_Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	TearDownGraph();

	return S_OK;
}

STDMETHODIMP CFcsPlayer::MP_SetFile(BSTR strFile)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	CString szPathName = CString(strFile);
	TCHAR* szFile = szPathName.GetBuffer(MAX_PATH);
	hr = OpenFile(szFile);
	szPathName.ReleaseBuffer();
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_SetWindow(long hParent, long x, long y, long nWidth, long nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	hr = SetVideoWindow(hParent);
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetOption(long nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::MP_Render(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = InitializeGraph();
#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	switch (m_nTemplateID) {
	case 1121311: //sdplay.GRF
		hr = Capture1();
		break;
	case 1121312: //sdbplay.GRF
		hr = Capture2();
		break;
	case 1141311: //hdplay.GRF
		hr = Capture3();
		break;
	case 1141312: //hdbplay.GRF
		hr = Capture4();
		break;
	case 1131311: //hdvplay.GRF
		hr = Capture5();
		break;
	case 1131312: //hdvbplay.GRF
		hr = Capture6();
		break;
	}

	// find sample grabber filter
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pSampleFilter = NULL;
	IBaseFilter* pVideoSampleFilter = NULL;
	ISampleGrabber* pSampleGrabber = NULL;
	ISampleGrabber* pVideoSampleGrabber = NULL;
	AM_MEDIA_TYPE mt;
	FILTER_INFO* pInfo = new FILTER_INFO;
	WAVEFORMATEX m_wformatEx;
	CString str;
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	//if (SUCCEEDED(hr))
	//{
	//}

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pSampleFilter, 0) == S_OK)
		{
			hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
			if (SUCCEEDED(hr))
				break;
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
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleGrabber);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pVideoSampleFilter);
	SAFE_RELEASE(pVideoSampleGrabber);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);


	return hr;

}

STDMETHODIMP CFcsPlayer::MP_GetLength(long* nLength)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr;
	LONGLONG timeNow;
	hr = GetDuration((LONGLONG*)&timeNow);
	long n = (long)((double)timeNow / (double)ONE_SECOND * m_dFps);
	*nLength = n;
	return hr;
}

STDMETHODIMP CFcsPlayer::MP_SetWndPosition(long x, long y, long nWidth, long nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// do nothing

	return S_OK;
}

STDMETHODIMP CFcsPlayer::GetAudio(long nIndex, long* nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::InitOnlyRawControl(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::MP_SaveBmpToFile(BSTR strFileName, long nWidth, long nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::MP_UpdateVideoWindow(long left, long top, long right, long bottom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	CRect rect = CRect(left, top, right, bottom);
	UpdateVideoWindow(&rect);
	return S_OK;
}

STDMETHODIMP CFcsPlayer::Open(BSTR sFileName, long nFormat, long nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int nValue = 1;
	KF_CreateObject1(&nValue);
	if (nValue == 0)
		return S_FALSE;
	// TODO: Add your implementation code here
	HRESULT hr;

	m_nGrabOption = nOption;
	m_nVideoFormat = nFormat;
	m_szpathName = CString(sFileName);
	IFcsOverlay* spOverlay = NULL;
	WCHAR* szFile = m_szpathName.GetBuffer(MAX_PATH);
	switch (nFormat) {
	case FCS_MEDIA_MXF_P2:
		hr = OpenP2Mxf(szFile);
		break;
	case FCS_MEDIA_MXF_SONY:
		hr = OpenSonyMxf(szFile);
		break;
	case FCS_MEDIA_AVI:
		hr = OpenAvi(szFile);
		break;
	case FCS_MEDIA_WMV:
		hr = OpenWmv(szFile);
		break;
	case FCS_MEDIA_MPEG2:
		hr = OpenMpeg2(szFile);
		break;
	case FCS_MEDIA_MPEG4:
		hr = OpenMpeg4(szFile);
		break;
	case -1:
		hr = OpenFile(szFile); //smart 		
		break;
	case 3001:
		hr = BlinkPlay(szFile); 
		break;
	case 3002:
		hr = Play37413(szFile); 
		break;
	case 3003:
		hr = Play3003(szFile); 
		break;
	case 3004:
		hr = Play3004(szFile); 
		break;
	default:
		hr = OpenFile(szFile); //smart 		
		break;
	}
	m_szpathName.ReleaseBuffer();
	if (SUCCEEDED(hr))
	{
		m_nVideoFormat = nFormat;
		// set video size to call back handler
		if (m_pSGCallback != NULL) {
			m_pSGCallback->SetExportDir(m_szKeyFrameExportPath);
			m_pSGCallback->SetOption(m_nGrabOption);
			m_pSGCallback->m_nBitPerPixel = 24;
			m_pSGCallback->m_pPlayer = (void*)this;
			hr = GetVideoSize(&m_pSGCallback->m_nWidth, &m_pSGCallback->m_nHeight, &m_pSGCallback->m_nArWidth, &m_pSGCallback->m_nArHeight);
		}
	}
	if (nFormat == FCS_MEDIA_MXF_P2)
	{
		return hr;
	}
#ifdef _DEBUG
	hr = SaveGraphFile(m_pGraph, _T("c:\\tmp.grf"));
#endif	


	return hr;
}

STDMETHODIMP CFcsPlayer::get_Fcs_Media_State(LONG FCS_STATE_RUNNING, LONG* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::put_Fcs_Media_State(LONG FCS_STATE_RUNNING, LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}
STDMETHODIMP CFcsPlayer::OpenP2Mxf(const WCHAR* szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	// search content/clip/filename.xml
	HRESULT hr = S_OK;
	if (!p2Paser.Load(CString(szPathName)))
		return S_FALSE;

	return hr;
}

STDMETHODIMP CFcsPlayer::OpenSonyMxf(const WCHAR* szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		hr = LoadGraphFile(m_pGraph, _T("f:\\video\\p2.grf"));
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

STDMETHODIMP CFcsPlayer::OpenAvi(const WCHAR* szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = S_OK;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IEnumFilters* pEnumFilter = NULL;
	BOOL bRenderFilter = FALSE;
	BOOL bSourceFilter = FALSE;
	IFilterGraph2 *pGraph2 = NULL;
	IVMRFilterConfig* pConfig = NULL;

	hr = InitializeGraph();
	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);
	if (SUCCEEDED(hr))
	{
		hr = LoadGraphFile(m_pGraph, _T("c:\\9fcs\\1.grf"));
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

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


	//Find render filter
	if (SUCCEEDED(hr))
	{
		pEnumFilter->Reset();
		while (pEnumFilter->Next(1, &pVMR, 0) == S_OK)
		{
			hr = IsRenderer(pVMR, &bRenderFilter);
			if (bRenderFilter)
				break;
		}
	}


	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//add new source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcName = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcName, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
	}

	FILTER_INFO Info;
	hr = pVMR->QueryFilterInfo(&Info);
	// Set windowless mode on the VMR. This must be done before the VMR is connected.
	hr = pVMR->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig);
	hr = pConfig->SetRenderingMode(VMRMode_Windowless);
	hr = pVMR->QueryInterface(IID_IVMRWindowlessControl, (void**)&m_pWindowless);
	hr = m_pWindowless->SetVideoClippingWindow(m_hwndVideo);
	hr = m_pWindowless->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);

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

STDMETHODIMP CFcsPlayer::OpenWmv(const WCHAR* szPathName)
{
	HRESULT hr = S_OK;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IBaseFilter* pAudioDecoder = NULL;
	IPin* pADecoderOutPin = NULL;
	IPin* pADecoderInPin = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;

	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("HDwmv9play.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);
	//ULONG nFetched = 0;
	//BOOL bSourceFilter;	
	//AM_MEDIA_TYPE mt;
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

	IPin* pSourceOutPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find WMV Paser filter
	IBaseFilter* pWmvPaser = NULL;
	IPin* pPaserVideoOutPin = NULL;
	IPin* pPaserAudioOutPin = NULL;

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pWmvPaser);
	}

	if (SUCCEEDED(hr))
	{
		hr = pWmvPaser->FindPin(_T("video 1"), &pPaserVideoOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = pWmvPaser->FindPin(_T("audio 2"), &pPaserAudioOutPin);
	}

	//Find Wmv Decoder filter
	IBaseFilter* pVideoDecoder = NULL;
	IPin* pVDecoderOutPin = NULL;
	IPin* pVDecoderInPin = NULL;

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pPaserVideoOutPin, &pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVDecoderOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_INPUT, &pVDecoderInPin);
	}

	//Find old video render filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVDecoderOutPin, &pOldRender);
	}

	//find audio decoder filter

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pPaserAudioOutPin, &pAudioDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioDecoder, PINDIR_OUTPUT, &pADecoderOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAudioDecoder, PINDIR_INPUT, &pADecoderInPin);
	}


	IBaseFilter* pSampleFilter = NULL;
	IPin* pSampleOutPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pADecoderOutPin, &pSampleFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pSampleOutPin);
	}

	// find audio render filter
	IBaseFilter* pAudioRender = NULL;

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSampleOutPin, &pAudioRender);
	}

	////disconnect all pins
	if (SUCCEEDED(hr))
	{
		hr = DisconnectAllPins(m_pGraph);
	}
	//remove source filter
	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add source filter
	if (SUCCEEDED(hr))
	{
		hr = AddSourceFilter(m_pGraph, szPathName, CLSID_AsyncReader, &pSource);
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

	//connect filters
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pWmvPaser);
	}

	hr = pWmvPaser->FindPin(_T("video 2"), &pPaserVideoOutPin);
	if (FAILED(hr))
	{
		hr = pWmvPaser->FindPin(_T("video 1"), &pPaserVideoOutPin);
	}
	hr = pVideoDecoder->FindPin(_T("in0"), &pVDecoderInPin);
	hr = m_pGraph->ConnectDirect(pPaserVideoOutPin, pVDecoderInPin, NULL);
	hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRenderer);

	//audio connect
	hr = pWmvPaser->FindPin(_T("audio 2"), &pPaserAudioOutPin);
	if (FAILED(hr))
	{
		hr = pWmvPaser->FindPin(_T("audio 1"), &pPaserAudioOutPin);
	}
	hr = pAudioDecoder->FindPin(_T("in0"), &pADecoderInPin);
	hr = m_pGraph->ConnectDirect(pPaserAudioOutPin, pADecoderInPin, NULL);
	hr = ConnectFilters(m_pGraph, pAudioDecoder, pSampleFilter);
	hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);


	// add callback function

	ISampleGrabber* pSampleGrabber = NULL;
	if (SUCCEEDED(hr))
	{
		AM_MEDIA_TYPE mt1;
		//m_pAudio->GetMediaType(&mt1);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			//m_wformatEx.cbSize = sizeof(WAVEFORMATEX);
			m_wformatEx.wFormatTag = WAVE_FORMAT_PCM;
			m_wformatEx.nChannels = 2;
			m_wformatEx.nSamplesPerSec = 48000;
			m_wformatEx.wBitsPerSample = 16;
			m_wformatEx.nBlockAlign = m_wformatEx.nChannels * m_wformatEx.wBitsPerSample / 8;
			m_wformatEx.nAvgBytesPerSec = m_wformatEx.nSamplesPerSec * m_wformatEx.nBlockAlign;

			ZeroMemory(&mt1, sizeof(AM_MEDIA_TYPE));
			mt1.majortype = MEDIATYPE_Audio;
			mt1.subtype = MEDIASUBTYPE_PCM;
			mt1.formattype = FORMAT_WaveFormatEx;
			mt1.pbFormat = (BYTE *)&m_wformatEx;
			hr = pSampleGrabber->SetMediaType(&mt1);
			//pSampleGrabber->SetBufferSamples(TRUE);
			pSampleGrabber->SetOneShot(FALSE);
			m_pAudioSample->wfex = m_wformatEx;
			m_pAudioSample->m_szPathName = m_szpathName;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);

		}
	}

	SAFE_RELEASE(pSampleGrabber);

	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pWmvPaser);
	SAFE_RELEASE(pPaserVideoOutPin);
	SAFE_RELEASE(pPaserAudioOutPin);
	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pVDecoderOutPin);
	SAFE_RELEASE(pVDecoderInPin);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pAudioDecoder);
	SAFE_RELEASE(pADecoderOutPin);
	SAFE_RELEASE(pADecoderInPin);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pSampleOutPin);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
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

STDMETHODIMP CFcsPlayer::OpenMpeg2(const WCHAR* szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save(const WCHAR* szTargetName, int nTargetFormat, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	switch (nTargetFormat) {
	case FCS_MEDIA_AVI:
		hr = Save2Avi(szTargetName, nOption);
		break;
	case FCS_MEDIA_MPEG2:
		hr = Save2Mpeg2(szTargetName, nOption);
		break;
	case FCS_MEDIA_MPEG4:
		hr = Save2Mpeg4(szTargetName, nOption);
		break;
	case FCS_MEDIA_MXF_P2:
		hr = Save2P2Mxf(szTargetName, nOption);
		break;
	case FCS_MEDIA_MXF_SONY:
		hr = Save2SonyMxf(szTargetName, nOption);
		break;
	case FCS_MEDIA_WMV:
		hr = Save2Wmv(szTargetName, nOption);
		break;
	}
	return hr;
}

HRESULT CFcsPlayer::BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter)
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


HRESULT CFcsPlayer::CreateWmvGraph(const WCHAR* szPathName)
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
	IBaseFilter* pColorConverter = NULL;
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

	hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
	AM_MEDIA_TYPE mt;
	//m_pAudio->GetMediaType(&mt1);
	pSampleFilter->QueryInterface(IID_ISampleGrabber, (void   **)&pSampleGrabber);
	ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
	mt.majortype = MEDIATYPE_Audio;
	mt.subtype = MEDIASUBTYPE_PCM;
	mt.formattype = FORMAT_WaveFormatEx;
	mt.pbFormat = (BYTE *)&m_wformatEx;
	hr = pSampleGrabber->SetMediaType(&mt);
	//pSampleGrabber->SetBufferSamples(TRUE);
	pSampleGrabber->SetOneShot(FALSE);
	m_pAudioSample->wfex = m_wformatEx;
	pSampleGrabber->SetCallback(m_pAudioSample, 0);

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

					if (szRegFilterName == _T("Color Space Converter"))
					{
						hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
							(void**)&pColorConverter);
						hr = m_pGraph->AddFilter(pColorConverter, _T("Color Space Converter"));
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
	if (FAILED(hr))
	{
		hr = pWmvParser->FindPin(_T("video 1"), &outPin);
	}
	hr = pVideoFilter->FindPin(_T("in0"), &inPin);
	hr = m_pGraph->ConnectDirect(outPin, inPin, NULL);
	//hr = ConnectFilters(m_pGraph, pWmvParser, pVideoFilter);
	hr = ConnectFilters(m_pGraph, pVideoFilter, pVideoRender);

	hr = ConnectFilters(m_pGraph, pWmvParser, pAudioFilter);
	hr = ConnectFilters(m_pGraph, pAudioFilter, pSampleFilter);
	hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
	m_bAudioStream = TRUE;
	//
	//
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

STDMETHODIMP CFcsPlayer::OpenMpeg4(const WCHAR* szpathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2Avi(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2Mpeg2(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2Mpeg4(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2P2Mxf(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2SonyMxf(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::Save2Wmv(const WCHAR* szTargetName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetKeyFramePath(const WCHAR* szPathName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szKeyFrameExportPath = CString(szPathName);
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetKeyFrameBasicParas(long pBasicParams)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	//CBasicParams* p = reinterpret_cast<CBasicParams*>(pBasicParams);
	//m_pKeyFrameParams = *p;
	//if (m_pSGCallback != NULL)
	//{
	//	m_pSGCallback->InitKeyFrameProcessor(&m_pKeyFrameParams);
	//}
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetTMFormat(long tmFormat)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	GUID tmFormatByFrame = TIME_FORMAT_FRAME;
	GUID tmFormatByTime = TIME_FORMAT_MEDIA_TIME;
	GUID tmCurrent;
	hr = GetTMFormat(&tmCurrent);
	switch (tmFormat) {
	case 0:  //frame
		hr = m_pSeek->IsFormatSupported(&TIME_FORMAT_FRAME);
		if (SUCCEEDED(hr))  // support this format
		{
			hr = m_pSeek->SetTimeFormat(&TIME_FORMAT_FRAME);
		}
		break;
	case 1: //media time
		hr = m_pSeek->IsFormatSupported(&TIME_FORMAT_MEDIA_TIME);
		if (SUCCEEDED(hr))  // support this format
		{
			hr = m_pSeek->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME);
		}
		break;
	}
	return hr;
}

STDMETHODIMP CFcsPlayer::Avi2Wmv(const WCHAR* szSrcName, const WCHAR* szDestName, int nOption)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	// Create a new filter graph. (This also closes the old one, if any.)
	HRESULT hr = S_OK;
	hr = InitializeGraph();


	// Create the Filter Graph.
	if (SUCCEEDED(hr))
	{
		hr = CreateAvi2WmvGraph(szSrcName, szDestName, nOption);
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

HRESULT CFcsPlayer::CreateAvi2WmvGraph(const WCHAR* szSrcName, const WCHAR* szDestName, int nOption)
{
	// Create the System Device Enumerator.
	HRESULT hr = S_OK;
	IBaseFilter *pSource = NULL;
	IBaseFilter *pAudioFilter = NULL;
	IBaseFilter *pVideoFilter = NULL;
	IBaseFilter *pAudioRender = NULL;
	IBaseFilter *pVideoRender = NULL;
	IBaseFilter *pSampleFilter = NULL;
	IBaseFilter* pMorganFilter = NULL;
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
	pSampleGrabber->SetCallback(m_pAudioSample, 1);

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

					/*					if (szRegFilterName == _T("Morgan Stream Switcher"))
					{
					hr = pMoniker->BindToObject(NULL, NULL, IID_IBaseFilter,
					(void**)&pMorganFilter);
					hr = m_pGraph->AddFilter(pMorganFilter, _T("Morgan Stream Switcher"));
					}
					*/
				}  //success to read friendly name
				if (pMorganFilter != NULL)
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

	hr = AddSourceFilter(m_pGraph, szSrcName, CLSID_AsyncReader, &pSource);

	//add avi splitter.
	IBaseFilter* pAviSplitter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AviSplitter, &pAviSplitter);
	}

	//add vedio decompress
	IBaseFilter* pAviDeCompressor = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_AVIDec, &pAviDeCompressor);
	}



	//add asf writer
	IBaseFilter* pWriter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddWriterFilter(m_pGraph, szDestName, CLSID_WMAsfWriter, TRUE, &pWriter);
	}

	//connect filter
	//video connection
	hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	hr = ConnectFilters(m_pGraph, pAviSplitter, pAviDeCompressor);
	hr = ConnectFilters(m_pGraph, pAviDeCompressor, pWriter);
	hr = ConnectFilters(m_pGraph, pAviSplitter, pWriter);
	m_bAudioStream = TRUE;
	//

	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pAviDeCompressor);
	SAFE_RELEASE(pWriter);
	SAFE_RELEASE(pMorganFilter);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pSampleFilter);
	return hr;
}

STDMETHODIMP CFcsPlayer::SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;

	return hr;
}


STDMETHODIMP CFcsPlayer::GetEvent(long* iEvent, long* L1, long* L2)
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



STDMETHODIMP CFcsPlayer::SetGraphPath(BSTR bstrGraphPath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szGraphPath = CString(bstrGraphPath);
	return S_OK;
}

STDMETHODIMP CFcsPlayer::GetBitRate(long* nBitRate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pVideo == NULL)
		return S_FALSE;
	hr = m_pVideo->get_VideoHeight(nBitRate);
	return hr;
}

STDMETHODIMP CFcsPlayer::GetAudioLevel(long nChannel, long* nVolume)
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

STDMETHODIMP CFcsPlayer::GetP2AudioCount(long* nCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nVideoFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	long n = p2Paser.GetAudioCount();
	*nCount = n;
	return S_OK;
}

STDMETHODIMP CFcsPlayer::GetP2VideoName(BSTR bstrVideoName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nVideoFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	CString str = p2Paser.GetVideoName();
	bstrVideoName = str.AllocSysString();
	return S_OK;
}

STDMETHODIMP CFcsPlayer::GetP2AudioName(long nIndex, BSTR* bstrAudioName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nVideoFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	CString str = p2Paser.GetAudioName(nIndex);
	*bstrAudioName = str.AllocSysString();
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetP2AudioName(BSTR bstrAudioName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_nVideoFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	m_szAudioName = CString(bstrAudioName);
	return S_OK;
}

STDMETHODIMP CFcsPlayer::RenderP2(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_nVideoFormat != FCS_MEDIA_MXF_P2)
		return S_FALSE;
	hr = InitializeGraph();
	if (p2Paser.m_szCodec == _T("DV100_1080/50i"))
	{
		hr = RenderP2Dv100();

	}
	if (p2Paser.m_szCodec == _T("AVC-I_1080/50i"))
	{
		hr = RenderP2Avc100();
	}
	if (p2Paser.m_szCodec == _T("DV50_422"))
	{
		hr = RenderP2Dv50();
	}

	if (p2Paser.m_szCodec == _T("DV25_420") || p2Paser.m_szCodec == _T("DV25_411"))
	{
		hr = RenderP2Dv25();
	}
#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	

	return hr;
}

HRESULT CFcsPlayer::RenderP2Dv100(void)
{
	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("p2dvcpro100p.GRF"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	IEnumFilters* pEnumFilter = NULL;
	AM_MEDIA_TYPE mt;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;
	ISampleGrabber* pSampleGrabber = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	WAVEFORMATEX m_wformatEx;
	IPin* pOutPin = NULL;
	CString str;
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro100\\CONTENTS\\VIDEO\\000126.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
				{
					bIsSource = FALSE;
				}
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	IBaseFilter* pAviSplitter;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pVideoPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pVideoPin);
	}

	IBaseFilter* pVideoDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	IPin* pVideoRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVideoRenderPin);
	}

	IBaseFilter* pOldVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoRenderPin, &pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoRenderPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	// render current window
	IBaseFilter* pVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	IBaseFilter* pSource = NULL;
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRender);
	}




	//Find Audio Source Filter
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro100\\CONTENTS\\AUDIO\\00012600.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
					bIsSource = FALSE;
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pAudioPin);
	}

	IBaseFilter* pSampleFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pSampleFilter);
	}

	IPin* pAudioRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pAudioRenderPin);
	}

	IBaseFilter* pAudioRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioRenderPin, &pAudioRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pSampleFilter);
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
	//}



	////initial SampleGrabber
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	}
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

	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pOldVideoRender);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoRenderPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioRenderPin);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}

HRESULT CFcsPlayer::RenderP2Avc100(void)
{

	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("P2avc100p.grf"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	IEnumFilters* pEnumFilter = NULL;
	AM_MEDIA_TYPE mt;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;
	ISampleGrabber* pSampleGrabber = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	WAVEFORMATEX m_wformatEx;
	IPin* pOutPin = NULL;
	CString str;
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2avc\\CONTENTS\\VIDEO\\00011R.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
				{
					bIsSource = FALSE;
				}
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	IBaseFilter* pAviSplitter;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pVideoPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pVideoPin);
	}

	IBaseFilter* pVideoDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	IPin* pVideoRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVideoRenderPin);
	}

	IBaseFilter* pOldVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoRenderPin, &pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoRenderPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	// render current window
	IBaseFilter* pVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	IBaseFilter* pSource = NULL;
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRender);
	}




	//Find Audio Source Filter
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2avc\\CONTENTS\\AUDIO\\00011R00.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
					bIsSource = FALSE;
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pAudioPin);
	}

	IBaseFilter* pSampleFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pSampleFilter);
	}

	IPin* pAudioRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pAudioRenderPin);
	}

	IBaseFilter* pAudioRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioRenderPin, &pAudioRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pSampleFilter);
	}




	////initial SampleGrabber
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	}
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

	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pOldVideoRender);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoRenderPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioRenderPin);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;

}

HRESULT CFcsPlayer::RenderP2Dv50(void)
{

	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("p2dv50p.GRF"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	IEnumFilters* pEnumFilter = NULL;
	AM_MEDIA_TYPE mt;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;
	ISampleGrabber* pSampleGrabber = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	WAVEFORMATEX m_wformatEx;
	IPin* pOutPin = NULL;
	CString str;
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro50\\CONTENTS\\VIDEO\\0001BY.MXF") ||
					str == _T("File Source (Async.)"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
				{
					bIsSource = FALSE;
				}
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	IBaseFilter* pAviSplitter;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pVideoPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pVideoPin);
	}

	IBaseFilter* pVideoDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	IPin* pVideoRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVideoRenderPin);
	}

	IBaseFilter* pOldVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoRenderPin, &pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoRenderPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	// render current window
	IBaseFilter* pVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	IBaseFilter* pSource = NULL;
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRender);
	}




	//Find Audio Source Filter
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro50\\CONTENTS\\AUDIO\\0001BY00.MXF") ||
					str == _T("File Source (Async.) 0001"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
					bIsSource = FALSE;
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pAudioPin);
	}

	IBaseFilter* pSampleFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pSampleFilter);
	}

	IPin* pAudioRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pAudioRenderPin);
	}

	IBaseFilter* pAudioRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioRenderPin, &pAudioRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pSampleFilter);
	}



	////initial SampleGrabber
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	}
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

	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pOldVideoRender);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoRenderPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioRenderPin);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;

}


HRESULT CFcsPlayer::RenderP2Dv25(void)
{

	HRESULT hr = S_OK;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;
	szGraphName = m_szGraphPath + CString(_T("p2dv25p.GRF"));
	if (SUCCEEDED(hr))
	{
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	IEnumFilters* pEnumFilter = NULL;
	AM_MEDIA_TYPE mt;
	IAMFilterMiscFlags *pFlags = NULL;
	IBaseFilter* pOldSource = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	BOOL bIsSource = FALSE;
	ISampleGrabber* pSampleGrabber = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	WAVEFORMATEX m_wformatEx;
	IPin* pOutPin = NULL;
	CString str;
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro\\CONTENTS\\VIDEO\\0001C7.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
				{
					bIsSource = FALSE;
				}
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	IBaseFilter* pAviSplitter;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pVideoPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pVideoPin);
	}

	IBaseFilter* pVideoDecoder = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoPin, &pVideoDecoder);
	}

	IPin* pVideoRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pVideoDecoder, PINDIR_OUTPUT, &pVideoRenderPin);
	}

	IBaseFilter* pOldVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pVideoRenderPin, &pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pVideoRenderPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldVideoRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	// render current window
	IBaseFilter* pVideoRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = AddFilterByCLSID(m_pGraph, CLSID_VideoMixingRenderer, &pVideoRender, L"VMR-9");
	}
	//Set windowless mode on the VMR. This must be done before the VMR is connected.
	if (SUCCEEDED(hr))
	{
		hr = InitWindowlessVMR(pVideoRender, m_hwndVideo, &m_pWindowless);
	}

	//Add source filter
	CString szVideoName = p2Paser.GetVideoName();
	IBaseFilter* pSource = NULL;
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = szVideoName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pVideoDecoder);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVideoDecoder, pVideoRender);
	}




	//Find Audio Source Filter
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
				hr = pOldSource->QueryFilterInfo(pInfo);
				str = CString(pInfo->achName);
				if (str == _T("C:\\9fcs\\p2dvcpro\\CONTENTS\\AUDIO\\0001C700.MXF"))
				{
					hr = S_OK;
					SAFE_RELEASE(pFlags);
					SAFE_RELEASE(pFileSrc);
					break;
				}
				else
					bIsSource = FALSE;
			}
		}
	}

	//find demultipixeler
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pOutPin);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pOutPin, &pAviSplitter);
	}

	IPin* pAudioPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pAviSplitter, PINDIR_OUTPUT, &pAudioPin);
	}

	IBaseFilter* pSampleFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioPin, &pSampleFilter);
	}

	IPin* pAudioRenderPin = NULL;
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pSampleFilter, PINDIR_OUTPUT, &pAudioRenderPin);
	}

	IBaseFilter* pAudioRender = NULL;
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pAudioRenderPin, &pAudioRender);
	}

	if (SUCCEEDED(hr))
	{
		hr = RemoveFilter(m_pGraph, pOldSource);
	}

	//Add audio source filter
	if (SUCCEEDED(hr))
	{
		WCHAR* szSrcFile = m_szAudioName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		szVideoName.ReleaseBuffer();
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pSource, pAviSplitter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviSplitter, pSampleFilter);
	}

	//if (SUCCEEDED(hr))
	//{
	//	hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
	//}



	////initial SampleGrabber
	if (SUCCEEDED(hr))
	{
		hr = pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	}
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

	SAFE_RELEASE(pVideoDecoder);
	SAFE_RELEASE(pOldVideoRender);
	SAFE_RELEASE(pVideoRender);
	SAFE_RELEASE(pVideoPin);
	SAFE_RELEASE(pVideoRenderPin);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pSampleFilter);
	SAFE_RELEASE(pAudioRender);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pOutPin);
	SAFE_RELEASE(pAudioPin);
	SAFE_RELEASE(pAudioRenderPin);
	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;

}

STDMETHODIMP CFcsPlayer::Free(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	TearDownGraph();
	return S_OK;
}

STDMETHODIMP CFcsPlayer::snapImage(long nIndex, BSTR bstrImagename)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return S_OK;
}

STDMETHODIMP CFcsPlayer::ChangeWindow(long hWndHandle)
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

STDMETHODIMP CFcsPlayer::ChangeHWnd(HWND hWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	HRESULT hr = S_OK;
	if (m_pGraph == NULL)
		return S_FALSE;
	m_hwndVideo = hWnd;
	//find render filter
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter* pVideoRenderer = NULL;
	IPin* pInputPin = NULL;
	FILTER_INFO* pInfo = new FILTER_INFO;
	BOOL bRenderFilter = FALSE;
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
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			if (str == _T("Video Renderer"))
				break;
			SAFE_RELEASE(pOldRender);
			pInfo = new FILTER_INFO;
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


	return hr;
}


HRESULT CFcsPlayer::LoadRun(BSTR bstrGrfName)
{
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

#ifdef _DEBUG
	hr = AddGraphToRot(m_pGraph, &m_ROTRegister);
#endif	
	return hr;
}


HRESULT CFcsPlayer::Capture1()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	BOOL bIsSource = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sdplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}


	IEnumFilters* pEnumFilter = NULL;
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//change video render
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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsPlayer::Capture2()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	BOOL bIsSource = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("sdbplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}


	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//change video render
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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsPlayer::Capture3()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);
	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	//change video render
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

	// find old source filter

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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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


	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsPlayer::Capture4()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdbplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}
	hr = m_pGraph->EnumFilters(&pEnumFilter);

	//change video render
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

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


HRESULT CFcsPlayer::Capture5()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	BOOL bIsSource = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdvplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}


	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}

	//change video render
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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}



HRESULT CFcsPlayer::Capture6()
{
	HRESULT hr = S_OK;
	IBaseFilter* pAviSplitter = NULL;
	IEnumFilters* pEnumFilter = NULL;
	IBaseFilter* pOldSource = NULL;
	IBaseFilter* pSource = NULL;
	IBaseFilter *pVMR = NULL;
	IBaseFilter *pOldRender = NULL;
	IBaseFilter *pVideoRenderer = NULL;
	IAMFilterMiscFlags *pFlags = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IPin* pSourceOutPin = NULL;
	IEnumPins *pEnum = NULL;
	BOOL bRenderFilter = FALSE;
	FILTER_INFO* pInfo = new FILTER_INFO;
	IFilterGraph2 *pGraph2 = NULL;
	IPin* pInputPin = NULL;
	BOOL bRenderedAnyPin = FALSE;
	CString szGraphName;
	if (m_szGraphPath.Right(1) != _T("\\"))
		m_szGraphPath += CString(_T("\\"));
	WCHAR* sFile;

	hr = m_pGraph->QueryInterface(IID_IFilterGraph2, (void**)&pGraph2);

	//hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		szGraphName = m_szGraphPath + CString(_T("hdvbplay.GRF"));
		sFile = szGraphName.GetBuffer(MAX_PATH);
		hr = LoadGraphFile(m_pGraph, sFile);
		szGraphName.ReleaseBuffer();
	}

	//change video render
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

	// find old source filter
	hr = m_pGraph->EnumFilters(&pEnumFilter);

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

	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(pOldSource, PINDIR_OUTPUT, &pSourceOutPin);
	}

	//Find Avi splitter filter
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pSourceOutPin, &pAviSplitter);
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
		WCHAR* szSrcFile = m_szpathName.GetBuffer(MAX_PATH);
		hr = AddSourceFilter(m_pGraph, szSrcFile, CLSID_AsyncReader, &pSource);
		m_szpathName.ReleaseBuffer();
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

	SAFE_RELEASE(pAviSplitter);
	SAFE_RELEASE(pEnumFilter);
	SAFE_RELEASE(pOldSource);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pVMR);
	SAFE_RELEASE(pOldRender);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pSourceOutPin);
	SAFE_RELEASE(pEnum);
	SAFE_RELEASE(pGraph2);
	SAFE_RELEASE(pInputPin);

	SAFE_RELEASE(pInfo->pGraph);
	SAFE_DELETE(pInfo);
	return hr;
}


STDMETHODIMP CFcsPlayer::SetTemplateID(long nTemplateID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_nTemplateID = nTemplateID;
	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetSourceFile(BSTR bstrSourceName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	m_szpathName = CString(bstrSourceName);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::WaitForCompletion(long nTimeOut, long* pEvCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_pEvent == NULL)
		return S_FALSE;
	HRESULT hr = m_pEvent->WaitForCompletion(nTimeOut, pEvCode);
	return hr;
}

STDMETHODIMP CFcsPlayer::BlinkCounter(const WCHAR* sFileName)
{
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HRESULT hr = S_OK;


	return hr;
}

HRESULT CFcsPlayer::BlinkCounter1(const WCHAR* sFileName)
{
	HRESULT hr = S_OK;

	return hr;
}

STDMETHODIMP CFcsPlayer::AddOverlay(BSTR BstrOverlay, long nLeft, long nTop, long nRight, long nBottom, long nScaleToFit)
{
	HRESULT hr = S_OK;
	BOOL bHasVideo = FALSE;
	hr = HasVideo(&bHasVideo);
	if (FAILED(hr) || !bHasVideo)
		return S_FALSE;
	if (m_pVideoFilter == NULL)
		return S_FALSE;
	IPin* pPin = NULL;
	IBaseFilter* pFilter = NULL;
	IFcsOverlay* spOverlay;
	hr = FindConnectedPin(m_pVideoFilter, PINDIR_INPUT, &pPin);
	if (SUCCEEDED(hr))
	{
		hr = GetConnectedFilter(pPin, &pFilter);
	}
	if (SUCCEEDED(hr))
	{
		hr = DisconnectPin(m_pGraph, pPin);
	}

	//add overlay filter to graph
	if (m_pOverlayFilter == NULL)
	{
		hr = BindAMRegFilter(_T("Fcs Overlay"), &m_pOverlayFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pOverlayFilter->QueryInterface(&spOverlay);
	}

	if (SUCCEEDED(hr))
	{
		hr = spOverlay->put_ImageOverlay(BstrOverlay, nLeft, nTop, nRight, nBottom, TRUE, (BOOL)nScaleToFit, 200);
	}
	//connect overlay filter
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pFilter, m_pOverlayFilter);
	}
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, m_pOverlayFilter, m_pVideoFilter);
	}
#ifdef _DEBUG
	RemoveGraphFromRot(m_ROTRegister);
#endif
	m_ROTRegister = 0;
#ifdef _DEBUG
	hr = SaveGraphFile(m_pGraph, _T("c:\\tmp.grf"));
#endif	
	SAFE_RELEASE(pPin);
	SAFE_RELEASE(pFilter);
	SAFE_RELEASE(spOverlay);
	return hr;
}

STDMETHODIMP CFcsPlayer::SetSegment(LONG nStart, LONG nEnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());



	if (m_pControl == NULL || m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr = S_OK;
	LONGLONG timeBegin = (LONGLONG)((double)nStart * (double)ONE_SECOND / m_dFps);
	LONGLONG timeEnd = (LONGLONG)((double)nEnd * (double)ONE_SECOND / m_dFps);

	hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning,
		&timeEnd, AM_SEEKING_AbsolutePositioning);

	if (SUCCEEDED(hr))
	{

		if (m_state == STATE_STOPPED)
		{
			hr = m_pControl->StopWhenReady();
		}
	}

	return hr;
}

STDMETHODIMP CFcsPlayer::GetCurrentTimeString(BSTR* bstrTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	LONGLONG timeNow;
	HRESULT hr = GetCurrentPosition(&timeNow);
	double dSec = RefTimeToSeconds(timeNow);
	long Secs = (long)dSec;
	long sec = Secs % 60;
	long minutes = Secs / 60;
	long hour = minutes / 60;
	long minute = minutes % 60;
	double n = dSec - (double)Secs;
	long frame = n * m_dFps;
	CString str;
	str.Format(_T("%02ld:%02ld:%02ld.%02ld"), hour, minute, sec, frame);
	BSTR bstr = str.AllocSysString();
	*bstrTime = bstr;

	return S_OK;
}

STDMETHODIMP CFcsPlayer::SetFullScreen(LONG mode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	int cx = ::GetSystemMetrics(SM_CXSCREEN);
	int cy = ::GetSystemMetrics(SM_CYSCREEN);
	HWND hWnd = reinterpret_cast<HWND>(mode);
	HDC hdc = ::GetDC(m_hwndVideo);
	CRect rect;

	::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, cx, cy, TRUE);
	MoveWindow(hWnd, 0, 0, cx, cy, TRUE);
	CRect rtVideo, rtScreen;
	rtScreen = CRect(0, 0, cx * 8 / 10.0, cy * 9.5 / 10.0);
	rtVideo = CRect(0, 0, cx * 8 / 10.0, cy * 9.5 / 10.0);

	m_pWindowless->SetVideoPosition(NULL, &rtScreen);
	m_pWindowless->RepaintVideo(m_hwndVideo, hdc);
	return TRUE;
	if (m_pVideoWindow == NULL)
		return S_FALSE;
	m_pVideoWindow->put_FullScreenMode(OATRUE);
	return S_OK;
	HRESULT hr;
	hr = m_pVideoWindow->get_FullScreenMode(&mode);
	if (mode == OATRUE)
		hr = m_pVideoWindow->put_FullScreenMode(OAFALSE);
	else
	{
		hr = m_pVideoWindow->put_FullScreenMode(OATRUE);
		RECT rt;
		GetClientRect(m_hwndVideo, &rt);
		m_pVideoWindow->SetWindowPosition(0, 0, rt.right, rt.bottom);
	}
	return hr;
}


STDMETHODIMP CFcsPlayer::GetTcCode(LONGLONG timeNow, BSTR* bstrTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	double dSec = RefTimeToSeconds(timeNow);
	long Secs = dSec;
	long sec = Secs % 60;
	long minutes = Secs / 60;
	long hour = minutes / 60;
	long minute = minutes % 60;
	double n = dSec - (double)Secs;
	long frame = n * m_dFps;
	CString str;
	str.Format(_T("%02ld:%02ld:%02ld.%02ld"), hour, minute, sec, frame);
	BSTR bstr = str.AllocSysString();
	*bstrTime = bstr;

	return S_OK;
}


STDMETHODIMP CFcsPlayer::FrameToRefTime(LONG nFrame, LONGLONG* refTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	LONGLONG nDuration;
	GetDuration(&nDuration);
	LONG nLength;
	MP_GetLength(&nLength);
	LONGLONG nTimeByFrame = nDuration / (LONGLONG)nLength;
	LONGLONG n;
	n = nFrame * nTimeByFrame;
	*refTime = n;

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetVideoInfo(LONG* nWidth, LONG* nHeight, DOUBLE* dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	using namespace MediaInfoLib;
	MediaInfo MI;
	double adFps;
	wchar_t* buf = m_szpathName.GetBuffer(MAX_PATH);
	MI.Open(buf);
	String Inform = MI.Inform();
	String sWidth = MI.Get(Stream_Video, 0, _T("Width"), Info_Text, Info_Name).c_str();
	String sHeight = MI.Get(Stream_Video, 0, _T("Height"), Info_Text, Info_Name).c_str();
	String sFrameRate = MI.Get(Stream_Video, 0, _T("FrameRate"), Info_Text, Info_Name).c_str();
	long nW = _wtol((wchar_t*)sWidth.c_str());
	long nH = _wtol((wchar_t*)sHeight.c_str());
	adFps = _wtof((wchar_t*)sFrameRate.c_str());
	if (nW == 0)
	{
		GetVideoSize(nWidth, nHeight, NULL, NULL);
	}
	else
	{
		*nWidth = nW;
		*nHeight = nH;
	}
	if (adFps != 0)
		*dFps = adFps;
	else
		*dFps = 24.0;
	MI.Close();

	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetSegmentByMs(LONGLONG timeBegin, LONGLONG timeEnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pControl == NULL || m_pSeek == NULL)
	{
		return S_FALSE;
	}

	HRESULT hr = S_OK;
	hr = m_pSeek->SetPositions(&timeBegin, AM_SEEKING_AbsolutePositioning,
		&timeEnd, AM_SEEKING_AbsolutePositioning);

	if (SUCCEEDED(hr))
	{
		if (m_state == STATE_STOPPED)
		{
			hr = m_pControl->StopWhenReady();
		}
	}

	return hr;
}


STDMETHODIMP CFcsPlayer::GetFaceRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	m_pBlinkCounter->GetFaceRect(left, top, right, bottom);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetFaceImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	m_pBlinkCounter->GetFaceImg(pImage, nSize);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetFaceWidth(LONG* nWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL)
	{
		nWidth = 0;
		return S_FALSE;
	}
	m_pBlinkCounter->GetFaceWidth(nWidth);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetFaceHeight(LONG* nHeight)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL)
	{
		nHeight = 0;
		return S_FALSE;
	}
	m_pBlinkCounter->GetFaceHight(nHeight);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetLeadFace(BYTE* pLeadFace)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL)
	{
		pLeadFace = NULL;
		return S_FALSE;
	}
	m_pBlinkCounter->GetLeadFace(pLeadFace);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetLEyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	m_pBlinkCounter->GetLEyeRect(left, top, right, bottom);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetREyeRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	m_pBlinkCounter->GetREyeRect(left, top, right, bottom);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetLEyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	m_pBlinkCounter->GetLEyeImg(pImage, nSize);


	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetREyeImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	m_pBlinkCounter->GetREyeImg(pImage, nSize);


	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetLEyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	m_pBlinkCounter->GetLEyeballRect(left, top, right, bottom);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetREyeballRect(LONG* left, LONG* top, LONG* right, LONG* bottom)
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
	m_pBlinkCounter->GetREyeballRect(left, top, right, bottom);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetLEyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	m_pBlinkCounter->GetLEyeballImg(pImage, nSize);


	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetREyeballImg(BYTE* pImage, LONG nSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL || pImage == NULL)
	{
		pImage = NULL;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetREyeballImg(pImage, nSize);


	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetActivativedValue(DOUBLE* dActivation)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pBlinkCounter == NULL)
	{
		*dActivation = 0;
		return S_FALSE;
	}
	return m_pBlinkCounter->GetActivativedValue(dActivation);

	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetBlinkCount(LONG* nCount)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetBlinkCount(nCount);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetCurTimeMs(LONG* MilliSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTimeMs(MilliSec);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetCurTime(LONGLONG* NSec)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCurTime(NSec);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::ResetCounter(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->ResetCounter();
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetCheck(SHORT nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetCheck(nCheck);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetCheck(SHORT* nCheck)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetCheck(nCheck);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetFaceRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetFaceRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetFaceRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetFaceRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetEyeRectLineWidth(FLOAT fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->SetEyeRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetEyeRectLineWidth(FLOAT* fLineWidth)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (m_pBlinkCounter == NULL)
	{
		return S_FALSE;
	}
	return m_pBlinkCounter->GetEyeRectLineWidth(fLineWidth);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::put_ImageOverlay(CHAR* szText, LONG left, LONG top, LONG right, LONG bottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	return S_OK;
}


STDMETHODIMP CFcsPlayer::DisplayOverlay(LONG nID, SHORT IsVisible)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->DisPlayOverlay(nID, IsVisible);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetCountOfArray(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->GetCountOfArray();
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayPosition(LONG nID, LONG nLeft, LONG nTop, LONG nRight, LONG nButtom)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayPosition(nID, nLeft, nTop, nRight, nButtom);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayColor(LONG nID, COLORREF nColor)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayColor(nID, nColor);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayFontSize(LONG nID, LONG nFontSize)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFontSize(nID, nFontSize);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayFont(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFont(nID, nFontStyle, bUnderLine, bWrap, bVertical, bRightAlign);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayText(LONG nID, BSTR szText)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayText(nID, szText);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayFontName(LONG nID, BSTR szFontName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->SetOverlayFontName(nID, szFontName);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetOverlayImgPosition(BSTR szImgName, LONG nLeft, LONG nTop, LONG nRight, LONG nButtom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	if (m_pOverlay == NULL)
	{
		return S_FALSE;
	}
	return m_pOverlay->put_ImageOverlay(szImgName, nLeft, nTop, nRight, nButtom, bDisplay, bScaleFit, nTranspency);
	return S_OK;
}


STDMETHODIMP CFcsPlayer::SetFps(DOUBLE dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	m_dFps = dFps;
	return S_OK;
}


STDMETHODIMP CFcsPlayer::GetFps(DOUBLE* dFps)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	*dFps = m_dFps;
	return S_OK;
}

HRESULT CFcsPlayer::Play37413(const WCHAR* sFileName)
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
	CString s = CString(sFileName);
	int n = s.ReverseFind('.');
	CString s1 = s.Right(3);
	s1.MakeLower();
	if (s1 == _T("mxf"))
	{
		HRESULT hr1 = OpenBlueRay(sFileName);
		return hr1;
	}

	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(sFileName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	//Find audio render 

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pAudioRender, 0) == S_OK)
		{
			if (pInfo == NULL)
				pInfo = new FILTER_INFO;
			pAudioRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			if (str == _T("Audio Renderer"))
			{
				hr = S_OK;
				break;
			}
			else
			{
				SAFE_RELEASE(pAudioRender);
				hr = S_FALSE;
				pInfo = new FILTER_INFO;
			}
		}
	}

	// find connected pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = FindConnectedPin(pAudioRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		//// create sample grabber and add to graph
		CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (LPVOID*)&pSampleFilter);

		hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
		AM_MEDIA_TYPE mt, mt1;
		//m_pAudio->GetMediaType(&mt1);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			//m_wformatEx.cbSize = sizeof(WAVEFORMATEX);
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
			m_pAudioSample->m_szPathName = m_szpathName;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);
		}
		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pVMR, pSampleFilter);
		}

		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
		}
	}

	// add blinkCounter filter
	SAFE_RELEASE(pVMR);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(m_pVideoFilter, PINDIR_INPUT, &pInputPin);
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

	if (m_pBlinkCounterFilter == NULL)
	{
		hr = BindAMRegFilter(_T("Fcs FrameEater"), &m_pFrameEaterFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pFrameEaterFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, m_pFrameEaterFilter, m_pVideoFilter);
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

HRESULT CFcsPlayer::Play3003(const WCHAR* sFileName)
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
	CString s = CString(sFileName);
	int n = s.ReverseFind('.');
	CString s1 = s.Right(3);
	s1.MakeLower();
	if (s1 == _T("mxf"))
	{
		HRESULT hr1 = OpenBlueRay(sFileName);
		return hr1;
	}

	hr = InitializeGraph();



	// Add the source filter to the graph.
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddSourceFilter(sFileName, NULL, &pSource);
	}

	// Try to render the streams.
	if (SUCCEEDED(hr))
	{
		hr = RenderStreams(pSource);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->EnumFilters(&pEnumFilter);
	}
	//Find audio render 

	if (SUCCEEDED(hr))
	{
		while (pEnumFilter->Next(1, &pAudioRender, 0) == S_OK)
		{
			if (pInfo == NULL)
				pInfo = new FILTER_INFO;
			pAudioRender->QueryFilterInfo(pInfo);
			CString str = CString(pInfo->achName);
			SAFE_RELEASE(pInfo->pGraph);
			SAFE_DELETE(pInfo);
			if (str == _T("Audio Renderer"))
			{
				hr = S_OK;
				break;
			}
			else
			{
				SAFE_RELEASE(pAudioRender);
				hr = S_FALSE;
				pInfo = new FILTER_INFO;
			}
		}
	}

	// find connected pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = FindConnectedPin(pAudioRender, PINDIR_INPUT, &pInputPin);
	}

	// find connected filter with this pin
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = GetConnectedFilter(pInputPin, &pVMR);
	}

	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		hr = DisconnectPin(m_pGraph, pInputPin);
	}

	SAFE_RELEASE(pInputPin);
	if (SUCCEEDED(hr) && pAudioRender != NULL)
	{
		//// create sample grabber and add to graph
		CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER,
			IID_IBaseFilter, (LPVOID*)&pSampleFilter);

		hr = m_pGraph->AddFilter(pSampleFilter, L"SampleGrabber");
		AM_MEDIA_TYPE mt, mt1;
		//m_pAudio->GetMediaType(&mt1);
		pSampleFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
		if (pSampleGrabber != NULL)
		{
			ZeroMemory(&m_wformatEx, sizeof(WAVEFORMATEX));
			//m_wformatEx.cbSize = sizeof(WAVEFORMATEX);
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
			m_pAudioSample->m_szPathName = m_szpathName;
			pSampleGrabber->SetCallback(m_pAudioSample, 0);
		}
		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pVMR, pSampleFilter);
		}

		if (SUCCEEDED(hr) && pAudioRender != NULL)
		{
			hr = ConnectFilters(m_pGraph, pSampleFilter, pAudioRender);
		}
	}

	// add face dete4ctor filter
	SAFE_RELEASE(pVMR);
	if (SUCCEEDED(hr))
	{
		hr = FindConnectedPin(m_pVideoFilter, PINDIR_INPUT, &pInputPin);
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

	if (m_pFaceDetectorFilter == NULL)
	{
		hr = BindAMRegFilter(_T("Fcs FaceDetector"), &m_pFaceDetectorFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pVMR, m_pFaceDetectorFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, m_pFaceDetectorFilter, m_pVideoFilter);
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

HRESULT CFcsPlayer::Play3004(const WCHAR* sFileName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());


	IBaseFilter* pHikVIsionSourceFilter = NULL;
	IBaseFilter* pHikVIsionDecoderFilter = NULL;
	IBaseFilter* pFaceDetector = NULL;
	IBaseFilter* pVideoRenderer = NULL;
	IPin* pInputPin = NULL;
	IBaseFilter *pVMR = NULL;
	IFileSourceFilter *pFileSrc = NULL;
	IEnumPins* pEnumPins = NULL;

	HRESULT hr = S_OK;


	hr = InitializeGraph();
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Hikvision Source Filter"), &pHikVIsionSourceFilter);
	}
	if (SUCCEEDED(hr))
	{
		hr = pHikVIsionSourceFilter->QueryInterface(IID_IFileSourceFilter, (void**)&pFileSrc);
	}

	if (SUCCEEDED(hr))
	{
		hr = pFileSrc->Load(sFileName, NULL);
	}

	if (SUCCEEDED(hr))
	{
		hr = pHikVIsionSourceFilter->EnumPins(&pEnumPins);
	}

	if (SUCCEEDED(hr))
	{
		hr = pEnumPins->Next(1, &pInputPin, NULL);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Hikvision Decoder Filter"), &pHikVIsionDecoderFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pInputPin, pHikVIsionDecoderFilter);
	}

	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Fcs FaceDetector"), &pFaceDetector);
	}

	SAFE_RELEASE(pEnumPins);
	SAFE_RELEASE(pInputPin);

	if (SUCCEEDED(hr))
	{
		hr = FindUnconnectedPin(pHikVIsionDecoderFilter, PINDIR_OUTPUT, &pInputPin);
	}

	//add vedio decompress
	IBaseFilter* pAviDeCompressor = NULL;
	if (SUCCEEDED(hr))
	{
		hr = BindAMRegFilter(_T("Pinnacle Image Converter"), &pAviDeCompressor);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pInputPin, pAviDeCompressor);
	}

	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(m_pGraph, pAviDeCompressor, pFaceDetector);
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
		hr = ConnectFilters(m_pGraph, pFaceDetector, pVideoRenderer);
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

	SAFE_RELEASE(pHikVIsionSourceFilter);
	SAFE_RELEASE(pHikVIsionDecoderFilter);
	SAFE_RELEASE(pFaceDetector);
	SAFE_RELEASE(pVideoRenderer);
	SAFE_RELEASE(pInputPin);
	SAFE_RELEASE(pEnumPins);
	SAFE_RELEASE(pFileSrc);
	SAFE_RELEASE(pAviDeCompressor);

	return hr;
}



HRESULT CFcsPlayer::GetRate(DOUBLE* pRate)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	HRESULT hr = m_pSeek->GetRate(pRate);
	return hr;
}
