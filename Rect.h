#pragma once

/*************************¾ØĞÎÅö×²*****************************/
class CRect
{
public:
	const int* m_X;
	const int* m_Y;
	int m_W;
	int m_H;
	int m_OffX;
	int m_OffY;

	CRect();
	void Init(int w, int h, int offx, int offy, const int* x = 0, const int* y = 0);
	void SetRect(int w, int h, int offx = 0, int offy = 0);
	bool CKpeng(CRect* rect);	//¾ØĞÎÅö×²
	bool CKpeng(int x, int y);  //ÊÇ·ñÅö×²
};