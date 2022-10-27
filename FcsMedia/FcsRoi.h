#pragma once


enum ShapeType {
	FCS_Shape_Rectangle,
	FCS_Shape_Ellipse,
	FCS_Shape_Circle
};
class CFcsRoi : public CObject
{
public:
	CFcsRoi();
	virtual ~CFcsRoi();
	void SetRect(LPRECT pRt);
	void SetRect(int left, int top, int right, int bottom);
	void GetRect(LPRECT pRt);
	void SetColor(COLORREF nColor) {
		m_nColor = nColor;
	}
	COLORREF GetColor() {
		return m_nColor;
	}
	void SetPenStyle(int nStyle) {
		m_nPenStyle = nStyle;
	}
	int GetPenStyle() {
		return m_nPenStyle;
	}
	void SetLineWidth(int nWidth) {
		m_nLineWidth = nWidth;
	}
	int GetLineWidth() {
		return m_nLineWidth;
	}
	void SetShapeType(int nType) {
		m_nShapeType = nType;
	}
	int GetShapeType() {
		return m_nShapeType;
	}
	void Draw(HDC hDC);
protected:
	CRect m_rtDimension;
	COLORREF m_nColor;
	int m_nLineWidth;
	int m_nPenStyle;
	int m_nShapeType;

};


