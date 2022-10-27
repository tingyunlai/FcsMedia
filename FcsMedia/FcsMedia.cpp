// FcsMedia.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "FcsMedia.h"


class CFcsMediaModule : public CAtlDllModuleT< CFcsMediaModule >
{
public :
	DECLARE_LIBID(LIBID_FcsMediaLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FCSMEDIA, "{7D315B4F-4CB3-4D2C-8910-ADCA9591AE8D}")
};

CFcsMediaModule _AtlModule;

class CFcsMediaApp : public CWinApp
{
public:

// Overrides
    virtual BOOL InitInstance();
    virtual int ExitInstance();
	//GdiplusStartupInput gdiplusStartupInput;
	//ULONG_PTR           gdiplusToken;


    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CFcsMediaApp, CWinApp)
END_MESSAGE_MAP()

CFcsMediaApp theApp;

BOOL CFcsMediaApp::InitInstance()
{
	//GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	return CWinApp::InitInstance();
}

int CFcsMediaApp::ExitInstance()
{
	//GdiplusShutdown(gdiplusToken);
	return CWinApp::ExitInstance();
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}

