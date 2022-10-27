

#include "stdafx.h"
#include "AudioSample.h"
#include "ExportManager.h"
//-----------------------------------------------------------------------------
// Constuctor
//
CAudioSample::CAudioSample()
{
	m_nWidth = 0;
	m_nHeight = 0;
	m_pPlayer = NULL;
	m_bFirst = TRUE;
	vuMeters.SetSize(2);
}

//-----------------------------------------------------------------------------
// Destructor
//
CAudioSample::~CAudioSample(void)
{
}

//-----------------------------------------------------------------------------
// QueryInterface
//
STDMETHODIMP CAudioSample::QueryInterface(REFIID riid, void **ppv)
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



//-----------------------------------------------------------------------------
// ISampleGrabberCB interface
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// SampleCB
// Callback for sample grabber interface which provides a media sample
STDMETHODIMP CAudioSample::SampleCB(double SampleTime, IMediaSample* pSample)
{
	HRESULT hr = S_OK;



	int BufferLen = pSample->GetActualDataLength();
	BYTE* pBuffer = NULL; // = new BYTE[BufferLen];
	pSample->GetPointer(&pBuffer);

	int sampleNum = BufferLen / wfex.nBlockAlign;
	int k = 0;
	int level;
	short tt;

	for (int i = 0; i < vuMeters.GetSize(); i++)
	{
		vuMeters.SetAt(i, 0);
	}

	long* peak = new long[wfex.nChannels];
	for (int i = 0; i < wfex.nChannels; i++)
		peak[i] = 0;
	long n = wfex.nSamplesPerSec * 0.1;
	short* tmp = new short[BufferLen];
	::CopyMemory(tmp, pBuffer, BufferLen);
	if (sampleNum <= n)
	{
		for (int i = 0; i < sampleNum; i++)
		{
			for (int j = 0; j < wfex.nChannels; j++)
			{
				if (abs(tmp[k]) > peak[j])
					peak[j] = abs(tmp[k]);
				k++;
			}
		}
		for (int i = 0; i < wfex.nChannels; i++)
		{
			double t = (double)(peak[i]) / 32768.0;
			t = 20 * log10(t);
			vuMeters.SetAt(i, (int)t + 60);
		}

	}
	else
	{

		for (int i = 0; i < sampleNum; i++)
		{
			for (int j = 0; j < wfex.nChannels; j++)
			{
				if (abs(tmp[k]) > peak[j])
					peak[j] = abs(tmp[k]);
				k++;
			}
			if (i % n == 0)
			{
				for (int i = 0; i < wfex.nChannels; i++)
				{
					double t = (double)(peak[i]) / 32768.0;
					t = 20 * log10(t);
					vuMeters.SetAt(i, (int)t + 60);
					peak[i] = 0;
				}
				//Sleep(30);
			}
		}
	}
	delete peak;
	delete tmp;
	return hr;
}

//-----------------------------------------------------------------------------
// BufferCB
// Callback for sample grabber interface which provides a buffer
STDMETHODIMP CAudioSample::BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen)
{
	HRESULT hr = S_OK;
	int sampleNum = BufferLen / wfex.nBlockAlign;
	for (int i = 0; i < vuMeters.GetSize(); i++)
	{
		vuMeters.SetAt(i, 0);
	}

	short* peak = new short[wfex.nChannels];
	for (int i = 0; i < wfex.nChannels; i++)
		peak[i] = 0;

	short* tmp = new short[BufferLen];
	::CopyMemory(tmp, pBuffer, BufferLen);

	int k = 0;
	for (int i = 0; i < sampleNum; i++)
	{
		for (int j = 0; j < wfex.nChannels; j++)
		{
			if (abs(tmp[k]) > peak[j])
				peak[j] = abs(tmp[k]);
			k++;
		}
	}

	for (int i = 0; i < wfex.nChannels; i++)
	{
		double t = (double)(peak[i]) / 32768.0;
		t = 20 * log10(t);
		vuMeters.Add((int)t + 60);
	}


	return hr;
}


HRESULT CAudioSample::GetAudiolevel(long nChannel, long* nVolume)
{
	HRESULT hr = S_OK;
	long nSize = vuMeters.GetSize();
	if (nSize == 0)
	{
		*nVolume = 0;
		return S_FALSE;
	}
	int n;
	if (nChannel == 0) //left
	{
		n = vuMeters.GetAt(nSize - 2);

	}
	else
	{
		n = vuMeters.GetAt(nSize - 1);
	}
	*nVolume = (long)n;
	return hr;
}
