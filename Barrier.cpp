#include"Barrier.h"
#include"Rect.h"
#include"Hero.h"
#include"Moster.h"

CBarrier::CBarrier()
{
	m_Rect = new CRect;
}
CBarrier::~CBarrier()
{
	delete m_Rect;
}
//初始化宽高
void CBarrier::Init(int w, int h)
{
	m_X = 0;
	m_Y = 0;
	m_W = w;
	m_H = h;
	m_Rect = new CRect;
	m_Rect->Init(m_W, m_H, 0, 0, &m_X, &m_Y);
}

//删除
void CBarrier::Clear()
{

}

//英雄的位置
void CBarrier::Colider(CHero* hero, int dir)
{
	if (!m_Rect->CKpeng(hero->GetRect()))
		return;
	if (dir==_UP)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffY + m_Rect->m_H - hero->GetRect()->m_OffY;
		hero->SetPos(x, y);
		//hero->SetState(_DOWN);
	}
	else if (dir == _DOWN)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffY + m_Rect->m_H - hero->GetRect()->m_OffY;
		hero->SetPos(x, y);
		hero->SetState(IDLE);
	}
	if (dir == _LEFT)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffX + m_Rect->m_W - hero->GetRect()->m_OffX;
		hero->SetPos(x, y);
		//hero->SetState(_DOWN);
	}
	else if (dir == _RIGHT)
	{
		int x = hero->GetPos().x;
		int y = hero->GetPos().y;
		y = m_Y + m_Rect->m_OffX + m_Rect->m_W - hero->GetRect()->m_OffX;
		hero->SetPos(x, y);
		//hero->SetState(_DOWN);
	}
}
//小怪的位置
void CBarrier::Colider(CBarrier* moster, int dir)
{
	/*if (!m_Rect->CKpeng(moster->GetRect())))
		return;*/
	//if (dir==)
}

//设置位置
void CBarrier::SetPos(int x, int y)
{
	m_X = x;
	m_Y = y;
}
//设置大小
void CBarrier::SetSize(int w, int h)
{
	m_W = w;
	m_H = h;
}


int CBarrier::GetPosX()
{
	return m_X;
}
int CBarrier::GetPosY()
{
	return m_Y;
}
int CBarrier::GetW()
{
	return m_W;
}

int CBarrier::GetH()
{
	return m_H;
}
CRect* CBarrier::GetRect()
{
	return m_Rect;
}