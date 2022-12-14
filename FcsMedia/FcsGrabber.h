// FcsGrabber.h : Declaration of the CFcsGrabber

#pragma once
#include "resource.h"       // main symbols
#include "FcsMedia.h"
#include "SGCallbackHandler.h"
#include "AudioSample.h"
#include "FcsBlinkCounter.h"
#include "FcsOverlay.h"
#include "FcsRoi.h"
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CFcsGrabber

class ATL_NO_VTABLE CFcsGrabber :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFcsGrabber, &CLSID_FcsGrabber>,
	public IDispatchImpl<IFcsGrabber, &IID_IFcsGrabber, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFcsGrabber()
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
		m_nVideoFormat = -1; //smart
		m_nGrabOption = -1;     //什么都不做
		m_bAudioMute = FALSE;
		m_pAudioSample = NULL;
		m_bSetBasicParams = FALSE;
		m_dFps = 25.0;
		m_pBlinkCounter = NULL;
		m_szGraphPath = _T("d:\\9jbu");
		m_pOverlay = NULL;
		m_bEnableRoi = FALSE;
		m_szExportDir = _T("c:\\a5\\");
		m_szExportName = _T("iris1.jpg");
		m_nExportWidh = 640;
		m_nExportHeight = 480;
		m_nCompressRatio = 10;
		m_nCaptureFreq = 8;
		m_nFramePerSec = 15;
	}


DECLARE_REGISTRY_RESOURCEID(IDR_FCSGRABBER)


BEGIN_COM_MAP(CFcsGrabber)
	COM_INTERFACE_ENTRY(IFcsGrabber)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		//TearDownGraph();
	}

private:
	HRESULT InitializeGraph();
	void	TearDownGraph();
	HRESULT UpdateVolume();
	HRESULT BuildGraph(void);
	HRESULT BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter, int nFilterMode);
	HRESULT BindCameraById(int nCamerano, IBaseFilter** pFilter, int nFilterMode);
	HRESULT	RenderStreams(IBaseFilter *pSource);
	CSGCallbackHandler* m_pSGCallback;
	CString          m_szGraphPath;
	long              m_nTemplateID;        //graph id
	long              m_nFileNo;               
	CAudioSample* m_pAudioSample;

	CString m_szPathName;                   
	CString m_szPathName1;                   //video url
	CString m_szKeyFrameExportPath;		
	int m_nVideoFormat;                       // eg. MXF, AVI, MPEG, WMV.. etc
	int m_nGrabOption;                   
	//state 
	BOOL            m_bLowBitRate;       
	BOOL            m_bCreateLowBitRate;  
	HWND			m_hwndVideo;	// Video clipping window
	HWND			m_hwndEvent;	// Window to receive events
	UINT			m_EventMsg;		// Windows message for graph events
	CRect           m_windowRect;
	double m_dFps;

	PlaybackState	m_state;
	DWORD			m_seekCaps;		// Caps bits for IMediaSeeking

	// Audio
	BOOL            m_bAudioStream; // Is there an audio stream?
	long			m_lVolume;		// Current volume (unless muted)
	BOOL			m_bMute;			// Volume muted?		
	DWORD m_ROTRegister;     // graph edit 的id

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
	IFcsBlinkCounter* m_pBlinkCounter;
	IFcsOverlay* m_pOverlay;
	enum { ENC_NONE, ENC_DV, ENC_WM, ENC_MJ };
	IVMRWindowlessControl	*m_pWindowless;
	VIDEOINFOHEADER m_vihDefault;
	WAVEFORMATEX m_wfexDefault;
	BOOL m_bAudioMute;
	BOOL m_bSetBasicParams;
	BOOL m_bEnableRoi;
	CFcsRoi m_Roi;
	
	CString m_szExportDir; 
	CString m_szExportName; 
	long m_nExportWidh;
	long m_nExportHeight; 
	int m_nCompressRatio; 
	int m_nCaptureFreq; 
	int m_nFramePerSec; 

private:
	HRESULT File1001(void);
	HRESULT Capture1(void);
	HRESULT Capture2(void);
	HRESULT Capture3(void);
	HRESULT Capture4(void);
	HRESULT Capture5(void);
	HRESULT Capture6(void);
	HRESULT Capture7(void);
	HRESULT Capture8(void);
	HRESULT Capture9(void);
	HRESULT Capture10(void);
	HRESULT Capture11(void);
	HRESULT Capture12(void);
	HRESULT Capture13(void);
	HRESULT Capture14(void);
	HRESULT Capture15(void);
	HRESULT Capture16(void);
	HRESULT Capture47411(void);
	HRESULT Capture47412(void);
	HRESULT Capture47413(void);
	HRESULT Capture2001(void);
	HRESULT Capture2002(void);
	HRESULT Capture3001(void);
	HRESULT Capture3002(void);
	HRESULT Capture3003(void);
	HRESULT Capture3004(void);
	HRESULT Capture4001(void);
	HRESULT Capture4002(void);
	HRESULT Capture4003(void);  
	HRESULT Capture5001(void); 
	HRESULT Capture5002(void); 
	HRESULT Capture6001(void); 
	HRESULT Capture6002(void); 
	HRESULT RunIrisCamera(void); 
	HRESULT RunIris4005(void); 
	HRESULT Capture7001(void); 
	HRESULT Capture7002(void); 
	HRESULT Capture7003(void); 
	HRESULT Capture8001(void); 
	HRESULT Capture8002(void); 
	HRESULT Avi2Mp4(void);
	HRESULT Video2Dump(void);

	HRESULT CreatePreviewGraph(void);

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
	STDMETHOD(GetVideoSize)(long* lpWidth, long* lpHeight , long* lpARWidth, long* lpARHeight);
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
	STDMETHOD(ChangeWindow)(long hWndHandle);
	STDMETHOD(ChangeHWnd)(HWND hWnd);

public:
	HRESULT Record2Files(void);
public:
	STDMETHOD(SaveKFInfo)(void);
	STDMETHOD(GetGraphPath)(BSTR* strGraphPath);
	STDMETHOD(IsMute)(SHORT* bMute);
	STDMETHOD(GetVideoFps)(DOUBLE* dFps);
	STDMETHOD(SetFullScreen)(SHORT* nResult, SHORT nState);
	STDMETHOD(SnapImage)(BSTR bstrImagename,LONG nNewWidth,LONG nNewHeight);
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
	STDMETHOD(DisPlayOverlay)(LONG nID, SHORT IsVisible);
	STDMETHOD(GetCountOfArray)(void);
	STDMETHOD(SetOverlayPosition)(LONG nId, LONG nLeft, LONG nTop, LONG nRight, LONG nBottom);
	STDMETHOD(SetOverlayColor)(LONG nID, COLORREF nColor);
	STDMETHOD(SetOverlayFontSize)(LONG nID, LONG nFontSize);
	STDMETHOD(SetOverlayFont)(LONG nID, LONG nFontStyle, SHORT bUnderLine, SHORT bWrap, SHORT bVertical, SHORT bRightAlign);
	STDMETHOD(SetOverlayText)(LONG nID, BSTR szText);
	STDMETHOD(SetOverlayFontName)(LONG nID, BSTR szFontName);
	STDMETHOD(SetOverlayImgPosition)(BSTR szImgName, LONG left, LONG top, LONG right, LONG bottom, SHORT bDisplay, SHORT bScaleFit, LONG nTranspency);
	//STDMETHOD(snapImage)(BSTR ImageName, LONG Width, LONG Height, LONG BitPerPixel);
	STDMETHOD(EnableRoi)(SHORT Enable);
	STDMETHOD(SetRoi)(LONG left, LONG top, LONG right, LONG bottom);
	STDMETHOD(ShowRoi)(void);
	STDMETHOD(SetRoiProp)(LONG nColor, LONG PenStyle, LONG LineWidth, LONG ShapeType);
	STDMETHOD(SnapGrayImage)(BSTR bstrImagename, LONG nNewWidth, LONG nNewHeight);
	STDMETHOD(SetExportDir)(BSTR ExportDir);
	STDMETHOD(SetExportName)(BSTR ImageName);
	STDMETHOD(SetExportImageWidth)(LONG Width);
	STDMETHOD(SetExportImageHeight)(LONG Height);
	STDMETHOD(SetCompressRatio)(LONG Ratio);
	STDMETHOD(SetCaptureFreq)(LONG Freq);
	STDMETHOD(SetCaneraFps)(LONG FramePerSec);
	STDMETHOD(EnableCapture)(LONG Enable);
	STDMETHOD(WaitForCompletion)(LONG nTimeout, LONG* evtCode);
};

OBJECT_ENTRY_AUTO(__uuidof(FcsGrabber), CFcsGrabber)
