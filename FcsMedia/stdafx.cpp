// stdafx.cpp : source file that includes just the standard includes
// FcsMedia.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

//-----------------------------------------------------------------------------
// CFcsPlayer::RemoveUnconnectedRenderer
// Description: Remove a renderer filter from the graph if the filter is
//              not connected. 
//-----------------------------------------------------------------------------

HRESULT RemoveUnconnectedRenderer(IGraphBuilder *pGraph, IBaseFilter *pRenderer, BOOL *pbRemoved)
{
	IPin *pPin = NULL;

	BOOL bRemoved = FALSE;

	// Look for a connected input pin on the renderer.

	HRESULT hr = FindConnectedPin(pRenderer, PINDIR_INPUT, &pPin);
	SAFE_RELEASE(pPin);

	// If this function succeeds, the renderer is connected, so we don't remove it.
	// If it fails, it means the renderer is not connected to anything, so
	// we remove it.

	if (FAILED(hr))
	{
		hr = pGraph->RemoveFilter(pRenderer);
		bRemoved = TRUE;
	}

	if (SUCCEEDED(hr))
	{
		*pbRemoved = bRemoved;
	}

	return hr;
}

//-----------------------------------------------------------------------------
// CFcsPlayer::InitWindowlessVMR
// Description: Initialize the VMR-9 for windowless mode. 
//-----------------------------------------------------------------------------

HRESULT InitWindowlessVMR9( 
						  IBaseFilter *pVMR,				// Pointer to the VMR
						  HWND hwnd,						// Clipping window
						  IVMRWindowlessControl** ppWC	// Receives a pointer to the VMR.
						  ) 
{ 

	IVMRFilterConfig* pConfig = NULL; 
	IVMRWindowlessControl *pWC = NULL;

	HRESULT hr = S_OK;

	// Set the rendering mode.  
	hr = pVMR->QueryInterface(IID_IVMRFilterConfig9, (void**)&pConfig); 
	if (SUCCEEDED(hr)) 
	{ 
		hr = pConfig->SetRenderingMode(VMRMode_Windowless); 
	}

	// Query for the windowless control interface.
	if (SUCCEEDED(hr))
	{
		hr = pVMR->QueryInterface(IID_IVMRWindowlessControl9, (void**)&pWC);
	}

	// Set the clipping window.
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetVideoClippingWindow(hwnd);
	}

	// Preserve aspect ratio by letter-boxing
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	if (SUCCEEDED(hr))
	{
		*ppWC = pWC;
		(*ppWC)->AddRef();
	}

	SAFE_RELEASE(pConfig);
	SAFE_RELEASE(pWC);

	return hr; 
} 

//-----------------------------------------------------------------------------
// CFcsPlayer::InitWindowlessVMR
// Description: Initialize the VMR for windowless mode. 
//-----------------------------------------------------------------------------

HRESULT InitWindowlessVMR(
	IBaseFilter *pVMR,				// Pointer to the VMR
	HWND hwnd,						// Clipping window
	IVMRWindowlessControl** ppWC	// Receives a pointer to the VMR.
	)
{

	IVMRFilterConfig* pConfig = NULL;
	IVMRWindowlessControl *pWC = NULL;

	HRESULT hr = S_OK;

	// Set the rendering mode.  
	hr = pVMR->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig);
	if (SUCCEEDED(hr))
	{
		hr = pConfig->SetRenderingMode(VMRMode_Windowless);
	}

	// Query for the windowless control interface.
	if (SUCCEEDED(hr))
	{
		hr = pVMR->QueryInterface(IID_IVMRWindowlessControl, (void**)&pWC);
	}

	// Set the clipping window.
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetVideoClippingWindow(hwnd);
	}

	// Preserve aspect ratio by letter-boxing
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	if (SUCCEEDED(hr))
	{
		*ppWC = pWC;
		(*ppWC)->AddRef();
	}

	SAFE_RELEASE(pConfig);
	SAFE_RELEASE(pWC);

	return hr;
}


//-----------------------------------------------------------------------------
// CFcsPlayer::InitWindowedVMR
// Description: Initialize the VMR-9 for windowless mode. 
//-----------------------------------------------------------------------------

HRESULT InitWindowedVMR( 
						  IBaseFilter *pVMR,				// Pointer to the VMR
						  HWND hwnd,						// Clipping window
						  IVMRWindowlessControl** ppWC	// Receives a pointer to the VMR.
						  ) 
{ 

	IVMRFilterConfig* pConfig = NULL; 
	IVMRWindowlessControl *pWC = NULL;

	HRESULT hr = S_OK;

	// Set the rendering mode.  
	hr = pVMR->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig); 
	if (SUCCEEDED(hr)) 
	{ 
		hr = pConfig->SetRenderingMode(VMRMode_Windowed); 
	}

	// Query for the windowless control interface.
	if (SUCCEEDED(hr))
	{
		hr = pVMR->QueryInterface(IID_IVMRWindowlessControl, (void**)&pWC);
	}

	// Set the clipping window.
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetVideoClippingWindow(hwnd);
	}

	// Preserve aspect ratio by letter-boxing
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	if (SUCCEEDED(hr))
	{
		*ppWC = pWC;
		(*ppWC)->AddRef();
	}

	SAFE_RELEASE(pConfig);
	SAFE_RELEASE(pWC);

	return hr; 
} 



//-----------------------------------------------------------------------------
// CFcsPlayer::InitRenderlessVMR
// Description: Initialize the VMR-9 for windowless mode. 
//-----------------------------------------------------------------------------

HRESULT InitRenderlessVMR( 
						  IBaseFilter *pVMR,				// Pointer to the VMR
						  HWND hwnd,						// Clipping window
						  IVMRWindowlessControl** ppWC	// Receives a pointer to the VMR.
						  ) 
{ 

	IVMRFilterConfig* pConfig = NULL; 
	IVMRWindowlessControl *pWC = NULL;

	HRESULT hr = S_OK;

	// Set the rendering mode.  
	hr = pVMR->QueryInterface(IID_IVMRFilterConfig, (void**)&pConfig); 
	if (SUCCEEDED(hr)) 
	{ 
		hr = pConfig->SetRenderingMode(VMRMode_Renderless); 
	}

	// Query for the windowless control interface.
	if (SUCCEEDED(hr))
	{
		hr = pVMR->QueryInterface(IID_IVMRWindowlessControl, (void**)&pWC);
	}

	// Set the clipping window.
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetVideoClippingWindow(hwnd);
	}

	// Preserve aspect ratio by letter-boxing
	if (SUCCEEDED(hr))
	{
		hr = pWC->SetAspectRatioMode(VMR_ARMODE_LETTER_BOX);
	}

	// Return the IVMRWindowlessControl pointer to the caller.
	if (SUCCEEDED(hr))
	{
		*ppWC = pWC;
		(*ppWC)->AddRef();
	}

	SAFE_RELEASE(pConfig);
	SAFE_RELEASE(pWC);

	return hr; 
} 




