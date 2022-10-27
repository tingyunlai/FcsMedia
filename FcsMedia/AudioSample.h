
#pragma once

class CAudioSample : public ISampleGrabberCB
{
public:
	CAudioSample();
	~CAudioSample(void);
	CString m_szPathName;
	STDMETHODIMP QueryInterface(REFIID riid, void **ppv);
	STDMETHODIMP_(ULONG) AddRef() { return 2; }		// fake the reference counting
	STDMETHODIMP_(ULONG) Release() { return 1; }	// fake the reference counting

													// ISampleGrabberCB interface
	STDMETHODIMP SampleCB(double SampleTime, IMediaSample* pSample);
	STDMETHODIMP BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen);
	void SetExportDir(CString str) {
		m_szExportDir = str;
	}

	void SetOption(int nOption) {
		m_nOption = nOption;
	}
	long m_nWidth;
	long m_nHeight;
	long m_nArWidth;
	long m_nArHeight;
	int m_nBitPerPixel;
	void* m_pPlayer;
	DWORD m_nBeginTime;
	WAVEFORMATEX wfex;
	CUIntArray vuMeters;
	BOOL m_bFirst;
	HRESULT GetAudiolevel(long nChannel, long* nVolume);
private:
	CString m_szExportDir;
	int m_nOption;  // action 0：key frame， 1：each frame


};
