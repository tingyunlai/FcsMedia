// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit


#include <afxwin.h>
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT
#pragma include_alias( "dxtrans.h", "qedit.h" )
#define __IDxtCompositor_INTERFACE_DEFINED__
#define __IDxtAlphaSetter_INTERFACE_DEFINED__
#define __IDxtJpeg_INTERFACE_DEFINED__
#define __IDxtKey_INTERFACE_DEFINED__
#include <rpcsal.h>
#include <Qedit.h>
#include <DShow.h>
#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <windows.h>
#include <atlimage.h>
//#include <streams.h>			// DShow
//#include <strsafe.h>
#include "..\..\DirectShow\Common\dshowutil.h"
#include <d3d9.h>
#include <vmr9.h>
#include "DecklinkInterface.h"
#include "KeyFrameDll.h"
//leadtools support
#include <math.h>
#include <stdio.h>
#include <opencv2\opencv.hpp>
#include <afx.h>
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) { if (x) { x->Release(); x = NULL; } }
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(x) { if (x) { delete x; x = NULL; } }
#endif

const long MIN_VOLUME = -10000;
const long MAX_VOLUME = 0;

#define DVENCODER_WIDTH             720
#define PAL_DVENCODER_HEIGHT        576
#define NTSC_DVENCODER_HEIGHT       480


enum DV_MODE
{
	CameraMode = 0L,
	VcrMode = 1L,
	UnknownMode = 2L
};


enum GRAPH_TYPE
{
	GRAPH_PREVIEW,
	GRAPH_DV_TO_FILE,
	GRAPH_DV_TO_FILE_NOPRE,
	GRAPH_FILE_TO_DV,
	GRAPH_FILE_TO_DV_NOPRE,
	GRAPH_DV_TO_FILE_TYPE2,
	GRAPH_DV_TO_FILE_NOPRE_TYPE2,
	GRAPH_FILE_TO_DV_TYPE2,
	GRAPH_FILE_TO_DV_NOPRE_TYPE2
};

enum PlaybackState
{
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_STOPPED,
	STATE_CLOSED
};

enum FunctionMode
{
	FCS_Grab_Mode,
	FCS_PlayBack_Mode,
	FCS_Encode_Mode,
	FCS_Download_Mode,
	JBU_FACE_DETECTION_MODE,
	JBU_IRIS_DETECTION_MODE
};

enum OperationMode
{
	FCS_OPTION_VEHICLE_COUNTING,    
	FCS_OPTION_BLINK_COUNTING       
};
enum FcsMediaType
{
	FCS_MEDIA_MXF_P2,
	FCS_MEDIA_MXF_SONY,
	FCS_MEDIA_AVI,
	FCS_MEDIA_MPEG2,
	FCS_MEDIA_MPEG4,
	FCS_MEDIA_AVI_DV_100,
	FCS_MEDIA_AVI_DV_50,
	FCS_MEDIA_AVI_DV_25,
	FCS_MEDIA_AVI_DV_MJ,
	FCS_MEDIA_MOV,
	FCS_MEDIA_WMV,
	FCS_MEDIA_MTS,
	FCS_MEDIA_MPEG2_HD
};

enum FilterMode {
	Filter_Directshow,
	Filter_VideoCaptureSource,
	Filter_AudioCaptureSource,
	Filter_VideoCompressor

};
struct CBasicParams
{

	int  nWidth;		
	int  nHeight;		
	BOOL bOcr;			
	int	 nOcrY1;		
	int  nOcrY2;		
	TCHAR pszPath[255];	
	TCHAR pszDbConnectStr[255];	
	TCHAR pszParentID[37];		
	TCHAR pszRootID[37];			
	TCHAR pszCreator[37];		
								
};

EXTERN_C const CLSID CLSID_WmvPaser;
EXTERN_C const CLSID CLSID_Dump;

#ifdef __cplusplus
class DECLSPEC_UUID("36A5F770-FE4C-11CE-A8ED-00AA002FEAB5")
	CLSID_Dump;
class DECLSPEC_UUID("1932C124-77DA-4151-99AA-234FEA09F463")
	CLSID_WmvPaser;
#endif

//end of leadtools support
HRESULT RemoveUnconnectedRenderer(IGraphBuilder *pGraph, IBaseFilter *pRenderer, BOOL *pbRemoved);
HRESULT InitWindowlessVMR(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl** ppWc);
HRESULT InitWindowlessVMR9(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl** ppWc);
HRESULT InitWindowedVMR(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl** ppWc);
HRESULT InitRenderlessVMR(IBaseFilter *pVMR, HWND hwnd, IVMRWindowlessControl** ppWc);


using namespace ATL;
//
