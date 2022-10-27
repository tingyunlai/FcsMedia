// FcsSerialControl.h : Declaration of the CFcsSerialControl

#pragma once
#include "resource.h"       // main symbols

#include "FcsMedia.h"

#define COMM_BUFFER_SIZE		20 

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CFcsSerialControl

class ATL_NO_VTABLE CFcsSerialControl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFcsSerialControl, &CLSID_FcsSerialControl>,
	public IDispatchImpl<IFcsSerialControl, &IID_IFcsSerialControl, &LIBID_FcsMediaLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFcsSerialControl()
	{
		hCommPort = INVALID_HANDLE_VALUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FCSSERIALCONTROL)


BEGIN_COM_MAP(CFcsSerialControl)
	COM_INTERFACE_ENTRY(IFcsSerialControl)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

protected:
	HANDLE hCommPort;

public:
	STDMETHOD(OpenPort)(BSTR portName);
	STDMETHOD(Play)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(ClosePort)(void);
public:
	void errorMessage(DWORD dwError);
public:
	STDMETHOD(Eject)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(FcsSerialControl), CFcsSerialControl)
