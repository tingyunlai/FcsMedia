// FcsWatermark.cpp : implementation file
//

#include "stdafx.h"
#include "FcsMedia.h"
#include "FcsWatermark.h"


// CFcsWatermark
const int ANIMATE_TIMER  = 2000;   // Timer IDs
const int SLIDE_TIMER    = 2001;
const int STROBE_TIMER   = 2002;
const int MAIN_TIMER     = 2003;
const int MAIN_TIMEOUT    = 125;
const float SLIDE_VALUE  = 0.05f;  // Amount to slide image in composition space
const float STROBE_VALUE = 0.125f; // Amount to add to bitmap alpha value


VOID CALLBACK TimerProc(
									   HWND hwnd,         // handle to window
									   UINT uMsg,         // WM_TIMER message
									   UINT_PTR idEvent,  // timer identifier
									   DWORD dwTime       // current system time
									   )
{
	//static int nToggle=0;

	//// If the user has disabled the watermark, just exit.
	//if (m_bWatermarkDisabled)
	//	return;

	//// Use one timer for efficiency, instead of starting/stopping
	//// three separate timers.  Since animation will run at half the
	//// rate of slide/strobe, only process animation in every other callback.
	//if (m_dwWatermarkFlags & MARK_SLIDE)
	//	HandleSlide();

	//if (m_dwWatermarkFlags & MARK_STROBE)
	//	HandleStrobe();

	//if (m_dwWatermarkFlags & MARK_ANIMATE)
	//{
	//	nToggle ^= 1;
	//	if (nToggle)
	//		HandleAnimation();
	//}
}


CFcsWatermark::CFcsWatermark()
{
	m_dEdgeBuffer = 0.4f;
	m_nNoImageInBitmap = 5;
}

CFcsWatermark::~CFcsWatermark()
{
}


// CFcsWatermark member functions

HRESULT CFcsWatermark::Init(HWND hWndApp, LONG cx, LONG cy, WCHAR* szImageName)
{
	m_hWndVideo = hWndApp;
	m_nVideoHeight = cy;
	m_nVideoWidth  = cx;
	m_csBitmapName = szImageName;
	return S_OK;
}
HRESULT CFcsWatermark::BlendApplicationImage()
{
	return S_OK;
}


void CFcsWatermark::ClearWatermarkState(void)
{
	KillTimer();

	// Clear current watermark flags
	m_dwWatermarkFlags = 0;
}


void CFcsWatermark::EnableWatermarkMenu(BOOL bEnable)
{
	m_bWatermarkDisabled = !bEnable;
}


HRESULT CFcsWatermark::MirrorWatermark(DWORD dwFlags)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Configure the X axis
	if (dwFlags & MARK_MIRROR)
	{
		// Swap left/right coordinates
		float fLeft = bmpInfo.rDest.left;
		bmpInfo.rDest.left = bmpInfo.rDest.right;
		bmpInfo.rDest.right = fLeft;

		//CheckMenuItem(ghMenu, ID_MIRROR, MF_CHECKED);
	}
	else
	{
		// If we're removing the mirror effect while sliding, then
		// it's not correct to reset the left/right coordinates to
		// the default saved global values.  Instead, just switch 
		// the left/right values.
		if (dwFlags & MARK_SLIDE)
		{
			// Swap left/right coordinates
			float fLeft = bmpInfo.rDest.left;
			bmpInfo.rDest.left = bmpInfo.rDest.right;
			bmpInfo.rDest.right = fLeft;
		}
		else
		{
			// We're not sliding, so just reset the left/right
			// coordinates to their original default values.
			bmpInfo.rDest.left  = m_rtDest.left;
			bmpInfo.rDest.right = m_rtSrc.right;
		}

		//CheckMenuItem(ghMenu, ID_MIRROR, MF_UNCHECKED);
	}

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
	//if (FAILED(hr))
	//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED!  hr=0x%x\r\n"), hr);

	return hr;
}


HRESULT CFcsWatermark::FlipWatermark(DWORD dwFlags)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Configure the Y axis
	if (dwFlags & MARK_FLIP)
	{
		// Swap left/right coordinates
		float fTop = bmpInfo.rDest.top;
		bmpInfo.rDest.top = bmpInfo.rDest.bottom;
		bmpInfo.rDest.bottom = fTop;

		//CheckMenuItem(ghMenu, ID_FLIP, MF_CHECKED);
	}
	else
	{
		bmpInfo.rDest.top = m_rtDest.top;
		bmpInfo.rDest.bottom = m_rtDest.bottom;

		//CheckMenuItem(ghMenu, ID_FLIP, MF_UNCHECKED);
	}

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
	//if (FAILED(hr))
	//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED!  hr=0x%x\r\n"), hr);

	return hr;
}


HRESULT CFcsWatermark::DisableWatermark(DWORD dwFlags, HWND ghApp)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	// Since the enable/disable menu will always be enabled,
	// verify that the VMR Alpha bitmap interface is set.
	if (!pBMP)
		return E_NOINTERFACE;

	// Read the current bitmap settings
	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// If the request is to disable the bitmap, then disable it
	// and ignore the other flags for now
	if (dwFlags & MARK_DISABLE)
	{
		// Disable other watermark menu items
		EnableWatermarkMenu(FALSE);

		// Remember if the flip/mirror states are set for redrawing
		if (m_dwWatermarkFlags & MARK_FLIP)
			m_bRestoreFlip = TRUE;
		if (m_dwWatermarkFlags & MARK_MIRROR)
			m_bRestoreMirror = TRUE;

		// If animation is active, reset
		if (dwFlags & MARK_ANIMATE)
		{
			ResetAnimation();

			// Read the current bitmap settings again post-reset
			pBMP->GetAlphaBitmapParameters(&bmpInfo);
		}

		// Temporarily disable bitmap display
		bmpInfo.dwFlags = VMRBITMAP_DISABLE;

		// Update the bitmap settings
		hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
		//if (FAILED(hr))
		//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED to disable watermark!  hr=0x%x\r\n"), hr);
	}
	else
	{
		// Reset the bitmap with default values
		hr = BlendApplicationImage();

		// Reenable other watermark menu items
		EnableWatermarkMenu(TRUE);

		// Preserve the previously-set mirror/flip settings
		if (m_bRestoreFlip)
		{
			FlipWatermark(m_dwWatermarkFlags);
			m_bRestoreFlip = FALSE;
		}
		if (m_bRestoreMirror)
		{
			MirrorWatermark(m_dwWatermarkFlags);
			m_bRestoreMirror = FALSE;
		}
	}

	return hr;
}


void CFcsWatermark::FlipFlag(DWORD dwFlag)
{
	// If the flag is set, clear it
	if (m_dwWatermarkFlags & dwFlag)
		m_dwWatermarkFlags &= ~dwFlag;

	// Otherwise, set the flag
	else
		m_dwWatermarkFlags |= dwFlag;
}


void CFcsWatermark::AnimateWatermark(DWORD dwFlags)
{
	if (dwFlags & MARK_ANIMATE)
	{
		StartTimer();
		//CheckMenuItem(ghMenu, ID_ANIMATE, MF_CHECKED);
	}
	else
	{
		//CheckMenuItem(ghMenu, ID_ANIMATE, MF_UNCHECKED);
		ResetAnimation();
	}
}


void CFcsWatermark::SlideWatermark(DWORD dwFlags)
{
	if (dwFlags & MARK_SLIDE)
	{
		StartTimer();
		//CheckMenuItem(ghMenu, ID_SLIDE, MF_CHECKED);
	}
	else
	{
		//CheckMenuItem(ghMenu, ID_SLIDE, MF_UNCHECKED);
		ResetBitmapPosition();
	}
}


void CFcsWatermark::StrobeWatermark(DWORD dwFlags)
{
	// Start cycling the bitmap's alpha value on a timer
	if (dwFlags & MARK_STROBE)
	{
		StartTimer();
		//CheckMenuItem(ghMenu, ID_STROBE, MF_CHECKED);
	}
	else
	{
		//CheckMenuItem(ghMenu, ID_STROBE, MF_UNCHECKED);
		ResetBitmapAlpha();
	}
}


void CFcsWatermark::StartTimer(void)
{
	if (!gnTimer)
		gnTimer = (int) ::SetTimer(NULL, MAIN_TIMER, MAIN_TIMEOUT, TimerProc);
}

void CFcsWatermark::KillTimer(void)
{
	if (gnTimer)
	{
		::KillTimer(NULL, gnTimer);
		gnTimer = 0;
	}
}



void CFcsWatermark::HandleStrobe(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Slowly increase the alpha value
	float fAlpha = bmpInfo.fAlpha + STROBE_VALUE;
	if (fAlpha > 1.0f)
		fAlpha = 0.0f;

	bmpInfo.fAlpha = fAlpha;

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	// If the bitmap is currently disabled, this call will fail
	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
}


void CFcsWatermark::ResetBitmapAlpha(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	if (!pBMP)
		return;

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Return bitmap alpha to its default value
	bmpInfo.fAlpha = TRANSPARENCY_VALUE;

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
	//if (FAILED(hr))
	//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED!  hr=0x%x\r\n"), hr);
}


void CFcsWatermark::HandleSlide(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Slowly decrease the X coordinate
	bmpInfo.rDest.left  -= SLIDE_VALUE;   
	bmpInfo.rDest.right -= SLIDE_VALUE;

	// Once the bitmap disappears off the left side of the screen,
	// reset to the rightmost side of the window.
	// Take into account that the bitmap might be mirrored, in which case
	// the left/right coordinates are switched.

	if ((m_dwWatermarkFlags & MARK_MIRROR) == 0)
	{
		// NOT mirrored
		if (bmpInfo.rDest.right <= m_dEdgeBuffer)
		{
			bmpInfo.rDest.left = 1.0f;
			bmpInfo.rDest.right = 1.0f + m_fBitmapCompWidth;
		}
	}
	else
	{
		// Mirrored
		if (bmpInfo.rDest.left <= m_dEdgeBuffer)
		{
			bmpInfo.rDest.right = 1.0f;
			bmpInfo.rDest.left = 1.0f + m_fBitmapCompWidth;
		}
	}

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	// If the bitmap is currently disabled, this call will fail
	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
}


void CFcsWatermark::ResetBitmapPosition(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	if (!pBMP)
		return;

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Return bitmap position to its original value.
	// Since the image may be currently mirrored, swap the
	// left/right coordinates if necessary
	if (m_dwWatermarkFlags & MARK_MIRROR)
	{
		// Mirrored
		bmpInfo.rDest.left  = m_rtDest.right;
		bmpInfo.rDest.right = m_rtDest.left;
	}
	else
	{
		// NOT mirrored
		bmpInfo.rDest.left  = m_rtDest.left;
		bmpInfo.rDest.right = m_rtDest.right;
	}

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
	//if (FAILED(hr))
	//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED!  hr=0x%x\r\n"), hr);
}


void CFcsWatermark::HandleAnimation(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};
	static int nCycle=0;

	// Fill the rDest and fAlpha values in bmpInfo
	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Move the image source to the right by one image width
	bmpInfo.rSrc.left   = m_nImageWidth * nCycle;
	bmpInfo.rSrc.right  = bmpInfo.rSrc.left + m_nImageWidth;
	bmpInfo.rSrc.top    = m_rtSrc.top;
	bmpInfo.rSrc.bottom = m_rtSrc.bottom;
	nCycle++;

	// If we have passed the last image in the wide bitmap,
	// then reset to the default source location (leftmost image)
	if (bmpInfo.rSrc.left >= m_nBitmapWidth)
	{
		bmpInfo.rSrc = m_rtSrcSingle;
		nCycle = 1;
	}

	// Set the necessary flag to update the source rectangle
	bmpInfo.dwFlags = VMRBITMAP_SRCRECT;

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	// Give the VMR a new bitmap to display
	// If the bitmap is currently disabled, this call will fail
	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
}


void CFcsWatermark::ResetAnimation(void)
{
	HRESULT hr;
	VMR9AlphaBitmap bmpInfo={0};

	if (!pBMP)
		return;

	hr = pBMP->GetAlphaBitmapParameters(&bmpInfo);

	// Update the source rectangle to the original single-image default
	bmpInfo.rSrc = m_rtSrcSingle;

	// Set the necessary flag to update the source rectangle
	bmpInfo.dwFlags = VMRBITMAP_SRCRECT;

	// Set the COLORREF so that the bitmap outline will be transparent
	SetColorRef(bmpInfo);

	hr = pBMP->UpdateAlphaBitmapParameters(&bmpInfo);
	//if (FAILED(hr))
	//    Msg(TEXT("UpdateAlphaBitmapParameters FAILED!  hr=0x%x\r\n"), hr);
}


void CFcsWatermark::SetColorRef(VMR9AlphaBitmap& bmpInfo)
{
	// Set the COLORREF so that the bitmap outline will be transparent
	bmpInfo.clrSrcKey = RGB(255, 255, 255);       // Pure white
	bmpInfo.dwFlags |= VMRBITMAP_SRCCOLORKEY;
}


void CFcsWatermark::SetAllEffects(void)
{
	// Activate any effects that aren't currently active
	if ((m_dwWatermarkFlags & MARK_ANIMATE) == 0)
	{
		FlipFlag(MARK_ANIMATE);
		AnimateWatermark(m_dwWatermarkFlags);
	}
	if ((m_dwWatermarkFlags & MARK_STROBE) == 0)
	{
		FlipFlag(MARK_STROBE);
		StrobeWatermark(m_dwWatermarkFlags);
	}
	if ((m_dwWatermarkFlags & MARK_SLIDE) == 0)
	{
		FlipFlag(MARK_SLIDE);
		SlideWatermark(m_dwWatermarkFlags);
	}
}


void CFcsWatermark::ClearAllEffects(void)
{
	KillTimer();

	// Deactivate all active effects
	if (m_dwWatermarkFlags & MARK_ANIMATE)
	{
		FlipFlag(MARK_ANIMATE);
		AnimateWatermark(m_dwWatermarkFlags);
	}
	if (m_dwWatermarkFlags & MARK_STROBE)
	{
		FlipFlag(MARK_STROBE);
		StrobeWatermark(m_dwWatermarkFlags);
	}
	if (m_dwWatermarkFlags & MARK_SLIDE)
	{
		FlipFlag(MARK_SLIDE);
		SlideWatermark(m_dwWatermarkFlags);
	}
}
