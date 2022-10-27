// FcsDeckControl.cpp : Implementation of CFcsDeckControl

#include "stdafx.h"
#include "FcsDeckControl.h"


// CFcsDeckControl


STDMETHODIMP CFcsDeckControl::Init(LONG* nResult)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	IDeckLinkInput * deckLinkInput = NULL;
	IDeckLinkDisplayModeIterator*	displayModeIterator = NULL;
	IDeckLinkDisplayMode*			deckLinkDisplayMode = NULL;
	HRESULT					hr; 
	long nWidth, nHeight;
	BMDTimeValue m_frameDuration;
	BMDTimeScale m_timeScale;
	BMDDeckControlError err;
	BMDDeckControlMode mode;
	BMDDeckControlVTRControlState vtrControlState;
	BMDDeckControlStatusFlags flags;

	// Create an IDeckLinkIterator object to enumerate all DeckLink cards in the system
	hr = CoCreateInstance(CLSID_CDeckLinkIterator, NULL, CLSCTX_ALL, IID_IDeckLinkIterator, (void**)&m_deckLinkIterator);

	if (SUCCEEDED(hr))
	{
		hr = m_deckLinkIterator->Next(&m_deckLink);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_deckLink->QueryInterface(IID_IDeckLinkInput, (void **)&deckLinkInput) ;	
	}

	if (SUCCEEDED(hr))
	{
		hr = deckLinkInput->GetDisplayModeIterator(&displayModeIterator) ;	
	}

	if (SUCCEEDED(hr))
	{
		hr = displayModeIterator->Next(&deckLinkDisplayMode) ;	
	}

	if (SUCCEEDED(hr))
	{
		nWidth = deckLinkDisplayMode->GetWidth();
		nHeight = deckLinkDisplayMode->GetHeight();
		deckLinkDisplayMode->GetFrameRate(&m_frameDuration, &m_timeScale);
		deckLinkDisplayMode->Release();
	}

	hr = m_deckLink->QueryInterface(IID_IDeckLinkDeckControl, (void**)&m_deckControl);
	if (SUCCEEDED(hr))
	{
		hr = m_deckControl->Open(m_timeScale, m_frameDuration, TRUE, &err) ;	
	}

	// wait for connection

	if (SUCCEEDED(hr))
	{
		while (1)
		{
			Sleep(3000);
			hr = m_deckControl->GetCurrentState(&mode, &vtrControlState, &flags) ;	
			if (SUCCEEDED(hr))
			{
				if (vtrControlState != 	bmdDeckControlNotInVTRControlMode)
					break;	
			}
		}
	}

	if (SUCCEEDED(hr))
	{
		if (vtrControlState == 	bmdDeckControlNotInVTRControlMode)
			hr = S_FALSE;	
	}
	*nResult = hr;
	//SAFE_RELEASE(deckLinkDisplayMode);
	SAFE_RELEASE(displayModeIterator);
	SAFE_RELEASE(deckLinkInput);
	return hr;
}

STDMETHODIMP CFcsDeckControl::Close(LONG nStatus)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
		return S_FALSE;
	HRESULT hr = m_deckControl->Close(nStatus);
	return hr;
}

STDMETHODIMP CFcsDeckControl::SetStandBy(LONG nStatus)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
		return S_FALSE;
	HRESULT hr = m_deckControl->SetStandby(nStatus);

	return hr;
}

STDMETHODIMP CFcsDeckControl::Play(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Play(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Stop(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Stop(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::TogglePlayStop(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->TogglePlayStop(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Eject(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Eject(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::GotoTimeCode(BSTR bstrTimeCode, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsDeckControl::FastForward(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->FastForward(TRUE, &err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Rewind(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Rewind(TRUE, &err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::StepForward(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->StepForward(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::StepBack(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->StepBack(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Jog(DOUBLE nRate, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	if (nRate < -50.0 || nRate >50.0)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlFailedToOpenDeviceError;
		return S_FALSE;

	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Jog(nRate, &err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Shuttle(DOUBLE nRate, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	if (nRate < -50.0 || nRate >50.0)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlFailedToOpenDeviceError;
		return S_FALSE;

	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Shuttle(nRate, &err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::GetTimeCode(BSTR bstrTimeCode, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->Eject(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::SetPreroll(LONG nSecond, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->SetPreroll((unsigned long)nSecond);
	*nResult = hr;
	*errCode = (LONG)0;
	return hr;
}

STDMETHODIMP CFcsDeckControl::GetPreroll(LONG* nSecond, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->GetPreroll((unsigned long*)nSecond);
	*nResult = hr;
	*errCode = (LONG)0;
	return hr;
}

STDMETHODIMP CFcsDeckControl::SetCaptureOffset(LONG nCaptureOffset)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->SetCaptureOffset(nCaptureOffset);
	return hr;
}

STDMETHODIMP CFcsDeckControl::GetCaptureOffset(LONG* nCaptureOffset, LONG* nResult)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->GetCaptureOffset(nCaptureOffset);
	*nResult = hr;
	return hr;
}

STDMETHODIMP CFcsDeckControl::SetExportOffset(LONG nExportOffset)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->SetExportOffset(nExportOffset);
	return hr;

}

STDMETHODIMP CFcsDeckControl::GetExportOffset(LONG* nExportOffset, LONG* nResult)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->GetExportOffset(nExportOffset);
	*nResult = hr;
	return hr;
}

STDMETHODIMP CFcsDeckControl::GetManualExportOffset(LONG* nExportOffset, LONG* nResult)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->GetManualExportOffset(nExportOffset);
	*nResult = hr;
	return hr;
}

STDMETHODIMP CFcsDeckControl::StartExport(BSTR bstrInPoint, BSTR bstrOutPoint, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsDeckControl::StartCapture(LONG useVITC, BSTR bstrInPoint, BSTR bstrOutPoint, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CFcsDeckControl::GetDeviceID(LONG* nDeviceID, LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->GetDeviceID((unsigned short*)nDeviceID, &err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::Abort(LONG* nResult)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		return S_FALSE;
	}
	HRESULT hr = m_deckControl->Abort();
	*nResult = hr;
	return hr;
}

STDMETHODIMP CFcsDeckControl::CrashRecordStart(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->CrashRecordStart(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

STDMETHODIMP CFcsDeckControl::CrashRecordStop(LONG* nResult, LONG* errCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (m_deckControl == NULL)
	{
		*nResult = S_FALSE;
		*errCode = bmdDeckControlNoCommunicationError;
		return S_FALSE;
	}
	BMDDeckControlError err;
	HRESULT hr = m_deckControl->CrashRecordStop(&err);
	*nResult = hr;
	*errCode = (LONG)err;
	return hr;
}

