

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Wed Oct 26 18:31:56 2022
 */
/* Compiler settings for FcsMedia.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "FcsMedia.h"

#define TYPE_FORMAT_STRING_SIZE   153                               
#define PROC_FORMAT_STRING_SIZE   9653                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _FcsMedia_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } FcsMedia_MIDL_TYPE_FORMAT_STRING;

typedef struct _FcsMedia_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } FcsMedia_MIDL_PROC_FORMAT_STRING;

typedef struct _FcsMedia_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } FcsMedia_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const FcsMedia_MIDL_TYPE_FORMAT_STRING FcsMedia__MIDL_TypeFormatString;
extern const FcsMedia_MIDL_PROC_FORMAT_STRING FcsMedia__MIDL_ProcFormatString;
extern const FcsMedia_MIDL_EXPR_FORMAT_STRING FcsMedia__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFcsPlayer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFcsPlayer_ProxyInfo;

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_ResetCounter_Proxy( 
    IFcsPlayer * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3238],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetCheck_Proxy( 
    IFcsPlayer * This,
    SHORT nCheck)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3260],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetCheck_Proxy( 
    IFcsPlayer * This,
    SHORT *nCheck)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3288],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetFaceRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT fLineWidth)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3316],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetFaceRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT *fLineWidth)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3344],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetEyeRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT fLineWidth)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3372],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetEyeRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT *fLineWidth)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3400],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_DisplayOverlay_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    SHORT IsVisible)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3428],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetCountOfArray_Proxy( 
    IFcsPlayer * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3462],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayPosition_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nLeft,
    LONG nTop,
    LONG nRight,
    LONG nButtom)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3484],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayColor_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    COLORREF nColor)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3536],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFontSize_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nFontSize)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3570],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFont_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nFontStyle,
    SHORT bUnderLine,
    SHORT bWrap,
    SHORT bVertical,
    SHORT bRightAlign)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3604],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayText_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    BSTR szText)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3662],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFontName_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    BSTR szFontName)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3696],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayImgPosition_Proxy( 
    IFcsPlayer * This,
    BSTR szImgName,
    LONG nLeft,
    LONG nTop,
    LONG nRight,
    LONG nButtom,
    SHORT bDisplay,
    SHORT bScaleFit,
    LONG nTranspency)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3730],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetFps_Proxy( 
    IFcsPlayer * This,
    DOUBLE dFps)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3800],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetFps_Proxy( 
    IFcsPlayer * This,
    DOUBLE *dFps)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3828],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetRate_Proxy( 
    IFcsPlayer * This,
    DOUBLE *pRate)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &FcsMedia__MIDL_ProcFormatString.Format[3856],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IExportManager_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IExportManager_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFcsGrabber_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFcsGrabber_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFcsDVManager_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFcsDVManager_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFcsDeckControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFcsDeckControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFcsSerialControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFcsSerialControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IJbuCapturer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IJbuCapturer_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, float, double or hyper in -Oif or -Oicf, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const FcsMedia_MIDL_PROC_FORMAT_STRING FcsMedia__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure SetWindow */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 16 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventWindow */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 38 */	NdrFcShort( 0x8 ),	/* 8 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter hwnd */

/* 44 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 48 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter msg */

/* 50 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 52 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 56 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 58 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 60 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure State */

/* 62 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 64 */	NdrFcLong( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x9 ),	/* 9 */
/* 70 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 72 */	NdrFcShort( 0x1c ),	/* 28 */
/* 74 */	NdrFcShort( 0x8 ),	/* 8 */
/* 76 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter state */

/* 78 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 80 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 84 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 86 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenFile */

/* 90 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 92 */	NdrFcLong( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0xa ),	/* 10 */
/* 98 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 100 */	NdrFcShort( 0x1a ),	/* 26 */
/* 102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 104 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter sFileName */

/* 106 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 108 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 110 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoSize */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xb ),	/* 11 */
/* 126 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 128 */	NdrFcShort( 0x70 ),	/* 112 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter lpWidth */

/* 134 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpHeight */

/* 140 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARWidth */

/* 146 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARHeight */

/* 152 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 154 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 160 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Run */


	/* Procedure Run */


	/* Procedure Play */

/* 164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0xc ),	/* 12 */
/* 172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 178 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Render */


	/* Procedure TC_Run */


	/* Procedure Pause */

/* 186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0xd ),	/* 13 */
/* 194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 204 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Free */


	/* Procedure Free */


	/* Procedure Stop */

/* 208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0xe ),	/* 14 */
/* 216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 222 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRate */

/* 230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0xf ),	/* 15 */
/* 238 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 244 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dSpeed */

/* 246 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTMFormat */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x10 ),	/* 16 */
/* 266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 268 */	NdrFcShort( 0x44 ),	/* 68 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter tmFormat */

/* 274 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 278 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HasVideo */

/* 286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x11 ),	/* 17 */
/* 294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 296 */	NdrFcShort( 0x1c ),	/* 28 */
/* 298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 300 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bHasVideo */

/* 302 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateVideoWindow */

/* 314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x12 ),	/* 18 */
/* 322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 324 */	NdrFcShort( 0x34 ),	/* 52 */
/* 326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 328 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter prc */

/* 330 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 334 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Repaint */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x13 ),	/* 19 */
/* 350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hdc */

/* 358 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 362 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */

/* 364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Play */


	/* Procedure TC_Free */


	/* Procedure DisplayModeChanged */

/* 370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x14 ),	/* 20 */
/* 378 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 384 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CanSeek */

/* 392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x15 ),	/* 21 */
/* 400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 402 */	NdrFcShort( 0x1c ),	/* 28 */
/* 404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 406 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bCanSeek */

/* 408 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPosition */

/* 420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x16 ),	/* 22 */
/* 428 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 434 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pos */

/* 436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 440 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDuration */

/* 448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x17 ),	/* 23 */
/* 456 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 458 */	NdrFcShort( 0x24 ),	/* 36 */
/* 460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 462 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pDuration */

/* 464 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 468 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentPosition */

/* 476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x18 ),	/* 24 */
/* 484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 486 */	NdrFcShort( 0x24 ),	/* 36 */
/* 488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 490 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pTimeNow */

/* 492 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Mute */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x19 ),	/* 25 */
/* 512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 514 */	NdrFcShort( 0x8 ),	/* 8 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bMute */

/* 520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMuted */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x1a ),	/* 26 */
/* 540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 542 */	NdrFcShort( 0x1c ),	/* 28 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bMuted */

/* 548 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetVolume */

/* 560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x1b ),	/* 27 */
/* 568 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 572 */	NdrFcShort( 0x8 ),	/* 8 */
/* 574 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter lVolume */

/* 576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CanSeek */


	/* Procedure GetVolume */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x1c ),	/* 28 */
/* 596 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 598 */	NdrFcShort( 0x1c ),	/* 28 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bCanSeek */


	/* Parameter lVolume */

/* 604 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 612 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */


	/* Procedure ReFresh */

/* 616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x1d ),	/* 29 */
/* 624 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_Seek */


	/* Procedure SetVideoWindow */

/* 638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x1e ),	/* 30 */
/* 646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 652 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter iPos */


	/* Parameter hParent */

/* 654 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 662 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2AudioCount */


	/* Procedure MP_GetPosition */

/* 666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x1f ),	/* 31 */
/* 674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 676 */	NdrFcShort( 0x1c ),	/* 28 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCount */


	/* Parameter nIndex */

/* 682 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_Pause */

/* 694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x20 ),	/* 32 */
/* 702 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveKFInfo */


	/* Procedure SaveKFInfo */


	/* Procedure MP_Stop */

/* 716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x21 ),	/* 33 */
/* 724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 730 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 734 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteControl */


	/* Procedure ChangeWindow */


	/* Procedure MP_Seek */

/* 738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x22 ),	/* 34 */
/* 746 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 752 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nFunctionID */


	/* Parameter hWndHandle */


	/* Parameter nIndex */

/* 754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_Run */

/* 766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x23 ),	/* 35 */
/* 774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 780 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_Initial */

/* 788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x24 ),	/* 36 */
/* 796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 802 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_Free */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x25 ),	/* 37 */
/* 818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 828 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_SetFile */

/* 832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x26 ),	/* 38 */
/* 840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 846 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter strFile */

/* 848 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 852 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_SetWindow */

/* 860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x27 ),	/* 39 */
/* 868 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 870 */	NdrFcShort( 0x28 ),	/* 40 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	0x4,		/* Oi2 Flags:  has return, */
			0x6,		/* 6 */

	/* Parameter hParent */

/* 876 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter x */

/* 882 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 888 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nWidth */

/* 894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 896 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 900 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 902 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOption */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x28 ),	/* 40 */
/* 920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nOption */

/* 928 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_Render */

/* 940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x29 ),	/* 41 */
/* 948 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 956 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_GetLength */

/* 962 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 964 */	NdrFcLong( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x2a ),	/* 42 */
/* 970 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 972 */	NdrFcShort( 0x1c ),	/* 28 */
/* 974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 976 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nLength */

/* 978 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_SetWndPosition */

/* 990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x2b ),	/* 43 */
/* 998 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1000 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1004 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter x */

/* 1006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1008 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 1012 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1014 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nWidth */

/* 1018 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1020 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 1024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1026 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1032 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAudio */

/* 1036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1044 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1050 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nIndex */

/* 1052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1058 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitOnlyRawControl */

/* 1070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1084 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 1086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SnapImage */


	/* Procedure MP_SaveBmpToFile */

/* 1092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1100 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1102 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1106 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter bstrImagename */


	/* Parameter strFileName */

/* 1108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1112 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nNewWidth */


	/* Parameter nWidth */

/* 1114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nNewHeight */


	/* Parameter nHeight */

/* 1120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_UpdateVideoWindow */

/* 1132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1140 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1142 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1146 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 1148 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 1154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1156 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 1160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 1166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1168 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1174 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 1178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1184 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1186 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1188 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1192 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter sFileName */

/* 1194 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nFormat */

/* 1200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1214 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Fcs_Media_State */

/* 1218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1226 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1230 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1232 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter FCS_STATE_RUNNING */

/* 1234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Fcs_Media_State */

/* 1252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1260 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1262 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1266 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter FCS_STATE_RUNNING */

/* 1268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1274 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenP2Mxf */

/* 1286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1294 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1296 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1300 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1302 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenSonyMxf */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1328 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1330 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1334 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenAvi */

/* 1342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1352 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1356 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1358 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1362 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenWmv */

/* 1370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1378 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1380 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1384 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1386 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenMpeg2 */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x37 ),	/* 55 */
/* 1406 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1408 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1414 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1418 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 1426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x38 ),	/* 56 */
/* 1434 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1436 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1440 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter szTargetName */

/* 1442 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1446 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nTargetFormat */

/* 1448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1456 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenMpeg4 */

/* 1466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x39 ),	/* 57 */
/* 1474 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1476 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1480 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szpathName */

/* 1482 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1486 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2Avi */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x3a ),	/* 58 */
/* 1502 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1504 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1510 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1514 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2Mpeg2 */

/* 1528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1534 */	NdrFcShort( 0x3b ),	/* 59 */
/* 1536 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1538 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1542 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1544 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1546 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1548 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1550 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1552 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1558 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2Mpeg4 */

/* 1562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x3c ),	/* 60 */
/* 1570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1572 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1576 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1578 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1592 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2P2Mxf */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x3d ),	/* 61 */
/* 1604 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1606 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1610 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1612 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1616 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2SonyMxf */

/* 1630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x3e ),	/* 62 */
/* 1638 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1640 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1646 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1648 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1650 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1652 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1654 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1660 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save2Wmv */

/* 1664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x3f ),	/* 63 */
/* 1672 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1674 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1678 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter szTargetName */

/* 1680 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1684 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1694 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeyFramePath */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1708 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1712 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */

/* 1714 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1718 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Return value */

/* 1720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1722 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTMFormat */

/* 1726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1732 */	NdrFcShort( 0x41 ),	/* 65 */
/* 1734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1740 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter tmFormat */

/* 1742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1744 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Avi2Wmv */

/* 1754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x42 ),	/* 66 */
/* 1762 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1764 */	NdrFcShort( 0x3c ),	/* 60 */
/* 1766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1768 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter szSrcName */

/* 1770 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1774 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter szDestName */

/* 1776 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1780 */	0x5,		/* FC_WCHAR */
			0x0,		/* 0 */

	/* Parameter nOption */

/* 1782 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1784 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1788 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1790 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeyFrameBasicParams */

/* 1794 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1796 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x43 ),	/* 67 */
/* 1802 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1804 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1806 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1808 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter nWidth */

/* 1810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 1816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bOcr */

/* 1822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY1 */

/* 1828 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY2 */

/* 1834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1836 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szExportPath */

/* 1840 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1844 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1848 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEvent */

/* 1852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1860 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1862 */	NdrFcShort( 0x54 ),	/* 84 */
/* 1864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1866 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter iEvent */

/* 1868 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter L1 */

/* 1874 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter L2 */

/* 1880 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1882 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1888 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGraphPath */

/* 1892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x45 ),	/* 69 */
/* 1900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1906 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrGraphPath */

/* 1908 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1912 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBitRate */

/* 1920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x46 ),	/* 70 */
/* 1928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1930 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1934 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nBitRate */

/* 1936 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAudioLevel */

/* 1948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x47 ),	/* 71 */
/* 1956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1958 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nChannel */

/* 1964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1966 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nVolume */

/* 1970 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 1972 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1978 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2AudioCount */

/* 1982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x48 ),	/* 72 */
/* 1990 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1992 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1996 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCount */

/* 1998 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2006 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2VideoName */

/* 2010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x49 ),	/* 73 */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2024 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrVideoName */

/* 2026 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2030 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2AudioName */

/* 2038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x4a ),	/* 74 */
/* 2046 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2052 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nIndex */

/* 2054 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bstrAudioName */

/* 2060 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2064 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetP2AudioName */

/* 2072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x4b ),	/* 75 */
/* 2080 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2086 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrAudioName */

/* 2088 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2092 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RenderP2 */

/* 2100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2114 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 2116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2118 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Free */

/* 2122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2128 */	NdrFcShort( 0x4d ),	/* 77 */
/* 2130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2136 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 2138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure snapImage */

/* 2144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x4e ),	/* 78 */
/* 2152 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2158 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nIndex */

/* 2160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bstrImagename */

/* 2166 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2170 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2174 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeWindow */

/* 2178 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2184 */	NdrFcShort( 0x4f ),	/* 79 */
/* 2186 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2192 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter hWndHandle */

/* 2194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeHWnd */

/* 2206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2220 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 2222 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2226 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 2228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2230 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExportDir */


	/* Procedure LoadRun */

/* 2234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2240 */	NdrFcShort( 0x51 ),	/* 81 */
/* 2242 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2248 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter ExportDir */


	/* Parameter bstrGrfName */

/* 2250 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTemplateID */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x52 ),	/* 82 */
/* 2270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2276 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nTemplateID */

/* 2278 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2286 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSourceFile */

/* 2290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x53 ),	/* 83 */
/* 2298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2304 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrSourceName */

/* 2306 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2310 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForCompletion */

/* 2318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x54 ),	/* 84 */
/* 2326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2328 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2332 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nTimeOut */

/* 2334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2336 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pEvCode */

/* 2340 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2344 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddOverlay */

/* 2352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2358 */	NdrFcShort( 0x55 ),	/* 85 */
/* 2360 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2362 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2366 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter BstrOverlay */

/* 2368 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2372 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nLeft */

/* 2374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nTop */

/* 2380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nRight */

/* 2386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2388 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBottom */

/* 2392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2394 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nScaleToFit */

/* 2398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2400 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2406 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentTimeString */

/* 2410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x56 ),	/* 86 */
/* 2418 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2424 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrTime */

/* 2426 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2430 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCaneraFps */


	/* Procedure SetFullScreen */

/* 2438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x57 ),	/* 87 */
/* 2446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2452 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter FramePerSec */


	/* Parameter mode */

/* 2454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2456 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTcCode */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x58 ),	/* 88 */
/* 2474 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2476 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter timeNow */

/* 2482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2486 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter bstrTime */

/* 2488 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2490 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2492 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 2494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2496 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FrameToRefTime */

/* 2500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2506 */	NdrFcShort( 0x59 ),	/* 89 */
/* 2508 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2510 */	NdrFcShort( 0x2c ),	/* 44 */
/* 2512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2514 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nFrame */

/* 2516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2518 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter refTime */

/* 2522 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2524 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2526 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2528 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2532 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoInfo */

/* 2534 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2536 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x5a ),	/* 90 */
/* 2542 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2544 */	NdrFcShort( 0x5c ),	/* 92 */
/* 2546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2548 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nWidth */

/* 2550 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 2556 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dFps */

/* 2562 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2564 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2566 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 2568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegment */

/* 2574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x5b ),	/* 91 */
/* 2582 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2584 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2588 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nStart */

/* 2590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nEnd */

/* 2596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSegmentByMs */

/* 2608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2614 */	NdrFcShort( 0x5c ),	/* 92 */
/* 2616 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2618 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2622 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter timeBegin */

/* 2624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2628 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter timeEnd */

/* 2630 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2634 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 2636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2638 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRect */

/* 2642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x5d ),	/* 93 */
/* 2650 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2652 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2656 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 2658 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 2664 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 2670 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 2676 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2678 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2684 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceImg */

/* 2688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x5e ),	/* 94 */
/* 2696 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2698 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2702 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 2704 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2706 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2708 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 2710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceWidth */

/* 2722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2728 */	NdrFcShort( 0x5f ),	/* 95 */
/* 2730 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2732 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2736 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nWidth */

/* 2738 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceHeight */

/* 2750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2756 */	NdrFcShort( 0x60 ),	/* 96 */
/* 2758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2760 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2764 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nHeight */

/* 2766 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2768 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLeadFace */

/* 2778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x61 ),	/* 97 */
/* 2786 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2788 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2792 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pLeadFace */

/* 2794 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2798 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 2800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeRect */

/* 2806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x62 ),	/* 98 */
/* 2814 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2816 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2820 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 2822 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 2828 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 2834 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 2840 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2842 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2848 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeRect */

/* 2852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x63 ),	/* 99 */
/* 2860 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2862 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2866 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 2868 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 2874 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 2880 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2882 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 2886 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2888 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2894 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeImg */

/* 2898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x64 ),	/* 100 */
/* 2906 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2908 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2912 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 2914 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2918 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 2920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeImg */

/* 2932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2938 */	NdrFcShort( 0x65 ),	/* 101 */
/* 2940 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2942 */	NdrFcShort( 0x21 ),	/* 33 */
/* 2944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2946 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 2948 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2952 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 2954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2962 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballRect */

/* 2966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2972 */	NdrFcShort( 0x66 ),	/* 102 */
/* 2974 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2976 */	NdrFcShort( 0x70 ),	/* 112 */
/* 2978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2980 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 2982 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2984 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 2988 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 2994 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 3000 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3002 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3008 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeballRect */

/* 3012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0x67 ),	/* 103 */
/* 3020 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3022 */	NdrFcShort( 0x70 ),	/* 112 */
/* 3024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3026 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 3028 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 3034 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 3040 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3042 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3044 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 3046 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3048 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3054 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballImg */

/* 3058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3064 */	NdrFcShort( 0x68 ),	/* 104 */
/* 3066 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3068 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3072 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 3074 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3078 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 3080 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeballImg */

/* 3092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3098 */	NdrFcShort( 0x69 ),	/* 105 */
/* 3100 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3102 */	NdrFcShort( 0x21 ),	/* 33 */
/* 3104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3106 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 3108 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3112 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 3114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActivativedValue */

/* 3126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3132 */	NdrFcShort( 0x6a ),	/* 106 */
/* 3134 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3136 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3140 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dActivation */

/* 3142 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3146 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlinkCount */

/* 3154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x6b ),	/* 107 */
/* 3162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3164 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3168 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCount */

/* 3170 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTimeMs */

/* 3182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x6c ),	/* 108 */
/* 3190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3192 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3196 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter MilliSec */

/* 3198 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTime */

/* 3210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x6d ),	/* 109 */
/* 3218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3220 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3224 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter NSec */

/* 3226 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3230 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetCounter */

/* 3238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3244 */	NdrFcShort( 0x6e ),	/* 110 */
/* 3246 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3252 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 3254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCheck */

/* 3260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3266 */	NdrFcShort( 0x6f ),	/* 111 */
/* 3268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3270 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3274 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3280 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCheck */

/* 3288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0x70 ),	/* 112 */
/* 3296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3298 */	NdrFcShort( 0x1a ),	/* 26 */
/* 3300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3302 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 3304 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3306 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3308 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3312 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFaceRectLineWidth */

/* 3316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3322 */	NdrFcShort( 0x71 ),	/* 113 */
/* 3324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3330 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 3332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3336 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 3338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRectLineWidth */

/* 3344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x72 ),	/* 114 */
/* 3352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3354 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3358 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 3360 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3364 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 3366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEyeRectLineWidth */

/* 3372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x73 ),	/* 115 */
/* 3380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3386 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 3388 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3392 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 3394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3396 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEyeRectLineWidth */

/* 3400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x74 ),	/* 116 */
/* 3408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3410 */	NdrFcShort( 0x1c ),	/* 28 */
/* 3412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3414 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 3416 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3420 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 3422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisplayOverlay */

/* 3428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3434 */	NdrFcShort( 0x75 ),	/* 117 */
/* 3436 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3438 */	NdrFcShort( 0xe ),	/* 14 */
/* 3440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3442 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 3444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsVisible */

/* 3450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3454 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCountOfArray */

/* 3462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0x76 ),	/* 118 */
/* 3470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3476 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 3478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayPosition */

/* 3484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x77 ),	/* 119 */
/* 3492 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3494 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3498 */	0x4,		/* Oi2 Flags:  has return, */
			0x6,		/* 6 */

	/* Parameter nID */

/* 3500 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nLeft */

/* 3506 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nTop */

/* 3512 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nRight */

/* 3518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nButtom */

/* 3524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3526 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3532 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayColor */

/* 3536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3542 */	NdrFcShort( 0x78 ),	/* 120 */
/* 3544 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3546 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3550 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 3552 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nColor */

/* 3558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFontSize */

/* 3570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3576 */	NdrFcShort( 0x79 ),	/* 121 */
/* 3578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3580 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3584 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 3586 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3588 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFontSize */

/* 3592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3600 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFont */

/* 3604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3610 */	NdrFcShort( 0x7a ),	/* 122 */
/* 3612 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3614 */	NdrFcShort( 0x28 ),	/* 40 */
/* 3616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3618 */	0x4,		/* Oi2 Flags:  has return, */
			0x7,		/* 7 */

	/* Parameter nID */

/* 3620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3622 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFontStyle */

/* 3626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3628 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bUnderLine */

/* 3632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3636 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bWrap */

/* 3638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3640 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3642 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bVertical */

/* 3644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3646 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3648 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bRightAlign */

/* 3650 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3652 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3654 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3658 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayText */

/* 3662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3668 */	NdrFcShort( 0x7b ),	/* 123 */
/* 3670 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3676 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 3678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szText */

/* 3684 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3688 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 3690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3692 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFontName */

/* 3696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x7c ),	/* 124 */
/* 3704 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3710 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 3712 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szFontName */

/* 3718 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3722 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 3724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3726 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayImgPosition */

/* 3730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3736 */	NdrFcShort( 0x7d ),	/* 125 */
/* 3738 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3740 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3744 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x9,		/* 9 */

	/* Parameter szImgName */

/* 3746 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3750 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nLeft */

/* 3752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nTop */

/* 3758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nRight */

/* 3764 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3766 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nButtom */

/* 3770 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3772 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bDisplay */

/* 3776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3778 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3780 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bScaleFit */

/* 3782 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3784 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3786 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter nTranspency */

/* 3788 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3790 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3796 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFps */

/* 3800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3806 */	NdrFcShort( 0x7e ),	/* 126 */
/* 3808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3810 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3814 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dFps */

/* 3816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3820 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFps */

/* 3828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3834 */	NdrFcShort( 0x7f ),	/* 127 */
/* 3836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3838 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3842 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dFps */

/* 3844 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3846 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3848 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3852 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRate */

/* 3856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3862 */	NdrFcShort( 0x80 ),	/* 128 */
/* 3864 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3866 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3870 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pRate */

/* 3872 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 3874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3876 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 3878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEventWindow */

/* 3884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3890 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3892 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3898 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter hWnd */

/* 3900 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3904 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Parameter msg */

/* 3906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */


	/* Procedure Play */


	/* Procedure Pause */


	/* Procedure Pause */


	/* Procedure Run */

/* 3918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3926 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3932 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 3934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3936 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStandBy */


	/* Procedure TC_SetWindow */

/* 3940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3946 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3948 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3954 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nStatus */


	/* Parameter hParent */

/* 3956 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_SetSourceFile */

/* 3968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3974 */	NdrFcShort( 0xa ),	/* 10 */
/* 3976 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3978 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3982 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter szSourceName */

/* 3984 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3988 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nFormat */

/* 3990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSeg */

/* 3996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nStart */

/* 4002 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nEnd */

/* 4008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4010 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4016 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_SetSinkFile */

/* 4020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0xb ),	/* 11 */
/* 4028 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4034 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter szSinkName */

/* 4036 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4038 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4040 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nFormat */

/* 4042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4044 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4050 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_GetLength */

/* 4054 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4060 */	NdrFcShort( 0xc ),	/* 12 */
/* 4062 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4064 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4068 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nLength */

/* 4070 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4072 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4078 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_GetPosition */

/* 4082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4088 */	NdrFcShort( 0xe ),	/* 14 */
/* 4090 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4092 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4096 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter iPos */

/* 4098 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Init */


	/* Procedure TC_Stop */

/* 4110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4116 */	NdrFcShort( 0xf ),	/* 15 */
/* 4118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4124 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEvent */

/* 4132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4138 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4140 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4142 */	NdrFcShort( 0x54 ),	/* 84 */
/* 4144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4146 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter iEvent */

/* 4148 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter L1 */

/* 4154 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4156 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter L2 */

/* 4160 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4168 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Render */


	/* Procedure Render */


	/* Procedure TC_ShowConfig */

/* 4172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4178 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4186 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_Init */

/* 4194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4208 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 4210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TC_Render */

/* 4216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4230 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 4232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWindow */

/* 4238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4244 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4252 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 4254 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4258 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 4260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGraphPath */


	/* Procedure SetGraphPath */


	/* Procedure KF_KeyFrame */

/* 4266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4280 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrGraphPath */


	/* Parameter bstrGraphPath */


	/* Parameter bstrVideoName */

/* 4282 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4286 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4290 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeyFrameBasicParams */

/* 4294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4300 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4302 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4304 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4308 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter nWidth */

/* 4310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 4316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bOcr */

/* 4322 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY1 */

/* 4328 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4330 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY2 */

/* 4334 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4336 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szExportPath */

/* 4340 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4342 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4344 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4346 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4348 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveKFInfo */

/* 4352 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4354 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4358 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4366 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 4368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGraphPath */

/* 4374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4380 */	NdrFcShort( 0x19 ),	/* 25 */
/* 4382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4388 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrGraphPath */

/* 4390 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4394 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 4402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4408 */	NdrFcShort( 0x1a ),	/* 26 */
/* 4410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4416 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 4418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure State */

/* 4424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4430 */	NdrFcShort( 0x1b ),	/* 27 */
/* 4432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4434 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4438 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter state */

/* 4440 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4448 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2VideoName */

/* 4452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4458 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4460 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4466 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrVideoName */

/* 4468 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4472 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetP2AudioName */

/* 4480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4486 */	NdrFcShort( 0x21 ),	/* 33 */
/* 4488 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4494 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nIndex */

/* 4496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4498 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bstrAudioName */

/* 4502 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4504 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4506 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4508 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4510 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetP2AudioName */

/* 4514 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4516 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4520 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4528 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrAudioName */

/* 4530 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4532 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4534 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4538 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRange */

/* 4542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4548 */	NdrFcShort( 0x23 ),	/* 35 */
/* 4550 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4552 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4556 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nBeginFrame */

/* 4558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4560 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nEndFrame */

/* 4564 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4566 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSeg */

/* 4570 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadRun */

/* 4582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4588 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4596 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrGrfName */

/* 4598 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4602 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeWindow */

/* 4610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4616 */	NdrFcShort( 0x25 ),	/* 37 */
/* 4618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4624 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter hWndHandle */

/* 4626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4630 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4634 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeHWnd */

/* 4638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4644 */	NdrFcShort( 0x26 ),	/* 38 */
/* 4646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4652 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 4654 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4658 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 4660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4662 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDuration */

/* 4666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4672 */	NdrFcShort( 0x27 ),	/* 39 */
/* 4674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4676 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4680 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nDuration */

/* 4682 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4684 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4686 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4688 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4690 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForCompletion */

/* 4694 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4696 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4700 */	NdrFcShort( 0x28 ),	/* 40 */
/* 4702 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4704 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4708 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nTimeOut */

/* 4710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4712 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pEvCode */

/* 4716 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PackAvi */

/* 4728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4734 */	NdrFcShort( 0x29 ),	/* 41 */
/* 4736 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4742 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter bstrVideo */

/* 4744 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4748 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrAudio1 */

/* 4750 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4754 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrAudio2 */

/* 4756 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4760 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrAudio3 */

/* 4762 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4764 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4766 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrOutAvi */

/* 4768 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4770 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4772 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4776 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWindow */


	/* Procedure SetWindow */


	/* Procedure SetWindow */

/* 4780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4786 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4794 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter hParent */


	/* Parameter hParent */


	/* Parameter hParent */

/* 4796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */


	/* Procedure Stop */


	/* Procedure Stop */


	/* Procedure Stop */

/* 4808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4814 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4816 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4822 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 4824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4826 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPosition */


	/* Procedure GetPosition */

/* 4830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4836 */	NdrFcShort( 0xa ),	/* 10 */
/* 4838 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4840 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4844 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter iPos */


	/* Parameter iPos */

/* 4846 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 4852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4854 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Seek */


	/* Procedure Seek */

/* 4858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4864 */	NdrFcShort( 0xb ),	/* 11 */
/* 4866 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4872 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter iPos */


	/* Parameter iPos */

/* 4874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 4880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWindowPosition */


	/* Procedure SetWindowPosition */

/* 4886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4892 */	NdrFcShort( 0xd ),	/* 13 */
/* 4894 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4896 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4900 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter top */


	/* Parameter top */

/* 4902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter left */


	/* Parameter left */

/* 4908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Width */


	/* Parameter Width */

/* 4914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4916 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Height */


	/* Parameter Height */

/* 4920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4922 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 4926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4928 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFile */


	/* Procedure SetFile */

/* 4932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4938 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4946 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter szPathName */


	/* Parameter szPathName */

/* 4948 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 4950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4952 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */

/* 4954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure State */


	/* Procedure GetLength */


	/* Procedure GetLength */

/* 4960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4966 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4970 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4974 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nState */


	/* Parameter nLength */


	/* Parameter nLength */

/* 4976 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeWindow */


	/* Procedure SetOption */


	/* Procedure SetOption */

/* 4988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4994 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5002 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter hWndHandle */


	/* Parameter nOption */


	/* Parameter nOption */

/* 5004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5006 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 5010 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5012 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAudio */


	/* Procedure GetAudio */

/* 5016 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5026 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5028 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5030 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nChannelID */


	/* Parameter nChannelID */

/* 5032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nVolume */


	/* Parameter nVolume */

/* 5038 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5040 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPosition */


	/* Procedure SetPosition */

/* 5050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5056 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5058 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5060 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5064 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pos */


	/* Parameter pos */

/* 5066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5068 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5070 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSinkFile */


	/* Procedure SetSinkFile */

/* 5078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5084 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5086 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5088 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5092 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter bstrPathName */


	/* Parameter bstrPathName */

/* 5094 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5098 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrPathName1 */


	/* Parameter bstrPathName1 */

/* 5100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5104 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nTemplateID */


	/* Parameter nTemplateID */

/* 5106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5108 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFileNo */


	/* Parameter nFileNo */

/* 5112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5114 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5120 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHWnd */


	/* Procedure SetHWnd */

/* 5124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5130 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5132 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5138 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */


	/* Parameter hWnd */

/* 5140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5144 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */


	/* Return value */

/* 5146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateVideoWindow */


	/* Procedure UpdateVideoWindow */

/* 5152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5158 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5162 */	NdrFcShort( 0x34 ),	/* 52 */
/* 5164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5166 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter prc */


	/* Parameter prc */

/* 5168 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5172 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Return value */


	/* Return value */

/* 5174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoSize */


	/* Procedure GetVideoSize */

/* 5180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5186 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5188 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5190 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5194 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter lpWidth */


	/* Parameter lpWidth */

/* 5196 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpHeight */


	/* Parameter lpHeight */

/* 5202 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARWidth */


	/* Parameter lpARWidth */

/* 5208 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARHeight */


	/* Parameter lpARHeight */

/* 5214 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5216 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5222 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Repaint */


	/* Procedure Repaint */

/* 5226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5232 */	NdrFcShort( 0x1b ),	/* 27 */
/* 5234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5240 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hdc */


	/* Parameter hdc */

/* 5242 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5244 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5246 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */


	/* Return value */

/* 5248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5250 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Record */


	/* Procedure Record */

/* 5254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5260 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5268 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 5270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateWindow */


	/* Procedure UpdateWindow */

/* 5276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5282 */	NdrFcShort( 0x1d ),	/* 29 */
/* 5284 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5286 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5290 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */


	/* Parameter left */

/* 5292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5294 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */


	/* Parameter top */

/* 5298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5300 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */


	/* Parameter right */

/* 5304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5306 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */


	/* Parameter bottom */

/* 5310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5312 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5318 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure State */


	/* Procedure State */

/* 5322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5328 */	NdrFcShort( 0x1e ),	/* 30 */
/* 5330 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5332 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5336 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nState */


	/* Parameter nState */

/* 5338 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAudioLevel */


	/* Procedure GetAudioLevel */

/* 5350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5356 */	NdrFcShort( 0x1f ),	/* 31 */
/* 5358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5360 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5364 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nChannel */


	/* Parameter nChannel */

/* 5366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nVolume */


	/* Parameter nVolume */

/* 5372 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetKeyFrameBasicParams */


	/* Procedure SetKeyFrameBasicParams */

/* 5384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5390 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5392 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5394 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5398 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter nWidth */


	/* Parameter nWidth */

/* 5400 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */


	/* Parameter nHeight */

/* 5406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bOcr */


	/* Parameter bOcr */

/* 5412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY1 */


	/* Parameter nOcrY1 */

/* 5418 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5420 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nOcrY2 */


	/* Parameter nOcrY2 */

/* 5424 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5426 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szExportPath */


	/* Parameter szExportPath */

/* 5430 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5432 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5434 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */

/* 5436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5438 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeHWnd */

/* 5442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5448 */	NdrFcShort( 0x23 ),	/* 35 */
/* 5450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5456 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 5458 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5462 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 5464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGraphPath */

/* 5470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5476 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5484 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter strGraphPath */

/* 5486 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5490 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 5492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMute */

/* 5498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5504 */	NdrFcShort( 0x25 ),	/* 37 */
/* 5506 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5508 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5512 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bMute */

/* 5514 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5518 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoFps */

/* 5526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5532 */	NdrFcShort( 0x26 ),	/* 38 */
/* 5534 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5536 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5540 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dFps */

/* 5542 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5546 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 5548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFullScreen */

/* 5554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5560 */	NdrFcShort( 0x27 ),	/* 39 */
/* 5562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5564 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5568 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 5570 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5574 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter nState */

/* 5576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5580 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5584 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SnapImage */

/* 5588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5594 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5596 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5598 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5602 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter bstrImagename */

/* 5604 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 5606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5608 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nNewWidth */

/* 5610 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5612 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nNewHeight */

/* 5616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5624 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_GetPosition */

/* 5628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5634 */	NdrFcShort( 0x29 ),	/* 41 */
/* 5636 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5638 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5642 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nIndex */

/* 5644 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentPosition */

/* 5656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5662 */	NdrFcShort( 0x2a ),	/* 42 */
/* 5664 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5666 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5670 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pTimeNow */

/* 5672 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5676 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRect */

/* 5684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5690 */	NdrFcShort( 0x2b ),	/* 43 */
/* 5692 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5694 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5698 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 5700 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 5706 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 5712 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5714 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 5718 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5720 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5726 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceWidth */

/* 5730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5736 */	NdrFcShort( 0x2c ),	/* 44 */
/* 5738 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5740 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5744 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nWidth */

/* 5746 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5752 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceHeight */

/* 5758 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5760 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5764 */	NdrFcShort( 0x2d ),	/* 45 */
/* 5766 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5768 */	NdrFcShort( 0x1c ),	/* 28 */
/* 5770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5772 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nHeight */

/* 5774 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeRect */

/* 5786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5792 */	NdrFcShort( 0x2e ),	/* 46 */
/* 5794 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5796 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5800 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 5802 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5804 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 5808 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 5814 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 5820 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5822 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5828 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeRect */

/* 5832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5838 */	NdrFcShort( 0x2f ),	/* 47 */
/* 5840 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5842 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5846 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 5848 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 5854 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 5860 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 5866 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5868 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5874 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballRect */

/* 5878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5884 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5886 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5888 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5892 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 5894 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5896 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 5900 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 5906 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5908 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 5912 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5914 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5920 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRect */


	/* Procedure GetREyeballRect */

/* 5924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5930 */	NdrFcShort( 0x31 ),	/* 49 */
/* 5932 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5934 */	NdrFcShort( 0x70 ),	/* 112 */
/* 5936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5938 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */


	/* Parameter left */

/* 5940 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5942 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */


	/* Parameter top */

/* 5946 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5948 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */


	/* Parameter right */

/* 5952 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5954 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */


	/* Parameter bottom */

/* 5958 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5960 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 5964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5966 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceImg */

/* 5970 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5976 */	NdrFcShort( 0x32 ),	/* 50 */
/* 5978 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5980 */	NdrFcShort( 0x21 ),	/* 33 */
/* 5982 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5984 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 5986 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 5988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5990 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 5992 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5994 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6000 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeImg */

/* 6004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6010 */	NdrFcShort( 0x33 ),	/* 51 */
/* 6012 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6014 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6018 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 6020 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6024 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 6026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeImg */

/* 6038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6044 */	NdrFcShort( 0x34 ),	/* 52 */
/* 6046 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6048 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6052 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 6054 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6058 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 6060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballImg */

/* 6072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6078 */	NdrFcShort( 0x35 ),	/* 53 */
/* 6080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6082 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6086 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 6088 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6090 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6092 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 6094 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6096 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeballImg */

/* 6106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6112 */	NdrFcShort( 0x36 ),	/* 54 */
/* 6114 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6116 */	NdrFcShort( 0x21 ),	/* 33 */
/* 6118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6120 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 6122 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6126 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 6128 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6136 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLeadFace */

/* 6140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6146 */	NdrFcShort( 0x37 ),	/* 55 */
/* 6148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6150 */	NdrFcShort( 0x19 ),	/* 25 */
/* 6152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6154 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pLeadFace */

/* 6156 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6160 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 6162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActivativedValue */

/* 6168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6174 */	NdrFcShort( 0x38 ),	/* 56 */
/* 6176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6178 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6182 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dActivation */

/* 6184 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6188 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 6190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlinkCount */

/* 6196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6202 */	NdrFcShort( 0x39 ),	/* 57 */
/* 6204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6206 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6210 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCount */

/* 6212 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6220 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTimeMs */

/* 6224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6230 */	NdrFcShort( 0x3a ),	/* 58 */
/* 6232 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6234 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6238 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter MilliSec */

/* 6240 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTime */

/* 6252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6258 */	NdrFcShort( 0x3b ),	/* 59 */
/* 6260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6262 */	NdrFcShort( 0x24 ),	/* 36 */
/* 6264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6266 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter NSec */

/* 6268 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6272 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetCounter */

/* 6280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6286 */	NdrFcShort( 0x3c ),	/* 60 */
/* 6288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6294 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 6296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCheck */

/* 6302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6308 */	NdrFcShort( 0x3d ),	/* 61 */
/* 6310 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6312 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6316 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 6318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6322 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCheck */

/* 6330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6336 */	NdrFcShort( 0x3e ),	/* 62 */
/* 6338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6340 */	NdrFcShort( 0x1a ),	/* 26 */
/* 6342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6344 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 6346 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6348 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6350 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6354 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFaceRectLineWidth */

/* 6358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6364 */	NdrFcShort( 0x3f ),	/* 63 */
/* 6366 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6372 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 6374 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6378 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 6380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRectLineWidth */

/* 6386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6392 */	NdrFcShort( 0x40 ),	/* 64 */
/* 6394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6396 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6400 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 6402 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6406 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 6408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEyeRectLineWidth */

/* 6414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6420 */	NdrFcShort( 0x41 ),	/* 65 */
/* 6422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6428 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 6430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6432 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6434 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 6436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6438 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEyeRectLineWidth */

/* 6442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6448 */	NdrFcShort( 0x42 ),	/* 66 */
/* 6450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6452 */	NdrFcShort( 0x1c ),	/* 28 */
/* 6454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6456 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 6458 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 6460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6462 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 6464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DisPlayOverlay */

/* 6470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6476 */	NdrFcShort( 0x43 ),	/* 67 */
/* 6478 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6480 */	NdrFcShort( 0xe ),	/* 14 */
/* 6482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6484 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 6486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter IsVisible */

/* 6492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6496 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6500 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCountOfArray */

/* 6504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6510 */	NdrFcShort( 0x44 ),	/* 68 */
/* 6512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6518 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 6520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayPosition */

/* 6526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6532 */	NdrFcShort( 0x45 ),	/* 69 */
/* 6534 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6536 */	NdrFcShort( 0x28 ),	/* 40 */
/* 6538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6540 */	0x4,		/* Oi2 Flags:  has return, */
			0x6,		/* 6 */

	/* Parameter nId */

/* 6542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nLeft */

/* 6548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nTop */

/* 6554 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6556 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nRight */

/* 6560 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nBottom */

/* 6566 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6568 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6574 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayColor */

/* 6578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6584 */	NdrFcShort( 0x46 ),	/* 70 */
/* 6586 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6588 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6592 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 6594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nColor */

/* 6600 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFontSize */

/* 6612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6618 */	NdrFcShort( 0x47 ),	/* 71 */
/* 6620 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6622 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6626 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 6628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFontSize */

/* 6634 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFont */

/* 6646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6652 */	NdrFcShort( 0x48 ),	/* 72 */
/* 6654 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6656 */	NdrFcShort( 0x28 ),	/* 40 */
/* 6658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6660 */	0x4,		/* Oi2 Flags:  has return, */
			0x7,		/* 7 */

	/* Parameter nID */

/* 6662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFontStyle */

/* 6668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bUnderLine */

/* 6674 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6678 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bWrap */

/* 6680 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6682 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6684 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bVertical */

/* 6686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6688 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6690 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bRightAlign */

/* 6692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6694 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6696 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6700 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayText */

/* 6704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6710 */	NdrFcShort( 0x49 ),	/* 73 */
/* 6712 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6718 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 6720 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szText */

/* 6726 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6730 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 6732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayFontName */

/* 6738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6744 */	NdrFcShort( 0x4a ),	/* 74 */
/* 6746 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6752 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter nID */

/* 6754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter szFontName */

/* 6760 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6764 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 6766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOverlayImgPosition */

/* 6772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6778 */	NdrFcShort( 0x4b ),	/* 75 */
/* 6780 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 6782 */	NdrFcShort( 0x34 ),	/* 52 */
/* 6784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6786 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x9,		/* 9 */

	/* Parameter szImgName */

/* 6788 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 6790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6792 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter left */

/* 6794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6796 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 6800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6802 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 6806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6808 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 6812 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6814 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bDisplay */

/* 6818 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6820 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6822 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter bScaleFit */

/* 6824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6826 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 6828 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter nTranspency */

/* 6830 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6832 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 6834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6836 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6838 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 6840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnableRoi */

/* 6842 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6844 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6848 */	NdrFcShort( 0x4c ),	/* 76 */
/* 6850 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6852 */	NdrFcShort( 0x6 ),	/* 6 */
/* 6854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6856 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Enable */

/* 6858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6862 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6864 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRoi */

/* 6870 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6872 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6876 */	NdrFcShort( 0x4d ),	/* 77 */
/* 6878 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6880 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6884 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 6886 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6888 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 6892 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6894 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 6898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6900 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 6904 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6906 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6912 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowRoi */

/* 6916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6922 */	NdrFcShort( 0x4e ),	/* 78 */
/* 6924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6930 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 6932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRoiProp */

/* 6938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6944 */	NdrFcShort( 0x4f ),	/* 79 */
/* 6946 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 6948 */	NdrFcShort( 0x20 ),	/* 32 */
/* 6950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6952 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter nColor */

/* 6954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6956 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 6958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter PenStyle */

/* 6960 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 6964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter LineWidth */

/* 6966 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 6970 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ShapeType */

/* 6972 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 6974 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 6976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 6978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6980 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SnapGrayImage */

/* 6984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6990 */	NdrFcShort( 0x50 ),	/* 80 */
/* 6992 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 6994 */	NdrFcShort( 0x10 ),	/* 16 */
/* 6996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 6998 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter bstrImagename */

/* 7000 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7002 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7004 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nNewWidth */

/* 7006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7008 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nNewHeight */

/* 7012 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7014 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7018 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7020 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7022 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExportName */

/* 7024 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7026 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7030 */	NdrFcShort( 0x52 ),	/* 82 */
/* 7032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7038 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter ImageName */

/* 7040 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7042 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7044 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 7046 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7048 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7050 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExportImageWidth */

/* 7052 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7054 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7058 */	NdrFcShort( 0x53 ),	/* 83 */
/* 7060 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7066 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Width */

/* 7068 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExportImageHeight */

/* 7080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7086 */	NdrFcShort( 0x54 ),	/* 84 */
/* 7088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7094 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Height */

/* 7096 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCompressRatio */

/* 7108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7114 */	NdrFcShort( 0x55 ),	/* 85 */
/* 7116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7122 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Ratio */

/* 7124 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7132 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCaptureFreq */

/* 7136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7142 */	NdrFcShort( 0x56 ),	/* 86 */
/* 7144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7150 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Freq */

/* 7152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnableCapture */

/* 7164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7170 */	NdrFcShort( 0x58 ),	/* 88 */
/* 7172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7178 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter Enable */

/* 7180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForCompletion */

/* 7192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7198 */	NdrFcShort( 0x59 ),	/* 89 */
/* 7200 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7202 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7206 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nTimeout */

/* 7208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter evtCode */

/* 7214 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7222 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDVMode */

/* 7226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7232 */	NdrFcShort( 0x23 ),	/* 35 */
/* 7234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7236 */	NdrFcShort( 0x1c ),	/* 28 */
/* 7238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7240 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nDvMode */

/* 7242 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7244 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7250 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeWindow */

/* 7254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7260 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7268 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter hWndHandle */

/* 7270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7278 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeHWnd */

/* 7282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7288 */	NdrFcShort( 0x25 ),	/* 37 */
/* 7290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7296 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 7298 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 7300 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7302 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 7304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7306 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PowerOn */

/* 7310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7316 */	NdrFcShort( 0x26 ),	/* 38 */
/* 7318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7324 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 7326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7328 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PowerOff */

/* 7332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7338 */	NdrFcShort( 0x27 ),	/* 39 */
/* 7340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7346 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 7348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StandBy */

/* 7354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7360 */	NdrFcShort( 0x28 ),	/* 40 */
/* 7362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7368 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 7370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7372 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDvRate */

/* 7376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7382 */	NdrFcShort( 0x29 ),	/* 41 */
/* 7384 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7390 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nRate */

/* 7392 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7394 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDvRate */

/* 7404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7410 */	NdrFcShort( 0x2a ),	/* 42 */
/* 7412 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7414 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7418 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dRate */

/* 7420 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7424 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGraphPath */

/* 7432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7438 */	NdrFcShort( 0x2b ),	/* 43 */
/* 7440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 7444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7446 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter strGraphPath */

/* 7448 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 7450 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7452 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 7454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsMute */

/* 7460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7466 */	NdrFcShort( 0x2c ),	/* 44 */
/* 7468 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7470 */	NdrFcShort( 0x1a ),	/* 26 */
/* 7472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7474 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bMute */

/* 7476 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7478 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7480 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 7482 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7484 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoFps */

/* 7488 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7494 */	NdrFcShort( 0x2d ),	/* 45 */
/* 7496 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7498 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7502 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dFps */

/* 7504 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7508 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 7510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MP_GetPosition */

/* 7516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7522 */	NdrFcShort( 0x2f ),	/* 47 */
/* 7524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7526 */	NdrFcShort( 0x1c ),	/* 28 */
/* 7528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7530 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nIndex */

/* 7532 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7534 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7540 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurrentPosition */

/* 7544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7550 */	NdrFcShort( 0x30 ),	/* 48 */
/* 7552 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7554 */	NdrFcShort( 0x24 ),	/* 36 */
/* 7556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7558 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pTimeNow */

/* 7560 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7564 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 7566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceWidth */

/* 7572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7578 */	NdrFcShort( 0x32 ),	/* 50 */
/* 7580 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7582 */	NdrFcShort( 0x1c ),	/* 28 */
/* 7584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7586 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nWidth */

/* 7588 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceHeight */

/* 7600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7606 */	NdrFcShort( 0x33 ),	/* 51 */
/* 7608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7610 */	NdrFcShort( 0x1c ),	/* 28 */
/* 7612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7614 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nHeight */

/* 7616 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7618 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7624 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeRect */

/* 7628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7634 */	NdrFcShort( 0x34 ),	/* 52 */
/* 7636 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7638 */	NdrFcShort( 0x70 ),	/* 112 */
/* 7640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7642 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 7644 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 7650 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 7656 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 7662 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7664 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7670 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeRect */

/* 7674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7680 */	NdrFcShort( 0x35 ),	/* 53 */
/* 7682 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7684 */	NdrFcShort( 0x70 ),	/* 112 */
/* 7686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7688 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 7690 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 7696 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 7702 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 7708 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7716 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballRect */

/* 7720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7726 */	NdrFcShort( 0x36 ),	/* 54 */
/* 7728 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7730 */	NdrFcShort( 0x70 ),	/* 112 */
/* 7732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7734 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 7736 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 7742 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 7748 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 7754 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7762 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeballRect */

/* 7766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7772 */	NdrFcShort( 0x37 ),	/* 55 */
/* 7774 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 7776 */	NdrFcShort( 0x70 ),	/* 112 */
/* 7778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7780 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 7782 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7784 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 7788 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7790 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 7794 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7796 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 7800 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7802 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7808 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 7810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceImg */

/* 7812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7818 */	NdrFcShort( 0x38 ),	/* 56 */
/* 7820 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7822 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7826 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 7828 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7832 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 7834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeImg */

/* 7846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7852 */	NdrFcShort( 0x39 ),	/* 57 */
/* 7854 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7856 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7860 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 7862 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7864 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7866 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 7868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7876 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeImg */

/* 7880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7886 */	NdrFcShort( 0x3a ),	/* 58 */
/* 7888 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7890 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7894 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 7896 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7898 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7900 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 7902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7904 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7910 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLEyeballImg */

/* 7914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7920 */	NdrFcShort( 0x3b ),	/* 59 */
/* 7922 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7924 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7928 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 7930 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7932 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7934 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 7936 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7938 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7944 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetREyeballImg */

/* 7948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7954 */	NdrFcShort( 0x3c ),	/* 60 */
/* 7956 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 7958 */	NdrFcShort( 0x21 ),	/* 33 */
/* 7960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7962 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter pImage */

/* 7964 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 7966 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 7968 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 7970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 7972 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 7974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 7976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 7978 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLeadFace */

/* 7982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 7984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 7988 */	NdrFcShort( 0x3d ),	/* 61 */
/* 7990 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 7992 */	NdrFcShort( 0x19 ),	/* 25 */
/* 7994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 7996 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pLeadFace */

/* 7998 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8002 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 8004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8006 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetActivativedValue */

/* 8010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8016 */	NdrFcShort( 0x3e ),	/* 62 */
/* 8018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8020 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8024 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter dActivation */

/* 8026 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8030 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 8032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBlinkCount */

/* 8038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8044 */	NdrFcShort( 0x3f ),	/* 63 */
/* 8046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8048 */	NdrFcShort( 0x1c ),	/* 28 */
/* 8050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8052 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCount */

/* 8054 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8060 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTimeMs */

/* 8066 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8068 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8072 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8076 */	NdrFcShort( 0x1c ),	/* 28 */
/* 8078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8080 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter MilliSec */

/* 8082 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurTime */

/* 8094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8100 */	NdrFcShort( 0x41 ),	/* 65 */
/* 8102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8104 */	NdrFcShort( 0x24 ),	/* 36 */
/* 8106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8108 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter NSec */

/* 8110 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8114 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 8116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetCounter */

/* 8122 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8128 */	NdrFcShort( 0x42 ),	/* 66 */
/* 8130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 8134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8136 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 8138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCheck */

/* 8144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8150 */	NdrFcShort( 0x43 ),	/* 67 */
/* 8152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8154 */	NdrFcShort( 0x6 ),	/* 6 */
/* 8156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8158 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 8160 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8164 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCheck */

/* 8172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8178 */	NdrFcShort( 0x44 ),	/* 68 */
/* 8180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8182 */	NdrFcShort( 0x1a ),	/* 26 */
/* 8184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8186 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCheck */

/* 8188 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8192 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 8194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8196 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFaceRectLineWidth */

/* 8200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8206 */	NdrFcShort( 0x45 ),	/* 69 */
/* 8208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8214 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 8216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8220 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 8222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFaceRectLineWidth */

/* 8228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8234 */	NdrFcShort( 0x46 ),	/* 70 */
/* 8236 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8238 */	NdrFcShort( 0x1c ),	/* 28 */
/* 8240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8242 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 8244 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8248 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 8250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8252 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetEyeRectLineWidth */

/* 8256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8262 */	NdrFcShort( 0x47 ),	/* 71 */
/* 8264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8270 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 8272 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8276 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 8278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEyeRectLineWidth */

/* 8284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8290 */	NdrFcShort( 0x48 ),	/* 72 */
/* 8292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8294 */	NdrFcShort( 0x1c ),	/* 28 */
/* 8296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8298 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter fLineWidth */

/* 8300 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8304 */	0xa,		/* FC_FLOAT */
			0x0,		/* 0 */

	/* Return value */

/* 8306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 8312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8318 */	NdrFcShort( 0x7 ),	/* 7 */
/* 8320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8322 */	NdrFcShort( 0x1c ),	/* 28 */
/* 8324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8326 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nResult */

/* 8328 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8330 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 8340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8354 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nStatus */

/* 8356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Play */

/* 8368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8374 */	NdrFcShort( 0xa ),	/* 10 */
/* 8376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8378 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8382 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8384 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8390 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stop */

/* 8402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8408 */	NdrFcShort( 0xb ),	/* 11 */
/* 8410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8412 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8416 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8418 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8424 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8428 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TogglePlayStop */

/* 8436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8442 */	NdrFcShort( 0xc ),	/* 12 */
/* 8444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8446 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8450 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8452 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8458 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Eject */

/* 8470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8476 */	NdrFcShort( 0xd ),	/* 13 */
/* 8478 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8480 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8484 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8486 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8488 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8492 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8494 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8500 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GotoTimeCode */

/* 8504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8510 */	NdrFcShort( 0xe ),	/* 14 */
/* 8512 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8514 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8518 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter bstrTimeCode */

/* 8520 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 8522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8524 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nResult */

/* 8526 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8532 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8534 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FastForward */

/* 8544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8550 */	NdrFcShort( 0xf ),	/* 15 */
/* 8552 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8554 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8558 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8560 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8566 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Rewind */

/* 8578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8584 */	NdrFcShort( 0x10 ),	/* 16 */
/* 8586 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8588 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8592 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8594 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8600 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8602 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StepForward */

/* 8612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8618 */	NdrFcShort( 0x11 ),	/* 17 */
/* 8620 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8622 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8626 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8628 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8634 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StepBack */

/* 8646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8652 */	NdrFcShort( 0x12 ),	/* 18 */
/* 8654 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8656 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8660 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 8662 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8664 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8668 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8670 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8676 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Jog */

/* 8680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8686 */	NdrFcShort( 0x13 ),	/* 19 */
/* 8688 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8690 */	NdrFcShort( 0x48 ),	/* 72 */
/* 8692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8694 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nRate */

/* 8696 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8700 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8702 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8708 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8716 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Shuttle */

/* 8720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8726 */	NdrFcShort( 0x14 ),	/* 20 */
/* 8728 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 8730 */	NdrFcShort( 0x48 ),	/* 72 */
/* 8732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8734 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nRate */

/* 8736 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8740 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8742 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8744 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8748 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8750 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8756 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTimeCode */

/* 8760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8766 */	NdrFcShort( 0x15 ),	/* 21 */
/* 8768 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8770 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8774 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter bstrTimeCode */

/* 8776 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 8778 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8780 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nResult */

/* 8782 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8784 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8788 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8792 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8796 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPreroll */

/* 8800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8806 */	NdrFcShort( 0x16 ),	/* 22 */
/* 8808 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8810 */	NdrFcShort( 0x40 ),	/* 64 */
/* 8812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8814 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nSecond */

/* 8816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8822 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8828 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8830 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8836 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreroll */

/* 8840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8846 */	NdrFcShort( 0x17 ),	/* 23 */
/* 8848 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 8850 */	NdrFcShort( 0x54 ),	/* 84 */
/* 8852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8854 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nSecond */

/* 8856 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8862 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 8868 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8870 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8876 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCaptureOffset */

/* 8880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8886 */	NdrFcShort( 0x18 ),	/* 24 */
/* 8888 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8894 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nCaptureOffset */

/* 8896 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8898 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8904 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCaptureOffset */

/* 8908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8914 */	NdrFcShort( 0x19 ),	/* 25 */
/* 8916 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8918 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8922 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nCaptureOffset */

/* 8924 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8930 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8932 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExportOffset */

/* 8942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8948 */	NdrFcShort( 0x1a ),	/* 26 */
/* 8950 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 8952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8956 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nExportOffset */

/* 8958 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 8960 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8962 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 8966 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetExportOffset */

/* 8970 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 8972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 8976 */	NdrFcShort( 0x1b ),	/* 27 */
/* 8978 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 8980 */	NdrFcShort( 0x38 ),	/* 56 */
/* 8982 */	NdrFcShort( 0x8 ),	/* 8 */
/* 8984 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nExportOffset */

/* 8986 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8988 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 8990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 8992 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 8994 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 8996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 8998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9000 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetManualExportOffset */

/* 9004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9010 */	NdrFcShort( 0x1c ),	/* 28 */
/* 9012 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9014 */	NdrFcShort( 0x38 ),	/* 56 */
/* 9016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9018 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nExportOffset */

/* 9020 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 9026 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartExport */

/* 9038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9044 */	NdrFcShort( 0x1d ),	/* 29 */
/* 9046 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9048 */	NdrFcShort( 0x38 ),	/* 56 */
/* 9050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9052 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter bstrInPoint */

/* 9054 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9056 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9058 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrOutPoint */

/* 9060 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9062 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9064 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nResult */

/* 9066 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9068 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 9072 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9074 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9080 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StartCapture */

/* 9084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9090 */	NdrFcShort( 0x1e ),	/* 30 */
/* 9092 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 9094 */	NdrFcShort( 0x40 ),	/* 64 */
/* 9096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9098 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter useVITC */

/* 9100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bstrInPoint */

/* 9106 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9110 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrOutPoint */

/* 9112 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9116 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nResult */

/* 9118 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 9124 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9126 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9132 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDeviceID */

/* 9136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9142 */	NdrFcShort( 0x1f ),	/* 31 */
/* 9144 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9146 */	NdrFcShort( 0x54 ),	/* 84 */
/* 9148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9150 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter nDeviceID */

/* 9152 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nResult */

/* 9158 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 9164 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9172 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Abort */

/* 9176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9182 */	NdrFcShort( 0x20 ),	/* 32 */
/* 9184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9186 */	NdrFcShort( 0x1c ),	/* 28 */
/* 9188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9190 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nResult */

/* 9192 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CrashRecordStart */

/* 9204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9210 */	NdrFcShort( 0x21 ),	/* 33 */
/* 9212 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9214 */	NdrFcShort( 0x38 ),	/* 56 */
/* 9216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9218 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 9220 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 9226 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CrashRecordStop */

/* 9238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9244 */	NdrFcShort( 0x22 ),	/* 34 */
/* 9246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9248 */	NdrFcShort( 0x38 ),	/* 56 */
/* 9250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9252 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nResult */

/* 9254 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errCode */

/* 9260 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenPort */

/* 9272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9278 */	NdrFcShort( 0x7 ),	/* 7 */
/* 9280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9286 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter portName */

/* 9288 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9292 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 9294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClosePort */

/* 9300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9306 */	NdrFcShort( 0xa ),	/* 10 */
/* 9308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9314 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 9316 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Free */


	/* Procedure Eject */

/* 9322 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9328 */	NdrFcShort( 0xb ),	/* 11 */
/* 9330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9336 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 9338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetWindowPosition */

/* 9344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9350 */	NdrFcShort( 0xa ),	/* 10 */
/* 9352 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9354 */	NdrFcShort( 0x20 ),	/* 32 */
/* 9356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9358 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter top */

/* 9360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter left */

/* 9366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Width */

/* 9372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Height */

/* 9378 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9380 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9386 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGraphPath */

/* 9390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9396 */	NdrFcShort( 0xe ),	/* 14 */
/* 9398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9404 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter bstrGraphPath */

/* 9406 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9410 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 9412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9414 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSinkFile */

/* 9418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9424 */	NdrFcShort( 0xf ),	/* 15 */
/* 9426 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9428 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9432 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter bstrPathName */

/* 9434 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9438 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter bstrPathName1 */

/* 9440 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9444 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter nTemplateID */

/* 9446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nFileNo */

/* 9452 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9454 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9460 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVideoSize */

/* 9464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9470 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9472 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9474 */	NdrFcShort( 0x70 ),	/* 112 */
/* 9476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9478 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter lpWidth */

/* 9480 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpHeight */

/* 9486 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARwidth */

/* 9492 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpARHeight */

/* 9498 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 9500 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9506 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateWindow */

/* 9510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9516 */	NdrFcShort( 0x11 ),	/* 17 */
/* 9518 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 9520 */	NdrFcShort( 0x20 ),	/* 32 */
/* 9522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9524 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter left */

/* 9526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9528 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter top */

/* 9532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter right */

/* 9538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bottom */

/* 9544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9546 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9552 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SnapImage */

/* 9556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9562 */	NdrFcShort( 0x15 ),	/* 21 */
/* 9564 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 9566 */	NdrFcShort( 0x10 ),	/* 16 */
/* 9568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9570 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter ImageName */

/* 9572 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9574 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9576 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter Width */

/* 9578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9580 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Height */

/* 9584 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 9586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 9590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9592 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 9594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeHWnd */

/* 9596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9602 */	NdrFcShort( 0x16 ),	/* 22 */
/* 9604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 9608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9610 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter hWnd */

/* 9612 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 9614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9616 */	NdrFcShort( 0x1a ),	/* Type Offset=26 */

	/* Return value */

/* 9618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateVideoWindow */

/* 9624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 9626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 9630 */	NdrFcShort( 0x17 ),	/* 23 */
/* 9632 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 9634 */	NdrFcShort( 0x34 ),	/* 52 */
/* 9636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 9638 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter prc */

/* 9640 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 9642 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 9644 */	NdrFcShort( 0x46 ),	/* Type Offset=70 */

	/* Return value */

/* 9646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 9648 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 9650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const FcsMedia_MIDL_TYPE_FORMAT_STRING FcsMedia__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x0,	/* FC_UP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/*  8 */	NdrFcShort( 0x4 ),	/* 4 */
/* 10 */	NdrFcShort( 0x2 ),	/* 2 */
/* 12 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 16 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 18 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 22 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 24 */	NdrFcShort( 0xffff ),	/* Offset= -1 (23) */
/* 26 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */
/* 30 */	NdrFcShort( 0x4 ),	/* 4 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (2) */
/* 36 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 38 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 40 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 42 */	0x5,		/* FC_WCHAR */
			0x5c,		/* FC_PAD */
/* 44 */	
			0x11, 0x0,	/* FC_RP */
/* 46 */	NdrFcShort( 0x8 ),	/* Offset= 8 (54) */
/* 48 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 54 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 56 */	NdrFcShort( 0x10 ),	/* 16 */
/* 58 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 60 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 62 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (48) */
			0x5b,		/* FC_END */
/* 66 */	
			0x11, 0x0,	/* FC_RP */
/* 68 */	NdrFcShort( 0x2 ),	/* Offset= 2 (70) */
/* 70 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 72 */	NdrFcShort( 0x10 ),	/* 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 76 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 78 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 80 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 82 */	NdrFcShort( 0x1 ),	/* 1 */
/* 84 */	NdrFcShort( 0x4 ),	/* 4 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0xffaa ),	/* Offset= -86 (2) */
/* 90 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 92 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 94 */	
			0x12, 0x0,	/* FC_UP */
/* 96 */	NdrFcShort( 0xc ),	/* Offset= 12 (108) */
/* 98 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 100 */	NdrFcShort( 0x2 ),	/* 2 */
/* 102 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 104 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 106 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 108 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 112 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (98) */
/* 114 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 116 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 118 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 120 */	NdrFcShort( 0x2 ),	/* 2 */
/* 122 */	NdrFcShort( 0x4 ),	/* 4 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (94) */
/* 128 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 130 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 132 */	
			0x11, 0x0,	/* FC_RP */
/* 134 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (118) */
/* 136 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 138 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 140 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 142 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 144 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 146 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 148 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 150 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            HWND_UserSize
            ,HWND_UserMarshal
            ,HWND_UserUnmarshal
            ,HWND_UserFree
            },
            {
            HDC_UserSize
            ,HDC_UserMarshal
            ,HDC_UserUnmarshal
            ,HDC_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IFcsPlayer, ver. 0.0,
   GUID={0xE892566C,0xC55A,0x4B82,{0x98,0x99,0xAA,0xD4,0x1E,0xD4,0x0B,0x76}} */

#pragma code_seg(".orpc")
static const unsigned short IFcsPlayer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    62,
    90,
    118,
    164,
    186,
    208,
    230,
    258,
    286,
    314,
    342,
    370,
    392,
    420,
    448,
    476,
    504,
    532,
    560,
    588,
    616,
    638,
    666,
    694,
    716,
    738,
    766,
    788,
    810,
    832,
    860,
    912,
    940,
    962,
    990,
    1036,
    1070,
    1092,
    1132,
    1178,
    1218,
    1252,
    1286,
    1314,
    1342,
    1370,
    1398,
    1426,
    1466,
    1494,
    1528,
    1562,
    1596,
    1630,
    1664,
    1698,
    1726,
    1754,
    1794,
    1852,
    1892,
    1920,
    1948,
    1982,
    2010,
    2038,
    2072,
    2100,
    2122,
    2144,
    2178,
    2206,
    2234,
    2262,
    2290,
    2318,
    2352,
    2410,
    2438,
    2466,
    2500,
    2534,
    2574,
    2608,
    2642,
    2688,
    2722,
    2750,
    2778,
    2806,
    2852,
    2898,
    2932,
    2966,
    3012,
    3058,
    3092,
    3126,
    3154,
    3182,
    3210,
    3238,
    3260,
    3288,
    3316,
    3344,
    3372,
    3400,
    3428,
    3462,
    3484,
    3536,
    3570,
    3604,
    3662,
    3696,
    3730,
    3800,
    3828,
    3856
    };

static const MIDL_STUBLESS_PROXY_INFO IFcsPlayer_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsPlayer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFcsPlayer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsPlayer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(129) _IFcsPlayerProxyVtbl = 
{
    &IFcsPlayer_ProxyInfo,
    &IID_IFcsPlayer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetEventWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::State */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenFile */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetVideoSize */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Play */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Pause */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetRate */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetTMFormat */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::HasVideo */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::UpdateVideoWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Repaint */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::DisplayModeChanged */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::CanSeek */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetDuration */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetCurrentPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Mute */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::IsMuted */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetVolume */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetVolume */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::ReFresh */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetVideoWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_GetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Pause */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Seek */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Run */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Initial */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Free */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_SetFile */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_SetWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetOption */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_Render */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_GetLength */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_SetWndPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetAudio */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::InitOnlyRawControl */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_SaveBmpToFile */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::MP_UpdateVideoWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Open */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::get_Fcs_Media_State */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::put_Fcs_Media_State */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenP2Mxf */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenSonyMxf */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenAvi */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenWmv */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenMpeg2 */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::OpenMpeg4 */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2Avi */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2Mpeg2 */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2Mpeg4 */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2P2Mxf */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2SonyMxf */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Save2Wmv */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetKeyFramePath */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetTMFormat */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Avi2Wmv */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetKeyFrameBasicParams */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetEvent */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetBitRate */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetAudioLevel */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetP2AudioCount */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetP2VideoName */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetP2AudioName */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetP2AudioName */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::RenderP2 */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::Free */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::snapImage */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::ChangeWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::ChangeHWnd */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::LoadRun */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetTemplateID */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetSourceFile */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::WaitForCompletion */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::AddOverlay */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetCurrentTimeString */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetFullScreen */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetTcCode */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::FrameToRefTime */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetVideoInfo */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetSegment */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::SetSegmentByMs */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetFaceRect */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetFaceImg */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetFaceWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetFaceHeight */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetLeadFace */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetLEyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetREyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetLEyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetREyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetLEyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetREyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetLEyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetREyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetActivativedValue */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetBlinkCount */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetCurTimeMs */ ,
    (void *) (INT_PTR) -1 /* IFcsPlayer::GetCurTime */ ,
    IFcsPlayer_ResetCounter_Proxy ,
    IFcsPlayer_SetCheck_Proxy ,
    IFcsPlayer_GetCheck_Proxy ,
    IFcsPlayer_SetFaceRectLineWidth_Proxy ,
    IFcsPlayer_GetFaceRectLineWidth_Proxy ,
    IFcsPlayer_SetEyeRectLineWidth_Proxy ,
    IFcsPlayer_GetEyeRectLineWidth_Proxy ,
    IFcsPlayer_DisplayOverlay_Proxy ,
    IFcsPlayer_GetCountOfArray_Proxy ,
    IFcsPlayer_SetOverlayPosition_Proxy ,
    IFcsPlayer_SetOverlayColor_Proxy ,
    IFcsPlayer_SetOverlayFontSize_Proxy ,
    IFcsPlayer_SetOverlayFont_Proxy ,
    IFcsPlayer_SetOverlayText_Proxy ,
    IFcsPlayer_SetOverlayFontName_Proxy ,
    IFcsPlayer_SetOverlayImgPosition_Proxy ,
    IFcsPlayer_SetFps_Proxy ,
    IFcsPlayer_GetFps_Proxy ,
    IFcsPlayer_GetRate_Proxy
};


static const PRPC_STUB_FUNCTION IFcsPlayer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFcsPlayerStubVtbl =
{
    &IID_IFcsPlayer,
    &IFcsPlayer_ServerInfo,
    129,
    &IFcsPlayer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IExportManager, ver. 0.0,
   GUID={0x10A84D63,0x730E,0x4F91,{0x81,0x9B,0x91,0x90,0xEC,0x57,0xCB,0xDC}} */

#pragma code_seg(".orpc")
static const unsigned short IExportManager_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    3884,
    3918,
    3940,
    3968,
    4020,
    4054,
    186,
    4082,
    4110,
    4132,
    4172,
    4194,
    4216,
    370,
    4238,
    4266,
    4294,
    4352,
    4374,
    4402,
    4424,
    588,
    616,
    638,
    666,
    4452,
    4480,
    4514,
    4542,
    4582,
    4610,
    4638,
    4666,
    4694,
    4728
    };

static const MIDL_STUBLESS_PROXY_INFO IExportManager_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IExportManager_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IExportManager_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IExportManager_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(42) _IExportManagerProxyVtbl = 
{
    &IExportManager_ProxyInfo,
    &IID_IExportManager,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetEventWindow */ ,
    (void *) (INT_PTR) -1 /* IExportManager::Run */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_SetWindow */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_SetSourceFile */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_SetSinkFile */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_GetLength */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Run */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_GetPosition */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Stop */ ,
    (void *) (INT_PTR) -1 /* IExportManager::GetEvent */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_ShowConfig */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Init */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Render */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Free */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetWindow */ ,
    (void *) (INT_PTR) -1 /* IExportManager::KF_KeyFrame */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetKeyFrameBasicParams */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SaveKFInfo */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IExportManager::Save */ ,
    (void *) (INT_PTR) -1 /* IExportManager::State */ ,
    (void *) (INT_PTR) -1 /* IExportManager::CanSeek */ ,
    (void *) (INT_PTR) -1 /* IExportManager::Pause */ ,
    (void *) (INT_PTR) -1 /* IExportManager::TC_Seek */ ,
    (void *) (INT_PTR) -1 /* IExportManager::GetP2AudioCount */ ,
    (void *) (INT_PTR) -1 /* IExportManager::GetP2VideoName */ ,
    (void *) (INT_PTR) -1 /* IExportManager::GetP2AudioName */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetP2AudioName */ ,
    (void *) (INT_PTR) -1 /* IExportManager::SetRange */ ,
    (void *) (INT_PTR) -1 /* IExportManager::LoadRun */ ,
    (void *) (INT_PTR) -1 /* IExportManager::ChangeWindow */ ,
    (void *) (INT_PTR) -1 /* IExportManager::ChangeHWnd */ ,
    (void *) (INT_PTR) -1 /* IExportManager::GetDuration */ ,
    (void *) (INT_PTR) -1 /* IExportManager::WaitForCompletion */ ,
    (void *) (INT_PTR) -1 /* IExportManager::PackAvi */
};


static const PRPC_STUB_FUNCTION IExportManager_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IExportManagerStubVtbl =
{
    &IID_IExportManager,
    &IExportManager_ServerInfo,
    42,
    &IExportManager_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFcsGrabber, ver. 0.0,
   GUID={0x58BB1EDE,0xA0AA,0x48C2,{0xB5,0x28,0x7E,0xED,0xB8,0x26,0xCD,0x95}} */

#pragma code_seg(".orpc")
static const unsigned short IFcsGrabber_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4780,
    3918,
    4808,
    4830,
    4858,
    164,
    4886,
    208,
    4110,
    4932,
    4172,
    4960,
    4988,
    5016,
    5050,
    4266,
    5078,
    5124,
    5152,
    5180,
    5226,
    5254,
    5276,
    5322,
    5350,
    5384,
    716,
    738,
    5442,
    5470,
    5498,
    5526,
    5554,
    5588,
    5628,
    5656,
    5684,
    5730,
    5758,
    5786,
    5832,
    5878,
    5924,
    5970,
    6004,
    6038,
    6072,
    6106,
    6140,
    6168,
    6196,
    6224,
    6252,
    6280,
    6302,
    6330,
    6358,
    6386,
    6414,
    6442,
    6470,
    6504,
    6526,
    6578,
    6612,
    6646,
    6704,
    6738,
    6772,
    6842,
    6870,
    6916,
    6938,
    6984,
    2234,
    7024,
    7052,
    7080,
    7108,
    7136,
    2438,
    7164,
    7192
    };

static const MIDL_STUBLESS_PROXY_INFO IFcsGrabber_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsGrabber_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFcsGrabber_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsGrabber_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(90) _IFcsGrabberProxyVtbl = 
{
    &IFcsGrabber_ProxyInfo,
    &IID_IFcsGrabber,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Pause */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Seek */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Run */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetWindowPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Free */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Init */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetFile */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Render */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLength */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOption */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetAudio */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetSinkFile */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetHWnd */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::UpdateVideoWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetVideoSize */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Repaint */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::Record */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::UpdateWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::State */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetAudioLevel */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetKeyFrameBasicParams */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SaveKFInfo */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::ChangeWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::ChangeHWnd */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::IsMute */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetVideoFps */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetFullScreen */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SnapImage */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::MP_GetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetCurrentPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetFaceRect */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetFaceWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetFaceHeight */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLEyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetREyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLEyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetREyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetFaceImg */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLEyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetREyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLEyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetREyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetLeadFace */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetActivativedValue */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetBlinkCount */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetCurTimeMs */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetCurTime */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::ResetCounter */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetCheck */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetCheck */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetFaceRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetFaceRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetEyeRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetEyeRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::DisPlayOverlay */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::GetCountOfArray */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayColor */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayFontSize */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayFont */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayText */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayFontName */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetOverlayImgPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::EnableRoi */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetRoi */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::ShowRoi */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetRoiProp */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SnapGrayImage */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetExportDir */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetExportName */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetExportImageWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetExportImageHeight */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetCompressRatio */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetCaptureFreq */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::SetCaneraFps */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::EnableCapture */ ,
    (void *) (INT_PTR) -1 /* IFcsGrabber::WaitForCompletion */
};


static const PRPC_STUB_FUNCTION IFcsGrabber_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFcsGrabberStubVtbl =
{
    &IID_IFcsGrabber,
    &IFcsGrabber_ServerInfo,
    90,
    &IFcsGrabber_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFcsDVManager, ver. 0.0,
   GUID={0x2C683837,0xF99F,0x4A06,{0x90,0x89,0x4B,0xC6,0x96,0x83,0xF1,0x23}} */

#pragma code_seg(".orpc")
static const unsigned short IFcsDVManager_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4780,
    3918,
    4808,
    4830,
    4858,
    164,
    4886,
    208,
    4110,
    4932,
    4172,
    4960,
    4988,
    5016,
    5050,
    4266,
    5078,
    5124,
    5152,
    5180,
    5226,
    5254,
    5276,
    5322,
    5350,
    5384,
    716,
    738,
    7226,
    7254,
    7282,
    7310,
    7332,
    7354,
    7376,
    7404,
    7432,
    7460,
    7488,
    1092,
    7516,
    7544,
    5924,
    7572,
    7600,
    7628,
    7674,
    7720,
    7766,
    7812,
    7846,
    7880,
    7914,
    7948,
    7982,
    8010,
    8038,
    8066,
    8094,
    8122,
    8144,
    8172,
    8200,
    8228,
    8256,
    8284
    };

static const MIDL_STUBLESS_PROXY_INFO IFcsDVManager_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsDVManager_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFcsDVManager_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsDVManager_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(73) _IFcsDVManagerProxyVtbl = 
{
    &IFcsDVManager_ProxyInfo,
    &IID_IFcsDVManager,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Pause */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Seek */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Run */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetWindowPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Free */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Init */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetFile */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Render */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLength */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetOption */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetAudio */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetSinkFile */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetHWnd */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::UpdateVideoWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetVideoSize */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Repaint */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::Record */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::UpdateWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::State */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetAudioLevel */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetKeyFrameBasicParams */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SaveKFInfo */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::RemoteControl */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetDVMode */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::ChangeWindow */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::ChangeHWnd */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::PowerOn */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::PowerOff */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::StandBy */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetDvRate */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetDvRate */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::IsMute */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetVideoFps */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SnapImage */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::MP_GetPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetCurrentPosition */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetFaceRect */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetFaceWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetFaceHeight */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLEyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetREyeRect */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLEyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetREyeballRect */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetFaceImg */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLEyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetREyeImg */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLEyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetREyeballImg */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetLeadFace */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetActivativedValue */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetBlinkCount */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetCurTimeMs */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetCurTime */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::ResetCounter */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetCheck */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetCheck */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetFaceRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetFaceRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::SetEyeRectLineWidth */ ,
    (void *) (INT_PTR) -1 /* IFcsDVManager::GetEyeRectLineWidth */
};


static const PRPC_STUB_FUNCTION IFcsDVManager_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFcsDVManagerStubVtbl =
{
    &IID_IFcsDVManager,
    &IFcsDVManager_ServerInfo,
    73,
    &IFcsDVManager_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFcsDeckControl, ver. 0.0,
   GUID={0x7D8113E6,0x0421,0x4622,{0x86,0x8B,0xED,0x30,0xD8,0x11,0x56,0x2C}} */

#pragma code_seg(".orpc")
static const unsigned short IFcsDeckControl_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    8312,
    8340,
    3940,
    8368,
    8402,
    8436,
    8470,
    8504,
    8544,
    8578,
    8612,
    8646,
    8680,
    8720,
    8760,
    8800,
    8840,
    8880,
    8908,
    8942,
    8970,
    9004,
    9038,
    9084,
    9136,
    9176,
    9204,
    9238
    };

static const MIDL_STUBLESS_PROXY_INFO IFcsDeckControl_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsDeckControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFcsDeckControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsDeckControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(35) _IFcsDeckControlProxyVtbl = 
{
    &IFcsDeckControl_ProxyInfo,
    &IID_IFcsDeckControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Init */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Close */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::SetStandBy */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Play */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::TogglePlayStop */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Eject */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GotoTimeCode */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::FastForward */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Rewind */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::StepForward */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::StepBack */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Jog */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Shuttle */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetTimeCode */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::SetPreroll */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetPreroll */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::SetCaptureOffset */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetCaptureOffset */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::SetExportOffset */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetExportOffset */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetManualExportOffset */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::StartExport */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::StartCapture */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::GetDeviceID */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::Abort */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::CrashRecordStart */ ,
    (void *) (INT_PTR) -1 /* IFcsDeckControl::CrashRecordStop */
};


static const PRPC_STUB_FUNCTION IFcsDeckControl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFcsDeckControlStubVtbl =
{
    &IID_IFcsDeckControl,
    &IFcsDeckControl_ServerInfo,
    35,
    &IFcsDeckControl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFcsSerialControl, ver. 0.0,
   GUID={0x2E450FE7,0xFD75,0x443E,{0xB2,0x05,0x3C,0x9F,0xB5,0x22,0x2C,0x69}} */

#pragma code_seg(".orpc")
static const unsigned short IFcsSerialControl_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    9272,
    3918,
    4808,
    9300,
    9322
    };

static const MIDL_STUBLESS_PROXY_INFO IFcsSerialControl_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsSerialControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFcsSerialControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IFcsSerialControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IFcsSerialControlProxyVtbl = 
{
    &IFcsSerialControl_ProxyInfo,
    &IID_IFcsSerialControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFcsSerialControl::OpenPort */ ,
    (void *) (INT_PTR) -1 /* IFcsSerialControl::Play */ ,
    (void *) (INT_PTR) -1 /* IFcsSerialControl::Stop */ ,
    (void *) (INT_PTR) -1 /* IFcsSerialControl::ClosePort */ ,
    (void *) (INT_PTR) -1 /* IFcsSerialControl::Eject */
};


static const PRPC_STUB_FUNCTION IFcsSerialControl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFcsSerialControlStubVtbl =
{
    &IID_IFcsSerialControl,
    &IFcsSerialControl_ServerInfo,
    12,
    &IFcsSerialControl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IJbuCapturer, ver. 0.0,
   GUID={0x17EF949B,0x13A3,0x4128,{0xB1,0x3C,0x2A,0x0D,0xC2,0x19,0x27,0x1D}} */

#pragma code_seg(".orpc")
static const unsigned short IJbuCapturer_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    4780,
    3918,
    4808,
    9344,
    9322,
    164,
    186,
    9390,
    9418,
    9464,
    9510,
    4960,
    4988,
    370,
    9556,
    9596,
    9624
    };

static const MIDL_STUBLESS_PROXY_INFO IJbuCapturer_ProxyInfo =
    {
    &Object_StubDesc,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IJbuCapturer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IJbuCapturer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    FcsMedia__MIDL_ProcFormatString.Format,
    &IJbuCapturer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IJbuCapturerProxyVtbl = 
{
    &IJbuCapturer_ProxyInfo,
    &IID_IJbuCapturer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::SetWindow */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Pause */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Stop */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::SetWindowPosition */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Free */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Init */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Render */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::SetGraphPath */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::SetSinkFile */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::GetVideoSize */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::UpdateWindow */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::State */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::ChangeWindow */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::Play */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::SnapImage */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::ChangeHWnd */ ,
    (void *) (INT_PTR) -1 /* IJbuCapturer::UpdateVideoWindow */
};


static const PRPC_STUB_FUNCTION IJbuCapturer_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IJbuCapturerStubVtbl =
{
    &IID_IJbuCapturer,
    &IJbuCapturer_ServerInfo,
    24,
    &IJbuCapturer_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    FcsMedia__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _FcsMedia_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFcsDVManagerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IExportManagerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFcsPlayerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IJbuCapturerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFcsGrabberProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFcsDeckControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFcsSerialControlProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _FcsMedia_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFcsDVManagerStubVtbl,
    ( CInterfaceStubVtbl *) &_IExportManagerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFcsPlayerStubVtbl,
    ( CInterfaceStubVtbl *) &_IJbuCapturerStubVtbl,
    ( CInterfaceStubVtbl *) &_IFcsGrabberStubVtbl,
    ( CInterfaceStubVtbl *) &_IFcsDeckControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IFcsSerialControlStubVtbl,
    0
};

PCInterfaceName const _FcsMedia_InterfaceNamesList[] = 
{
    "IFcsDVManager",
    "IExportManager",
    "IFcsPlayer",
    "IJbuCapturer",
    "IFcsGrabber",
    "IFcsDeckControl",
    "IFcsSerialControl",
    0
};

const IID *  const _FcsMedia_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _FcsMedia_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _FcsMedia, pIID, n)

int __stdcall _FcsMedia_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _FcsMedia, 7, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _FcsMedia, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _FcsMedia, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _FcsMedia, 7, *pIndex )
    
}

const ExtendedProxyFileInfo FcsMedia_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _FcsMedia_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _FcsMedia_StubVtblList,
    (const PCInterfaceName * ) & _FcsMedia_InterfaceNamesList,
    (const IID ** ) & _FcsMedia_BaseIIDList,
    & _FcsMedia_IID_Lookup, 
    7,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

