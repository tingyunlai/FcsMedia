// FcsDVManager.h : Declaration of the CFcsDVManager

#pragma once
#include "resource.h"       // main symbols
#include <xprtdefs.h>
#include "FcsMedia.h"
#include "SGCallbackHandler.h"
#include "AudioSample.h"
#include "FcsBlinkCounter.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CFcsDVManager

class ATL_NO_VTABLE CFcsDVManager :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFcsDVManager, &CLSID_FcsDVManager>,
	public IDispatchImpl<IFcsDVManager, &IID_IFcsDVManager, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFcsDVManager()
	{
		m_state = STATE_CLOSED;
		m_hwndVideo = NULL;
		m_hwndEvent = NULL;
		m_EventMsg = 0;
		m_pGraph = NULL;
		m_pControl = NULL;
		m_pEvent = NULL;
		m_pSeek = NULL;
		m_pWindowless = NULL;
		m_pAudio = NULL;
		m_seekCaps = 0;
		m_pVideoCapture = NULL;
		m_pAudioCapture = NULL;
		m_pVideoRenderer = NULL;
		m_pSmartT = NULL;
		m_bMute = FALSE;
		m_lVolume = MAX_VOLUME;
		m_ROTRegister = 0;
		m_pSGCallback = NULL;
		m_szPathName = _T("");
		m_nVideoFormat = -1; 
		m_nGrabOption = -1;     
		m_bAudioMute = FALSE;
		m_pAudioSample = NULL;
		m_bSetBasicParams = FALSE;
		m_pIAMExtDevice = NULL;
		m_pIAMExtTransport = NULL;
		m_pIAMTCReader = NULL;
		m_pDeviceFilter = NULL;
		m_pInputFileFilter = NULL;

		m_dFps = 25.0;

	}

	DECLARE_REGISTRY_RESOURCEID(IDR_FCSDVMANAGER)


	BEGIN_COM_MAP(CFcsDVManager)
		COM_INTERFACE_ENTRY(IFcsDVManager)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		TearDownGraph();
	}
private:

	HRESULT Capture30(void);
	HRESULT Capture31(void);
	HRESULT Capture32(void);
	HRESULT Capture33(void);
	HRESULT Capture34(void);
	HRESULT Capture35(void);
	HRESULT Capture36(void);
	HRESULT Capture37(void);
	HRESULT DVCaptureMpeg2(void);
	HRESULT DVCapturePlay(void);

	HRESULT InitializeGraph();
	void	TearDownGraph();
	HRESULT UpdateVolume();
	BOOL IsDeviceOutputDV(IBaseFilter * pFilter);
	HRESULT BuildBasicGraph();
	HRESULT AddDeviceFilter(void);
	HRESULT Capture1(void);
	HRESULT Record2Files(void);

	CSGCallbackHandler* m_pSGCallback;
	CString          m_szGraphPath;
	long              m_nTemplateID;        //template id
	long              m_nFileNo;            //file no
	CAudioSample* m_pAudioSample;

	CString m_szPathName;                   //video name
	CString m_szPathName1;                   //video2
	CString m_szKeyFrameExportPath;		//keyframe export path
	int m_nVideoFormat;                       //media format eg. MXF, AVI, MPEG, WMV.. etc
	int m_nGrabOption;                   //SampleGrabber action， 0：keyframe， 1：each frame
										 //state 
	BOOL            m_bLowBitRate;        
	BOOL            m_bCreateLowBitRate;  
	HWND			m_hwndVideo;	// Video clipping window
	HWND			m_hwndEvent;	// Window to receive events
	UINT			m_EventMsg;		// Windows message for graph events
	CRect           m_windowRect;

	PlaybackState	m_state;
	DWORD			m_seekCaps;		// Caps bits for IMediaSeeking

									// Audio
	BOOL            m_bAudioStream; // Is there an audio stream?
	long			m_lVolume;		// Current volume (unless muted)
	BOOL			m_bMute;			// Volume muted?		
	DWORD m_ROTRegister;     // graphedit id

	IGraphBuilder	*m_pGraph;
	IMediaControl	*m_pControl;
	IMediaEventEx	*m_pEvent;
	IMediaSeeking	*m_pSeek;
	IBasicAudio		*m_pAudio;
	CBasicParams     m_pKeyFrameParams;
	IBaseFilter* m_pVideoCapture;
	IBaseFilter* m_pAudioCapture;
	IBaseFilter* m_pVideoRenderer;
	IBaseFilter* m_pSmartT;
	enum { ENC_NONE, ENC_DV, ENC_WM, ENC_MJ };
	IVMRWindowlessControl	*m_pWindowless;
	VIDEOINFOHEADER m_vihDefault;
	WAVEFORMATEX m_wfexDefault;
	BOOL m_bAudioMute;
	BOOL m_bSetBasicParams;
	IVideoWindow            *m_pVideoWindow;
	IAMDroppedFrames        *m_pDroppedFrames;

	IAMExtDevice            *m_pIAMExtDevice;
	IAMExtTransport         *m_pIAMExtTransport;
	IAMTimecodeReader       *m_pIAMTCReader;
	IBaseFilter             *m_pDeviceFilter;
	IBaseFilter             *m_pInputFileFilter;

	TCHAR                   m_DeviceName[_MAX_PATH];
	// State maintaining member variables
	long                 m_SubunitMode; // vcr or camera
	_DVENCODERVIDEOFORMAT   m_VideoFormat; //pal or ntsc
	LONG                    m_AvgTimePerFrame;
	_DVRESOLUTION           m_DVResolution; //  resolution of DV decoder
	GRAPH_TYPE              m_iGraphType;
	double m_dFps;
	IFcsBlinkCounter* m_pBlinkCounter;
public:
	STDMETHOD(SetWindow)(long hParent);
	STDMETHOD(Pause)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(GetPosition)(long* iPos);
	STDMETHOD(Seek)(long iPos);
	STDMETHOD(Run)(void);
	STDMETHOD(SetWindowPosition)(long top, long left, long Width, long Height);
	STDMETHOD(Free)(void);
	STDMETHOD(Init)(void);
	STDMETHOD(SetFile)(BSTR szPathName);
	STDMETHOD(Render)(void);
	STDMETHOD(GetLength)(long* nLength);
	STDMETHOD(SetOption)(long nOption);
	STDMETHOD(GetAudio)(long nChannelID, long* nVolume);
	STDMETHOD(SetPosition)(LONGLONG pos);
	STDMETHOD(GetVideoSize)(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight);
	STDMETHOD(Repaint)(HDC hdc);
	STDMETHOD(State)(long* state);
	STDMETHOD(SetGraphPath)(BSTR bstrGraphPath);
	STDMETHOD(SetSinkFile)(BSTR bstrPathName, BSTR bstrPathName1, long nTemplateID, long nFileNo);
	STDMETHOD(SetHWnd)(HWND hWnd);
	STDMETHOD(UpdateVideoWindow)(const LPRECT prc);
	STDMETHOD(Record)(void);
	STDMETHOD(UpdateWindow)(long left, long top, long right, long bottom);
	STDMETHOD(GetAudioLevel)(long nChannel, long* nVolume);
	STDMETHOD(SetKeyFrameBasicParams)(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath);
	STDMETHOD(SaveKFInfo)(void);
	STDMETHOD(GetDVMode)(long* nDvMode);  //vcr or camera, otherwise unknown
	STDMETHOD(ChangeWindow)(long hWndHandle);
	STDMETHOD(ChangeHWnd)(HWND hWnd);
	STDMETHOD(RemoteControl)(long nFunctionID);
public:
	STDMETHOD(PowerOn)(void);
public:
	STDMETHOD(PowerOff)(void);
public:
	STDMETHOD(StandBy)(void);
public:
	STDMETHOD(SetDvRate)(long nRate);
public:
	STDMETHOD(GetDvRate)(double* dRate);
	STDMETHOD(GetGraphPath)(BSTR* strGraphPath);
	STDMETHOD(IsMute)(SHORT* bMute);
	STDMETHOD(GetVideoFps)(DOUBLE* dFps);
	STDMETHOD(SnapImage)(BSTR bstrImagename, LONG nNewWidth, LONG nNewHeight);
	STDMETHOD(MP_GetPosition)(LONG* nIndex);
	STDMETHOD(GetCurrentPosition)(LONGLONG* pTimeNow);
	STDMETHOD(GetFaceRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetFaceWidth)(LONG* nWidth);
	STDMETHOD(GetFaceHeight)(LONG* nHeight);
	STDMETHOD(GetLEyeRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetREyeRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetLEyeballRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetREyeballRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetFaceImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetLEyeImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetREyeImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetLEyeballImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetREyeballImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetLeadFace)(BYTE* pLeadFace);
	STDMETHOD(GetActivativedValue)(DOUBLE* dActivation);
	STDMETHOD(GetBlinkCount)(LONG* nCount);
	STDMETHOD(GetCurTimeMs)(LONG* MilliSec);
	STDMETHOD(GetCurTime)(LONGLONG* NSec);
	STDMETHOD(ResetCounter)(void);
	STDMETHOD(SetCheck)(SHORT nCheck);
	STDMETHOD(GetCheck)(SHORT* nCheck);
	STDMETHOD(SetFaceRectLineWidth)(FLOAT fLineWidth);
	STDMETHOD(GetFaceRectLineWidth)(FLOAT* fLineWidth);
	STDMETHOD(SetEyeRectLineWidth)(FLOAT fLineWidth);
	STDMETHOD(GetEyeRectLineWidth)(FLOAT* fLineWidth);
};

OBJECT_ENTRY_AUTO(__uuidof(FcsDVManager), CFcsDVManager)
