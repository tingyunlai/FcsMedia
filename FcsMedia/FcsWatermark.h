#pragma once
#include <tchar.h>
#include <dshow.h>
#include <stdio.h>
#include "resource.h"

// CFcsWatermark command target
#define TRANSPARENCY_VALUE   (0.5f)   // Alpha range is 0.0f to 1.0f
#define MARK_FLIP       0x1
#define MARK_MIRROR     0x2
#define MARK_ANIMATE    0x4
#define MARK_SLIDE      0x8
#define MARK_STROBE     0x10
#define MARK_DISABLE    0x80

class CFcsWatermark : public CObject
{
public:
	CFcsWatermark();
	virtual ~CFcsWatermark();
	HRESULT Init(HWND hWndApp, LONG cx, LONG cy, WCHAR* szImageName);
	HRESULT BlendApplicationImage();
	HRESULT DisableWatermark(DWORD dwFlags, HWND ghApp);
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

	//VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

	//
	// Global data
	//
protected:
	IVMRMixerBitmap9 *pBMP;
	int gnTimer;
	LONG m_nBitmapWidth;
	LONG m_nBitmapHeight;
	LONG m_nImageWidth;
	LONG m_nImageHeight;
	LONG m_nNoImageInBitmap;
	LONG m_nVideoWidth;
	LONG m_nVideoHeight;
	float m_dEdgeBuffer;
	float m_fBitmapCompWidth;
	VMR9NormalizedRect m_rtDest;
	CRect m_rtSrc;
	CRect m_rtSrcSingle;
	// current watermark flags
	DWORD m_dwWatermarkFlags;
	BOOL m_bWatermarkDisabled;
	BOOL  m_bRestoreFlip;
	BOOL  m_bRestoreMirror;
	WCHAR* m_csBitmapName;
	HWND m_hWndVideo;

};


