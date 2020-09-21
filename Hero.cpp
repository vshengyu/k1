#include"Hero.h"
#include"Frame.h"
#include"Rect.h"
#include"Action.h"
#include"Orth.h"
#include"Barrier.h"
#include"Moster.h"



void CHero::Init()
{
	/*******************��������*****************************/


	m_mp = 1900;//��
	m_hp = 1900;//Ѫ

	m_State = IDLE;
	m_Speed = 5;
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Dir = _LEFT;
	m_isLive = 1;
	m_Rect = new CRect;
	m_Rect->Init(50, 60, -165, -255, (const int*)&(m_Pos.x), (const int*)(&m_Pos.y));

	m_Barrier = CFrame::GetFrame()->GetWallList();

	/************************************************/
	m_Frame = CFrame::GetFrame();
	/**************************�ӵ�************************/
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0401.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0402.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0403.bmp");
	m_Frame->LoadBmp("�ӵ�_��", "pic\\�ӵ�\\0404.bmp");

	/***************************���湥������************************/
	m_Frame->LoadBmp("���湥��1", "pic\\Ӣ��\\����\\0101.bmp");
	m_Frame->LoadBmp("���湥��2", "pic\\Ӣ��\\����\\0102.bmp");
	m_Frame->LoadBmp("���湥��3", "pic\\Ӣ��\\����\\0103.bmp");
	m_Frame->LoadBmp("���湥��4", "pic\\Ӣ��\\����\\0104.bmp");
	m_Frame->LoadBmp("վ", "pic\\Ӣ��\\����\\վ.bmp");

	/***************************��߹�������************************/
	m_Frame->LoadBmp("��߹���1", "pic\\Ӣ��\\���\\0205.bmp");
	m_Frame->LoadBmp("��߹���2", "pic\\Ӣ��\\���\\0206.bmp");
	m_Frame->LoadBmp("��߹���3", "pic\\Ӣ��\\���\\0207.bmp");
	m_Frame->LoadBmp("��߹���4", "pic\\Ӣ��\\���\\0208.bmp");
	m_Frame->LoadBmp("վ", "pic\\Ӣ��\\���\\վ.bmp");

	/***************************�ұ߹�������************************/
	m_Frame->LoadBmp("�ұ߹���1", "pic\\Ӣ��\\�ұ�\\0301.bmp");
	m_Frame->LoadBmp("�ұ߹���2", "pic\\Ӣ��\\�ұ�\\0302.bmp");
	m_Frame->LoadBmp("�ұ߹���3", "pic\\Ӣ��\\�ұ�\\0303.bmp");
	m_Frame->LoadBmp("�ұ߹���4", "pic\\Ӣ��\\�ұ�\\0304.bmp");
	m_Frame->LoadBmp("վ", "pic\\Ӣ��\\�ұ�\\վ.bmp");

	/***************************��߹�������************************/
	m_Frame->LoadBmp("��߹���1", "pic\\Ӣ��\\����\\0305.bmp");
	m_Frame->LoadBmp("��߹���2", "pic\\Ӣ��\\����\\0306.bmp");
	m_Frame->LoadBmp("��߹���3", "pic\\Ӣ��\\����\\0307.bmp");
	m_Frame->LoadBmp("��߹���4", "pic\\Ӣ��\\����\\0308.bmp");
	m_Frame->LoadBmp("վ", "pic\\Ӣ��\\����\\վ.bmp");


	/****************************Ѫ��*****************************/

	//m_Frame->LoadBmp("Ѫ��1", "pic\\Ѫ��\\0501.bmp");
	//m_Frame->LoadBmp("Ѫ��2", "pic\\Ѫ��\\0502.bmp");
	//m_Frame->LoadBmp("Ѫ��3", "pic\\Ѫ��\\0503.bmp");
	//m_Frame->LoadBmp("Ѫ��4", "pic\\Ѫ��\\0504.bmp");
	//m_Frame->LoadBmp("Ѫ��5", "pic\\Ѫ��\\0505.bmp");
	//m_Frame->LoadBmp("Ѫ��5", "pic\\Ѫ��\\0506.bmp");


	_PIC pic;
	CAction* act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "���湥��1";
	pic.cw = 77;
	pic.ch = 90;
	pic.sw = 77;
	pic.sh = 90;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "���湥��2";
	pic.cw = 81;
	pic.ch = 95;
	pic.sw = 81;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);


	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "���湥��3";
	pic.cw = 77;
	pic.ch = 95;
	pic.sw = 77;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "���湥��4";
	pic.cw = 77;
	pic.ch = 95;
	pic.sw = 77;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(5);
	m_ActList.push_back(act);


	/******************************��߹���1***************************/
	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���1";
	pic.cw = 81;
	pic.ch = 95;
	pic.sw = 81;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���2";
	pic.cw = 84;
	pic.ch = 96;
	pic.sw = 84;
	pic.sh = 96;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���3";
	pic.cw = 84;
	pic.ch = 96;
	pic.sw = 84;
	pic.sh = 96;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���4";
	pic.cw = 84;
	pic.ch = 96;
	pic.sw = 84;
	pic.sh = 96;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(6);
	m_ActList.push_back(act);




	/*************�ұ߹���1*****************/

	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "�ұ߹���1";
	pic.cw = 87;
	pic.ch = 97;
	pic.sw = 87;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "�ұ߹���2";
	pic.cw = 87;
	pic.ch = 98;
	pic.sw = 87;
	pic.sh = 98;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "�ұ߹���3";
	pic.cw = 88;
	pic.ch = 100;
	pic.sw = 88;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "�ұ߹���4";
	pic.cw = 92;
	pic.ch = 100;
	pic.sw = 92;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(7);
	m_ActList.push_back(act);

	/**********************************************��߹���1********************/


	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���1";
	pic.cw = 76;
	pic.ch = 100;
	pic.sw = 76;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���2";
	pic.cw = 79;
	pic.ch = 100;
	pic.sw = 79;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���3";
	pic.cw = 79;
	pic.ch = 100;
	pic.sw = 79;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���4";
	pic.cw = 79;
	pic.ch = 100;
	pic.sw = 79;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(4);
	m_ActList.push_back(act);
	//////////////////////վ����
	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���1";
	pic.cw = 76;
	pic.ch = 100;
	pic.sw = 76;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	act->AddPic(pic);
	act->SetNextAct(4);
	m_ActList.push_back(act);
	//////////////////////վ����
	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "���湥��1";
	pic.cw = 77;
	pic.ch = 90;
	pic.sw = 77;
	pic.sh = 90;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	act->AddPic(pic);
	act->SetNextAct(5);
	m_ActList.push_back(act);
	//////////////////////վ����
	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "��߹���1";
	pic.cw = 81;
	pic.ch = 95;
	pic.sw = 81;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	act->AddPic(pic);
	act->SetNextAct(6);
	m_ActList.push_back(act);
	//////////////////////վ����
	act = new CAction;

	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "�ұ߹���1";
	pic.cw = 87;
	pic.ch = 97;
	pic.sw = 87;
	pic.sh = 97;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);

	act->AddPic(pic);
	act->SetNextAct(7);
	m_ActList.push_back(act);


	m_CurAct = 0;
	m_CurF = 0;
	m_CurCF = 0;
	m_Pos.x = 500;//Ӣ�۵�λ��
	m_Pos.y = 450;
	m_H = 0;
	m_W = 0;



	CFrame::GetFrame()->SetFont(50, 50);







	/******************************ͼƬ����*************************/
	m_CurAct = 7;
	m_CurF = 0;
	m_CurCF = 0;

	//??
	m_x = 500;
	m_y = 700;
}



//����״̬
void CHero::Idle()
{

	m_CurF = 0;
	m_CurCF = 0;

	if (m_Dir == _UP)
	{
		m_CurAct = 4;
	}
	if (m_Dir == _DOWN)
	{
		m_CurAct = 5;
	}
	if (m_Dir == _LEFT)
	{
		m_CurAct = 6;
	}
	if (m_Dir == _RIGHT)
	{
		m_CurAct = 7;
	}
	m_State = IDLE;
}


void CHero::Run()
{
	m_Frame->CameraMove();
	//�ӵ�����
	std::list<MYPOINT>::iterator it = m_Biu.begin();
	while (it != m_Biu.end())
	{
		if (it->dir == _UP)
			m_Frame->DrawBmp("�ӵ�_��", it->x , it->y , 57, 65, 0, 0, 57, 65, RGB(0, 0, 0));	//�ӵ���
		else if (it->dir == _DOWN)
			m_Frame->DrawBmp("�ӵ�_��", it->x, it->y , 56, 61, 0, 0, 56, 61, RGB(0, 0, 0));	//�ӵ���
		else if (it->dir == _LEFT)
			m_Frame->DrawBmp("�ӵ�_��", it->x , it->y, 57, 63, 0, 0, 57, 63, RGB(0, 0, 0));	//�ӵ���
		else if (it->dir == _RIGHT)
			m_Frame->DrawBmp("�ӵ�_��", it->x , it->y, 57, 61, 0, 0, 57, 61, RGB(0, 0, 0));	//�ӵ���
		it++;

	}

	it = m_Biu.begin();
	while (it != m_Biu.end())
	{
		////�ӵ���ʧ����
		if (it->x - m_Frame->GetCX() > 1600)	it = m_Biu.erase(it);
		else if (it->x - m_Frame->GetCX() < 0)	it = m_Biu.erase(it);
		else if (it->y - m_Frame->GetCY() > 800)	it = m_Biu.erase(it);
		else if (it->y - m_Frame->GetCY() < 0)	it = m_Biu.erase(it);


		else
		{
			if (it->dir == _UP)
				it->y -= 30;
			else if (it->dir == _DOWN)
				it->y += 30;
			else if (it->dir == _RIGHT)
				it->x += 30;
			else if (it->dir == _LEFT)
				it->x -= 30;
			it++;
		}
	}

	/*****************************�ж��ӵ���ײ************************/
	std::list<CMoster*>* templist = CFrame::GetFrame()->GetMosterList();
	std::list<CMoster*>::iterator it1;
		it = m_Biu.begin();
		while (it!=m_Biu.end())
		{
			it1 = templist->begin();
			bool flag = false;
			while (it1 != templist->end())
			{
				if ((*it1)->GetRect()->CKpeng(it->x+28, it->y+32))
				{
					flag = true;
					delete (*it1);
					templist->erase(it1);
					it = m_Biu.erase(it);
					break;
				}
				it1++;
			}
			if (flag)break;
			it++;
		}

		/**************Ѫ��������*************/
		m_mp += 1;
		if (m_mp >= 1900)
			m_mp = 1900;
		if (m_hp >= 1900)
			m_hp = 1900;




	//*********************************ͼƬ
	_PIC* pic = m_ActList[m_CurAct]->GetPic(m_CurF);

	if (pic != NULL)
		m_Frame->DrawBmp(pic->id, m_Pos.x + pic->offx, m_Pos.y + pic->offy, pic->cw, pic->ch, pic->sx, pic->sy, pic->sw, pic->sh, pic->c);

	m_CurCF += 1;
	if (m_CurCF >= pic->cf)
	{
		m_CurCF = 0;
		m_CurF += 1;
		if (m_CurF >= m_ActList[m_CurAct]->GetActLen() - 1)
		{
			m_CurAct = m_ActList[m_CurAct]->GetNextAct();
			if (m_State == _ATTACK)
				m_State = m_Dir;
			m_CurF = 0;
		}
	}

	//����
	if (m_Frame->GetKeyState(_GI_K_A) == _KS_DH && m_State != _ATTACK)
		m_State = _LEFT;
	else if (m_Frame->GetKeyState(_GI_K_D) == _KS_DH && m_State != _ATTACK)
		m_State = _RIGHT;
	else if (m_Frame->GetKeyState(_GI_K_W) == _KS_DH && m_State != _ATTACK)
		m_State = _UP;
	else if (m_Frame->GetKeyState(_GI_K_S) == _KS_DH && m_State != _ATTACK)
		m_State = _DOWN;
	else
		Idle();
	if (m_Frame->GetKeyState(_GI_K_J) == _KS_DC && m_State != _ATTACK)			PressJ();


	//��ǰ״̬
	if (m_State == 0)		
		PressA();
	if (m_State == 1)	
		PressD();
	if (m_State == 2)	
		PressW();
	if (m_State == 3)	
		PressS();

	if (m_State != _ATTACK)	
		Move();


	//�ж���ײ
	

}


void CHero::End()
{
	int len = m_ActList.size();
	for (int i = 0; i < len; ++i)
	{
		delete m_ActList[i];
	}
	if (m_Rect)delete m_Rect;
	CFrame::GetFrame()->ClearBmp();
}
/**********************************Ӣ���ƶ�***************************/

void CHero::PressA()
{
	if (m_CurAct == 3 || m_CurAct == 2 || m_CurAct == 0)
	{
		m_CurF = 0;
		m_CurCF = 0;
	}
	if (m_CurAct == 1)	return;
	m_CurAct = 1;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = 0;
}
void CHero::PressD()
{
	if (m_CurAct == 3 || m_CurAct == 1 || m_CurAct == 0)
	{
		m_CurF = 0;
		m_CurCF = 0;
	}
	if (m_CurAct == 2)	return;
	m_CurAct = 2;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = 1;
}
void CHero::PressW()
{
	if (m_CurAct == 2 || m_CurAct == 1 || m_CurAct == 0)
	{
		m_CurF = 0;
		m_CurCF = 0;
	}
	if (m_CurAct == 3)	return;
	m_CurAct = 3;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = 2;
}
void CHero::PressS()
{
	if (m_CurAct == 3 || m_CurAct == 1 || m_CurAct == 2)
	{
		m_CurF = 0;
		m_CurCF = 0;
	}
	if (m_CurAct == 0)	return;
	m_CurAct = 0;
	m_CurF = 0;
	m_CurCF = 0;
	m_Dir = 3;
}

//****************************************����״̬**************************************/
void CHero::PressJ()
{

	if (m_State == _RIGHT)
	{
		if (m_mp < 100)
			return;
		m_mp -= 100;//������
		m_CurAct = 2;
		m_CurF = 0;
		m_CurCF = 0;
		MYPOINT temp;
		temp.x = m_Pos.x - 120;
		temp.y = m_Pos.y - 300;
		temp.dir = _RIGHT;
		m_Biu.push_back(temp);
	}
	else if (m_State == _LEFT)
	{
		if (m_mp < 100)
			return;
		m_mp -= 100;//������
		m_CurAct = 1;
		m_CurF = 0;
		m_CurCF = 0;
		MYPOINT temp;
		temp.x = m_Pos.x - 190;
		temp.y = m_Pos.y - 300;
		temp.dir = _LEFT;
		m_Biu.push_back(temp);
	}
	else if (m_State == _UP)
	{
		if (m_mp < 100)
			return;
		m_mp -= 100;//������
		m_CurAct = 3;
		m_CurF = 0;
		m_CurCF = 0;
		MYPOINT temp;
		temp.x = m_Pos.x - 150;
		temp.y = m_Pos.y - 300;
		temp.dir = _UP;
		m_Biu.push_back(temp);
	}
	else if (m_State == _DOWN)
	{
		if (m_mp < 100)
			return;
		m_mp -= 100;//������
		m_CurAct = 0;
		m_CurF = 0;
		m_CurCF = 0;
		MYPOINT temp;
		temp.x = m_Pos.x - 190;
		temp.y = m_Pos.y - 280;
		temp.dir = _DOWN;
		m_Biu.push_back(temp);
	}
	else if (m_State == IDLE)
	{
		if (m_Dir == _RIGHT)
		{
			m_CurAct = 2;
			m_CurF = 0;
			m_CurCF = 0;
		}
		else if (m_Dir == _LEFT)
		{
			m_CurAct = 1;
			m_CurF = 0;
			m_CurCF = 0;
		}
		else if (m_Dir == _UP)
		{
			m_CurAct = 3;
			m_CurF = 0;
			m_CurCF = 0;
		}
		else if (m_Dir == _DOWN)
		{
			m_CurAct = 0;
			m_CurF = 0;
			m_CurCF = 0;
		}
	}
	m_State = _ATTACK;
	
}
void CHero::Move()
{
	if (m_State == IDLE)
		return;
	if (m_State == _LEFT)
		m_Pos.x -= m_Speed;
	else if (m_State == _RIGHT)
		m_Pos.x += m_Speed;
	else if (m_State == _UP)
		m_Pos.y -= m_Speed;
	else if (m_State == _DOWN)
		m_Pos.y += m_Speed;
}
void PressK()
{

}

//����
CRect* CHero::GetRect()
{
	return m_Rect;
}
void CHero::SetPos(int x, int y)
{
	m_Pos.x = x;
	m_Pos.y = y;
}
void CHero::SetState(int state)
{
	m_State = state;
}
_POINT CHero::GetPos()
{
	return m_Pos;
}
const int* CHero::GetPosX()
{
	return &m_Pos.x;
}
const int* CHero::GetPosY()
{
	return &m_Pos.y;
}

void CHero::SetisLive(int flag)
{
	m_isLive = flag;
}
int CHero::GetisLive()
{
	return m_isLive;
}


/**********************12.23���*****************************/
//��õ�ǰ����
int CHero::GetCurAct()
{
	return m_CurAct1;
}
void CHero::SetCurAct(int act)
{
	m_CurAct1 = act;
}

//Ӣ��Ѫ��������
int CHero::GetHP()
{
	return m_hp;
}
int CHero::GetMP()
{
	return m_mp;
}

//��Ѫ
void  CHero::blood()
{
	m_hp -= 150; 
	if (m_hp <= 0)
	{
		m_hp = 0;
		m_isLive = 0;
	}
}

