

#pragma once
#include "resource.h"       



#include "FcsMedia.h"
#include "_IJbuCapturerEvents_CP.h"

#include "SGCallbackHandler.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CJbuCapturer

class ATL_NO_VTABLE CJbuCapturer :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CJbuCapturer, &CLSID_JbuCapturer>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CJbuCapturer>,
	public CProxy_IJbuCapturerEvents<CJbuCapturer>,
	public IDispatchImpl<IJbuCapturer, &IID_IJbuCapturer, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CJbuCapturer()
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
		m_pVideoRenderer = NULL;
		m_pSGCallback = NULL;
		m_szGraphPath = _T("d:\\9jbu");
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_JBUCAPTURER)


	BEGIN_COM_MAP(CJbuCapturer)
		COM_INTERFACE_ENTRY(IJbuCapturer)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CJbuCapturer)
		CONNECTION_POINT_ENTRY(__uuidof(_IJbuCapturerEvents))
	END_CONNECTION_POINT_MAP()
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


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
	HRESULT SetKeyFrameBasicParams(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath);
	HRESULT InitializeGraph();
	void	TearDownGraph();
	HRESULT UpdateVolume();
	HRESULT BuildGraph(void);
	HRESULT BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter);
	HRESULT	RenderStreams(IBaseFilter *pSource);
	HRESULT DShowFace();
	CSGCallbackHandler* m_pSGCallback;
	CString          m_szGraphPath;
	long              m_nTemplateID;        
	long              m_nFileNo;               
	HWND			m_hwndVideo;	// Video clipping window
	HWND			m_hwndEvent;	// Window to receive events
	UINT			m_EventMsg;		// Windows message for graph events
	CRect           m_windowRect;
	PlaybackState	m_state;
	DWORD			m_seekCaps;		// Caps bits for IMediaSeeking
	IGraphBuilder	*m_pGraph;
	IMediaControl	*m_pControl;
	IMediaEventEx	*m_pEvent;
	IMediaSeeking	*m_pSeek;
	IBasicAudio		*m_pAudio;
	CBasicParams     m_pKeyFrameParams;
	IBaseFilter* m_pVideoRenderer;
	enum { ENC_NONE, ENC_DV, ENC_WM, ENC_MJ };
	IVMRWindowlessControl	*m_pWindowless;
	DWORD m_ROTRegister;     // graph edit 的id
	CString m_szPathName;                  
	CString m_szPathName1;                   
											 // Audio
	BOOL            m_bAudioStream; // Is there an audio stream?
	long			m_lVolume;		// Current volume (unless muted)
	BOOL			m_bMute;			// Volume muted?		

public:



	STDMETHOD(SetWindow)(LONG hParent);
	STDMETHOD(Pause)();
	STDMETHOD(Stop)();
	STDMETHOD(SetWindowPosition)(LONG top, LONG left, LONG Width, LONG Height);
	STDMETHOD(Free)();
	STDMETHOD(Init)();
	STDMETHOD(Render)();
	STDMETHOD(SetGraphPath)(BSTR bstrGraphPath);
	STDMETHOD(SetSinkFile)(BSTR bstrPathName, BSTR bstrPathName1, LONG nTemplateID, LONG nFileNo);
	STDMETHOD(GetVideoSize)(LONG* lpWidth, LONG* lpHeight, LONG* lpARwidth, LONG* lpARHeight);
	STDMETHOD(UpdateWindow)(LONG left, LONG top, LONG right, LONG bottom);
	STDMETHOD(State)(LONG* nState);
	STDMETHOD(ChangeWindow)(LONG hWndHandle);
	STDMETHOD(Play)();
	STDMETHOD(SnapImage)(BSTR ImageName, LONG Width, LONG Height);
	STDMETHOD(ChangeHWnd)(HWND hWnd);
	STDMETHOD(UpdateVideoWindow)(const LPRECT prc);

};

OBJECT_ENTRY_AUTO(__uuidof(JbuCapturer), CJbuCapturer)
