#include"Action.h"
void CAction::AddPic(_PIC pic)
{
	m_PicList.push_back(pic);
}
//º¯ÊýÖØÐÂ
void CAction::AddPic(const char* id, int sw, int sh, int sx, int sy,
	int cw, int ch, int offx, int offy, int cf, unsigned int c)
{
	_PIC p;
	p.id = id;
	p.id = id;
	p.sw = sw;
	p.sh = sh;
	p.sx = sx;
	p.sy = sy;
	p.cw = cw;
	p.ch = ch;
	p.offx = offx;
	p.offy = offy;
	p.cf = cf;
	p.c = c;
	m_PicList.push_back(p);
}
_PIC* CAction::GetPic(int f)
{
	if (f<0 || f>m_PicList.size())return 0;
	return &m_PicList[f];
}
int CAction::PicLen()
{
	return m_PicList.size();
}
void CAction::SetNextAct(int next)
{
	if (next < 0)
		return;
	m_NextAct = next;
}
int CAction::GetNextAct()
{
	return m_NextAct;
}
int CAction::GetActLen()
{
	return m_PicList.size();
}