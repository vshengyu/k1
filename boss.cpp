#include"boss.h"
#include"Frame.h"
#include"Rect.h"
#include"Barrier.h"
#include"Action.h"
#include"Hero.h"

void CBoss::Init()
{
	m_State = _IDLE;
	m_Speed = 8;
	m_Pos.x = 0;
	m_Atkcd = 0;  //攻击冷却
	m_Acd = 100;
	m_Pos.y = 0;
	m_Dir = LEFT;
	m_Rect->Init(30, 30, -150, -255, (const int*)&m_Pos.x, (const int*)&m_Pos.y);
	
	m_Frame = CFrame::GetFrame();
	m_Barrier = m_Frame->GetWallList();

	m_CurAct = 0;	//当前动作
	m_CurF = 0;		//当前动作的第几张图片
	m_CurCF = 0;	//当前图片已经持续的循环数记录


	/**************************子弹************************/
	m_Frame->LoadBmp("子弹_上", "pic\\子弹\\0401.bmp");
	m_Frame->LoadBmp("子弹_下", "pic\\子弹\\0402.bmp");
	m_Frame->LoadBmp("子弹_右", "pic\\子弹\\0403.bmp");
	m_Frame->LoadBmp("子弹_左", "pic\\子弹\\0404.bmp");

	/***************************************读取文件******************/
	m_Frame->LoadBmp("龙下1","pic\\boss1\\0111.bmp");
	m_Frame->LoadBmp("龙下2", "pic\\boss1\\0112.bmp");
	m_Frame->LoadBmp("龙下3", "pic\\boss1\\0113.bmp");
	m_Frame->LoadBmp("龙下4", "pic\\boss1\\0114.bmp");

	m_Frame->LoadBmp("龙上1", "pic\\boss1\\0123.bmp");
	m_Frame->LoadBmp("龙上2", "pic\\boss1\\0124.bmp");
	m_Frame->LoadBmp("龙上3", "pic\\boss1\\0125.bmp");
	m_Frame->LoadBmp("龙上4", "pic\\boss1\\0126.bmp");

	m_Frame->LoadBmp("龙左1", "pic\\boss1\\0115.bmp");
	m_Frame->LoadBmp("龙左2", "pic\\boss1\\0116.bmp");
	m_Frame->LoadBmp("龙左3", "pic\\boss1\\0117.bmp");
	m_Frame->LoadBmp("龙左4", "pic\\boss1\\0118.bmp");

	m_Frame->LoadBmp("龙右1", "pic\\boss1\\0119.bmp");
	m_Frame->LoadBmp("龙右2", "pic\\boss1\\0120.bmp");
	m_Frame->LoadBmp("龙右3", "pic\\boss1\\0121.bmp");
	m_Frame->LoadBmp("龙右4", "pic\\boss1\\0122.bmp");



	
	/***************************************加载动画区域****************************/
	_PIC pic;
	CAction* act = new CAction;

	//下0
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙下1";
	pic.cw = 94;
	pic.ch = 93;
	pic.sw = 94;
	pic.sh = 93;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙下2";
	pic.cw = 94;
	pic.ch = 93;
	pic.sw = 94;
	pic.sh = 93;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙下3";
	pic.cw = 97;
	pic.ch = 93;
	pic.sw = 97;
	pic.sh = 93;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙下4";
	pic.cw = 93;
	pic.ch = 93;
	pic.sw = 93;
	pic.sh = 93;
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
	pic.id = "龙上1";
	pic.cw = 93;
	pic.ch = 99;
	pic.sw = 93;
	pic.sh = 99;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙上2";
	pic.cw = 85;
	pic.ch = 99;
	pic.sw = 85;
	pic.sh = 99;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙上3";
	pic.cw = 92;
	pic.ch = 96;
	pic.sw = 92;
	pic.sh = 96;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙上4";
	pic.cw = 93;
	pic.ch = 97;
	pic.sw = 93;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(1);
	m_ActList.push_back(act);



	//左	2

	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙左1";
	pic.cw = 95;
	pic.ch = 97;
	pic.sw = 95;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙左2";
	pic.cw = 97;
	pic.ch = 97;
	pic.sw = 97;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙左3";
	pic.cw = 97;
	pic.ch = 91;
	pic.sw = 97;
	pic.sh = 91;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙左4";
	pic.cw = 97;
	pic.ch = 95;
	pic.sw = 97;
	pic.sh = 95;
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
	pic.id = "龙右1";
	pic.cw = 95;
	pic.ch = 98;
	pic.sw = 95;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙右2";
	pic.cw = 96;
	pic.ch = 93;
	pic.sw = 96;
	pic.sh = 93;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙右3";
	pic.cw = 100;
	pic.ch = 91;
	pic.sw = 100;
	pic.sh = 91;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "龙右4";
	pic.cw = 95;
	pic.ch = 95;
	pic.sw = 95;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(3);
	m_ActList.push_back(act);

}

void CBoss::Run()
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


	 //移动
	switch (m_Dir)
	{
	case UP:m_Pos.y--; break;
	case DOWN:m_Pos.y++; break;
	case LEFT:m_Pos.x--; break;
	case RIGHT:m_Pos.x++; break;
	}

	//攻击
	it = m_Buling.begin();
	while (it != m_Buling.end())
	{
		if (m_Frame->GetHero()->GetRect()->CKpeng(it->x + 28, it->y + 32))
		{
			m_Frame->GetHero()->blood();
		}
		it++;
	}


	/***************矩形*****************/

	if (m_CurAct == 0 && m_CurF <= 3)
	{
		if (CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 150, m_Pos.y - 255) || CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 130, m_Pos.y - 310))
		{
			CFrame::GetFrame()->GetHero()->blood();
		}
	}

	/***************矩形*****************/

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
void CBoss::End()
{
	std::vector<CAction*>::iterator it;
	for (it = m_ActList.begin(); it != m_ActList.end(); it++)delete *it;
	m_ActList.clear();
}

