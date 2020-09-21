#include"Rect.h"
#include"Action.h"
#include"Hero.h"
#include"Moster.h"
#include"Barrier.h"
#include"Frame.h"

CMoster::CMoster()
{
	m_Rect = new CRect;
}

CMoster::~CMoster()
{
	delete m_Rect;
	std::vector<CAction*>::iterator it;
	for (it = m_ActList.begin(); it != m_ActList.end(); it++)delete *it;
	m_ActList.clear();
}

void CMoster::Init()
{
	//Ѫ��
	m_Hp = 1200;
	m_Mp = 1200;
	m_Atkcd = 0;  //������ȴ
	m_Acd = 100;
	m_State = IDLE;
	m_Speed = 16;
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Dir = LEFT;
	m_Rect->Init(35, 35, -170, -300, (const int*)&m_Pos.x, (const int*)&m_Pos.y);
	m_Frame = CFrame::GetFrame();
	m_Barrier = m_Frame->GetWallList();

	m_CurAct = 0;	//��ǰ����
	m_CurF = 0;		//��ǰ�����ĵڼ���ͼƬ
	m_CurCF = 0;	//��ǰͼƬ�Ѿ�������ѭ������¼

	/**************************�ӵ�************************/
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0401.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0402.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0403.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0404.bmp");

	/***************************************��ȡ�ļ�******************/
	m_Frame->LoadBmp("������1", "pic\\boss\\0601.bmp");
	m_Frame->LoadBmp("������2", "pic\\boss\\0602.bmp");
	m_Frame->LoadBmp("������3", "pic\\boss\\0603.bmp");
	m_Frame->LoadBmp("������4", "pic\\boss\\0604.bmp");


	m_Frame->LoadBmp("������1", "pic\\boss\\0701.bmp");
	m_Frame->LoadBmp("������2", "pic\\boss\\0702.bmp");
	m_Frame->LoadBmp("������3", "pic\\boss\\0703.bmp");
	m_Frame->LoadBmp("������4", "pic\\boss\\0704.bmp");

	m_Frame->LoadBmp("������1", "pic\\boss\\0801.bmp");
	m_Frame->LoadBmp("������2", "pic\\boss\\0802.bmp");
	m_Frame->LoadBmp("������3", "pic\\boss\\0803.bmp");
	m_Frame->LoadBmp("������4", "pic\\boss\\0804.bmp");

	m_Frame->LoadBmp("������1", "pic\\boss\\0901.bmp");
	m_Frame->LoadBmp("������2", "pic\\boss\\0902.bmp");
	m_Frame->LoadBmp("������3", "pic\\boss\\0903.bmp");
	m_Frame->LoadBmp("������4", "pic\\boss\\0904.bmp");





	/***************************************���ض�������****************************/

	_PIC pic;
	CAction* act = new CAction;

	//��0
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������1";
	pic.cw = 42;
	pic.ch = 35;
	pic.sw = 42;
	pic.sh = 35;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������2";
	pic.cw = 34;
	pic.ch = 34;
	pic.sw = 34;
	pic.sh = 34;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������3";
	pic.cw = 41;
	pic.ch = 32;
	pic.sw = 41;
	pic.sh = 32;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������4";
	pic.cw = 42;
	pic.ch = 31;
	pic.sw = 42;
	pic.sh = 31;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	act->SetNextAct(0);
	m_ActList.push_back(act);


	//��
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������1";
	pic.cw = 43;
	pic.ch = 34;
	pic.sw = 43;
	pic.sh = 34;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������2";
	pic.cw = 35;
	pic.ch = 35;
	pic.sw = 35;
	pic.sh = 35;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������3";
	pic.cw = 39;
	pic.ch = 35;
	pic.sw = 39;
	pic.sh = 35;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������4";
	pic.cw = 32;
	pic.ch = 31;
	pic.sw = 32;
	pic.sh = 31;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(1);
	m_ActList.push_back(act);
	//�� 1


	//��2
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������1";
	pic.cw = 30;
	pic.ch = 36;
	pic.sw = 30;
	pic.sh = 36;
	pic.sx = 0;
	pic.sy = 0;

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������2";
	pic.cw = 31;
	pic.ch = 37;
	pic.sw = 31;
	pic.sh = 37;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������3";
	pic.cw = 31;
	pic.ch = 37;
	pic.sw = 31;
	pic.sh = 37;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������4";
	pic.cw = 30;
	pic.ch = 32;
	pic.sw = 30;
	pic.sh = 32;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(2);
	m_ActList.push_back(act);

	//�� 2


	//��3
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������1";
	pic.cw = 33;
	pic.ch = 35;
	pic.sw = 33;
	pic.sh = 35;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);




	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������2";
	pic.cw = 29;
	pic.ch = 38;
	pic.sw = 29;
	pic.sh = 38;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������3";
	pic.cw = 30;
	pic.ch = 36;
	pic.sw = 30;
	pic.sh = 36;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);



	pic.c = RGB(255, 255, 255);
	pic.cf = 5;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "������4";
	pic.cw = 31;
	pic.ch = 35;
	pic.sw = 31;
	pic.sh = 35;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(3);
	m_ActList.push_back(act);

	m_x = 500;
	m_y = 500;
	leftx = 100;
	rightx = 600;
}
void CMoster::Run()
{
	int tx = m_Pos.x - CFrame::GetFrame()->GetCX();

	//�ӵ�����
	
	/***************************************��ͼ����************************/
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

	/*************���ζ�Ӣ������˺�***********************/
	if (m_CurAct == 0 && m_CurF <= 3)
	{
		if (CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 170, m_Pos.y - 280) || CFrame::GetFrame()->GetHero()->GetRect()->CKpeng(m_Pos.x - 165, m_Pos.y - 300))
		{
			CFrame::GetFrame()->GetHero()->blood();
		}
	}


	/***************************************�ƶ�����********************/

	switch (m_Dir)
	{
	case UP:m_Pos.y--; break;
	case DOWN:m_Pos.y++; break;
	case LEFT:m_Pos.x--; break;
	case RIGHT:m_Pos.x++; break;
	}


	/************************AI��������*******************/

	//���Ӣ������
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
	


	/**************Ѫ��������*************/
	if (m_Mp >= 1200)
		m_Mp = 1200;
	if (m_Hp >= 1200)
		m_Hp = 1200;
	

	m_Atkcd--;

	if (m_Atkcd <= 0)
		m_Atkcd = 0;
	//�����ӵ�
	if (m_Atkcd == 0)
			Actk();

	//�ж���ײ
	/*******************�ӵ���ײ**************/
	

	
}

//1
void CMoster::PressUP()
{  
	if (m_CurAct == 1)	return;
	m_CurAct = 1;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = UP;

}

//2
void CMoster::PressLEFT()
{
	if (m_CurAct == 2)	return;
	m_CurAct = 2;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = LEFT;
}

//3
void CMoster::PressRIGHT()
{
	if (m_CurAct == 3)	return;
	m_CurAct = 3;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = RIGHT;
}

//0
void CMoster::PressDOWN()
{
	if (m_CurAct == 0)	return;
	m_CurAct = 0;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = DOWN;
}

void CMoster::End()
{
	int len = m_ActList.size();
	for (int i = 0; i < len; ++i)
	{
		delete m_ActList[i];
	}

	CFrame::GetFrame()->ClearBmp();
}
void CMoster::SetPos(int x, int y)
{
	m_Pos.x = x;
	m_Pos.y = y;
}
void CMoster::SetDir(int dir)
{
	m_Dir = dir;
}
CRect* CMoster::GetRect()
{
	return m_Rect;
}
POINT CMoster::GetPos()
{
	return m_Pos;
}
const int* CMoster::GetPosX()
{
	return (const int*)&m_Pos.x;
}
const int* CMoster::GetPosY()
{
	return (const int*)&m_Pos.y;
}
void CMoster::Clear()
{

}
int CMoster::GetCurAct()
{
	return m_CurAct;
}

int CMoster::GetisLive()
{
	return m_isLive;
}
void CMoster::SetisLive(int flag)
{
	m_isLive = flag;
}


void CMoster::blood()
{
	m_Hp -= 100;
	if (m_Hp <= 0)
	{
		m_Hp = 0;
		m_isLive = 0;
	}
}

int CMoster::GetHp()
{
	return m_Hp;
}
int CMoster::GetMp()
{
	return m_Mp;
}



//����
void CMoster::Actk()
{
	m_Atkcd = m_Acd;
	if (m_Dir == UP)
	{
		MYPOINT temp;
		temp.x = m_Pos.x - 150;
		temp.y = m_Pos.y - 300;
		temp.dir = UP;
		m_Buling.push_back(temp);
	}
	else if (m_Dir == DOWN)
	{
		MYPOINT temp;
		temp.x = m_Pos.x - 190;
		temp.y = m_Pos.y - 280;
		temp.dir = DOWN;
		m_Buling.push_back(temp);
	}
	else if (m_Dir == LEFT)
	{
		MYPOINT temp;
		temp.x = m_Pos.x - 190;
		temp.y = m_Pos.y - 280;
		temp.dir = LEFT;
		m_Buling.push_back(temp);
	}
	else if (m_Dir == RIGHT)
	{
		MYPOINT temp;
		temp.x = m_Pos.x - 190;
		temp.y = m_Pos.y - 280;
		temp.dir = RIGHT;
		m_Buling.push_back(temp);
	}
}
