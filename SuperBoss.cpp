#include"SuperBoss.h"
#include"Frame.h"
#include"Rect.h"
#include"Barrier.h"
#include"Action.h"
#include"Hero.h"

void CSuperBoss::Init()
{
	m_mp = 1900;//蓝
	m_hp = 1900;//血
	m_State = _IDLE;
	m_Speed = 12;
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Atkcd = 0;  //攻击冷却
	m_Acd = 30;
	m_Dir = LEFT;
	m_Rect->Init(30, 30, -150, -255, (const int*)&m_Pos.x, (const int*)&m_Pos.y);
	m_Frame = CFrame::GetFrame();
	m_Barrier = m_Frame->GetWallList();





	m_CurAct = 0;	//当前动作
	m_CurF = 0;		//当前动作的第几张图片
	m_CurCF = 0;	//当前图片已经持续的循环数记录




	/***************************************读取文件******************/
	m_Frame->LoadBmp("下1", "pic\\S3\\0401.bmp");
	m_Frame->LoadBmp("下2", "pic\\S3\\0402.bmp");
	m_Frame->LoadBmp("下3", "pic\\S3\\0403.bmp");
	m_Frame->LoadBmp("下4", "pic\\S3\\0404.bmp");


	m_Frame->LoadBmp("上1", "pic\\S3\\0701.bmp");
	m_Frame->LoadBmp("上2", "pic\\S3\\0702.bmp");
	m_Frame->LoadBmp("上3", "pic\\S3\\0703.bmp");
	m_Frame->LoadBmp("上4", "pic\\S3\\0704.bmp");

	m_Frame->LoadBmp("左1", "pic\\S3\\0501.bmp");
	m_Frame->LoadBmp("左2", "pic\\S3\\0502.bmp");
	m_Frame->LoadBmp("左3", "pic\\S3\\0503.bmp");
	m_Frame->LoadBmp("左4", "pic\\S3\\0504.bmp");

	m_Frame->LoadBmp("右1", "pic\\S3\\0601.bmp");
	m_Frame->LoadBmp("右2", "pic\\S3\\0602.bmp");
	m_Frame->LoadBmp("右3", "pic\\S3\\0603.bmp");
	m_Frame->LoadBmp("右4", "pic\\S3\\0604.bmp");

	




	/***************************************加载动画区域****************************/
	_PIC pic;
	CAction* act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "下1";
	pic.cw = 92;
	pic.ch = 97;
	pic.sw = 92;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "下2";
	pic.cw = 92;
	pic.ch = 97;
	pic.sw = 92;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "下3";
	pic.cw = 92;
	pic.ch = 97;
	pic.sw = 92;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "下4";
	pic.cw = 92;
	pic.ch = 97;
	pic.sw = 92;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(0);
	m_ActList.push_back(act);
	


	//上1
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "上1";
	pic.cw = 91;
	pic.ch = 98;
	pic.sw = 91;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "上2";
	pic.cw = 91;
	pic.ch = 98;
	pic.sw = 91;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "上3";
	pic.cw = 91;
	pic.ch = 98;
	pic.sw = 91;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "上4";
	pic.cw = 91;
	pic.ch = 98;
	pic.sw = 91;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(1);
	m_ActList.push_back(act);

	//左2
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "左1";
	pic.cw = 76;
	pic.ch = 97;
	pic.sw = 76;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "左2";
	pic.cw = 76;
	pic.ch = 97;
	pic.sw = 76;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "左3";
	pic.cw = 76;
	pic.ch = 97;
	pic.sw = 76;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "左4";
	pic.cw = 76;
	pic.ch = 97;
	pic.sw = 76;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(2);
	m_ActList.push_back(act);




	//右3
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "右1";
	pic.cw = 76;
	pic.ch = 98;
	pic.sw = 76;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "右2";
	pic.cw = 76;
	pic.ch = 98;
	pic.sw = 76;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "右3";
	pic.cw = 76;
	pic.ch = 98;
	pic.sw = 76;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "右4";
	pic.cw = 76;
	pic.ch = 98;
	pic.sw = 76;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(3);
	m_ActList.push_back(act);

}
void CSuperBoss::Run()
{
	int tx = m_Pos.x - CFrame::GetFrame()->GetCX();
	if (tx<-2 || tx>1600)
		return;

	//子弹设置
	std::list<MYPOINT>::iterator it = m_Buling.begin();
	while (it != m_Buling.end())
	{
		if (it->dir == UP)
			m_Frame->DrawBmp("子弹_上", it->x, it->y, 57, 65, 0, 0, 57, 65, RGB(0, 0, 0));	//子弹上
		else if (it->dir == DOWN)
			m_Frame->DrawBmp("子弹_下", it->x, it->y, 56, 61, 0, 0, 56, 61, RGB(0, 0, 0));	//子弹下
		else if (it->dir == LEFT)
			m_Frame->DrawBmp("子弹_左", it->x, it->y, 57, 63, 0, 0, 57, 63, RGB(0, 0, 0));	//子弹左
		else if (it->dir == RIGHT)
			m_Frame->DrawBmp("子弹_右", it->x, it->y, 57, 61, 0, 0, 57, 61, RGB(0, 0, 0));	//子弹右
		it++;

	}
	it = m_Buling.begin();
	while (it != m_Buling.end())
	{
		////子弹消失方向
		if (it->x - m_Frame->GetCX() > 1600)	it = m_Buling.erase(it);
		else if (it->x - m_Frame->GetCX() < 0)	it = m_Buling.erase(it);
		else if (it->y - m_Frame->GetCY() > 800)	it = m_Buling.erase(it);
		else if (it->y - m_Frame->GetCY() < 0)	it = m_Buling.erase(it);


		else
		{
			if (it->dir == UP)
				it->y -= 30;
			else if (it->dir == DOWN)
				it->y += 30;
			else if (it->dir == RIGHT)
				it->x += 30;
			else if (it->dir == LEFT)
				it->x -= 30;
			it++;
		}
	}
	/***************************画图************************/
	if (m_CurAct >= 0 && m_CurAct < m_ActList.size())
	{
		_PIC* pic = m_ActList[m_CurAct]->GetPic(m_CurF);
		if (pic != NULL)
			m_Frame->DrawBmp(pic->id, m_Pos.x + pic->offx, m_Pos.y + pic->offy, pic->cw, pic->ch, pic->sx, pic->sy, pic->sw, pic->sh, pic->c);
		m_CurCF += 1;
		if (m_CurCF >= pic->cf)
		{
			m_CurCF = 0;
			m_CurF += 1;
			if (m_CurF >= m_ActList[m_CurAct]->GetActLen())
			{
				m_CurAct = m_ActList[m_CurAct]->GetNextAct();
				m_CurF = 0;
				m_CurCF = 0;
			}
		}
	}
	/**************血量和蓝量*************/
	if (m_hp >= 1900)
		m_hp = 1900;

	m_mp += 1;
	if (m_mp >= 1900)
		m_mp = 1900;
	//移动
	switch (m_Dir)
	{
	case UP:m_Pos.y--; break;
	case DOWN:m_Pos.y++; break;
	case LEFT:m_Pos.x--; break;
	case RIGHT:m_Pos.x++; break;
	}


	/***************矩形碰撞****************/

	if (m_CurAct == 0 && m_CurF <= 3)
	{
		if (CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 150, m_Pos.y - 255) || CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 130, m_Pos.y - 310))
		{
			CFrame::GetFrame()->GetHero()->blood();
		}
	}
	/*******************子弹碰撞**************/
	it = m_Buling.begin();
	while (it != m_Buling.end())
	{
		if(m_Frame->GetHero()->GetRect()->CKpeng(it->x + 30, it->y +40))
		{
			m_Frame->GetHero()->blood();
		}
		it++;
	}




	//获得英雄坐标
	POINT tempPos;
	tempPos.x = m_Frame->GetHero()->GetPos().x;
	tempPos.y = m_Frame->GetHero()->GetPos().y;
	int x = m_Pos.x + m_Rect->m_OffX - tempPos.x - m_Frame->GetHero()->GetRect()->m_OffX;
	int y = m_Pos.y + m_Rect->m_OffY - tempPos.y - m_Frame->GetHero()->GetRect()->m_OffY;
	if (x > 0)
		PressLEFT();
	else if (x<-0)
		PressRIGHT();
	else if (y < 0)
		PressDOWN();
	else if (y > -0)
		PressUP();

	m_Atkcd--;

	if (m_Atkcd <= 0)
		m_Atkcd = 0;
	if (m_Atkcd == 0)
		Actk();
}
void CSuperBoss::End()
{
	std::vector<CAction*>::iterator it;
	for (it = m_ActList.begin(); it != m_ActList.end(); it++)delete *it;
	m_ActList.clear();
}
int CSuperBoss::GetHp()
{
	return m_Hp;
}
int CSuperBoss::GetMp()
{
	return m_Mp;
}