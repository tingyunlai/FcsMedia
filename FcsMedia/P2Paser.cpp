#include "StdAfx.h"
#include "P2Paser.h"

CP2Paser::CP2Paser(void)
{
}

CP2Paser::~CP2Paser(void)
{
}

BOOL CP2Paser::Load(CString szXMLName)
{
	BOOL hr;
	m_szXMLName = szXMLName;
	CString str, str2;
	CString str1;
	int n = m_szXMLName.ReverseFind('\\');
	int nStrLength = m_szXMLName.GetLength();
	m_szClipName = m_szXMLName.Right(nStrLength -n -1);
	m_szClipPath = m_szXMLName.Left(n);
	n = m_szClipPath.ReverseFind('\\');
	str = m_szClipPath.Left(n);
	m_szVideoPath = str +CString(_T("\\Video"));
	m_szAudioPath = str + CString(_T("\\Audio"));

	CStdioFile fp;
	hr = fp.Open(m_szXMLName, CFile::modeRead);
	if (!hr)
		return FALSE;
	fp.SeekToBegin();
	long nLength = (long)fp.GetLength();
	long nIndex= 0;
	m_nAudioNo = 0;
	while (nIndex < nLength)
	{
		fp.ReadString(str);
		nIndex += str.GetLength();
		str.Trim();
		str1 = str.Left(6);
		if (str1 == _T("<Codec"))
		{
			n = str.Find('>');
			str2 = str.Mid(n+1);
			n = str2.Find('<');
			m_szCodec = str2.Left(n);
		}

		str1 = str.Left(7);
		if (str1 == _T("<Audio>"))
			m_nAudioNo++;
		str1 = str.Left(9);
		if (str1 == _T("</P2Main>"))
			break;
	}
	fp.Close();
	return TRUE;
}

CString CP2Paser::GetVideoName()
{
	int n = m_szClipName.ReverseFind('.');
	CString str = m_szClipName.Left(n);
	if (m_szVideoPath.Right(1) != _T("\\"))
		m_szVideoPath += CString(_T("\\"));
	str = m_szVideoPath + str +CString(_T(".MXF"));
	return str;
}

CString CP2Paser::GetAudioName(int nIndex)
{
	int n = m_szClipName.ReverseFind('.');
	CString str = m_szClipName.Left(n);
	if (m_szAudioPath.Right(1) != _T("\\"))
		m_szAudioPath += CString(_T("\\"));
	CString str1;
	str1.Format(_T("%s%02d.MXF"), str, nIndex);
	str = m_szAudioPath + str1;
	return str;
}
