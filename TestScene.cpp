#include "TestScene.h"
#include "Action.h"
#include"Frame.h"
void CTS::Init()
{
	m_Frame = CFrame::GetFrame();
	/***************************正面攻击测试************************/
	m_Frame->LoadBmp("正面攻击1", "pic\\英雄\\正面\\0101.bmp");
	m_Frame->LoadBmp("正面攻击2", "pic\\英雄\\正面\\0102.bmp");
	m_Frame->LoadBmp("正面攻击3", "pic\\英雄\\正面\\0103.bmp");
	m_Frame->LoadBmp("正面攻击4", "pic\\英雄\\正面\\0104.bmp");

	/***************************左边攻击测试************************/
	m_Frame->LoadBmp("左边攻击1", "pic\\英雄\\左边\\0205.bmp");
	m_Frame->LoadBmp("左边攻击2", "pic\\英雄\\左边\\0206.bmp");
	m_Frame->LoadBmp("左边攻击3", "pic\\英雄\\左边\\0207.bmp");
	m_Frame->LoadBmp("左边攻击4", "pic\\英雄\\左边\\0208.bmp");

	/***************************右边攻击测试************************/
	m_Frame->LoadBmp("右边攻击1", "pic\\英雄\\右边\\0301.bmp");
	m_Frame->LoadBmp("右边攻击2", "pic\\英雄\\右边\\0302.bmp");
	m_Frame->LoadBmp("右边攻击3", "pic\\英雄\\右边\\0303.bmp");
	m_Frame->LoadBmp("右边攻击4", "pic\\英雄\\右边\\0304.bmp");

	/***************************后边攻击测试************************/
	m_Frame->LoadBmp("后边攻击1", "pic\\英雄\\后面\\0305.bmp");
	m_Frame->LoadBmp("后边攻击2", "pic\\英雄\\后面\\0306.bmp");
	m_Frame->LoadBmp("后边攻击3", "pic\\英雄\\后面\\0307.bmp");
	m_Frame->LoadBmp("后边攻击4", "pic\\英雄\\右面\\0308.bmp");

	_PIC pic;
	CAction* act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "正面攻击1";
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
	pic.id = "正面攻击2";
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
	pic.id = "正面攻击3";
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
	pic.id = "正面攻击4";
	pic.cw = 77;
	pic.ch = 95;
	pic.sw = 77;
	pic.sh = 95;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(0);
	m_ActionList.push_back(act);


	/******************************左边攻击1***************************/
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "左边攻击1";
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
	pic.id = "左边攻击2";
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
	pic.id = "左边攻击3";
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
	pic.id = "左边攻击4";
	pic.cw = 84;
	pic.ch = 96;
	pic.sw = 84;
	pic.sh = 96;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(1);
	m_ActionList.push_back(act);




	/*************右边攻击1*****************/

	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "右边攻击1";
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
	pic.id = "右边攻击2";
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
	pic.id = "右边攻击3";
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
	pic.id = "右边攻击4";
	pic.cw = 92;
	pic.ch = 100;
	pic.sw = 92;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(2);
	m_ActionList.push_back(act);

	/**********************************************后边攻击1********************/
	act = new CAction;
	pic.c = RGB(255, 255, 255);
	pic.cf = 3;
	pic.offx = -177;
	pic.offy = -280;
	pic.id = "后边攻击1";
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
	pic.id = "后边攻击2";
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
	pic.id = "后边攻击3";
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
	pic.id = "后边攻击4";
	pic.cw = 79;
	pic.ch = 100;
	pic.sw = 79;
	pic.sh = 100;
	pic.sx = 0;
	pic.sy = 0;
	act->AddPic(pic);
	act->SetNextAct(3);
	m_ActionList.push_back(act);




	m_CurAct = 0;
	m_CurF = 0;
	m_CurCF = 0;
	m_Pos.x = 500;
	m_Pos.y = 450;
	m_H = 0;
	m_W = 0;
	m_Frame->LoadBmp("背景", "pic\\地图level1.bmp");
	m_Frame->SetWinDow(0, 0);
	m_Frame->LookAt((const int*)& m_Pos.x, (const int*)& m_Pos.y);//摄像机

	CFrame::GetFrame()->SetFont(50, 50);
}
void CTS::Run()
{
	m_Frame->CameraMove();
	m_Frame->DrawBmp("背景", 0, 0, 1152, 1000, 0, 0, 1152, 648);
	CFrame* Frame = CFrame::GetFrame();
	_PIC* pic = m_ActionList[m_CurAct]->GetPic(m_CurF);


	/********判断pic是否为空**********/
	if (pic != NULL)
		m_Frame->DrawBmp(pic->id, m_Pos.x + pic->offx, m_Pos.y + pic->offy, pic->cw, pic->ch, pic->sx, pic->sy, pic->sw, pic->sh, pic->c);
	m_CurCF += 1;

	if (m_CurCF >= pic->cf)
	{
		m_CurCF = 0;
		m_CurF += 1;
		if (m_CurF >= m_ActionList[m_CurAct]->GetActLen() - 1 )
		{
			m_CurAct = m_ActionList[m_CurAct]->GetNextAct();
			m_CurF = 0;
		}
	}
	if (m_Frame->GetKeyState(_GI_K_A) == _KS_DH)
	{
		m_CurAct = 1;
		m_CurF += 1;
		m_Pos.x -= 10;
		

	}
	else if (m_Frame->GetKeyState(_GI_K_D) == _KS_DH)
	{
		m_CurAct = 2;
		m_CurF += 1;
		m_Pos.x += 10;

	}

	if (m_Frame->GetKeyState(_GI_K_W) == _KS_DH)
	{
		m_CurAct = 3;
		m_CurF += 1;
		m_Pos.y -= 10;
	}
	else if (m_Frame->GetKeyState(_GI_K_S) == _KS_DH)
	{
		m_CurAct = 0;
		m_CurF += 1;
		m_Pos.y += 10;
	}


	if (m_Frame->GetKeyState(_GI_K_J) == _KS_DC)
	{
		m_CurAct = 1;
		m_CurF = 0;
		m_CurCF = 0;
	}




	if (m_Frame->GetKeyState(_GI_K_K) == _KS_DC)
	{
		
		m_CurF = 2;
		m_CurCF = 1;
	}


	Sleep(20);
	/*Frame->DrawLine(50, m_y, 1500, m_y, RGB(0, 254, 0), 2);
	Frame->DrawSolidRect(m_x - 2, m_y - 2, 5, 5, 1, RGB(255, 0, 0), RGB(255, 0, 0));
	char buf[64];
	sprintf_s(buf, 64, "CurF = %d, x = %d, y = %d", m_CurF, pic->offx, pic->offy);
	Frame->DrawString(20, 20, buf, RGB(0, 0, 200));*/
}
void CTS::End()
{
	std::vector<CAction*>::iterator it;
	for (it = m_ActionList.begin(); it != m_ActionList.end(); it++)delete* it;
	m_ActionList.clear();
	m_Frame->ClearBmp();
}