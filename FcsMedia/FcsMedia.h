

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FcsMedia_h__
#define __FcsMedia_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFcsPlayer_FWD_DEFINED__
#define __IFcsPlayer_FWD_DEFINED__
typedef interface IFcsPlayer IFcsPlayer;
#endif 	/* __IFcsPlayer_FWD_DEFINED__ */


#ifndef __IExportManager_FWD_DEFINED__
#define __IExportManager_FWD_DEFINED__
typedef interface IExportManager IExportManager;
#endif 	/* __IExportManager_FWD_DEFINED__ */


#ifndef __IFcsGrabber_FWD_DEFINED__
#define __IFcsGrabber_FWD_DEFINED__
typedef interface IFcsGrabber IFcsGrabber;
#endif 	/* __IFcsGrabber_FWD_DEFINED__ */


#ifndef __IFcsDVManager_FWD_DEFINED__
#define __IFcsDVManager_FWD_DEFINED__
typedef interface IFcsDVManager IFcsDVManager;
#endif 	/* __IFcsDVManager_FWD_DEFINED__ */


#ifndef __IFcsDeckControl_FWD_DEFINED__
#define __IFcsDeckControl_FWD_DEFINED__
typedef interface IFcsDeckControl IFcsDeckControl;
#endif 	/* __IFcsDeckControl_FWD_DEFINED__ */


#ifndef __IFcsSerialControl_FWD_DEFINED__
#define __IFcsSerialControl_FWD_DEFINED__
typedef interface IFcsSerialControl IFcsSerialControl;
#endif 	/* __IFcsSerialControl_FWD_DEFINED__ */


#ifndef __IJbuCapturer_FWD_DEFINED__
#define __IJbuCapturer_FWD_DEFINED__
typedef interface IJbuCapturer IJbuCapturer;
#endif 	/* __IJbuCapturer_FWD_DEFINED__ */


#ifndef __FcsPlayer_FWD_DEFINED__
#define __FcsPlayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class FcsPlayer FcsPlayer;
#else
typedef struct FcsPlayer FcsPlayer;
#endif /* __cplusplus */

#endif 	/* __FcsPlayer_FWD_DEFINED__ */


#ifndef __ExportManager_FWD_DEFINED__
#define __ExportManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class ExportManager ExportManager;
#else
typedef struct ExportManager ExportManager;
#endif /* __cplusplus */

#endif 	/* __ExportManager_FWD_DEFINED__ */


#ifndef __FcsGrabber_FWD_DEFINED__
#define __FcsGrabber_FWD_DEFINED__

#ifdef __cplusplus
typedef class FcsGrabber FcsGrabber;
#else
typedef struct FcsGrabber FcsGrabber;
#endif /* __cplusplus */

#endif 	/* __FcsGrabber_FWD_DEFINED__ */


#ifndef __FcsDVManager_FWD_DEFINED__
#define __FcsDVManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class FcsDVManager FcsDVManager;
#else
typedef struct FcsDVManager FcsDVManager;
#endif /* __cplusplus */

#endif 	/* __FcsDVManager_FWD_DEFINED__ */


#ifndef __FcsDeckControl_FWD_DEFINED__
#define __FcsDeckControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class FcsDeckControl FcsDeckControl;
#else
typedef struct FcsDeckControl FcsDeckControl;
#endif /* __cplusplus */

#endif 	/* __FcsDeckControl_FWD_DEFINED__ */


#ifndef __FcsSerialControl_FWD_DEFINED__
#define __FcsSerialControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class FcsSerialControl FcsSerialControl;
#else
typedef struct FcsSerialControl FcsSerialControl;
#endif /* __cplusplus */

#endif 	/* __FcsSerialControl_FWD_DEFINED__ */


#ifndef ___IJbuCapturerEvents_FWD_DEFINED__
#define ___IJbuCapturerEvents_FWD_DEFINED__
typedef interface _IJbuCapturerEvents _IJbuCapturerEvents;
#endif 	/* ___IJbuCapturerEvents_FWD_DEFINED__ */


#ifndef __JbuCapturer_FWD_DEFINED__
#define __JbuCapturer_FWD_DEFINED__

#ifdef __cplusplus
typedef class JbuCapturer JbuCapturer;
#else
typedef struct JbuCapturer JbuCapturer;
#endif /* __cplusplus */

#endif 	/* __JbuCapturer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "decklinkapi.h"
#include "Amux.h"
#include "FcsOverlay.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFcsPlayer_INTERFACE_DEFINED__
#define __IFcsPlayer_INTERFACE_DEFINED__

/* interface IFcsPlayer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFcsPlayer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E892566C-C55A-4B82-9899-AAD41ED40B76")
    IFcsPlayer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEventWindow( 
            HWND hwnd,
            UINT msg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE State( 
            UINT *state) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenFile( 
            const WCHAR *sFileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoSize( 
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRate( 
            double dSpeed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTMFormat( 
            GUID *tmFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HasVideo( 
            BOOL *bHasVideo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateVideoWindow( 
            const LPRECT prc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Repaint( 
            HDC hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayModeChanged( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanSeek( 
            BOOL *bCanSeek) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPosition( 
            LONGLONG pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDuration( 
            LONGLONG *pDuration) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurrentPosition( 
            LONGLONG *pTimeNow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mute( 
            BOOL bMute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsMuted( 
            BOOL *bMuted) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVolume( 
            long lVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVolume( 
            long *lVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReFresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVideoWindow( 
            long hParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_GetPosition( 
            long *nIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Seek( 
            long nIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Initial( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_SetFile( 
            BSTR strFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_SetWindow( 
            long hParent,
            long x,
            long y,
            long nWidth,
            long nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            long nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_Render( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_GetLength( 
            long *nLength) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_SetWndPosition( 
            long x,
            long y,
            long nWidth,
            long nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudio( 
            long nIndex,
            long *nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitOnlyRawControl( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_SaveBmpToFile( 
            BSTR strFileName,
            long nWidth,
            long nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MP_UpdateVideoWindow( 
            long left,
            long top,
            long right,
            long bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            BSTR sFileName,
            long nFormat,
            long nOption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Fcs_Media_State( 
            LONG FCS_STATE_RUNNING,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fcs_Media_State( 
            LONG FCS_STATE_RUNNING,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenP2Mxf( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenSonyMxf( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAvi( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenWmv( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenMpeg2( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            const WCHAR *szTargetName,
            int nTargetFormat,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenMpeg4( 
            const WCHAR *szpathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2Avi( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2Mpeg2( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2Mpeg4( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2P2Mxf( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2SonyMxf( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save2Wmv( 
            const WCHAR *szTargetName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKeyFramePath( 
            const WCHAR *szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTMFormat( 
            long tmFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Avi2Wmv( 
            const WCHAR *szSrcName,
            const WCHAR *szDestName,
            int nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKeyFrameBasicParams( 
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEvent( 
            long *iEvent,
            long *L1,
            long *L2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphPath( 
            BSTR bstrGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBitRate( 
            long *nBitRate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioLevel( 
            long nChannel,
            long *nVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2AudioCount( 
            long *nCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2VideoName( 
            BSTR bstrVideoName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2AudioName( 
            long nIndex,
            BSTR *bstrAudioName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetP2AudioName( 
            BSTR bstrAudioName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RenderP2( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE snapImage( 
            long nIndex,
            BSTR bstrImagename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeWindow( 
            long hWndHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadRun( 
            BSTR bstrGrfName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTemplateID( 
            long nTemplateID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSourceFile( 
            BSTR bstrSourceName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForCompletion( 
            long nTimeOut,
            long *pEvCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddOverlay( 
            BSTR BstrOverlay,
            long nLeft,
            long nTop,
            long nRight,
            long nBottom,
            long nScaleToFit) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurrentTimeString( 
            BSTR *bstrTime) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFullScreen( 
            LONG mode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTcCode( 
            LONGLONG timeNow,
            BSTR *bstrTime) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FrameToRefTime( 
            LONG nFrame,
            LONGLONG *refTime) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVideoInfo( 
            LONG *nWidth,
            LONG *nHeight,
            DOUBLE *dFps) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSegment( 
            LONG nStart,
            LONG nEnd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSegmentByMs( 
            LONGLONG timeBegin,
            LONGLONG timeEnd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceWidth( 
            LONG *nWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceHeight( 
            LONG *nHeight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLeadFace( 
            BYTE *pLeadFace) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActivativedValue( 
            DOUBLE *dActivation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetBlinkCount( 
            LONG *nCount) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTimeMs( 
            LONG *MilliSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTime( 
            LONGLONG *NSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetCounter( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCheck( 
            SHORT nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCheck( 
            SHORT *nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFaceRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetEyeRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetEyeRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisplayOverlay( 
            LONG nID,
            SHORT IsVisible) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCountOfArray( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayPosition( 
            LONG nID,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nButtom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayColor( 
            LONG nID,
            COLORREF nColor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFontSize( 
            LONG nID,
            LONG nFontSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFont( 
            LONG nID,
            LONG nFontStyle,
            SHORT bUnderLine,
            SHORT bWrap,
            SHORT bVertical,
            SHORT bRightAlign) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayText( 
            LONG nID,
            BSTR szText) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFontName( 
            LONG nID,
            BSTR szFontName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayImgPosition( 
            BSTR szImgName,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nButtom,
            SHORT bDisplay,
            SHORT bScaleFit,
            LONG nTranspency) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFps( 
            DOUBLE dFps) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFps( 
            DOUBLE *dFps) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRate( 
            DOUBLE *pRate) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFcsPlayerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFcsPlayer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFcsPlayer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFcsPlayer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFcsPlayer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFcsPlayer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFcsPlayer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFcsPlayer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IFcsPlayer * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetEventWindow )( 
            IFcsPlayer * This,
            HWND hwnd,
            UINT msg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *State )( 
            IFcsPlayer * This,
            UINT *state);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenFile )( 
            IFcsPlayer * This,
            const WCHAR *sFileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoSize )( 
            IFcsPlayer * This,
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRate )( 
            IFcsPlayer * This,
            double dSpeed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTMFormat )( 
            IFcsPlayer * This,
            GUID *tmFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HasVideo )( 
            IFcsPlayer * This,
            BOOL *bHasVideo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateVideoWindow )( 
            IFcsPlayer * This,
            const LPRECT prc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Repaint )( 
            IFcsPlayer * This,
            HDC hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisplayModeChanged )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanSeek )( 
            IFcsPlayer * This,
            BOOL *bCanSeek);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPosition )( 
            IFcsPlayer * This,
            LONGLONG pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDuration )( 
            IFcsPlayer * This,
            LONGLONG *pDuration);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentPosition )( 
            IFcsPlayer * This,
            LONGLONG *pTimeNow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mute )( 
            IFcsPlayer * This,
            BOOL bMute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsMuted )( 
            IFcsPlayer * This,
            BOOL *bMuted);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVolume )( 
            IFcsPlayer * This,
            long lVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVolume )( 
            IFcsPlayer * This,
            long *lVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReFresh )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVideoWindow )( 
            IFcsPlayer * This,
            long hParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_GetPosition )( 
            IFcsPlayer * This,
            long *nIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Pause )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Stop )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Seek )( 
            IFcsPlayer * This,
            long nIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Run )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Initial )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Free )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_SetFile )( 
            IFcsPlayer * This,
            BSTR strFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_SetWindow )( 
            IFcsPlayer * This,
            long hParent,
            long x,
            long y,
            long nWidth,
            long nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOption )( 
            IFcsPlayer * This,
            long nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_Render )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_GetLength )( 
            IFcsPlayer * This,
            long *nLength);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_SetWndPosition )( 
            IFcsPlayer * This,
            long x,
            long y,
            long nWidth,
            long nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            IFcsPlayer * This,
            long nIndex,
            long *nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitOnlyRawControl )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_SaveBmpToFile )( 
            IFcsPlayer * This,
            BSTR strFileName,
            long nWidth,
            long nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MP_UpdateVideoWindow )( 
            IFcsPlayer * This,
            long left,
            long top,
            long right,
            long bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IFcsPlayer * This,
            BSTR sFileName,
            long nFormat,
            long nOption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fcs_Media_State )( 
            IFcsPlayer * This,
            LONG FCS_STATE_RUNNING,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fcs_Media_State )( 
            IFcsPlayer * This,
            LONG FCS_STATE_RUNNING,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenP2Mxf )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenSonyMxf )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAvi )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenWmv )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenMpeg2 )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nTargetFormat,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenMpeg4 )( 
            IFcsPlayer * This,
            const WCHAR *szpathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2Avi )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2Mpeg2 )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2Mpeg4 )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2P2Mxf )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2SonyMxf )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save2Wmv )( 
            IFcsPlayer * This,
            const WCHAR *szTargetName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKeyFramePath )( 
            IFcsPlayer * This,
            const WCHAR *szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTMFormat )( 
            IFcsPlayer * This,
            long tmFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Avi2Wmv )( 
            IFcsPlayer * This,
            const WCHAR *szSrcName,
            const WCHAR *szDestName,
            int nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKeyFrameBasicParams )( 
            IFcsPlayer * This,
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEvent )( 
            IFcsPlayer * This,
            long *iEvent,
            long *L1,
            long *L2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphPath )( 
            IFcsPlayer * This,
            BSTR bstrGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBitRate )( 
            IFcsPlayer * This,
            long *nBitRate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudioLevel )( 
            IFcsPlayer * This,
            long nChannel,
            long *nVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2AudioCount )( 
            IFcsPlayer * This,
            long *nCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2VideoName )( 
            IFcsPlayer * This,
            BSTR bstrVideoName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2AudioName )( 
            IFcsPlayer * This,
            long nIndex,
            BSTR *bstrAudioName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetP2AudioName )( 
            IFcsPlayer * This,
            BSTR bstrAudioName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RenderP2 )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Free )( 
            IFcsPlayer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *snapImage )( 
            IFcsPlayer * This,
            long nIndex,
            BSTR bstrImagename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeWindow )( 
            IFcsPlayer * This,
            long hWndHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeHWnd )( 
            IFcsPlayer * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadRun )( 
            IFcsPlayer * This,
            BSTR bstrGrfName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTemplateID )( 
            IFcsPlayer * This,
            long nTemplateID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSourceFile )( 
            IFcsPlayer * This,
            BSTR bstrSourceName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForCompletion )( 
            IFcsPlayer * This,
            long nTimeOut,
            long *pEvCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddOverlay )( 
            IFcsPlayer * This,
            BSTR BstrOverlay,
            long nLeft,
            long nTop,
            long nRight,
            long nBottom,
            long nScaleToFit);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentTimeString )( 
            IFcsPlayer * This,
            BSTR *bstrTime);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFullScreen )( 
            IFcsPlayer * This,
            LONG mode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTcCode )( 
            IFcsPlayer * This,
            LONGLONG timeNow,
            BSTR *bstrTime);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FrameToRefTime )( 
            IFcsPlayer * This,
            LONG nFrame,
            LONGLONG *refTime);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoInfo )( 
            IFcsPlayer * This,
            LONG *nWidth,
            LONG *nHeight,
            DOUBLE *dFps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetSegment )( 
            IFcsPlayer * This,
            LONG nStart,
            LONG nEnd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetSegmentByMs )( 
            IFcsPlayer * This,
            LONGLONG timeBegin,
            LONGLONG timeEnd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRect )( 
            IFcsPlayer * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceImg )( 
            IFcsPlayer * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceWidth )( 
            IFcsPlayer * This,
            LONG *nWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceHeight )( 
            IFcsPlayer * This,
            LONG *nHeight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLeadFace )( 
            IFcsPlayer * This,
            BYTE *pLeadFace);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeRect )( 
            IFcsPlayer * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeRect )( 
            IFcsPlayer * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeImg )( 
            IFcsPlayer * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeImg )( 
            IFcsPlayer * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballRect )( 
            IFcsPlayer * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballRect )( 
            IFcsPlayer * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballImg )( 
            IFcsPlayer * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballImg )( 
            IFcsPlayer * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActivativedValue )( 
            IFcsPlayer * This,
            DOUBLE *dActivation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetBlinkCount )( 
            IFcsPlayer * This,
            LONG *nCount);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTimeMs )( 
            IFcsPlayer * This,
            LONG *MilliSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTime )( 
            IFcsPlayer * This,
            LONGLONG *NSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetCounter )( 
            IFcsPlayer * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCheck )( 
            IFcsPlayer * This,
            SHORT nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCheck )( 
            IFcsPlayer * This,
            SHORT *nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFaceRectLineWidth )( 
            IFcsPlayer * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRectLineWidth )( 
            IFcsPlayer * This,
            FLOAT *fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetEyeRectLineWidth )( 
            IFcsPlayer * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetEyeRectLineWidth )( 
            IFcsPlayer * This,
            FLOAT *fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisplayOverlay )( 
            IFcsPlayer * This,
            LONG nID,
            SHORT IsVisible);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCountOfArray )( 
            IFcsPlayer * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayPosition )( 
            IFcsPlayer * This,
            LONG nID,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nButtom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayColor )( 
            IFcsPlayer * This,
            LONG nID,
            COLORREF nColor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFontSize )( 
            IFcsPlayer * This,
            LONG nID,
            LONG nFontSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFont )( 
            IFcsPlayer * This,
            LONG nID,
            LONG nFontStyle,
            SHORT bUnderLine,
            SHORT bWrap,
            SHORT bVertical,
            SHORT bRightAlign);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayText )( 
            IFcsPlayer * This,
            LONG nID,
            BSTR szText);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFontName )( 
            IFcsPlayer * This,
            LONG nID,
            BSTR szFontName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayImgPosition )( 
            IFcsPlayer * This,
            BSTR szImgName,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nButtom,
            SHORT bDisplay,
            SHORT bScaleFit,
            LONG nTranspency);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFps )( 
            IFcsPlayer * This,
            DOUBLE dFps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFps )( 
            IFcsPlayer * This,
            DOUBLE *dFps);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRate )( 
            IFcsPlayer * This,
            DOUBLE *pRate);
        
        END_INTERFACE
    } IFcsPlayerVtbl;

    interface IFcsPlayer
    {
        CONST_VTBL struct IFcsPlayerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFcsPlayer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFcsPlayer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFcsPlayer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFcsPlayer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFcsPlayer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFcsPlayer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFcsPlayer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFcsPlayer_SetWindow(This,hWnd)	\
    ( (This)->lpVtbl -> SetWindow(This,hWnd) ) 

#define IFcsPlayer_SetEventWindow(This,hwnd,msg)	\
    ( (This)->lpVtbl -> SetEventWindow(This,hwnd,msg) ) 

#define IFcsPlayer_State(This,state)	\
    ( (This)->lpVtbl -> State(This,state) ) 

#define IFcsPlayer_OpenFile(This,sFileName)	\
    ( (This)->lpVtbl -> OpenFile(This,sFileName) ) 

#define IFcsPlayer_GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight)	\
    ( (This)->lpVtbl -> GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight) ) 

#define IFcsPlayer_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#define IFcsPlayer_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IFcsPlayer_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IFcsPlayer_SetRate(This,dSpeed)	\
    ( (This)->lpVtbl -> SetRate(This,dSpeed) ) 

#define IFcsPlayer_GetTMFormat(This,tmFormat)	\
    ( (This)->lpVtbl -> GetTMFormat(This,tmFormat) ) 

#define IFcsPlayer_HasVideo(This,bHasVideo)	\
    ( (This)->lpVtbl -> HasVideo(This,bHasVideo) ) 

#define IFcsPlayer_UpdateVideoWindow(This,prc)	\
    ( (This)->lpVtbl -> UpdateVideoWindow(This,prc) ) 

#define IFcsPlayer_Repaint(This,hdc)	\
    ( (This)->lpVtbl -> Repaint(This,hdc) ) 

#define IFcsPlayer_DisplayModeChanged(This)	\
    ( (This)->lpVtbl -> DisplayModeChanged(This) ) 

#define IFcsPlayer_CanSeek(This,bCanSeek)	\
    ( (This)->lpVtbl -> CanSeek(This,bCanSeek) ) 

#define IFcsPlayer_SetPosition(This,pos)	\
    ( (This)->lpVtbl -> SetPosition(This,pos) ) 

#define IFcsPlayer_GetDuration(This,pDuration)	\
    ( (This)->lpVtbl -> GetDuration(This,pDuration) ) 

#define IFcsPlayer_GetCurrentPosition(This,pTimeNow)	\
    ( (This)->lpVtbl -> GetCurrentPosition(This,pTimeNow) ) 

#define IFcsPlayer_Mute(This,bMute)	\
    ( (This)->lpVtbl -> Mute(This,bMute) ) 

#define IFcsPlayer_IsMuted(This,bMuted)	\
    ( (This)->lpVtbl -> IsMuted(This,bMuted) ) 

#define IFcsPlayer_SetVolume(This,lVolume)	\
    ( (This)->lpVtbl -> SetVolume(This,lVolume) ) 

#define IFcsPlayer_GetVolume(This,lVolume)	\
    ( (This)->lpVtbl -> GetVolume(This,lVolume) ) 

#define IFcsPlayer_ReFresh(This)	\
    ( (This)->lpVtbl -> ReFresh(This) ) 

#define IFcsPlayer_SetVideoWindow(This,hParent)	\
    ( (This)->lpVtbl -> SetVideoWindow(This,hParent) ) 

#define IFcsPlayer_MP_GetPosition(This,nIndex)	\
    ( (This)->lpVtbl -> MP_GetPosition(This,nIndex) ) 

#define IFcsPlayer_MP_Pause(This)	\
    ( (This)->lpVtbl -> MP_Pause(This) ) 

#define IFcsPlayer_MP_Stop(This)	\
    ( (This)->lpVtbl -> MP_Stop(This) ) 

#define IFcsPlayer_MP_Seek(This,nIndex)	\
    ( (This)->lpVtbl -> MP_Seek(This,nIndex) ) 

#define IFcsPlayer_MP_Run(This)	\
    ( (This)->lpVtbl -> MP_Run(This) ) 

#define IFcsPlayer_MP_Initial(This)	\
    ( (This)->lpVtbl -> MP_Initial(This) ) 

#define IFcsPlayer_MP_Free(This)	\
    ( (This)->lpVtbl -> MP_Free(This) ) 

#define IFcsPlayer_MP_SetFile(This,strFile)	\
    ( (This)->lpVtbl -> MP_SetFile(This,strFile) ) 

#define IFcsPlayer_MP_SetWindow(This,hParent,x,y,nWidth,nHeight)	\
    ( (This)->lpVtbl -> MP_SetWindow(This,hParent,x,y,nWidth,nHeight) ) 

#define IFcsPlayer_SetOption(This,nOption)	\
    ( (This)->lpVtbl -> SetOption(This,nOption) ) 

#define IFcsPlayer_MP_Render(This)	\
    ( (This)->lpVtbl -> MP_Render(This) ) 

#define IFcsPlayer_MP_GetLength(This,nLength)	\
    ( (This)->lpVtbl -> MP_GetLength(This,nLength) ) 

#define IFcsPlayer_MP_SetWndPosition(This,x,y,nWidth,nHeight)	\
    ( (This)->lpVtbl -> MP_SetWndPosition(This,x,y,nWidth,nHeight) ) 

#define IFcsPlayer_GetAudio(This,nIndex,nOption)	\
    ( (This)->lpVtbl -> GetAudio(This,nIndex,nOption) ) 

#define IFcsPlayer_InitOnlyRawControl(This)	\
    ( (This)->lpVtbl -> InitOnlyRawControl(This) ) 

#define IFcsPlayer_MP_SaveBmpToFile(This,strFileName,nWidth,nHeight)	\
    ( (This)->lpVtbl -> MP_SaveBmpToFile(This,strFileName,nWidth,nHeight) ) 

#define IFcsPlayer_MP_UpdateVideoWindow(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> MP_UpdateVideoWindow(This,left,top,right,bottom) ) 

#define IFcsPlayer_Open(This,sFileName,nFormat,nOption)	\
    ( (This)->lpVtbl -> Open(This,sFileName,nFormat,nOption) ) 

#define IFcsPlayer_get_Fcs_Media_State(This,FCS_STATE_RUNNING,pVal)	\
    ( (This)->lpVtbl -> get_Fcs_Media_State(This,FCS_STATE_RUNNING,pVal) ) 

#define IFcsPlayer_put_Fcs_Media_State(This,FCS_STATE_RUNNING,newVal)	\
    ( (This)->lpVtbl -> put_Fcs_Media_State(This,FCS_STATE_RUNNING,newVal) ) 

#define IFcsPlayer_OpenP2Mxf(This,szPathName)	\
    ( (This)->lpVtbl -> OpenP2Mxf(This,szPathName) ) 

#define IFcsPlayer_OpenSonyMxf(This,szPathName)	\
    ( (This)->lpVtbl -> OpenSonyMxf(This,szPathName) ) 

#define IFcsPlayer_OpenAvi(This,szPathName)	\
    ( (This)->lpVtbl -> OpenAvi(This,szPathName) ) 

#define IFcsPlayer_OpenWmv(This,szPathName)	\
    ( (This)->lpVtbl -> OpenWmv(This,szPathName) ) 

#define IFcsPlayer_OpenMpeg2(This,szPathName)	\
    ( (This)->lpVtbl -> OpenMpeg2(This,szPathName) ) 

#define IFcsPlayer_Save(This,szTargetName,nTargetFormat,nOption)	\
    ( (This)->lpVtbl -> Save(This,szTargetName,nTargetFormat,nOption) ) 

#define IFcsPlayer_OpenMpeg4(This,szpathName)	\
    ( (This)->lpVtbl -> OpenMpeg4(This,szpathName) ) 

#define IFcsPlayer_Save2Avi(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2Avi(This,szTargetName,nOption) ) 

#define IFcsPlayer_Save2Mpeg2(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2Mpeg2(This,szTargetName,nOption) ) 

#define IFcsPlayer_Save2Mpeg4(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2Mpeg4(This,szTargetName,nOption) ) 

#define IFcsPlayer_Save2P2Mxf(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2P2Mxf(This,szTargetName,nOption) ) 

#define IFcsPlayer_Save2SonyMxf(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2SonyMxf(This,szTargetName,nOption) ) 

#define IFcsPlayer_Save2Wmv(This,szTargetName,nOption)	\
    ( (This)->lpVtbl -> Save2Wmv(This,szTargetName,nOption) ) 

#define IFcsPlayer_SetKeyFramePath(This,szPathName)	\
    ( (This)->lpVtbl -> SetKeyFramePath(This,szPathName) ) 

#define IFcsPlayer_SetTMFormat(This,tmFormat)	\
    ( (This)->lpVtbl -> SetTMFormat(This,tmFormat) ) 

#define IFcsPlayer_Avi2Wmv(This,szSrcName,szDestName,nOption)	\
    ( (This)->lpVtbl -> Avi2Wmv(This,szSrcName,szDestName,nOption) ) 

#define IFcsPlayer_SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath)	\
    ( (This)->lpVtbl -> SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath) ) 

#define IFcsPlayer_GetEvent(This,iEvent,L1,L2)	\
    ( (This)->lpVtbl -> GetEvent(This,iEvent,L1,L2) ) 

#define IFcsPlayer_SetGraphPath(This,bstrGraphPath)	\
    ( (This)->lpVtbl -> SetGraphPath(This,bstrGraphPath) ) 

#define IFcsPlayer_GetBitRate(This,nBitRate)	\
    ( (This)->lpVtbl -> GetBitRate(This,nBitRate) ) 

#define IFcsPlayer_GetAudioLevel(This,nChannel,nVolume)	\
    ( (This)->lpVtbl -> GetAudioLevel(This,nChannel,nVolume) ) 

#define IFcsPlayer_GetP2AudioCount(This,nCount)	\
    ( (This)->lpVtbl -> GetP2AudioCount(This,nCount) ) 

#define IFcsPlayer_GetP2VideoName(This,bstrVideoName)	\
    ( (This)->lpVtbl -> GetP2VideoName(This,bstrVideoName) ) 

#define IFcsPlayer_GetP2AudioName(This,nIndex,bstrAudioName)	\
    ( (This)->lpVtbl -> GetP2AudioName(This,nIndex,bstrAudioName) ) 

#define IFcsPlayer_SetP2AudioName(This,bstrAudioName)	\
    ( (This)->lpVtbl -> SetP2AudioName(This,bstrAudioName) ) 

#define IFcsPlayer_RenderP2(This)	\
    ( (This)->lpVtbl -> RenderP2(This) ) 

#define IFcsPlayer_Free(This)	\
    ( (This)->lpVtbl -> Free(This) ) 

#define IFcsPlayer_snapImage(This,nIndex,bstrImagename)	\
    ( (This)->lpVtbl -> snapImage(This,nIndex,bstrImagename) ) 

#define IFcsPlayer_ChangeWindow(This,hWndHandle)	\
    ( (This)->lpVtbl -> ChangeWindow(This,hWndHandle) ) 

#define IFcsPlayer_ChangeHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> ChangeHWnd(This,hWnd) ) 

#define IFcsPlayer_LoadRun(This,bstrGrfName)	\
    ( (This)->lpVtbl -> LoadRun(This,bstrGrfName) ) 

#define IFcsPlayer_SetTemplateID(This,nTemplateID)	\
    ( (This)->lpVtbl -> SetTemplateID(This,nTemplateID) ) 

#define IFcsPlayer_SetSourceFile(This,bstrSourceName)	\
    ( (This)->lpVtbl -> SetSourceFile(This,bstrSourceName) ) 

#define IFcsPlayer_WaitForCompletion(This,nTimeOut,pEvCode)	\
    ( (This)->lpVtbl -> WaitForCompletion(This,nTimeOut,pEvCode) ) 

#define IFcsPlayer_AddOverlay(This,BstrOverlay,nLeft,nTop,nRight,nBottom,nScaleToFit)	\
    ( (This)->lpVtbl -> AddOverlay(This,BstrOverlay,nLeft,nTop,nRight,nBottom,nScaleToFit) ) 

#define IFcsPlayer_GetCurrentTimeString(This,bstrTime)	\
    ( (This)->lpVtbl -> GetCurrentTimeString(This,bstrTime) ) 

#define IFcsPlayer_SetFullScreen(This,mode)	\
    ( (This)->lpVtbl -> SetFullScreen(This,mode) ) 

#define IFcsPlayer_GetTcCode(This,timeNow,bstrTime)	\
    ( (This)->lpVtbl -> GetTcCode(This,timeNow,bstrTime) ) 

#define IFcsPlayer_FrameToRefTime(This,nFrame,refTime)	\
    ( (This)->lpVtbl -> FrameToRefTime(This,nFrame,refTime) ) 

#define IFcsPlayer_GetVideoInfo(This,nWidth,nHeight,dFps)	\
    ( (This)->lpVtbl -> GetVideoInfo(This,nWidth,nHeight,dFps) ) 

#define IFcsPlayer_SetSegment(This,nStart,nEnd)	\
    ( (This)->lpVtbl -> SetSegment(This,nStart,nEnd) ) 

#define IFcsPlayer_SetSegmentByMs(This,timeBegin,timeEnd)	\
    ( (This)->lpVtbl -> SetSegmentByMs(This,timeBegin,timeEnd) ) 

#define IFcsPlayer_GetFaceRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetFaceRect(This,left,top,right,bottom) ) 

#define IFcsPlayer_GetFaceImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetFaceImg(This,pImage,nSize) ) 

#define IFcsPlayer_GetFaceWidth(This,nWidth)	\
    ( (This)->lpVtbl -> GetFaceWidth(This,nWidth) ) 

#define IFcsPlayer_GetFaceHeight(This,nHeight)	\
    ( (This)->lpVtbl -> GetFaceHeight(This,nHeight) ) 

#define IFcsPlayer_GetLeadFace(This,pLeadFace)	\
    ( (This)->lpVtbl -> GetLeadFace(This,pLeadFace) ) 

#define IFcsPlayer_GetLEyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeRect(This,left,top,right,bottom) ) 

#define IFcsPlayer_GetREyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeRect(This,left,top,right,bottom) ) 

#define IFcsPlayer_GetLEyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeImg(This,pImage,nSize) ) 

#define IFcsPlayer_GetREyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeImg(This,pImage,nSize) ) 

#define IFcsPlayer_GetLEyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeballRect(This,left,top,right,bottom) ) 

#define IFcsPlayer_GetREyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeballRect(This,left,top,right,bottom) ) 

#define IFcsPlayer_GetLEyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeballImg(This,pImage,nSize) ) 

#define IFcsPlayer_GetREyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeballImg(This,pImage,nSize) ) 

#define IFcsPlayer_GetActivativedValue(This,dActivation)	\
    ( (This)->lpVtbl -> GetActivativedValue(This,dActivation) ) 

#define IFcsPlayer_GetBlinkCount(This,nCount)	\
    ( (This)->lpVtbl -> GetBlinkCount(This,nCount) ) 

#define IFcsPlayer_GetCurTimeMs(This,MilliSec)	\
    ( (This)->lpVtbl -> GetCurTimeMs(This,MilliSec) ) 

#define IFcsPlayer_GetCurTime(This,NSec)	\
    ( (This)->lpVtbl -> GetCurTime(This,NSec) ) 

#define IFcsPlayer_ResetCounter(This)	\
    ( (This)->lpVtbl -> ResetCounter(This) ) 

#define IFcsPlayer_SetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> SetCheck(This,nCheck) ) 

#define IFcsPlayer_GetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> GetCheck(This,nCheck) ) 

#define IFcsPlayer_SetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsPlayer_GetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsPlayer_SetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetEyeRectLineWidth(This,fLineWidth) ) 

#define IFcsPlayer_GetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetEyeRectLineWidth(This,fLineWidth) ) 

#define IFcsPlayer_DisplayOverlay(This,nID,IsVisible)	\
    ( (This)->lpVtbl -> DisplayOverlay(This,nID,IsVisible) ) 

#define IFcsPlayer_GetCountOfArray(This)	\
    ( (This)->lpVtbl -> GetCountOfArray(This) ) 

#define IFcsPlayer_SetOverlayPosition(This,nID,nLeft,nTop,nRight,nButtom)	\
    ( (This)->lpVtbl -> SetOverlayPosition(This,nID,nLeft,nTop,nRight,nButtom) ) 

#define IFcsPlayer_SetOverlayColor(This,nID,nColor)	\
    ( (This)->lpVtbl -> SetOverlayColor(This,nID,nColor) ) 

#define IFcsPlayer_SetOverlayFontSize(This,nID,nFontSize)	\
    ( (This)->lpVtbl -> SetOverlayFontSize(This,nID,nFontSize) ) 

#define IFcsPlayer_SetOverlayFont(This,nID,nFontStyle,bUnderLine,bWrap,bVertical,bRightAlign)	\
    ( (This)->lpVtbl -> SetOverlayFont(This,nID,nFontStyle,bUnderLine,bWrap,bVertical,bRightAlign) ) 

#define IFcsPlayer_SetOverlayText(This,nID,szText)	\
    ( (This)->lpVtbl -> SetOverlayText(This,nID,szText) ) 

#define IFcsPlayer_SetOverlayFontName(This,nID,szFontName)	\
    ( (This)->lpVtbl -> SetOverlayFontName(This,nID,szFontName) ) 

#define IFcsPlayer_SetOverlayImgPosition(This,szImgName,nLeft,nTop,nRight,nButtom,bDisplay,bScaleFit,nTranspency)	\
    ( (This)->lpVtbl -> SetOverlayImgPosition(This,szImgName,nLeft,nTop,nRight,nButtom,bDisplay,bScaleFit,nTranspency) ) 

#define IFcsPlayer_SetFps(This,dFps)	\
    ( (This)->lpVtbl -> SetFps(This,dFps) ) 

#define IFcsPlayer_GetFps(This,dFps)	\
    ( (This)->lpVtbl -> GetFps(This,dFps) ) 

#define IFcsPlayer_GetRate(This,pRate)	\
    ( (This)->lpVtbl -> GetRate(This,pRate) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_ResetCounter_Proxy( 
    IFcsPlayer * This);


void __RPC_STUB IFcsPlayer_ResetCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetCheck_Proxy( 
    IFcsPlayer * This,
    SHORT nCheck);


void __RPC_STUB IFcsPlayer_SetCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetCheck_Proxy( 
    IFcsPlayer * This,
    SHORT *nCheck);


void __RPC_STUB IFcsPlayer_GetCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetFaceRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT fLineWidth);


void __RPC_STUB IFcsPlayer_SetFaceRectLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetFaceRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT *fLineWidth);


void __RPC_STUB IFcsPlayer_GetFaceRectLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetEyeRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT fLineWidth);


void __RPC_STUB IFcsPlayer_SetEyeRectLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetEyeRectLineWidth_Proxy( 
    IFcsPlayer * This,
    FLOAT *fLineWidth);


void __RPC_STUB IFcsPlayer_GetEyeRectLineWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_DisplayOverlay_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    SHORT IsVisible);


void __RPC_STUB IFcsPlayer_DisplayOverlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetCountOfArray_Proxy( 
    IFcsPlayer * This);


void __RPC_STUB IFcsPlayer_GetCountOfArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayPosition_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nLeft,
    LONG nTop,
    LONG nRight,
    LONG nButtom);


void __RPC_STUB IFcsPlayer_SetOverlayPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayColor_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    COLORREF nColor);


void __RPC_STUB IFcsPlayer_SetOverlayColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFontSize_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nFontSize);


void __RPC_STUB IFcsPlayer_SetOverlayFontSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFont_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    LONG nFontStyle,
    SHORT bUnderLine,
    SHORT bWrap,
    SHORT bVertical,
    SHORT bRightAlign);


void __RPC_STUB IFcsPlayer_SetOverlayFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayText_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    BSTR szText);


void __RPC_STUB IFcsPlayer_SetOverlayText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayFontName_Proxy( 
    IFcsPlayer * This,
    LONG nID,
    BSTR szFontName);


void __RPC_STUB IFcsPlayer_SetOverlayFontName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetOverlayImgPosition_Proxy( 
    IFcsPlayer * This,
    BSTR szImgName,
    LONG nLeft,
    LONG nTop,
    LONG nRight,
    LONG nButtom,
    SHORT bDisplay,
    SHORT bScaleFit,
    LONG nTranspency);


void __RPC_STUB IFcsPlayer_SetOverlayImgPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_SetFps_Proxy( 
    IFcsPlayer * This,
    DOUBLE dFps);


void __RPC_STUB IFcsPlayer_SetFps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetFps_Proxy( 
    IFcsPlayer * This,
    DOUBLE *dFps);


void __RPC_STUB IFcsPlayer_GetFps_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFcsPlayer_GetRate_Proxy( 
    IFcsPlayer * This,
    DOUBLE *pRate);


void __RPC_STUB IFcsPlayer_GetRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFcsPlayer_INTERFACE_DEFINED__ */


#ifndef __IExportManager_INTERFACE_DEFINED__
#define __IExportManager_INTERFACE_DEFINED__

/* interface IExportManager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExportManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10A84D63-730E-4F91-819B-9190EC57CBDC")
    IExportManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEventWindow( 
            HWND hWnd,
            UINT msg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_SetWindow( 
            long hParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_SetSourceFile( 
            BSTR szSourceName,
            long nFormat,
            long nSeg,
            long nStart,
            long nEnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_SetSinkFile( 
            BSTR szSinkName,
            long nFormat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_GetLength( 
            LONG *nLength) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_GetPosition( 
            LONG *iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEvent( 
            long *iEvent,
            long *L1,
            long *L2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_ShowConfig( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Render( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE KF_KeyFrame( 
            BSTR bstrVideoName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKeyFrameBasicParams( 
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveKFInfo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphPath( 
            BSTR bstrGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE State( 
            UINT *state) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanSeek( 
            BOOL *bCanSeek) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TC_Seek( 
            long iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2AudioCount( 
            long *nCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2VideoName( 
            BSTR bstrVideoName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetP2AudioName( 
            long nIndex,
            BSTR *bstrAudioName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetP2AudioName( 
            BSTR bstrAudioName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRange( 
            long nBeginFrame,
            long nEndFrame,
            long nSeg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadRun( 
            BSTR bstrGrfName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeWindow( 
            long hWndHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDuration( 
            LONGLONG *nDuration) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForCompletion( 
            long nTimeOut,
            long *pEvCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PackAvi( 
            BSTR bstrVideo,
            BSTR bstrAudio1,
            BSTR bstrAudio2,
            BSTR bstrAudio3,
            BSTR bstrOutAvi) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExportManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExportManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExportManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExportManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExportManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExportManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExportManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExportManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetEventWindow )( 
            IExportManager * This,
            HWND hWnd,
            UINT msg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_SetWindow )( 
            IExportManager * This,
            long hParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_SetSourceFile )( 
            IExportManager * This,
            BSTR szSourceName,
            long nFormat,
            long nSeg,
            long nStart,
            long nEnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_SetSinkFile )( 
            IExportManager * This,
            BSTR szSinkName,
            long nFormat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_GetLength )( 
            IExportManager * This,
            LONG *nLength);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Run )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_GetPosition )( 
            IExportManager * This,
            LONG *iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Stop )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEvent )( 
            IExportManager * This,
            long *iEvent,
            long *L1,
            long *L2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_ShowConfig )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Init )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Render )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Free )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IExportManager * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *KF_KeyFrame )( 
            IExportManager * This,
            BSTR bstrVideoName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKeyFrameBasicParams )( 
            IExportManager * This,
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveKFInfo )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphPath )( 
            IExportManager * This,
            BSTR bstrGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *State )( 
            IExportManager * This,
            UINT *state);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanSeek )( 
            IExportManager * This,
            BOOL *bCanSeek);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IExportManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TC_Seek )( 
            IExportManager * This,
            long iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2AudioCount )( 
            IExportManager * This,
            long *nCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2VideoName )( 
            IExportManager * This,
            BSTR bstrVideoName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetP2AudioName )( 
            IExportManager * This,
            long nIndex,
            BSTR *bstrAudioName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetP2AudioName )( 
            IExportManager * This,
            BSTR bstrAudioName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRange )( 
            IExportManager * This,
            long nBeginFrame,
            long nEndFrame,
            long nSeg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadRun )( 
            IExportManager * This,
            BSTR bstrGrfName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeWindow )( 
            IExportManager * This,
            long hWndHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeHWnd )( 
            IExportManager * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDuration )( 
            IExportManager * This,
            LONGLONG *nDuration);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForCompletion )( 
            IExportManager * This,
            long nTimeOut,
            long *pEvCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PackAvi )( 
            IExportManager * This,
            BSTR bstrVideo,
            BSTR bstrAudio1,
            BSTR bstrAudio2,
            BSTR bstrAudio3,
            BSTR bstrOutAvi);
        
        END_INTERFACE
    } IExportManagerVtbl;

    interface IExportManager
    {
        CONST_VTBL struct IExportManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExportManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExportManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExportManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExportManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IExportManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IExportManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IExportManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IExportManager_SetEventWindow(This,hWnd,msg)	\
    ( (This)->lpVtbl -> SetEventWindow(This,hWnd,msg) ) 

#define IExportManager_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IExportManager_TC_SetWindow(This,hParent)	\
    ( (This)->lpVtbl -> TC_SetWindow(This,hParent) ) 

#define IExportManager_TC_SetSourceFile(This,szSourceName,nFormat,nSeg,nStart,nEnd)	\
    ( (This)->lpVtbl -> TC_SetSourceFile(This,szSourceName,nFormat,nSeg,nStart,nEnd) ) 

#define IExportManager_TC_SetSinkFile(This,szSinkName,nFormat)	\
    ( (This)->lpVtbl -> TC_SetSinkFile(This,szSinkName,nFormat) ) 

#define IExportManager_TC_GetLength(This,nLength)	\
    ( (This)->lpVtbl -> TC_GetLength(This,nLength) ) 

#define IExportManager_TC_Run(This)	\
    ( (This)->lpVtbl -> TC_Run(This) ) 

#define IExportManager_TC_GetPosition(This,iPos)	\
    ( (This)->lpVtbl -> TC_GetPosition(This,iPos) ) 

#define IExportManager_TC_Stop(This)	\
    ( (This)->lpVtbl -> TC_Stop(This) ) 

#define IExportManager_GetEvent(This,iEvent,L1,L2)	\
    ( (This)->lpVtbl -> GetEvent(This,iEvent,L1,L2) ) 

#define IExportManager_TC_ShowConfig(This)	\
    ( (This)->lpVtbl -> TC_ShowConfig(This) ) 

#define IExportManager_TC_Init(This)	\
    ( (This)->lpVtbl -> TC_Init(This) ) 

#define IExportManager_TC_Render(This)	\
    ( (This)->lpVtbl -> TC_Render(This) ) 

#define IExportManager_TC_Free(This)	\
    ( (This)->lpVtbl -> TC_Free(This) ) 

#define IExportManager_SetWindow(This,hWnd)	\
    ( (This)->lpVtbl -> SetWindow(This,hWnd) ) 

#define IExportManager_KF_KeyFrame(This,bstrVideoName)	\
    ( (This)->lpVtbl -> KF_KeyFrame(This,bstrVideoName) ) 

#define IExportManager_SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath)	\
    ( (This)->lpVtbl -> SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath) ) 

#define IExportManager_SaveKFInfo(This)	\
    ( (This)->lpVtbl -> SaveKFInfo(This) ) 

#define IExportManager_SetGraphPath(This,bstrGraphPath)	\
    ( (This)->lpVtbl -> SetGraphPath(This,bstrGraphPath) ) 

#define IExportManager_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IExportManager_State(This,state)	\
    ( (This)->lpVtbl -> State(This,state) ) 

#define IExportManager_CanSeek(This,bCanSeek)	\
    ( (This)->lpVtbl -> CanSeek(This,bCanSeek) ) 

#define IExportManager_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IExportManager_TC_Seek(This,iPos)	\
    ( (This)->lpVtbl -> TC_Seek(This,iPos) ) 

#define IExportManager_GetP2AudioCount(This,nCount)	\
    ( (This)->lpVtbl -> GetP2AudioCount(This,nCount) ) 

#define IExportManager_GetP2VideoName(This,bstrVideoName)	\
    ( (This)->lpVtbl -> GetP2VideoName(This,bstrVideoName) ) 

#define IExportManager_GetP2AudioName(This,nIndex,bstrAudioName)	\
    ( (This)->lpVtbl -> GetP2AudioName(This,nIndex,bstrAudioName) ) 

#define IExportManager_SetP2AudioName(This,bstrAudioName)	\
    ( (This)->lpVtbl -> SetP2AudioName(This,bstrAudioName) ) 

#define IExportManager_SetRange(This,nBeginFrame,nEndFrame,nSeg)	\
    ( (This)->lpVtbl -> SetRange(This,nBeginFrame,nEndFrame,nSeg) ) 

#define IExportManager_LoadRun(This,bstrGrfName)	\
    ( (This)->lpVtbl -> LoadRun(This,bstrGrfName) ) 

#define IExportManager_ChangeWindow(This,hWndHandle)	\
    ( (This)->lpVtbl -> ChangeWindow(This,hWndHandle) ) 

#define IExportManager_ChangeHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> ChangeHWnd(This,hWnd) ) 

#define IExportManager_GetDuration(This,nDuration)	\
    ( (This)->lpVtbl -> GetDuration(This,nDuration) ) 

#define IExportManager_WaitForCompletion(This,nTimeOut,pEvCode)	\
    ( (This)->lpVtbl -> WaitForCompletion(This,nTimeOut,pEvCode) ) 

#define IExportManager_PackAvi(This,bstrVideo,bstrAudio1,bstrAudio2,bstrAudio3,bstrOutAvi)	\
    ( (This)->lpVtbl -> PackAvi(This,bstrVideo,bstrAudio1,bstrAudio2,bstrAudio3,bstrOutAvi) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExportManager_INTERFACE_DEFINED__ */


#ifndef __IFcsGrabber_INTERFACE_DEFINED__
#define __IFcsGrabber_INTERFACE_DEFINED__

/* interface IFcsGrabber */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFcsGrabber;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58BB1EDE-A0AA-48C2-B528-7EEDB826CD95")
    IFcsGrabber : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            long hParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosition( 
            long *iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek( 
            long iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowPosition( 
            long top,
            long left,
            long Width,
            long Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFile( 
            BSTR szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Render( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLength( 
            long *nLength) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            long nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudio( 
            long nChannelID,
            long *nVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPosition( 
            LONGLONG pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphPath( 
            BSTR bstrGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSinkFile( 
            BSTR bstrPathName,
            BSTR bstrPathName1,
            long nTemplateID,
            long nFileNo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateVideoWindow( 
            const LPRECT prc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoSize( 
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Repaint( 
            HDC hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Record( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateWindow( 
            long left,
            long top,
            long right,
            long bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE State( 
            long *nState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioLevel( 
            long nChannel,
            long *nVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKeyFrameBasicParams( 
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveKFInfo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeWindow( 
            long hWndHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGraphPath( 
            BSTR *strGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsMute( 
            SHORT *bMute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFps( 
            DOUBLE *dFps) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFullScreen( 
            SHORT *nResult,
            SHORT nState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapImage( 
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MP_GetPosition( 
            LONG *nIndex) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurrentPosition( 
            LONGLONG *pTimeNow) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceWidth( 
            LONG *nWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceHeight( 
            LONG *nHeight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLeadFace( 
            BYTE *pLeadFace) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActivativedValue( 
            DOUBLE *dActivation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetBlinkCount( 
            LONG *nCount) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTimeMs( 
            LONG *MilliSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTime( 
            LONGLONG *NSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetCounter( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCheck( 
            SHORT nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCheck( 
            SHORT *nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFaceRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetEyeRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetEyeRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisPlayOverlay( 
            LONG nID,
            SHORT IsVisible) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCountOfArray( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayPosition( 
            LONG nId,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nBottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayColor( 
            LONG nID,
            COLORREF nColor) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFontSize( 
            LONG nID,
            LONG nFontSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFont( 
            LONG nID,
            LONG nFontStyle,
            SHORT bUnderLine,
            SHORT bWrap,
            SHORT bVertical,
            SHORT bRightAlign) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayText( 
            LONG nID,
            BSTR szText) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayFontName( 
            LONG nID,
            BSTR szFontName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOverlayImgPosition( 
            BSTR szImgName,
            LONG left,
            LONG top,
            LONG right,
            LONG bottom,
            SHORT bDisplay,
            SHORT bScaleFit,
            LONG nTranspency) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EnableRoi( 
            SHORT Enable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRoi( 
            LONG left,
            LONG top,
            LONG right,
            LONG bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowRoi( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRoiProp( 
            LONG nColor,
            LONG PenStyle,
            LONG LineWidth,
            LONG ShapeType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapGrayImage( 
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExportDir( 
            BSTR ExportDir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExportName( 
            BSTR ImageName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExportImageWidth( 
            LONG Width) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExportImageHeight( 
            LONG Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCompressRatio( 
            LONG Ratio) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaptureFreq( 
            LONG Freq) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaneraFps( 
            LONG FramePerSec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableCapture( 
            LONG Enable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WaitForCompletion( 
            LONG nTimeout,
            LONG *evtCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFcsGrabberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFcsGrabber * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFcsGrabber * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFcsGrabber * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFcsGrabber * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFcsGrabber * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFcsGrabber * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFcsGrabber * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IFcsGrabber * This,
            long hParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPosition )( 
            IFcsGrabber * This,
            long *iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IFcsGrabber * This,
            long iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowPosition )( 
            IFcsGrabber * This,
            long top,
            long left,
            long Width,
            long Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Free )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            IFcsGrabber * This,
            BSTR szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IFcsGrabber * This,
            long *nLength);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOption )( 
            IFcsGrabber * This,
            long nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            IFcsGrabber * This,
            long nChannelID,
            long *nVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPosition )( 
            IFcsGrabber * This,
            LONGLONG pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphPath )( 
            IFcsGrabber * This,
            BSTR bstrGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSinkFile )( 
            IFcsGrabber * This,
            BSTR bstrPathName,
            BSTR bstrPathName1,
            long nTemplateID,
            long nFileNo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHWnd )( 
            IFcsGrabber * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateVideoWindow )( 
            IFcsGrabber * This,
            const LPRECT prc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoSize )( 
            IFcsGrabber * This,
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Repaint )( 
            IFcsGrabber * This,
            HDC hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Record )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateWindow )( 
            IFcsGrabber * This,
            long left,
            long top,
            long right,
            long bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *State )( 
            IFcsGrabber * This,
            long *nState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudioLevel )( 
            IFcsGrabber * This,
            long nChannel,
            long *nVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKeyFrameBasicParams )( 
            IFcsGrabber * This,
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveKFInfo )( 
            IFcsGrabber * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeWindow )( 
            IFcsGrabber * This,
            long hWndHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeHWnd )( 
            IFcsGrabber * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGraphPath )( 
            IFcsGrabber * This,
            BSTR *strGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsMute )( 
            IFcsGrabber * This,
            SHORT *bMute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoFps )( 
            IFcsGrabber * This,
            DOUBLE *dFps);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFullScreen )( 
            IFcsGrabber * This,
            SHORT *nResult,
            SHORT nState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapImage )( 
            IFcsGrabber * This,
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MP_GetPosition )( 
            IFcsGrabber * This,
            LONG *nIndex);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentPosition )( 
            IFcsGrabber * This,
            LONGLONG *pTimeNow);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRect )( 
            IFcsGrabber * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceWidth )( 
            IFcsGrabber * This,
            LONG *nWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceHeight )( 
            IFcsGrabber * This,
            LONG *nHeight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeRect )( 
            IFcsGrabber * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeRect )( 
            IFcsGrabber * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballRect )( 
            IFcsGrabber * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballRect )( 
            IFcsGrabber * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceImg )( 
            IFcsGrabber * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeImg )( 
            IFcsGrabber * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeImg )( 
            IFcsGrabber * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballImg )( 
            IFcsGrabber * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballImg )( 
            IFcsGrabber * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLeadFace )( 
            IFcsGrabber * This,
            BYTE *pLeadFace);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActivativedValue )( 
            IFcsGrabber * This,
            DOUBLE *dActivation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetBlinkCount )( 
            IFcsGrabber * This,
            LONG *nCount);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTimeMs )( 
            IFcsGrabber * This,
            LONG *MilliSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTime )( 
            IFcsGrabber * This,
            LONGLONG *NSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetCounter )( 
            IFcsGrabber * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCheck )( 
            IFcsGrabber * This,
            SHORT nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCheck )( 
            IFcsGrabber * This,
            SHORT *nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFaceRectLineWidth )( 
            IFcsGrabber * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRectLineWidth )( 
            IFcsGrabber * This,
            FLOAT *fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetEyeRectLineWidth )( 
            IFcsGrabber * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetEyeRectLineWidth )( 
            IFcsGrabber * This,
            FLOAT *fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisPlayOverlay )( 
            IFcsGrabber * This,
            LONG nID,
            SHORT IsVisible);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCountOfArray )( 
            IFcsGrabber * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayPosition )( 
            IFcsGrabber * This,
            LONG nId,
            LONG nLeft,
            LONG nTop,
            LONG nRight,
            LONG nBottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayColor )( 
            IFcsGrabber * This,
            LONG nID,
            COLORREF nColor);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFontSize )( 
            IFcsGrabber * This,
            LONG nID,
            LONG nFontSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFont )( 
            IFcsGrabber * This,
            LONG nID,
            LONG nFontStyle,
            SHORT bUnderLine,
            SHORT bWrap,
            SHORT bVertical,
            SHORT bRightAlign);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayText )( 
            IFcsGrabber * This,
            LONG nID,
            BSTR szText);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayFontName )( 
            IFcsGrabber * This,
            LONG nID,
            BSTR szFontName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayImgPosition )( 
            IFcsGrabber * This,
            BSTR szImgName,
            LONG left,
            LONG top,
            LONG right,
            LONG bottom,
            SHORT bDisplay,
            SHORT bScaleFit,
            LONG nTranspency);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EnableRoi )( 
            IFcsGrabber * This,
            SHORT Enable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetRoi )( 
            IFcsGrabber * This,
            LONG left,
            LONG top,
            LONG right,
            LONG bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowRoi )( 
            IFcsGrabber * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetRoiProp )( 
            IFcsGrabber * This,
            LONG nColor,
            LONG PenStyle,
            LONG LineWidth,
            LONG ShapeType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapGrayImage )( 
            IFcsGrabber * This,
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExportDir )( 
            IFcsGrabber * This,
            BSTR ExportDir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExportName )( 
            IFcsGrabber * This,
            BSTR ImageName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExportImageWidth )( 
            IFcsGrabber * This,
            LONG Width);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExportImageHeight )( 
            IFcsGrabber * This,
            LONG Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCompressRatio )( 
            IFcsGrabber * This,
            LONG Ratio);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureFreq )( 
            IFcsGrabber * This,
            LONG Freq);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaneraFps )( 
            IFcsGrabber * This,
            LONG FramePerSec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableCapture )( 
            IFcsGrabber * This,
            LONG Enable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WaitForCompletion )( 
            IFcsGrabber * This,
            LONG nTimeout,
            LONG *evtCode);
        
        END_INTERFACE
    } IFcsGrabberVtbl;

    interface IFcsGrabber
    {
        CONST_VTBL struct IFcsGrabberVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFcsGrabber_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFcsGrabber_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFcsGrabber_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFcsGrabber_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFcsGrabber_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFcsGrabber_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFcsGrabber_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFcsGrabber_SetWindow(This,hParent)	\
    ( (This)->lpVtbl -> SetWindow(This,hParent) ) 

#define IFcsGrabber_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IFcsGrabber_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IFcsGrabber_GetPosition(This,iPos)	\
    ( (This)->lpVtbl -> GetPosition(This,iPos) ) 

#define IFcsGrabber_Seek(This,iPos)	\
    ( (This)->lpVtbl -> Seek(This,iPos) ) 

#define IFcsGrabber_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IFcsGrabber_SetWindowPosition(This,top,left,Width,Height)	\
    ( (This)->lpVtbl -> SetWindowPosition(This,top,left,Width,Height) ) 

#define IFcsGrabber_Free(This)	\
    ( (This)->lpVtbl -> Free(This) ) 

#define IFcsGrabber_Init(This)	\
    ( (This)->lpVtbl -> Init(This) ) 

#define IFcsGrabber_SetFile(This,szPathName)	\
    ( (This)->lpVtbl -> SetFile(This,szPathName) ) 

#define IFcsGrabber_Render(This)	\
    ( (This)->lpVtbl -> Render(This) ) 

#define IFcsGrabber_GetLength(This,nLength)	\
    ( (This)->lpVtbl -> GetLength(This,nLength) ) 

#define IFcsGrabber_SetOption(This,nOption)	\
    ( (This)->lpVtbl -> SetOption(This,nOption) ) 

#define IFcsGrabber_GetAudio(This,nChannelID,nVolume)	\
    ( (This)->lpVtbl -> GetAudio(This,nChannelID,nVolume) ) 

#define IFcsGrabber_SetPosition(This,pos)	\
    ( (This)->lpVtbl -> SetPosition(This,pos) ) 

#define IFcsGrabber_SetGraphPath(This,bstrGraphPath)	\
    ( (This)->lpVtbl -> SetGraphPath(This,bstrGraphPath) ) 

#define IFcsGrabber_SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo)	\
    ( (This)->lpVtbl -> SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo) ) 

#define IFcsGrabber_SetHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> SetHWnd(This,hWnd) ) 

#define IFcsGrabber_UpdateVideoWindow(This,prc)	\
    ( (This)->lpVtbl -> UpdateVideoWindow(This,prc) ) 

#define IFcsGrabber_GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight)	\
    ( (This)->lpVtbl -> GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight) ) 

#define IFcsGrabber_Repaint(This,hdc)	\
    ( (This)->lpVtbl -> Repaint(This,hdc) ) 

#define IFcsGrabber_Record(This)	\
    ( (This)->lpVtbl -> Record(This) ) 

#define IFcsGrabber_UpdateWindow(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> UpdateWindow(This,left,top,right,bottom) ) 

#define IFcsGrabber_State(This,nState)	\
    ( (This)->lpVtbl -> State(This,nState) ) 

#define IFcsGrabber_GetAudioLevel(This,nChannel,nVolume)	\
    ( (This)->lpVtbl -> GetAudioLevel(This,nChannel,nVolume) ) 

#define IFcsGrabber_SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath)	\
    ( (This)->lpVtbl -> SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath) ) 

#define IFcsGrabber_SaveKFInfo(This)	\
    ( (This)->lpVtbl -> SaveKFInfo(This) ) 

#define IFcsGrabber_ChangeWindow(This,hWndHandle)	\
    ( (This)->lpVtbl -> ChangeWindow(This,hWndHandle) ) 

#define IFcsGrabber_ChangeHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> ChangeHWnd(This,hWnd) ) 

#define IFcsGrabber_GetGraphPath(This,strGraphPath)	\
    ( (This)->lpVtbl -> GetGraphPath(This,strGraphPath) ) 

#define IFcsGrabber_IsMute(This,bMute)	\
    ( (This)->lpVtbl -> IsMute(This,bMute) ) 

#define IFcsGrabber_GetVideoFps(This,dFps)	\
    ( (This)->lpVtbl -> GetVideoFps(This,dFps) ) 

#define IFcsGrabber_SetFullScreen(This,nResult,nState)	\
    ( (This)->lpVtbl -> SetFullScreen(This,nResult,nState) ) 

#define IFcsGrabber_SnapImage(This,bstrImagename,nNewWidth,nNewHeight)	\
    ( (This)->lpVtbl -> SnapImage(This,bstrImagename,nNewWidth,nNewHeight) ) 

#define IFcsGrabber_MP_GetPosition(This,nIndex)	\
    ( (This)->lpVtbl -> MP_GetPosition(This,nIndex) ) 

#define IFcsGrabber_GetCurrentPosition(This,pTimeNow)	\
    ( (This)->lpVtbl -> GetCurrentPosition(This,pTimeNow) ) 

#define IFcsGrabber_GetFaceRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetFaceRect(This,left,top,right,bottom) ) 

#define IFcsGrabber_GetFaceWidth(This,nWidth)	\
    ( (This)->lpVtbl -> GetFaceWidth(This,nWidth) ) 

#define IFcsGrabber_GetFaceHeight(This,nHeight)	\
    ( (This)->lpVtbl -> GetFaceHeight(This,nHeight) ) 

#define IFcsGrabber_GetLEyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeRect(This,left,top,right,bottom) ) 

#define IFcsGrabber_GetREyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeRect(This,left,top,right,bottom) ) 

#define IFcsGrabber_GetLEyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeballRect(This,left,top,right,bottom) ) 

#define IFcsGrabber_GetREyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeballRect(This,left,top,right,bottom) ) 

#define IFcsGrabber_GetFaceImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetFaceImg(This,pImage,nSize) ) 

#define IFcsGrabber_GetLEyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeImg(This,pImage,nSize) ) 

#define IFcsGrabber_GetREyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeImg(This,pImage,nSize) ) 

#define IFcsGrabber_GetLEyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeballImg(This,pImage,nSize) ) 

#define IFcsGrabber_GetREyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeballImg(This,pImage,nSize) ) 

#define IFcsGrabber_GetLeadFace(This,pLeadFace)	\
    ( (This)->lpVtbl -> GetLeadFace(This,pLeadFace) ) 

#define IFcsGrabber_GetActivativedValue(This,dActivation)	\
    ( (This)->lpVtbl -> GetActivativedValue(This,dActivation) ) 

#define IFcsGrabber_GetBlinkCount(This,nCount)	\
    ( (This)->lpVtbl -> GetBlinkCount(This,nCount) ) 

#define IFcsGrabber_GetCurTimeMs(This,MilliSec)	\
    ( (This)->lpVtbl -> GetCurTimeMs(This,MilliSec) ) 

#define IFcsGrabber_GetCurTime(This,NSec)	\
    ( (This)->lpVtbl -> GetCurTime(This,NSec) ) 

#define IFcsGrabber_ResetCounter(This)	\
    ( (This)->lpVtbl -> ResetCounter(This) ) 

#define IFcsGrabber_SetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> SetCheck(This,nCheck) ) 

#define IFcsGrabber_GetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> GetCheck(This,nCheck) ) 

#define IFcsGrabber_SetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsGrabber_GetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsGrabber_SetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetEyeRectLineWidth(This,fLineWidth) ) 

#define IFcsGrabber_GetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetEyeRectLineWidth(This,fLineWidth) ) 

#define IFcsGrabber_DisPlayOverlay(This,nID,IsVisible)	\
    ( (This)->lpVtbl -> DisPlayOverlay(This,nID,IsVisible) ) 

#define IFcsGrabber_GetCountOfArray(This)	\
    ( (This)->lpVtbl -> GetCountOfArray(This) ) 

#define IFcsGrabber_SetOverlayPosition(This,nId,nLeft,nTop,nRight,nBottom)	\
    ( (This)->lpVtbl -> SetOverlayPosition(This,nId,nLeft,nTop,nRight,nBottom) ) 

#define IFcsGrabber_SetOverlayColor(This,nID,nColor)	\
    ( (This)->lpVtbl -> SetOverlayColor(This,nID,nColor) ) 

#define IFcsGrabber_SetOverlayFontSize(This,nID,nFontSize)	\
    ( (This)->lpVtbl -> SetOverlayFontSize(This,nID,nFontSize) ) 

#define IFcsGrabber_SetOverlayFont(This,nID,nFontStyle,bUnderLine,bWrap,bVertical,bRightAlign)	\
    ( (This)->lpVtbl -> SetOverlayFont(This,nID,nFontStyle,bUnderLine,bWrap,bVertical,bRightAlign) ) 

#define IFcsGrabber_SetOverlayText(This,nID,szText)	\
    ( (This)->lpVtbl -> SetOverlayText(This,nID,szText) ) 

#define IFcsGrabber_SetOverlayFontName(This,nID,szFontName)	\
    ( (This)->lpVtbl -> SetOverlayFontName(This,nID,szFontName) ) 

#define IFcsGrabber_SetOverlayImgPosition(This,szImgName,left,top,right,bottom,bDisplay,bScaleFit,nTranspency)	\
    ( (This)->lpVtbl -> SetOverlayImgPosition(This,szImgName,left,top,right,bottom,bDisplay,bScaleFit,nTranspency) ) 

#define IFcsGrabber_EnableRoi(This,Enable)	\
    ( (This)->lpVtbl -> EnableRoi(This,Enable) ) 

#define IFcsGrabber_SetRoi(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> SetRoi(This,left,top,right,bottom) ) 

#define IFcsGrabber_ShowRoi(This)	\
    ( (This)->lpVtbl -> ShowRoi(This) ) 

#define IFcsGrabber_SetRoiProp(This,nColor,PenStyle,LineWidth,ShapeType)	\
    ( (This)->lpVtbl -> SetRoiProp(This,nColor,PenStyle,LineWidth,ShapeType) ) 

#define IFcsGrabber_SnapGrayImage(This,bstrImagename,nNewWidth,nNewHeight)	\
    ( (This)->lpVtbl -> SnapGrayImage(This,bstrImagename,nNewWidth,nNewHeight) ) 

#define IFcsGrabber_SetExportDir(This,ExportDir)	\
    ( (This)->lpVtbl -> SetExportDir(This,ExportDir) ) 

#define IFcsGrabber_SetExportName(This,ImageName)	\
    ( (This)->lpVtbl -> SetExportName(This,ImageName) ) 

#define IFcsGrabber_SetExportImageWidth(This,Width)	\
    ( (This)->lpVtbl -> SetExportImageWidth(This,Width) ) 

#define IFcsGrabber_SetExportImageHeight(This,Height)	\
    ( (This)->lpVtbl -> SetExportImageHeight(This,Height) ) 

#define IFcsGrabber_SetCompressRatio(This,Ratio)	\
    ( (This)->lpVtbl -> SetCompressRatio(This,Ratio) ) 

#define IFcsGrabber_SetCaptureFreq(This,Freq)	\
    ( (This)->lpVtbl -> SetCaptureFreq(This,Freq) ) 

#define IFcsGrabber_SetCaneraFps(This,FramePerSec)	\
    ( (This)->lpVtbl -> SetCaneraFps(This,FramePerSec) ) 

#define IFcsGrabber_EnableCapture(This,Enable)	\
    ( (This)->lpVtbl -> EnableCapture(This,Enable) ) 

#define IFcsGrabber_WaitForCompletion(This,nTimeout,evtCode)	\
    ( (This)->lpVtbl -> WaitForCompletion(This,nTimeout,evtCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFcsGrabber_INTERFACE_DEFINED__ */


#ifndef __IFcsDVManager_INTERFACE_DEFINED__
#define __IFcsDVManager_INTERFACE_DEFINED__

/* interface IFcsDVManager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFcsDVManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C683837-F99F-4A06-9089-4BC69683F123")
    IFcsDVManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            long hParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosition( 
            long *iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Seek( 
            long iPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowPosition( 
            long top,
            long left,
            long Width,
            long Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFile( 
            BSTR szPathName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Render( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLength( 
            long *nLength) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOption( 
            long nOption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudio( 
            long nChannelID,
            long *nVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPosition( 
            LONGLONG pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphPath( 
            BSTR bstrGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSinkFile( 
            BSTR bstrPathName,
            BSTR bstrPathName1,
            long nTemplateID,
            long nFileNo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateVideoWindow( 
            const LPRECT prc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoSize( 
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Repaint( 
            HDC hdc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Record( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateWindow( 
            long left,
            long top,
            long right,
            long bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE State( 
            long *nState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAudioLevel( 
            long nChannel,
            long *nVolume) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetKeyFrameBasicParams( 
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveKFInfo( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoteControl( 
            long nFunctionID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDVMode( 
            long *nDvMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeWindow( 
            long hWndHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PowerOn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PowerOff( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StandBy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDvRate( 
            long nRate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDvRate( 
            double *dRate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGraphPath( 
            BSTR *strGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsMute( 
            SHORT *bMute) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoFps( 
            DOUBLE *dFps) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapImage( 
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MP_GetPosition( 
            LONG *nIndex) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurrentPosition( 
            LONGLONG *pTimeNow) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceWidth( 
            LONG *nWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceHeight( 
            LONG *nHeight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballRect( 
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLEyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetREyeballImg( 
            BYTE *pImage,
            LONG nSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLeadFace( 
            BYTE *pLeadFace) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActivativedValue( 
            DOUBLE *dActivation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetBlinkCount( 
            LONG *nCount) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTimeMs( 
            LONG *MilliSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCurTime( 
            LONGLONG *NSec) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetCounter( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCheck( 
            SHORT nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCheck( 
            SHORT *nCheck) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFaceRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFaceRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetEyeRectLineWidth( 
            FLOAT fLineWidth) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetEyeRectLineWidth( 
            FLOAT *fLineWidth) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFcsDVManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFcsDVManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFcsDVManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFcsDVManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFcsDVManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFcsDVManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFcsDVManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFcsDVManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IFcsDVManager * This,
            long hParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPosition )( 
            IFcsDVManager * This,
            long *iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IFcsDVManager * This,
            long iPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowPosition )( 
            IFcsDVManager * This,
            long top,
            long left,
            long Width,
            long Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Free )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFile )( 
            IFcsDVManager * This,
            BSTR szPathName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IFcsDVManager * This,
            long *nLength);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOption )( 
            IFcsDVManager * This,
            long nOption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudio )( 
            IFcsDVManager * This,
            long nChannelID,
            long *nVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPosition )( 
            IFcsDVManager * This,
            LONGLONG pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphPath )( 
            IFcsDVManager * This,
            BSTR bstrGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSinkFile )( 
            IFcsDVManager * This,
            BSTR bstrPathName,
            BSTR bstrPathName1,
            long nTemplateID,
            long nFileNo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHWnd )( 
            IFcsDVManager * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateVideoWindow )( 
            IFcsDVManager * This,
            const LPRECT prc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoSize )( 
            IFcsDVManager * This,
            long *lpWidth,
            long *lpHeight,
            long *lpARWidth,
            long *lpARHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Repaint )( 
            IFcsDVManager * This,
            HDC hdc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Record )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateWindow )( 
            IFcsDVManager * This,
            long left,
            long top,
            long right,
            long bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *State )( 
            IFcsDVManager * This,
            long *nState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAudioLevel )( 
            IFcsDVManager * This,
            long nChannel,
            long *nVolume);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetKeyFrameBasicParams )( 
            IFcsDVManager * This,
            long nWidth,
            long nHeight,
            BOOL bOcr,
            long nOcrY1,
            long nOcrY2,
            BSTR szExportPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveKFInfo )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoteControl )( 
            IFcsDVManager * This,
            long nFunctionID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDVMode )( 
            IFcsDVManager * This,
            long *nDvMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeWindow )( 
            IFcsDVManager * This,
            long hWndHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeHWnd )( 
            IFcsDVManager * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PowerOn )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PowerOff )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StandBy )( 
            IFcsDVManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDvRate )( 
            IFcsDVManager * This,
            long nRate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDvRate )( 
            IFcsDVManager * This,
            double *dRate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGraphPath )( 
            IFcsDVManager * This,
            BSTR *strGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsMute )( 
            IFcsDVManager * This,
            SHORT *bMute);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoFps )( 
            IFcsDVManager * This,
            DOUBLE *dFps);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapImage )( 
            IFcsDVManager * This,
            BSTR bstrImagename,
            LONG nNewWidth,
            LONG nNewHeight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MP_GetPosition )( 
            IFcsDVManager * This,
            LONG *nIndex);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurrentPosition )( 
            IFcsDVManager * This,
            LONGLONG *pTimeNow);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRect )( 
            IFcsDVManager * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceWidth )( 
            IFcsDVManager * This,
            LONG *nWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceHeight )( 
            IFcsDVManager * This,
            LONG *nHeight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeRect )( 
            IFcsDVManager * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeRect )( 
            IFcsDVManager * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballRect )( 
            IFcsDVManager * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballRect )( 
            IFcsDVManager * This,
            LONG *left,
            LONG *top,
            LONG *right,
            LONG *bottom);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceImg )( 
            IFcsDVManager * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeImg )( 
            IFcsDVManager * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeImg )( 
            IFcsDVManager * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLEyeballImg )( 
            IFcsDVManager * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetREyeballImg )( 
            IFcsDVManager * This,
            BYTE *pImage,
            LONG nSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLeadFace )( 
            IFcsDVManager * This,
            BYTE *pLeadFace);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActivativedValue )( 
            IFcsDVManager * This,
            DOUBLE *dActivation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetBlinkCount )( 
            IFcsDVManager * This,
            LONG *nCount);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTimeMs )( 
            IFcsDVManager * This,
            LONG *MilliSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCurTime )( 
            IFcsDVManager * This,
            LONGLONG *NSec);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetCounter )( 
            IFcsDVManager * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCheck )( 
            IFcsDVManager * This,
            SHORT nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCheck )( 
            IFcsDVManager * This,
            SHORT *nCheck);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFaceRectLineWidth )( 
            IFcsDVManager * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFaceRectLineWidth )( 
            IFcsDVManager * This,
            FLOAT *fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetEyeRectLineWidth )( 
            IFcsDVManager * This,
            FLOAT fLineWidth);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetEyeRectLineWidth )( 
            IFcsDVManager * This,
            FLOAT *fLineWidth);
        
        END_INTERFACE
    } IFcsDVManagerVtbl;

    interface IFcsDVManager
    {
        CONST_VTBL struct IFcsDVManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFcsDVManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFcsDVManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFcsDVManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFcsDVManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFcsDVManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFcsDVManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFcsDVManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFcsDVManager_SetWindow(This,hParent)	\
    ( (This)->lpVtbl -> SetWindow(This,hParent) ) 

#define IFcsDVManager_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IFcsDVManager_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IFcsDVManager_GetPosition(This,iPos)	\
    ( (This)->lpVtbl -> GetPosition(This,iPos) ) 

#define IFcsDVManager_Seek(This,iPos)	\
    ( (This)->lpVtbl -> Seek(This,iPos) ) 

#define IFcsDVManager_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IFcsDVManager_SetWindowPosition(This,top,left,Width,Height)	\
    ( (This)->lpVtbl -> SetWindowPosition(This,top,left,Width,Height) ) 

#define IFcsDVManager_Free(This)	\
    ( (This)->lpVtbl -> Free(This) ) 

#define IFcsDVManager_Init(This)	\
    ( (This)->lpVtbl -> Init(This) ) 

#define IFcsDVManager_SetFile(This,szPathName)	\
    ( (This)->lpVtbl -> SetFile(This,szPathName) ) 

#define IFcsDVManager_Render(This)	\
    ( (This)->lpVtbl -> Render(This) ) 

#define IFcsDVManager_GetLength(This,nLength)	\
    ( (This)->lpVtbl -> GetLength(This,nLength) ) 

#define IFcsDVManager_SetOption(This,nOption)	\
    ( (This)->lpVtbl -> SetOption(This,nOption) ) 

#define IFcsDVManager_GetAudio(This,nChannelID,nVolume)	\
    ( (This)->lpVtbl -> GetAudio(This,nChannelID,nVolume) ) 

#define IFcsDVManager_SetPosition(This,pos)	\
    ( (This)->lpVtbl -> SetPosition(This,pos) ) 

#define IFcsDVManager_SetGraphPath(This,bstrGraphPath)	\
    ( (This)->lpVtbl -> SetGraphPath(This,bstrGraphPath) ) 

#define IFcsDVManager_SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo)	\
    ( (This)->lpVtbl -> SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo) ) 

#define IFcsDVManager_SetHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> SetHWnd(This,hWnd) ) 

#define IFcsDVManager_UpdateVideoWindow(This,prc)	\
    ( (This)->lpVtbl -> UpdateVideoWindow(This,prc) ) 

#define IFcsDVManager_GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight)	\
    ( (This)->lpVtbl -> GetVideoSize(This,lpWidth,lpHeight,lpARWidth,lpARHeight) ) 

#define IFcsDVManager_Repaint(This,hdc)	\
    ( (This)->lpVtbl -> Repaint(This,hdc) ) 

#define IFcsDVManager_Record(This)	\
    ( (This)->lpVtbl -> Record(This) ) 

#define IFcsDVManager_UpdateWindow(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> UpdateWindow(This,left,top,right,bottom) ) 

#define IFcsDVManager_State(This,nState)	\
    ( (This)->lpVtbl -> State(This,nState) ) 

#define IFcsDVManager_GetAudioLevel(This,nChannel,nVolume)	\
    ( (This)->lpVtbl -> GetAudioLevel(This,nChannel,nVolume) ) 

#define IFcsDVManager_SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath)	\
    ( (This)->lpVtbl -> SetKeyFrameBasicParams(This,nWidth,nHeight,bOcr,nOcrY1,nOcrY2,szExportPath) ) 

#define IFcsDVManager_SaveKFInfo(This)	\
    ( (This)->lpVtbl -> SaveKFInfo(This) ) 

#define IFcsDVManager_RemoteControl(This,nFunctionID)	\
    ( (This)->lpVtbl -> RemoteControl(This,nFunctionID) ) 

#define IFcsDVManager_GetDVMode(This,nDvMode)	\
    ( (This)->lpVtbl -> GetDVMode(This,nDvMode) ) 

#define IFcsDVManager_ChangeWindow(This,hWndHandle)	\
    ( (This)->lpVtbl -> ChangeWindow(This,hWndHandle) ) 

#define IFcsDVManager_ChangeHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> ChangeHWnd(This,hWnd) ) 

#define IFcsDVManager_PowerOn(This)	\
    ( (This)->lpVtbl -> PowerOn(This) ) 

#define IFcsDVManager_PowerOff(This)	\
    ( (This)->lpVtbl -> PowerOff(This) ) 

#define IFcsDVManager_StandBy(This)	\
    ( (This)->lpVtbl -> StandBy(This) ) 

#define IFcsDVManager_SetDvRate(This,nRate)	\
    ( (This)->lpVtbl -> SetDvRate(This,nRate) ) 

#define IFcsDVManager_GetDvRate(This,dRate)	\
    ( (This)->lpVtbl -> GetDvRate(This,dRate) ) 

#define IFcsDVManager_GetGraphPath(This,strGraphPath)	\
    ( (This)->lpVtbl -> GetGraphPath(This,strGraphPath) ) 

#define IFcsDVManager_IsMute(This,bMute)	\
    ( (This)->lpVtbl -> IsMute(This,bMute) ) 

#define IFcsDVManager_GetVideoFps(This,dFps)	\
    ( (This)->lpVtbl -> GetVideoFps(This,dFps) ) 

#define IFcsDVManager_SnapImage(This,bstrImagename,nNewWidth,nNewHeight)	\
    ( (This)->lpVtbl -> SnapImage(This,bstrImagename,nNewWidth,nNewHeight) ) 

#define IFcsDVManager_MP_GetPosition(This,nIndex)	\
    ( (This)->lpVtbl -> MP_GetPosition(This,nIndex) ) 

#define IFcsDVManager_GetCurrentPosition(This,pTimeNow)	\
    ( (This)->lpVtbl -> GetCurrentPosition(This,pTimeNow) ) 

#define IFcsDVManager_GetFaceRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetFaceRect(This,left,top,right,bottom) ) 

#define IFcsDVManager_GetFaceWidth(This,nWidth)	\
    ( (This)->lpVtbl -> GetFaceWidth(This,nWidth) ) 

#define IFcsDVManager_GetFaceHeight(This,nHeight)	\
    ( (This)->lpVtbl -> GetFaceHeight(This,nHeight) ) 

#define IFcsDVManager_GetLEyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeRect(This,left,top,right,bottom) ) 

#define IFcsDVManager_GetREyeRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeRect(This,left,top,right,bottom) ) 

#define IFcsDVManager_GetLEyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetLEyeballRect(This,left,top,right,bottom) ) 

#define IFcsDVManager_GetREyeballRect(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> GetREyeballRect(This,left,top,right,bottom) ) 

#define IFcsDVManager_GetFaceImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetFaceImg(This,pImage,nSize) ) 

#define IFcsDVManager_GetLEyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeImg(This,pImage,nSize) ) 

#define IFcsDVManager_GetREyeImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeImg(This,pImage,nSize) ) 

#define IFcsDVManager_GetLEyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetLEyeballImg(This,pImage,nSize) ) 

#define IFcsDVManager_GetREyeballImg(This,pImage,nSize)	\
    ( (This)->lpVtbl -> GetREyeballImg(This,pImage,nSize) ) 

#define IFcsDVManager_GetLeadFace(This,pLeadFace)	\
    ( (This)->lpVtbl -> GetLeadFace(This,pLeadFace) ) 

#define IFcsDVManager_GetActivativedValue(This,dActivation)	\
    ( (This)->lpVtbl -> GetActivativedValue(This,dActivation) ) 

#define IFcsDVManager_GetBlinkCount(This,nCount)	\
    ( (This)->lpVtbl -> GetBlinkCount(This,nCount) ) 

#define IFcsDVManager_GetCurTimeMs(This,MilliSec)	\
    ( (This)->lpVtbl -> GetCurTimeMs(This,MilliSec) ) 

#define IFcsDVManager_GetCurTime(This,NSec)	\
    ( (This)->lpVtbl -> GetCurTime(This,NSec) ) 

#define IFcsDVManager_ResetCounter(This)	\
    ( (This)->lpVtbl -> ResetCounter(This) ) 

#define IFcsDVManager_SetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> SetCheck(This,nCheck) ) 

#define IFcsDVManager_GetCheck(This,nCheck)	\
    ( (This)->lpVtbl -> GetCheck(This,nCheck) ) 

#define IFcsDVManager_SetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsDVManager_GetFaceRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetFaceRectLineWidth(This,fLineWidth) ) 

#define IFcsDVManager_SetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> SetEyeRectLineWidth(This,fLineWidth) ) 

#define IFcsDVManager_GetEyeRectLineWidth(This,fLineWidth)	\
    ( (This)->lpVtbl -> GetEyeRectLineWidth(This,fLineWidth) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFcsDVManager_INTERFACE_DEFINED__ */


#ifndef __IFcsDeckControl_INTERFACE_DEFINED__
#define __IFcsDeckControl_INTERFACE_DEFINED__

/* interface IFcsDeckControl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFcsDeckControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7D8113E6-0421-4622-868B-ED30D811562C")
    IFcsDeckControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            LONG *nResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            LONG nStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStandBy( 
            LONG nStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TogglePlayStop( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eject( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GotoTimeCode( 
            BSTR bstrTimeCode,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FastForward( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rewind( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StepForward( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StepBack( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Jog( 
            DOUBLE nRate,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Shuttle( 
            DOUBLE nRate,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTimeCode( 
            BSTR bstrTimeCode,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPreroll( 
            LONG nSecond,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPreroll( 
            LONG *nSecond,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaptureOffset( 
            LONG nCaptureOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCaptureOffset( 
            LONG *nCaptureOffset,
            LONG *nResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExportOffset( 
            LONG nExportOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetExportOffset( 
            LONG *nExportOffset,
            LONG *nResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetManualExportOffset( 
            LONG *nExportOffset,
            LONG *nResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartExport( 
            BSTR bstrInPoint,
            BSTR bstrOutPoint,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartCapture( 
            LONG useVITC,
            BSTR bstrInPoint,
            BSTR bstrOutPoint,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeviceID( 
            LONG *nDeviceID,
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Abort( 
            LONG *nResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CrashRecordStart( 
            LONG *nResult,
            LONG *errCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CrashRecordStop( 
            LONG *nResult,
            LONG *errCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFcsDeckControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFcsDeckControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFcsDeckControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFcsDeckControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFcsDeckControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFcsDeckControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFcsDeckControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFcsDeckControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFcsDeckControl * This,
            LONG *nResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IFcsDeckControl * This,
            LONG nStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStandBy )( 
            IFcsDeckControl * This,
            LONG nStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TogglePlayStop )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eject )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GotoTimeCode )( 
            IFcsDeckControl * This,
            BSTR bstrTimeCode,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FastForward )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rewind )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StepForward )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StepBack )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Jog )( 
            IFcsDeckControl * This,
            DOUBLE nRate,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Shuttle )( 
            IFcsDeckControl * This,
            DOUBLE nRate,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTimeCode )( 
            IFcsDeckControl * This,
            BSTR bstrTimeCode,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPreroll )( 
            IFcsDeckControl * This,
            LONG nSecond,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPreroll )( 
            IFcsDeckControl * This,
            LONG *nSecond,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureOffset )( 
            IFcsDeckControl * This,
            LONG nCaptureOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCaptureOffset )( 
            IFcsDeckControl * This,
            LONG *nCaptureOffset,
            LONG *nResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExportOffset )( 
            IFcsDeckControl * This,
            LONG nExportOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExportOffset )( 
            IFcsDeckControl * This,
            LONG *nExportOffset,
            LONG *nResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetManualExportOffset )( 
            IFcsDeckControl * This,
            LONG *nExportOffset,
            LONG *nResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartExport )( 
            IFcsDeckControl * This,
            BSTR bstrInPoint,
            BSTR bstrOutPoint,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartCapture )( 
            IFcsDeckControl * This,
            LONG useVITC,
            BSTR bstrInPoint,
            BSTR bstrOutPoint,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeviceID )( 
            IFcsDeckControl * This,
            LONG *nDeviceID,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Abort )( 
            IFcsDeckControl * This,
            LONG *nResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CrashRecordStart )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CrashRecordStop )( 
            IFcsDeckControl * This,
            LONG *nResult,
            LONG *errCode);
        
        END_INTERFACE
    } IFcsDeckControlVtbl;

    interface IFcsDeckControl
    {
        CONST_VTBL struct IFcsDeckControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFcsDeckControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFcsDeckControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFcsDeckControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFcsDeckControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFcsDeckControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFcsDeckControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFcsDeckControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFcsDeckControl_Init(This,nResult)	\
    ( (This)->lpVtbl -> Init(This,nResult) ) 

#define IFcsDeckControl_Close(This,nStatus)	\
    ( (This)->lpVtbl -> Close(This,nStatus) ) 

#define IFcsDeckControl_SetStandBy(This,nStatus)	\
    ( (This)->lpVtbl -> SetStandBy(This,nStatus) ) 

#define IFcsDeckControl_Play(This,nResult,errCode)	\
    ( (This)->lpVtbl -> Play(This,nResult,errCode) ) 

#define IFcsDeckControl_Stop(This,nResult,errCode)	\
    ( (This)->lpVtbl -> Stop(This,nResult,errCode) ) 

#define IFcsDeckControl_TogglePlayStop(This,nResult,errCode)	\
    ( (This)->lpVtbl -> TogglePlayStop(This,nResult,errCode) ) 

#define IFcsDeckControl_Eject(This,nResult,errCode)	\
    ( (This)->lpVtbl -> Eject(This,nResult,errCode) ) 

#define IFcsDeckControl_GotoTimeCode(This,bstrTimeCode,nResult,errCode)	\
    ( (This)->lpVtbl -> GotoTimeCode(This,bstrTimeCode,nResult,errCode) ) 

#define IFcsDeckControl_FastForward(This,nResult,errCode)	\
    ( (This)->lpVtbl -> FastForward(This,nResult,errCode) ) 

#define IFcsDeckControl_Rewind(This,nResult,errCode)	\
    ( (This)->lpVtbl -> Rewind(This,nResult,errCode) ) 

#define IFcsDeckControl_StepForward(This,nResult,errCode)	\
    ( (This)->lpVtbl -> StepForward(This,nResult,errCode) ) 

#define IFcsDeckControl_StepBack(This,nResult,errCode)	\
    ( (This)->lpVtbl -> StepBack(This,nResult,errCode) ) 

#define IFcsDeckControl_Jog(This,nRate,nResult,errCode)	\
    ( (This)->lpVtbl -> Jog(This,nRate,nResult,errCode) ) 

#define IFcsDeckControl_Shuttle(This,nRate,nResult,errCode)	\
    ( (This)->lpVtbl -> Shuttle(This,nRate,nResult,errCode) ) 

#define IFcsDeckControl_GetTimeCode(This,bstrTimeCode,nResult,errCode)	\
    ( (This)->lpVtbl -> GetTimeCode(This,bstrTimeCode,nResult,errCode) ) 

#define IFcsDeckControl_SetPreroll(This,nSecond,nResult,errCode)	\
    ( (This)->lpVtbl -> SetPreroll(This,nSecond,nResult,errCode) ) 

#define IFcsDeckControl_GetPreroll(This,nSecond,nResult,errCode)	\
    ( (This)->lpVtbl -> GetPreroll(This,nSecond,nResult,errCode) ) 

#define IFcsDeckControl_SetCaptureOffset(This,nCaptureOffset)	\
    ( (This)->lpVtbl -> SetCaptureOffset(This,nCaptureOffset) ) 

#define IFcsDeckControl_GetCaptureOffset(This,nCaptureOffset,nResult)	\
    ( (This)->lpVtbl -> GetCaptureOffset(This,nCaptureOffset,nResult) ) 

#define IFcsDeckControl_SetExportOffset(This,nExportOffset)	\
    ( (This)->lpVtbl -> SetExportOffset(This,nExportOffset) ) 

#define IFcsDeckControl_GetExportOffset(This,nExportOffset,nResult)	\
    ( (This)->lpVtbl -> GetExportOffset(This,nExportOffset,nResult) ) 

#define IFcsDeckControl_GetManualExportOffset(This,nExportOffset,nResult)	\
    ( (This)->lpVtbl -> GetManualExportOffset(This,nExportOffset,nResult) ) 

#define IFcsDeckControl_StartExport(This,bstrInPoint,bstrOutPoint,nResult,errCode)	\
    ( (This)->lpVtbl -> StartExport(This,bstrInPoint,bstrOutPoint,nResult,errCode) ) 

#define IFcsDeckControl_StartCapture(This,useVITC,bstrInPoint,bstrOutPoint,nResult,errCode)	\
    ( (This)->lpVtbl -> StartCapture(This,useVITC,bstrInPoint,bstrOutPoint,nResult,errCode) ) 

#define IFcsDeckControl_GetDeviceID(This,nDeviceID,nResult,errCode)	\
    ( (This)->lpVtbl -> GetDeviceID(This,nDeviceID,nResult,errCode) ) 

#define IFcsDeckControl_Abort(This,nResult)	\
    ( (This)->lpVtbl -> Abort(This,nResult) ) 

#define IFcsDeckControl_CrashRecordStart(This,nResult,errCode)	\
    ( (This)->lpVtbl -> CrashRecordStart(This,nResult,errCode) ) 

#define IFcsDeckControl_CrashRecordStop(This,nResult,errCode)	\
    ( (This)->lpVtbl -> CrashRecordStop(This,nResult,errCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFcsDeckControl_INTERFACE_DEFINED__ */


#ifndef __IFcsSerialControl_INTERFACE_DEFINED__
#define __IFcsSerialControl_INTERFACE_DEFINED__

/* interface IFcsSerialControl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFcsSerialControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E450FE7-FD75-443E-B205-3C9FB5222C69")
    IFcsSerialControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenPort( 
            BSTR portName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClosePort( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eject( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFcsSerialControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFcsSerialControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFcsSerialControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFcsSerialControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFcsSerialControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFcsSerialControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFcsSerialControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFcsSerialControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenPort )( 
            IFcsSerialControl * This,
            BSTR portName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IFcsSerialControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IFcsSerialControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClosePort )( 
            IFcsSerialControl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eject )( 
            IFcsSerialControl * This);
        
        END_INTERFACE
    } IFcsSerialControlVtbl;

    interface IFcsSerialControl
    {
        CONST_VTBL struct IFcsSerialControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFcsSerialControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFcsSerialControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFcsSerialControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFcsSerialControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFcsSerialControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFcsSerialControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFcsSerialControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFcsSerialControl_OpenPort(This,portName)	\
    ( (This)->lpVtbl -> OpenPort(This,portName) ) 

#define IFcsSerialControl_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#define IFcsSerialControl_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IFcsSerialControl_ClosePort(This)	\
    ( (This)->lpVtbl -> ClosePort(This) ) 

#define IFcsSerialControl_Eject(This)	\
    ( (This)->lpVtbl -> Eject(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFcsSerialControl_INTERFACE_DEFINED__ */


#ifndef __IJbuCapturer_INTERFACE_DEFINED__
#define __IJbuCapturer_INTERFACE_DEFINED__

/* interface IJbuCapturer */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IJbuCapturer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17EF949B-13A3-4128-B13C-2A0DC219271D")
    IJbuCapturer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindow( 
            LONG hParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowPosition( 
            LONG top,
            LONG left,
            LONG Width,
            LONG Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Free( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Render( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGraphPath( 
            BSTR bstrGraphPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSinkFile( 
            BSTR bstrPathName,
            BSTR bstrPathName1,
            LONG nTemplateID,
            LONG nFileNo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoSize( 
            LONG *lpWidth,
            LONG *lpHeight,
            LONG *lpARwidth,
            LONG *lpARHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateWindow( 
            LONG left,
            LONG top,
            LONG right,
            LONG bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE State( 
            LONG *nState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeWindow( 
            LONG hWndHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SnapImage( 
            BSTR ImageName,
            LONG Width,
            LONG Height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeHWnd( 
            HWND hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateVideoWindow( 
            const LPRECT prc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IJbuCapturerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJbuCapturer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJbuCapturer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJbuCapturer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJbuCapturer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJbuCapturer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJbuCapturer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJbuCapturer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindow )( 
            IJbuCapturer * This,
            LONG hParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowPosition )( 
            IJbuCapturer * This,
            LONG top,
            LONG left,
            LONG Width,
            LONG Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Free )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Render )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGraphPath )( 
            IJbuCapturer * This,
            BSTR bstrGraphPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSinkFile )( 
            IJbuCapturer * This,
            BSTR bstrPathName,
            BSTR bstrPathName1,
            LONG nTemplateID,
            LONG nFileNo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoSize )( 
            IJbuCapturer * This,
            LONG *lpWidth,
            LONG *lpHeight,
            LONG *lpARwidth,
            LONG *lpARHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateWindow )( 
            IJbuCapturer * This,
            LONG left,
            LONG top,
            LONG right,
            LONG bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *State )( 
            IJbuCapturer * This,
            LONG *nState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeWindow )( 
            IJbuCapturer * This,
            LONG hWndHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Play )( 
            IJbuCapturer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SnapImage )( 
            IJbuCapturer * This,
            BSTR ImageName,
            LONG Width,
            LONG Height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeHWnd )( 
            IJbuCapturer * This,
            HWND hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateVideoWindow )( 
            IJbuCapturer * This,
            const LPRECT prc);
        
        END_INTERFACE
    } IJbuCapturerVtbl;

    interface IJbuCapturer
    {
        CONST_VTBL struct IJbuCapturerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJbuCapturer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJbuCapturer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJbuCapturer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJbuCapturer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJbuCapturer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJbuCapturer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJbuCapturer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IJbuCapturer_SetWindow(This,hParent)	\
    ( (This)->lpVtbl -> SetWindow(This,hParent) ) 

#define IJbuCapturer_Pause(This)	\
    ( (This)->lpVtbl -> Pause(This) ) 

#define IJbuCapturer_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IJbuCapturer_SetWindowPosition(This,top,left,Width,Height)	\
    ( (This)->lpVtbl -> SetWindowPosition(This,top,left,Width,Height) ) 

#define IJbuCapturer_Free(This)	\
    ( (This)->lpVtbl -> Free(This) ) 

#define IJbuCapturer_Init(This)	\
    ( (This)->lpVtbl -> Init(This) ) 

#define IJbuCapturer_Render(This)	\
    ( (This)->lpVtbl -> Render(This) ) 

#define IJbuCapturer_SetGraphPath(This,bstrGraphPath)	\
    ( (This)->lpVtbl -> SetGraphPath(This,bstrGraphPath) ) 

#define IJbuCapturer_SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo)	\
    ( (This)->lpVtbl -> SetSinkFile(This,bstrPathName,bstrPathName1,nTemplateID,nFileNo) ) 

#define IJbuCapturer_GetVideoSize(This,lpWidth,lpHeight,lpARwidth,lpARHeight)	\
    ( (This)->lpVtbl -> GetVideoSize(This,lpWidth,lpHeight,lpARwidth,lpARHeight) ) 

#define IJbuCapturer_UpdateWindow(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> UpdateWindow(This,left,top,right,bottom) ) 

#define IJbuCapturer_State(This,nState)	\
    ( (This)->lpVtbl -> State(This,nState) ) 

#define IJbuCapturer_ChangeWindow(This,hWndHandle)	\
    ( (This)->lpVtbl -> ChangeWindow(This,hWndHandle) ) 

#define IJbuCapturer_Play(This)	\
    ( (This)->lpVtbl -> Play(This) ) 

#define IJbuCapturer_SnapImage(This,ImageName,Width,Height)	\
    ( (This)->lpVtbl -> SnapImage(This,ImageName,Width,Height) ) 

#define IJbuCapturer_ChangeHWnd(This,hWnd)	\
    ( (This)->lpVtbl -> ChangeHWnd(This,hWnd) ) 

#define IJbuCapturer_UpdateVideoWindow(This,prc)	\
    ( (This)->lpVtbl -> UpdateVideoWindow(This,prc) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJbuCapturer_INTERFACE_DEFINED__ */



#ifndef __FcsMediaLib_LIBRARY_DEFINED__
#define __FcsMediaLib_LIBRARY_DEFINED__

/* library FcsMediaLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FcsMediaLib;

EXTERN_C const CLSID CLSID_FcsPlayer;

#ifdef __cplusplus

class DECLSPEC_UUID("BA839D65-700B-4C7B-856F-DC31AA13D689")
FcsPlayer;
#endif

EXTERN_C const CLSID CLSID_ExportManager;

#ifdef __cplusplus

class DECLSPEC_UUID("79BBBCBB-9291-4023-B114-68AEB598B8C5")
ExportManager;
#endif

EXTERN_C const CLSID CLSID_FcsGrabber;

#ifdef __cplusplus

class DECLSPEC_UUID("5E13B842-C644-4881-8147-5610B803CF4A")
FcsGrabber;
#endif

EXTERN_C const CLSID CLSID_FcsDVManager;

#ifdef __cplusplus

class DECLSPEC_UUID("882A89F6-AF61-4278-AF70-109EF9B3754C")
FcsDVManager;
#endif

EXTERN_C const CLSID CLSID_FcsDeckControl;

#ifdef __cplusplus

class DECLSPEC_UUID("03276B5B-7E36-43AC-B770-2D6776E34505")
FcsDeckControl;
#endif

EXTERN_C const CLSID CLSID_FcsSerialControl;

#ifdef __cplusplus

class DECLSPEC_UUID("DABFBC36-1E3C-4261-876F-0371407A1DD5")
FcsSerialControl;
#endif

#ifndef ___IJbuCapturerEvents_DISPINTERFACE_DEFINED__
#define ___IJbuCapturerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IJbuCapturerEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IJbuCapturerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("22DC2861-7895-45EB-B9C5-0AE5766AB114")
    _IJbuCapturerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IJbuCapturerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IJbuCapturerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IJbuCapturerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IJbuCapturerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IJbuCapturerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IJbuCapturerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IJbuCapturerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IJbuCapturerEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IJbuCapturerEventsVtbl;

    interface _IJbuCapturerEvents
    {
        CONST_VTBL struct _IJbuCapturerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IJbuCapturerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IJbuCapturerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IJbuCapturerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IJbuCapturerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IJbuCapturerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IJbuCapturerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IJbuCapturerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IJbuCapturerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_JbuCapturer;

#ifdef __cplusplus

class DECLSPEC_UUID("811DF04E-488E-4818-BA3F-644F78577020")
JbuCapturer;
#endif
#endif /* __FcsMediaLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


