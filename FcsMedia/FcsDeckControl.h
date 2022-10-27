// FcsDeckControl.h : Declaration of the CFcsDeckControl

#pragma once
#include "resource.h"       // main symbols

#include "FcsMedia.h"
#include "DeckLinkAPI_h.h"
#include "decklinkapi_i.c"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CFcsDeckControl

class ATL_NO_VTABLE CFcsDeckControl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFcsDeckControl, &CLSID_FcsDeckControl>,
	public IDispatchImpl<IFcsDeckControl, &IID_IFcsDeckControl, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFcsDeckControl()
	{
		m_deckLinkIterator = NULL; 
		m_deckLink = NULL; 
		m_deckControl = NULL;
		m_deckLinkAttributes = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FCSDECKCONTROL)


BEGIN_COM_MAP(CFcsDeckControl)
	COM_INTERFACE_ENTRY(IFcsDeckControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		SAFE_RELEASE(m_deckControl);
		SAFE_RELEASE(m_deckLink);
		SAFE_RELEASE(m_deckLinkIterator);
		SAFE_RELEASE(m_deckLinkAttributes);
	}
protected:
	IDeckLinkIterator*		m_deckLinkIterator; 
	IDeckLink*				m_deckLink; 
	IDeckLinkDeckControl* m_deckControl;
	IDeckLinkAttributes*	m_deckLinkAttributes; 

public:
public:
	STDMETHOD(Init)(LONG* nResult);
public:
	STDMETHOD(Close)(LONG nStatus);
public:
	STDMETHOD(SetStandBy)(LONG nStatus);
public:
	STDMETHOD(Play)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Stop)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(TogglePlayStop)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Eject)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(GotoTimeCode)(BSTR bstrTimeCode, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(FastForward)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Rewind)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(StepForward)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(StepBack)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Jog)(DOUBLE nRate, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Shuttle)(DOUBLE nRate, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(GetTimeCode)(BSTR bstrTimeCode, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(SetPreroll)(LONG nSecond, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(GetPreroll)(LONG* nSecond, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(SetCaptureOffset)(LONG nCaptureOffset);
public:
	STDMETHOD(GetCaptureOffset)(LONG* nCaptureOffset, LONG* nResult);
public:
	STDMETHOD(SetExportOffset)(LONG nExportOffset);
public:
	STDMETHOD(GetExportOffset)(LONG* nExportOffset, LONG* nResult);
public:
	STDMETHOD(GetManualExportOffset)(LONG* nExportOffset, LONG* nResult);
public:
	STDMETHOD(StartExport)(BSTR bstrInPoint, BSTR bstrOutPoint, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(StartCapture)(LONG useVITC, BSTR bstrInPoint, BSTR bstrOutPoint, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(GetDeviceID)(LONG* nDeviceID, LONG* nResult, LONG* errCode);
public:
	STDMETHOD(Abort)(LONG* nResult);
public:
	STDMETHOD(CrashRecordStart)(LONG* nResult, LONG* errCode);
public:
	STDMETHOD(CrashRecordStop)(LONG* nResult, LONG* errCode);
};

OBJECT_ENTRY_AUTO(__uuidof(FcsDeckControl), CFcsDeckControl)
