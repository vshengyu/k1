#include"Orth.h"
#include"Rect.h"
#include"Hero.h"
COrth::COrth()
{
	m_Rect = new CRect;
	m_Flag = 1;
}
COrth::~COrth()
{
	delete m_Rect;
}
void COrth::Init(int w, int h)
{
	m_X = 0;
	m_Y = 0;
	m_W = w;
	m_H = h;
	m_Flag = 1;
	m_Rect = new CRect;
	m_Rect->Init(m_W, m_H, 0, 0, &m_X, &m_Y);
}
void COrth::Clear()
{

}
void COrth::Colider(CHero* hero, int dir)
{
	/*if (!m_Rect->CKpeng(hero->GetRect()))return;
	hero->SetMoveFlag(1);
	if (dir == UP)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffY + m_Rect->m_H - hero->GetRect()->m_OffY;
		hero->SetPos(x, y);
		hero->SetState(M_DOWN);
	}
	else if (dir == DOWN)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffY - hero->GetRect()->m_OffY - hero->GetRect()->m_H;
		hero->SetPos(x, y);
		hero->SetState(IDLE);
	}
	if (dir == LEFT)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		x = m_X + m_Rect->m_OffX + m_Rect->m_W - hero->GetRect()->m_OffX;
		hero->SetPos(x, y);
		hero->SetState(M_DOWN);
	}
	else if (dir == RIGHT)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		x = m_X + m_Rect->m_OffX - hero->GetRect()->m_OffX - hero->GetRect()->m_W;
		hero->SetPos(x, y);
		hero->SetState(M_DOWN);
	}*/
}
void COrth::Colider(COrth* moster, int dir)
{
	
}
void COrth::SetPos(int x, int y)
{
	m_X = x;
	m_Y = y;
}
void COrth::SetSize(int w, int h)
{
	m_W = w;
	m_H = h;
}
void COrth::SetFlag(int flag)
{
	m_Flag = flag;
}
int COrth::GetPosX()
{
	return m_X;
}
int COrth::GetPosY()
{
	return m_Y;
 }
int COrth::GetW()
{
	return m_W;
}
int COrth::GetFlag()
{
	return m_Flag;
}
int COrth::GetH()
{
	return m_H;
}
//CRect* COrth::GetRect()
//{
//	return m_Rect;
//}