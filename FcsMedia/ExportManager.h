// ExportManager.h : Declaration of the CExportManager

#pragma once
#include "resource.h"       // main symbols
#include "SGCallbackHandler.h"
#include "FcsMedia.h"
#include "P2Paser.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CExportManager

class ATL_NO_VTABLE CExportManager :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CExportManager, &CLSID_ExportManager>,
	public IDispatchImpl<IExportManager, &IID_IExportManager, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CExportManager()
	{
		m_state = STATE_CLOSED;
		m_seekCaps = 0;
		m_pGraph = NULL;
		m_pControl = NULL;
		m_pEvent = NULL;
		m_pSeek = NULL;
		m_pWindowless = NULL;
		m_pAudio = NULL;
		m_hwndEvent = NULL;
		m_ROTRegister = 0;
		m_bAudioStream = FALSE;
		m_pSGCallback = NULL;
		m_bSetBasicParams = FALSE;
		m_pEventSink = NULL;
		m_nInputFormat = -10;
		m_nOutputFormat = -10;
		m_nBeginFrame = 0;
		m_nEndFrame = 0;
		m_nSeg = 0;
		m_dFps = 25.0;

	}

DECLARE_REGISTRY_RESOURCEID(IDR_EXPORTMANAGER)


BEGIN_COM_MAP(CExportManager)
	COM_INTERFACE_ENTRY(IExportManager)
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
		SAFE_RELEASE(m_pSGCallback);
	}

public:
	long           m_nBeginFrame;
	long			 m_nEndFrame;
	long           m_nSeg;                 

private:

	//state 
	PlaybackState	m_state;
	DWORD			m_seekCaps;		
	BOOL            m_bAudioStream;    
	CRect            m_windowRect;
	BOOL			m_bSetBasicParams; 
	CBasicParams     m_pKeyFrameParams;
	CString          m_szGraphPath;
	long            m_nInputFormat;     //format of source file
	long            m_nOutputFormat;   //format of sink file
	// Audio
	long			m_lVolume;		// Current volume (unless muted)
	BOOL			m_bMute;			// Volume muted?		
	IGraphBuilder	*m_pGraph;
	IMediaControl	*m_pControl;
	IMediaEventEx	*m_pEvent;
	IMediaSeeking	*m_pSeek;
	IBasicAudio		*m_pAudio;
	IMediaEventSink  *m_pEventSink;
	CString m_szSourceName;
	CString m_szSinkName;
	CString m_szTempWmv;
	IVMRWindowlessControl	*m_pWindowless;
	CSGCallbackHandler* m_pSGCallback;
	HWND			m_hwndEvent;	// Window to receive events
	HWND           	m_hwndVideo;   //preview window
	UINT			m_EventMsg;		// Windows message for graph events
	DWORD m_ROTRegister;     
	CP2Paser p2Paser;
	CString          m_szVideoName;       //used by p2 only at this verion
	CString          m_szAudioName;		//used by p2 only at this version
	IBaseFilter*  m_pSource;
	double m_dFps;

	HRESULT InitializeGraph();
	void	TearDownGraph();
	HRESULT BindAMRegFilter(const WCHAR* szFilterName, IBaseFilter** pFilter);
	HRESULT CreateWmvGraph(const WCHAR* szSrcName, const WCHAR* szDestName);
	HRESULT UpdateVolume();
	HRESULT P2Dv1002Wmv();
	HRESULT P2Dv502Wmv();
	HRESULT P2Dv252Wmv();
	HRESULT P2Avc1002Wmv();

	//DV AVI
	HRESULT Encode1();
	//DV50 AVI
	HRESULT Encode2();
	// AVI
	HRESULT Encode3();
	//MXF wav
	HRESULT Encode4();
	//AVI
	HRESULT Encode5();
	//DV100 AVI
	HRESULT Encode6();
	//DV100MXF
	HRESULT Encode7();
	//avi to avi 
	HRESULT Encode8();
	//mpg to mpg 
	HRESULT Encode9();

	HRESULT Encode10();
	// MPEG2 to MP4
	HRESULT Encode11();

	STDMETHOD(HasVideo)(BOOL* bHasVideo);
public:
	STDMETHOD(State)(UINT* state);
	STDMETHOD(CanSeek)(BOOL* bCanSeek);
	STDMETHOD(SetPosition)(LONGLONG pos);
	STDMETHOD(GetDuration)(LONGLONG* pDuration);       
	STDMETHOD(SetWindow)(HWND hWnd);
	STDMETHOD(UpdateVideoWindow)(const LPRECT prc);
	STDMETHOD(GetVideoSize)(long* lpWidth, long* lpHeight , long* lpARWidth, long* lpARHeight);
	STDMETHOD(Repaint)(HDC hdc);
	STDMETHOD(SetEventWindow)(HWND hWnd, UINT msg);
	STDMETHOD(Run)(void);
	STDMETHOD(TC_SetWindow)(long hParent);
	STDMETHOD(TC_SetSourceFile)(BSTR szSourceName, long nFormat, long nSeg, long nStart, long nEnd);
	STDMETHOD(TC_SetSinkFile)(BSTR szSinkName, long nFormat);
	STDMETHOD(TC_GetLength)(LONG* nLength);
	STDMETHOD(TC_Run)(void);
	STDMETHOD(TC_GetPosition)(LONG* iPos);
	STDMETHOD(TC_Stop)(void);
	STDMETHOD(GetEvent)(long* iEvent, long* L1, long* L2);
	STDMETHOD(TC_ShowConfig)(void);
	STDMETHOD(TC_Init)(void);
	STDMETHOD(TC_Render)(void);
	STDMETHOD(TC_Free)(void);
	STDMETHOD(SetKeyFrameBasicParams)(long nWidth, long nHeight, BOOL bOcr, long nOcrY1, long nOcrY2, BSTR szExportPath);
	STDMETHOD(KF_KeyFrame)(BSTR bstrVideoName);
	STDMETHOD(SaveKFInfo)(void);
	STDMETHOD(SetGraphPath)(BSTR bstrGraphPath);
	STDMETHOD(Save)(void);
	STDMETHOD(GetP2AudioCount)(long* nCount);
	STDMETHOD(GetP2VideoName)(BSTR bstrVideoName);
	STDMETHOD(GetP2AudioName)(long nIndex, BSTR* bstrAudioName);
	STDMETHOD(SetP2AudioName)(BSTR bstrAudioName);
	STDMETHOD(LoadRun)(BSTR bstrGrfName);
	STDMETHOD(SetRange)(long nStart, long nEnd, long nSeg);
	STDMETHOD(ChangeWindow)(long hWndHandle);
	STDMETHOD(ChangeHWnd)(HWND hWnd);
	STDMETHOD(PackAvi)(BSTR bstrVideo, BSTR bstrAudio1, BSTR bstrAudio2, BSTR bstrAudio3, BSTR bstrOutAvi);

protected:
	HRESULT SmartSave(void);
	HRESULT SmartSave2(void);
	HRESULT HDSmartSave(void);
	//input source type:sony blue_ray
	HRESULT SonyMxf2Wmv(void);
	HRESULT SonyMxf2Avi100(void);
	HRESULT SonyMxf2Avi50(void);
	HRESULT SonyMxf2Avi25(void);
	HRESULT SonyMxf2AviMj(void);
	HRESULT SonyMxf2Mpeg2(void);
	HRESULT SonyMxf2Mov(void);

	//input source type:P2 Mxf
	HRESULT P2Mxf2Wmv(void);
	HRESULT P2Mxf2Avi100(void);
	HRESULT P2Mxf2Avi50(void);
	HRESULT P2Mxf2Avi25(void);
	HRESULT P2Mxf2AviMj(void);
	HRESULT P2Mxf2Mpeg2(void);
	HRESULT P2Mxf2Mov(void);

	//input source type:Avi
	HRESULT Avi2Wmv(void);
	HRESULT Avi2Avi100(void);
	HRESULT Avi2Avi50(void);
	HRESULT Avi2Avi25(void);
	HRESULT Avi2AviMj(void);
	HRESULT Avi2Mpeg2(void);
	HRESULT Avi2Mov(void);

	//input source type:Mpeg2
	HRESULT HDMpeg22Wmv(void);
	HRESULT Mpeg22Wmv(void);
	HRESULT Mpeg22Avi100(void);
	HRESULT Mpeg2Avi50(void);
	HRESULT Mpeg22Avi25(void);
	HRESULT Mpeg22AviMj(void);
	HRESULT Mpeg22Mpeg2(void);
	HRESULT Mpeg22Mov(void);

	//input source type:Mts
	HRESULT Mts2Wmv(void);
	HRESULT Mts2Avi100(void);
	HRESULT Mts2Avi50(void);
	HRESULT Mts2Avi25(void);
	HRESULT Mts2AviMj(void);
	HRESULT Mts2Mpeg2(void);
	HRESULT Mts2Mov(void);


	//HRESULT Mpeg2Wmv(void);
	HRESULT ChangeP2SourceFilter(const WCHAR* szVideoName);
	HRESULT ChnageSourceFilter(const WCHAR* szSrcName);
public:
	STDMETHOD(Pause)(void);
public:
	STDMETHOD(TC_Seek)(long iPos);
	HRESULT ChangeWriter();
	HRESULT NotifyEnd();
public:
	STDMETHOD(WaitForCompletion)(long nTimeOut, long* pEvCode);
};

OBJECT_ENTRY_AUTO(__uuidof(ExportManager), CExportManager)
