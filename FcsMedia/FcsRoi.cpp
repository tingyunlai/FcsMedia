
//

#include "stdafx.h"
#include "FcsMedia.h"
#include "FcsRoi.h"


// CFcsRoi

CFcsRoi::CFcsRoi()
{
	m_nColor = RGB(0, 255, 0);
	m_nLineWidth = 1;
	m_nPenStyle = PS_SOLID;
	m_nShapeType = FCS_Shape_Rectangle;

}

CFcsRoi::~CFcsRoi()
{
}




void CFcsRoi::SetRect(LPRECT pRt)
{
	m_rtDimension.left = pRt->left;
	m_rtDimension.top = pRt->top;
	m_rtDimension.right = pRt->right;
	m_rtDimension.bottom = pRt->bottom;
}

void CFcsRoi::SetRect(int left, int top, int right, int bottom)
{
	m_rtDimension.left = left;
	m_rtDimension.top = top;
	m_rtDimension.right = right;
	m_rtDimension.bottom = bottom;
}

void CFcsRoi::GetRect(LPRECT pRt)
{
	pRt->left = m_rtDimension.left;
	pRt->top = m_rtDimension.top;
	pRt->right = m_rtDimension.right;
	pRt->bottom = m_rtDimension.bottom;
}

void CFcsRoi::Draw(HDC hDC)
{
	CDC dc;
	dc.Attach(hDC);
	CPen* pNewPen = new CPen(m_nPenStyle, m_nLineWidth, m_nColor);
	CPen* pOldPen = (CPen*)dc.SelectObject(pNewPen);
	if (m_nShapeType == FCS_Shape_Rectangle)
		dc.Rectangle(&m_rtDimension);
	if (m_nShapeType == FCS_Shape_Ellipse)
		dc.Ellipse(&m_rtDimension);
	dc.SelectObject(pOldPen);
	dc.Detach();
	delete pNewPen;
}