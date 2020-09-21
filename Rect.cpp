#include "Rect.h"
CRect::CRect()
{
	m_X = 0;
	m_Y = 0;
}

void CRect::Init(int w, int h, int offx, int offy, const int* x, const int* y)
{
	m_OffX = offx;
	m_OffY = offy;
	m_W = w;
	m_H = h;
	m_X = x;
	m_Y = y;
}
void CRect::SetRect(int w, int h, int offx, int offy)
{
	m_OffX = offx;
	m_OffY = offy;
	m_W = w;
	m_H = h;
}
bool CRect::CKpeng(CRect* rect)
{
	int x1, y1, x2, y2;
	if (m_X && m_Y)
	{
		x1 = *m_X + m_OffX;
		y1 = *m_Y + m_OffY;
	}
	else
	{
		x1 = m_OffX;
		y1 = m_OffY;
	}
	if (rect->m_X && rect->m_Y)
	{
		x2 = *rect->m_X + rect->m_OffX;
		y2 = *rect->m_Y + rect->m_OffY;
	}
	else
	{
		x2 = rect->m_OffX;
		y2 = rect->m_OffY;
	}

	int top1 = y1;
	int down1 = y1 + m_H - 1;
	int left1 = x1;
	int right1 = x1 + m_W - 1;

	int top2 = y2;
	int down2 = y2 + rect->m_H - 1;
	int left2 = x2;
	int right2 = x2 + rect->m_W - 1;

	if (top1 > down2 || down1<top2 || left1>right2 || right1 < left2)return false;
	return true;
}
bool CRect::CKpeng(int x, int y)
{
	int x1, y1, x2, y2;
	x2 = x;
	y2 = y;
	if (m_X && m_Y)
	{
		x1 = *m_X + m_OffX;
		y1 = *m_Y + m_OffY;
	}
	else
	{
		x1 = m_OffX;
		y1 = m_OffY;
	}

	int top1 = y1;
	int down1 = y1 + m_H - 1;
	int left1 = x1;
	int right1 = x1 + m_W - 1;

	int top2 = y2;
	int down2 = y2;
	int left2 = x2;
	int right2 = x2;

	if (top1 > down2 || down1<top2 || left1>right2 || right1 < left2)return false;
	return true;
}