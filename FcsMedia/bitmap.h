//------------------------------------------------------------------------------
// File: Watermark.h
//
// Desc: DirectShow sample code - header file for video in window movie
//       player application.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

//
// Constants
//
#define TRANSPARENCY_VALUE   (0.5f)   // Alpha range is 0.0f to 1.0f
#define MARK_FLIP       0x1
#define MARK_MIRROR     0x2
#define MARK_ANIMATE    0x4
#define MARK_SLIDE      0x8
#define MARK_STROBE     0x10
#define MARK_DISABLE    0x80

//
// Function prototypes
//
HRESULT BlendApplicationImage(HWND hwndApp, long cx, long cy, WCHAR* csImageName);
HRESULT DisableWatermark(DWORD dwFlags);
HRESULT FlipWatermark(DWORD dwFlags);
HRESULT MirrorWatermark(DWORD dwFlags);

void AnimateWatermark(DWORD dwFlags);
void SlideWatermark(DWORD dwFlags);
void StrobeWatermark(DWORD dwFlags);
void FlipFlag(DWORD dwFlag);
void SetAllEffects(void);
void ClearAllEffects(void);
void EnableWatermarkMenu(BOOL bEnable);

void HandleStrobe(void);
void HandleSlide(void);
void HandleAnimation(void);

void ResetBitmapAlpha(void);
void ResetBitmapPosition(void);
void ResetAnimation(void);
void ClearWatermarkState(void);

void StartTimer(void);
void KillTimer(void);
void SetColorRef(VMR9AlphaBitmap& bmpInfo);

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

//
// Global data
//
extern IVMRMixerBitmap9 *pBMP;
