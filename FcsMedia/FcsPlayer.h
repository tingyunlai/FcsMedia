// FcsPlayer.h : Declaration of the CFcsPlayer

#pragma once
#include "resource.h"       // main symbols

#include "FcsMedia.h"
#include "P2Paser.h"
#include "sgcallbackhandler.h"
#include "AudioSample.h"
#include "FcsBlinkCounter.h"
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif




struct GraphEventCallback
{
	virtual void OnGraphEvent(long eventCode, LONG_PTR param1, LONG_PTR param2) = 0;
};

// CFcsPlayer

class ATL_NO_VTABLE CFcsPlayer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFcsPlayer, &CLSID_FcsPlayer>,
	public IDispatchImpl<IFcsPlayer, &IID_IFcsPlayer, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFcsPlayer()
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
		m_pVideo = NULL;
		m_pVideoWindow = NULL;
		m_seekCaps = 0;
		m_bMute = FALSE;
		m_lVolume = MAX_VOLUME;
		m_ROTRegister = 0;
		m_pAudioSample = NULL;
		m_pSGCallback = NULL;
		m_szpathName = _T("");
		m_nVideoFormat = -1; //smart
		m_nGrabOption = -1;     //什么都不做
		m_pImageBuffer = NULL;
		m_nImageSize = 0;
		m_bFirstVideo = TRUE;
		m_pImageConverter = NULL;
		m_pBlinkCounterFilter = NULL;
		m_pVideoFilter = NULL;
		m_pOverlayFilter = NULL;
		m_pOverlay = NULL;
		m_pBlinkCounter = NULL;
		m_pFaceDetectorFilter = NULL;
		m_dFps = 25.0;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_FCSPLAYER)


	BEGIN_COM_MAP(CFcsPlayer)
		COM_INTERFACE_ENTRY(IFcsPlayer)
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
	HRESULT InitializeGraph();
	void	TearDownGraph();
	HRESULT	RenderStreams(IBaseFilter *pSource);
	HRESULT UpdateVolume();
	HRESULT BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter);
	CAudioSample* m_pAudioSample;
	HRESULT CreateWmvGraph(const WCHAR* szPathName);
	// Option = 0 不预览， 1：预览
	HRESULT CreateAvi2WmvGraph(const WCHAR* szSrcName, const WCHAR* szDestName, int nOption);
	//回录
	HRESULT Capture1(void);
	HRESULT Capture2(void);
	HRESULT Capture3(void);
	HRESULT Capture4(void);
	HRESULT Capture5(void);
	HRESULT Capture6(void);
	HRESULT BlinkPlay(const WCHAR* sFileName);
	HRESULT Play37413(const WCHAR* sFileName);
	HRESULT Play3003(const WCHAR* sFileName); // face detector
	HRESULT Play3004(const WCHAR* sFileName); // Hikvision face detector

	CString m_szpathName;                   
	CString m_szKeyFrameExportPath;		
	int m_nVideoFormat;                     
	int m_nGrabOption;                   
	CString          m_szGraphPath;
	CString          m_szVideoName;       
	CString          m_szAudioName;		
										
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
	DWORD m_ROTRegister;     // graph edit 的id
	WAVEFORMATEX m_wformatEx;
	IGraphBuilder	*m_pGraph;
	IMediaControl	*m_pControl;
	IMediaEventEx	*m_pEvent;
	IMediaSeeking	*m_pSeek;
	IBasicAudio		*m_pAudio;
	IBasicVideo		*m_pVideo;
	CBasicParams     m_pKeyFrameParams;
	CP2Paser p2Paser;
	CSGCallbackHandler* m_pSGCallback;
	IVideoWindow    *m_pVideoWindow;

	IVMRWindowlessControl	*m_pWindowless;
	IBaseFilter* m_pImageConverter;
	IBaseFilter* m_pBlinkCounterFilter;
	IBaseFilter* m_pFrameEaterFilter;
	IBaseFilter* m_pFaceDetectorFilter;
	IBaseFilter* m_pVideoFilter;
	IBaseFilter* m_pOverlayFilter;
	IFcsOverlay* m_pOverlay;
	IFcsBlinkCounter* m_pBlinkCounter;
	long m_nTemplateID;
	BOOL m_bFirstVideo;
	double m_dFps;



public:
	STDMETHOD(ReFresh)(void);
	STDMETHOD(SetVideoWindow)(long hParent);
	STDMETHOD(MP_GetPosition)(long* nIndex);   
	STDMETHOD(MP_Pause)(void);
	STDMETHOD(MP_Stop)(void);
	STDMETHOD(MP_Seek)(long nIndex);
	STDMETHOD(MP_Run)(void);
	STDMETHOD(MP_Initial)(void);
	STDMETHOD(MP_Free)(void);
	STDMETHOD(MP_SetFile)(BSTR strFile);
	STDMETHOD(MP_SetWindow)(long hParent, long x, long y, long nWidth, long nHeight);
	STDMETHOD(SetOption)(long nOption);
	STDMETHOD(MP_Render)(void);
	STDMETHOD(MP_GetLength)(long* nLength);    //返回总帧数
	STDMETHOD(MP_SetWndPosition)(long x, long y, long nWidth, long nHeight);
	STDMETHOD(GetAudio)(long nIndex, long* nOption);
	STDMETHOD(InitOnlyRawControl)(void);
	STDMETHOD(MP_SaveBmpToFile)(BSTR strFileName, long nWidth, long nHeight);
	STDMETHOD(MP_UpdateVideoWindow)(long left, long top, long right, long bottom);
	STDMETHOD(SetKeyFrameBasicParas)(long pBasicParams);

public:
	STDMETHOD(SetWindow)(HWND hWnd);
	STDMETHOD(SetEventWindow)(HWND hwnd, UINT msg);
	STDMETHOD(State)(UINT* state);
	STDMETHOD(CanSeek)(BOOL* bCanSeek);
	STDMETHOD(HasVideo)(BOOL* bHasVideo);
	STDMETHOD(OpenFile)(const WCHAR* sFileName);
	STDMETHOD(OpenBlueRay)(const WCHAR* sFileName);
	STDMETHOD(GetVideoSize)(long* lpWidth, long* lpHeight, long* lpARWidth, long* lpARHeight);
	STDMETHOD(Play)(void);
	STDMETHOD(Pause)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(SetRate)(double dSpeed);
	STDMETHOD(GetTMFormat)(GUID* tmFormat);
	STDMETHOD(UpdateVideoWindow)(const LPRECT prc);
	STDMETHOD(Repaint)(HDC hdc);
	STDMETHOD(DisplayModeChanged)(void);
	STDMETHOD(SetPosition)(LONGLONG pos);
	STDMETHOD(GetDuration)(LONGLONG* pDuration);      
	STDMETHOD(GetCurrentPosition)(LONGLONG* pTimeNow);    
	STDMETHOD(Mute)(BOOL bMute);
	STDMETHOD(IsMuted)(BOOL* bMuted);
	STDMETHOD(SetVolume)(long lVolume);
	STDMETHOD(GetVolume)(long* lVolume);
	STDMETHOD(Open)(BSTR sFileName, long nFormat, long nOption);
	STDMETHOD(get_Fcs_Media_State)(LONG FCS_STATE_RUNNING, LONG* pVal);
	STDMETHOD(put_Fcs_Media_State)(LONG FCS_STATE_RUNNING, LONG newVal);
	STDMETHOD(OpenP2Mxf)(const WCHAR* szPathName);
	STDMETHOD(OpenSonyMxf)(const WCHAR* szPathName);
	STDMETHOD(OpenAvi)(const WCHAR* szPathName);
	STDMETHOD(OpenWmv)(const WCHAR* szPathName);
	STDMETHOD(OpenMpeg2)(const WCHAR* szPathName);
	STDMETHOD(Save)(const WCHAR* szTargetName, int nTargetFormat, int nOption);
	STDMETHOD(OpenMpeg4)(const WCHAR* szpathName);
	STDMETHOD(Save2Avi)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(Save2Mpeg2)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(Save2Mpeg4)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(Save2P2Mxf)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(Save2SonyMxf)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(Save2Wmv)(const WCHAR* szTargetName, int nOption);
	STDMETHOD(SetKeyFramePath)(const WCHAR* szPathName);
	STDMETHOD(SetTMFormat)(long tmFormat);
	STDMETHOD(Avi2Wmv)(const WCHAR* szSrcName, const WCHAR* szDestName, int nOption);
	STDMETHOD(SetKeyFrameBasicParams)(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath);
	STDMETHOD(GetEvent)(long* iEvent, long* L1, long* L2);
	STDMETHOD(SetGraphPath)(BSTR bstrGraphPath);
	STDMETHOD(GetBitRate)(long* nBitRate);
	STDMETHOD(GetAudioLevel)(long nChannel, long* nVolume);
	STDMETHOD(GetP2AudioCount)(long* nCount);
	STDMETHOD(GetP2VideoName)(BSTR bstrVideoName);
	STDMETHOD(GetP2AudioName)(long nIndex, BSTR* bstrAudioName);
	STDMETHOD(SetP2AudioName)(BSTR bstrAudioName);
	STDMETHOD(RenderP2)(void);
	STDMETHOD(ChangeWindow)(long hWndHandle);
	STDMETHOD(ChangeHWnd)(HWND hWnd);
	STDMETHOD(LoadRun)(BSTR bstrGrfName);
	STDMETHOD(BlinkCounter)(const WCHAR* sFileName);
	STDMETHOD(WaitForCompletion)(long nTimeOut, long* pEvCode);
	STDMETHOD(AddOverlay)(BSTR BstrOverlay, long nLeft, long nTop, long nRight, long nBottom, long nScaleToFit);
	STDMETHOD(snapImage)(long nIndex, BSTR bstrImagename);
	STDMETHOD(Free)(void);
	STDMETHOD(SetTemplateID)(long nTemplateID);
	STDMETHOD(SetSourceFile)(BSTR bstrSourceName);
	HRESULT BlinkCounter1(const WCHAR* sFileName);
protected:
	HRESULT RenderP2Dv100(void);
	HRESULT RenderP2Avc100(void);
	HRESULT RenderP2Dv50(void);
	HRESULT RenderP2Dv25(void);
public:

public:
	BYTE* m_pImageBuffer;
	long m_nImageSize;

public:
	STDMETHOD(GetCurrentTimeString)(BSTR* bstrTime);
	STDMETHOD(SetFullScreen)(LONG mode);
	STDMETHOD(GetTcCode)(LONGLONG timeNow, BSTR* bstrTime);
	STDMETHOD(FrameToRefTime)(LONG nFrame, LONGLONG* refTime);
	STDMETHOD(GetVideoInfo)(LONG* nWidth, LONG* nHeight, DOUBLE* dFps);
	STDMETHOD(SetSegment)(LONG nStart, LONG nEnd);
	STDMETHOD(SetSegmentByMs)(LONGLONG timeBegin, LONGLONG timeEnd);
	STDMETHOD(GetFaceRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetFaceImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetFaceWidth)(LONG* nWidth);
	STDMETHOD(GetFaceHeight)(LONG* nHeight);
	STDMETHOD(GetLeadFace)(BYTE* pLeadFace);
	STDMETHOD(GetLEyeRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetREyeRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetLEyeImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetREyeImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetLEyeballRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetREyeballRect)(LONG* left, LONG* top, LONG* right, LONG* bottom);
	STDMETHOD(GetLEyeballImg)(BYTE* pImage, LONG nSize);
	STDMETHOD(GetREyeballImg)(BYTE* pImage, LONG nSize);
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
	STDMETHOD(put_ImageOverlay)(CHAR* szText, LONG left, LONG top, LONG right, LONG bottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency);
	STDMETHOD(DisplayOverlay)(LONG nID, SHORT IsVisible);
	STDMETHOD(GetCountOfArray)(void);
	STDMETHOD(SetOverlayPosition)(LONG nID, LONG nLeft, LONG nTop, LONG nRight, LONG nButtom);
	STDMETHOD(SetOverlayColor)(LONG nID, COLORREF nColor);
	STDMETHOD(SetOverlayFontSize)(LONG nID, LONG nFontSize);
	STDMETHOD(SetOverlayFont)(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign);
	STDMETHOD(SetOverlayText)(LONG nID, BSTR szText);
	STDMETHOD(SetOverlayFontName)(LONG nID, BSTR szFontName);
	STDMETHOD(SetOverlayImgPosition)(BSTR szImgName, LONG nLeft, LONG nTop, LONG nRight, LONG nButtom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency);
	STDMETHOD(SetFps)(DOUBLE dFps);
	STDMETHOD(GetFps)(DOUBLE* dFps);
	STDMETHOD(GetRate)(DOUBLE* pRate);
};

OBJECT_ENTRY_AUTO(__uuidof(FcsPlayer), CFcsPlayer)
