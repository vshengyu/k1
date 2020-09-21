#include"Hero.h"
#include"Rect.h"
#include"Barrier.h"
#include"Moster.h"
#include"Frame.h"
#include"S3.h"
#include"boss.h"


void CS3::Init()
{
	m_Frame = CFrame::GetFrame();
	m_Frame->SetWinDow(0, 0);
	m_Frame->LookAt(m_Frame->GetHero()->GetPosX(), m_Frame->GetHero()->GetPosY());
	m_Frame->LoadBmp("±³¾°", "pic\\S3.bmp");
}
void CS3::Run()
{
	m_Frame->CameraMove();
	m_Frame->DrawBmp("±³¾°", 0, 0, 2114, 1200, 0, 0, 1152, 648);

	//ÑªÌõ

}
void CS3::End()
{
	m_Frame->ClearMoster();
}