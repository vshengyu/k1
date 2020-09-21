#include"Hero.h"
#include"Rect.h"
#include"Barrier.h"
#include"Moster.h"
#include"Frame.h"
#include"S2.h"
#include"boss.h"
#include"SuperBoss.h"

void CS2::Init()
{
	m_Frame = CFrame::GetFrame();
	m_Frame->SetWinDow(0, 0);
	m_Frame->LookAt(m_Frame->GetHero()->GetPosX(), m_Frame->GetHero()->GetPosY());
	m_Frame->LoadBmp("背景", "pic\\map3.bmp");
	m_Frame->LoadBmp("Boss", "pic\\S3\\0666.bmp");
	m_Frame->LoadBmp("头像", "pic\\poto.bmp");
	m_Frame->LoadBmp("框", "pic\\buff.bmp");


	/********************************障碍物加载区域***********************************************************///

	CBarrier* wall = new CBarrier;
	wall->Init(1000, 1000);
	wall->SetPos(500,450);
	m_Frame->AddWall(wall);

	wall = new CBarrier;
	wall->Init(1000, 3);
	wall->SetPos(0, -2);
	m_Frame->AddWall(wall);


	/********************************敌人加载区域***********************************************************/

	CBoss* boss;

	boss = new CBoss;
	boss->Init();
	boss->SetPos(600, 800);
	m_Frame->AddMoster(boss);

	boss = new CBoss;
	boss->Init();
	boss->SetPos(100, 100);
	m_Frame->AddMoster(boss);




	CMoster* moster;

	moster = new CMoster;
	moster->Init();
	moster->SetPos(500, 400);
	m_Frame->AddMoster(moster);


	moster = new CMoster;
	moster->Init();
	moster->SetPos(500, 600);
	m_Frame->AddMoster(moster);


	moster = new CMoster;
	moster->Init();
	moster->SetPos(100, 600);
	m_Frame->AddMoster(moster);


	CSuperBoss* superboss;

	superboss = new CSuperBoss;
	superboss->Init();
	superboss->SetPos(1200, 600);
	m_Frame->AddMoster(superboss);


}
void CS2::Run()
{
	m_Frame->CameraMove();
	m_Frame->DrawBmp("背景", 0, 0, 2114, 1200, 0, 0, 2108, 866);
	m_Frame->DrawBmp("头像", 700 + m_Frame->GetCX(), 680 + m_Frame->GetCY(), 255, 222, 0, 0, 357, 355, RGB(255, 255, 255));
	m_Frame->DrawBmp("框", 0 + m_Frame->GetCX(), 100 + m_Frame->GetCY(), 1600, 800, 0, 0, 2114, 1200, RGB(255, 255, 255));
	m_Frame->DrawBmp("Boss", 1210+ m_Frame->GetCX(), 690 + m_Frame->GetCY(), 160, 160, 0, 0, 170, 170, RGB(255, 255, 255));

	//英雄血条
	m_Frame->DrawSolidRect(116, 755, m_Frame->GetHero()->GetHP() / 4, 12, 4 * 4, RGB(0, 120, 16), RGB(0, 120, 16));
	m_Frame->DrawSolidRect(60, 820, m_Frame->GetHero()->GetMP() / 4, 12, 4 * 4, RGB(25, 107, 193), RGB(25, 107, 193));
	
	//Boss血条
	m_Frame->DrawSolidRect(1150, 861, m_Frame->GetMoster()->GetHp() / 4, 12, 4 * 3, RGB(120, 0, 16), RGB(120, 0, 16));

	m_Frame->DrawSolidRect(1150, 886, m_Frame->GetMoster()->GetMp() / 4, 12, 2, RGB(0, 0, 120), RGB(0, 0, 120));

		//61 69


	//死亡重置
	if (m_Frame->GetHero()->GetisLive() == 0)
	{
		m_Frame->GetHero()->Init();
		m_Frame->GetHero()->SetPos(600, 500);
		m_Frame->SetNextScene("游戏场景1");
	}

	std::list<CMoster*>* templist = m_Frame->GetMosterList();
	std::list<CMoster*>::iterator it;
	m_Frame->GetHero()->Run();
	it = templist->begin();
	while (it!=templist->end())
	{
		if ((*it)->GetCurAct() == 10)
		{
			delete *it;
			it = templist->erase(it);
		}
		else
		{
			(*it)->Run();
			it++;
		}
	}

	/*for (it = templist->begin(); it != templist->end(); it++)
	{
		m_Frame->DrawRect(*(*it)->GetRect()->m_X + (*it)->GetRect()->m_OffX - m_Frame->GetCX(),
			*(*it)->GetRect()->m_Y + (*it)->GetRect()->m_OffY - m_Frame->GetCY(),
			(*it)->GetRect()->m_W, (*it)->GetRect()->m_H, 3, RGB(0, 255, 0));
	}

	m_Frame->DrawRect(*m_Frame->GetHero()->GetRect()->m_X + m_Frame->GetHero()->GetRect()->m_OffX - m_Frame->GetCX(),
		*m_Frame->GetHero()->GetRect()->m_Y + m_Frame->GetHero()->GetRect()->m_OffY - m_Frame->GetCY(),
		m_Frame->GetHero()->GetRect()->m_W, m_Frame->GetHero()->GetRect()->m_H, 3, RGB(0, 255, 0));

	m_Frame->DrawRect(*m_Frame->GetHero()->GetRect()->m_X + m_Frame->GetHero()->GetRect()->m_OffX - m_Frame->GetCX(),
		*m_Frame->GetHero()->GetRect()->m_Y + m_Frame->GetHero()->GetRect()->m_OffY - m_Frame->GetCY(),
		m_Frame->GetHero()->GetRect()->m_W, m_Frame->GetHero()->GetRect()->m_H, 3, RGB(255, 0, 0));*/

	//m_Frame->DrawRect(30 - m_Frame->GetCX(), 0 - m_Frame->GetCY(), 70, 70, 3, RGB(255, 255, 0));
}

void CS2::End()
{
	m_Frame->ClearMoster();
	m_Frame->ClearWall();
}