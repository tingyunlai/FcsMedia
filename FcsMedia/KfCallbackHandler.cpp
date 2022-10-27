//-----------------------------------------------------------------------------
// KfCallbackHandler.cpp
//
// Desc: DirectShow histogram sample callback handler
//
// Copyright (c) Blackmagic Design 2005. All rights reserved.
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "KfCallbackHandler.h"
#include "FcsPlayer.h"
#include "keyFrameDll.h"
//-----------------------------------------------------------------------------
// Constuctor
//
CKfCallbackHandler::CKfCallbackHandler()
{
	m_nWidth = 0;
	m_nHeight = 0;
	m_pPlayer = NULL;
	m_pKeyFrameProcessor = NULL;
}

//-----------------------------------------------------------------------------
// Destructor
//
CKfCallbackHandler::~CKfCallbackHandler(void)
{
}

//-----------------------------------------------------------------------------
// QueryInterface
//
STDMETHODIMP CKfCallbackHandler::QueryInterface(REFIID riid, void **ppv)
{
	HRESULT hr = S_OK;

	if ((riid == IID_ISampleGrabberCB) || (riid == IID_IUnknown))
	{
		*ppv = (void*)static_cast<ISampleGrabberCB*>(this);
	}
	else
	{
		hr = E_NOINTERFACE;
	}

	return hr;
}


// Initial Class
HRESULT CKfCallbackHandler::InitKeyFrameProcessor(CBasicParams* pBasicParams)
{
	if (m_pKeyFrameProcessor != NULL)
		SAFE_DELETE(m_pKeyFrameProcessor);
	HRESULT hr = KF_CreateObject((void**)&m_pKeyFrameProcessor);
	if (FAILED(hr))
		return hr;
	//CBasicParams p;
	//p.nWidth = pBasicParams->nWidth;
	hr = KF_SetBasicParams((void*)m_pKeyFrameProcessor, (void*)pBasicParams);
	return hr;
}
//-----------------------------------------------------------------------------
// ISampleGrabberCB interface
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// SampleCB
// Callback for sample grabber interface which provides a media sample
STDMETHODIMP CKfCallbackHandler::SampleCB(double SampleTime, IMediaSample* pSample)
{
	HRESULT hr = S_OK;

	if (pSample)
	{
		long cbData = pSample->GetActualDataLength();
		BYTE* pData = NULL;
		hr = pSample->GetPointer(&pData);
		//if (SUCCEEDED(hr))
		//{
		//	hr = m_pCtrl->SetBuffer(reinterpret_cast<const unsigned char*>(pData), cbData);
		//}
	}
	else
	{
		hr = E_POINTER;
	}
	
	return hr;
}

//-----------------------------------------------------------------------------
// BufferCB
// Callback for sample grabber interface which provides a buffer
STDMETHODIMP CKfCallbackHandler::BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen)
{
	HRESULT hr = S_OK;
	long nFrameID = 0;
	if (pBuffer && m_nWidth >0)
	{
		if (m_pPlayer == NULL)
			return S_FALSE;
		CFcsPlayer* pPlay = (CFcsPlayer*)m_pPlayer;
		pPlay->MP_GetPosition(&nFrameID);
		if (m_nOption == 0)
			KF_ProcessFrame((void*)m_pKeyFrameProcessor, (void*)pBuffer, (long*)&nFrameID);
		if (m_nOption == 1)
			hr = SaveImage(SampleTime, pBuffer, BufferLen);
	}
	else
	{
		hr = E_POINTER;
	}
	
	return hr;
}

HRESULT CKfCallbackHandler::SaveImage(double SampleTime, BYTE* pImagePixel, long nImageLength)
{
	HRESULT hr = S_OK;
	L_INT nRet;
	int nBpp;
	CString str;
	LONGLONG timeNow;
	if (m_pPlayer == NULL)
		return S_FALSE;
	CFcsPlayer* pPlayer = (CFcsPlayer*)m_pPlayer;
	if (m_nBitPerPixel == 8)
		nBpp = 0;
	else
		nBpp = m_nBitPerPixel;
	LBitmapBase  MyBitmap;
	nRet = MyBitmap.Create(m_nWidth, m_nHeight, nBpp, ORDER_RGBORGRAY, NULL, BOTTOM_LEFT, TYPE_USER, (L_UCHAR*)pImagePixel, nImageLength);
	if (nRet != SUCCESS)
		return S_FALSE;
	pPlayer->GetCurrentPosition(&timeNow);
	str.Format(_T("%I64u.jpg"), timeNow);
	str = m_szExportDir + str;
	TCHAR* szFile = str.GetBuffer(MAX_PATH);
	MyBitmap.SetFileName(szFile);
	nRet = MyBitmap.Save(FILE_JPEG, nBpp, 30, 0,MULTIPAGE_OPERATION_OVERWRITE);
	str.ReleaseBuffer();
	return hr;
}
