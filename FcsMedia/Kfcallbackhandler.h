//-----------------------------------------------------------------------------
// KfCallbackHandler.h
//
// Desc: DirectShow histogram sample callback handler
//
//-----------------------------------------------------------------------------

#pragma once

class CKfCallbackHandler : public ISampleGrabberCB
{
public:
	CKfCallbackHandler();
	~CKfCallbackHandler(void);

	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef() { return 2; }		// fake the reference counting
	STDMETHODIMP_(ULONG) Release() { return 1; }	// fake the reference counting

	// ISampleGrabberCB interface
	STDMETHODIMP SampleCB(double SampleTime, IMediaSample* pSample);
	STDMETHODIMP BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen);
	HRESULT InitKeyFrameProcessor(CBasicParams* pBasicParams);
	void SetExportDir(CString str){
		m_szExportDir = str;
	}
	void EnbaleGetKeyFrame(BOOL bEnbale){
		m_bGetKeyFrame = bEnbale;
	}
	void SetOption(int nOption){
		m_nOption = nOption;
	}
	long m_nWidth;
	long m_nHeight;
	long m_nArWidth;
	long m_nArHeight;
	int m_nBitPerPixel;
	void* m_pPlayer;
	DWORD m_nBeginTime;

private:
	HRESULT SaveImage(double SampleTime, BYTE* pImagePixel, long nImageLength);
	CString m_szExportDir;
	CObject* m_pKeyFrameProcessor;
	BOOL m_bGetKeyFrame; 
	int m_nOption;  // 得到 FRAME后的动作 0：取关键帧， 1：抓取每一帧


};
