// FcsSerialControl.cpp : Implementation of CFcsSerialControl

#include "stdafx.h"
#include "FcsSerialControl.h"


// CFcsSerialControl


STDMETHODIMP CFcsSerialControl::OpenPort(BSTR portName)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	BOOL	  serialOpen = FALSE; 
	COMMTIMEOUTS	timeouts;
	CString str = CString(portName);
	TCHAR* wPortName = str.GetBuffer(MAX_PATH);
	hCommPort = CreateFile(wPortName, GENERIC_READ | GENERIC_WRITE, 0, 
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hCommPort == INVALID_HANDLE_VALUE)
	{
		return S_FALSE;
	}

	serialOpen = TRUE;

	// set read timeouts
	timeouts.ReadIntervalTimeout = 0;
	timeouts.ReadTotalTimeoutConstant = 15;	// standard says the deck should replies within 9 ms
	timeouts.ReadTotalTimeoutMultiplier = 0;

	// mark write timeouts as not used
	timeouts.WriteTotalTimeoutMultiplier = 0;
	timeouts.WriteTotalTimeoutConstant = 0;

	serialOpen = SetCommTimeouts(hCommPort, &timeouts);
	if (serialOpen)
		return S_OK;
	else
		return S_FALSE;
}

STDMETHODIMP CFcsSerialControl::Play(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (hCommPort == INVALID_HANDLE_VALUE)
		return S_FALSE;

	DWORD			byteCount=0;
	unsigned char	transmitBuffer[COMM_BUFFER_SIZE] = {0}; 
	unsigned char	receiveBuffer[COMM_BUFFER_SIZE] = {0}; 
	transmitBuffer[0] = 0x20;		// Play command 
	transmitBuffer[1] = 0x01; 
	transmitBuffer[2] = 0x21; 

	try
	{

		if (!WriteFile(hCommPort, transmitBuffer, 3, &byteCount, NULL))
		{
			throw false;
		}
	}
	catch (...)
	{
		DWORD dwError = GetLastError();					// additional debug information
		errorMessage(dwError);
	}
	return S_OK;
}

STDMETHODIMP CFcsSerialControl::Stop(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	DWORD			byteCount=0;
	unsigned char	transmitBuffer[COMM_BUFFER_SIZE] = {0}; 
	unsigned char	receiveBuffer[COMM_BUFFER_SIZE] = {0}; 

	transmitBuffer[0] = 0x20;		// Stop command 
	transmitBuffer[1] = 0x00; 
	transmitBuffer[2] = 0x20; 

	try
	{
		if (!WriteFile(hCommPort, transmitBuffer, 3, &byteCount, NULL))
		{
			throw false;
		}
	}
	catch (...)
	{
		DWORD dwError = GetLastError();					// additional debug information
		errorMessage(dwError);
	}
	return S_OK;
}

STDMETHODIMP CFcsSerialControl::ClosePort(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	if (hCommPort != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hCommPort);
		return S_OK;
	}
	else 
		return S_FALSE;
}

void CFcsSerialControl::errorMessage(DWORD dwError)
{
	LPVOID lpMsgBuf;

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );
	CString str;
	str.Format(_T("\nError: %08X: \n%s"), dwError,  (LPCTSTR)lpMsgBuf);
	TRACE(str);
	LocalFree(lpMsgBuf);
}

STDMETHODIMP CFcsSerialControl::Eject(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your implementation code here
	DWORD			byteCount=0;
	unsigned char	transmitBuffer[COMM_BUFFER_SIZE] = {0}; 
	unsigned char	receiveBuffer[COMM_BUFFER_SIZE] = {0}; 

	transmitBuffer[0] = 0x20;		// eject command 
	transmitBuffer[1] = 0x0F; 
	transmitBuffer[2] = 0x2F; 

	try
	{
		if (!WriteFile(hCommPort, transmitBuffer, 3, &byteCount, NULL))
		{
			throw false;
		}
	}
	catch (...)
	{
		DWORD dwError = GetLastError();					// additional debug information
		errorMessage(dwError);
	}
	return S_OK;
}
