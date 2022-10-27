#pragma once

class CP2Paser
{
public:
	CP2Paser(void);
	~CP2Paser(void);
	CString m_szCodec;
	BOOL Load(CString szXMLName);
	CString GetVideoName();
	CString GetAudioName(int nIndex);
	int GetAudioCount(){
		return m_nAudioNo;
	}
	CString GetClipPath(){
		return m_szClipPath;
	}
protected:
	CString m_szXMLName;
	CString m_szClipName;
	CString m_szClipPath;
	CString m_szVideoPath;
	CString m_szAudioPath;
	int       m_nAudioNo;
	long     m_SamplingRate;


};
