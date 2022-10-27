

#pragma once

class CSGCallbackHandler : public ISampleGrabberCB
{
public:
	CSGCallbackHandler();
	~CSGCallbackHandler(void);
	//Pen* greenPen;
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef() { return 2; }		// fake the reference counting
	STDMETHODIMP_(ULONG) Release() { return 1; }	// fake the reference counting

													// ISampleGrabberCB interface
	STDMETHODIMP SampleCB(double SampleTime, IMediaSample* pSample);
	STDMETHODIMP BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen);
	HRESULT InitKeyFrameProcessor(CBasicParams* pBasicParams);
	void SetExportDir(CString str) {
		m_szExportDir = str;
	}
	void EnbaleGetKeyFrame(BOOL bEnbale) {
		m_bGetKeyFrame = bEnbale;
	}
	BOOL SaveBitmap(BYTE * pBuffer, long lBufferSize);
	void SetOption(int nOption) {
		m_nOption = nOption;
	}
	void SaveDataFile();
	void RestImageCounter() {
		m_nImageCount = 0;
	}
	long GetImageIndex() {
		return m_nImageCount;
	}
	void SetMode(int nMode) {
		m_nMode = nMode;
	}

public:
	HRESULT SaveImage(double SampleTime, BYTE* pImagePixel, long nImageLength);
	void EnableCapture(LONG nEnable);
	long m_nWidth;
	long m_nHeight;
	long m_nArWidth;
	long m_nArHeight;
	int m_nBitPerPixel;
	void* m_pPlayer;
	DWORD m_nBeginTime;
	long m_nImageSize;
	BYTE* m_pImageBuffer;
	AM_MEDIA_TYPE g_StillMediaType;
	CObject* m_pKeyFrameProcessor;
	BOOL m_bGetKeyFrame;
	int m_nOption;  
	long m_nImageCount;
	int m_nMode;
	BOOL m_bEnable;

	CString m_szExportDir;
	CString m_szExportName; 
	long m_nExportWidh;
	long m_nExportHeight;
	LONG m_nCompressRatio;
	LONG m_nCaptureFreq;
	LONG m_nFramePerSec; 
};
