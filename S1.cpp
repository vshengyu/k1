#include"S1.h"
#include"Frame.h"
void CS1::Init()
{
	pFrame = CFrame::GetFrame();
	pFrame->LoadBmp("小丑", "Sprite1.bmp");
	m_x = 0;
	m_y = 400;

}
void CS1::Run()
{
	//pFrame->DrawBmp("小丑", m_x, m_y, 63, 127, 0, 0, 63, 127);
	////                                        原图宽 高，新图x,y和宽高
	//pFrame->DrawBmp("小丑", m_x + 45, m_y + 45, 65, 34, 66, 25, 65, 34);
	//枪 67,26,64,33
	//子弹 59,135,12,4

	std::list<POINT>::iterator it = m_Biu.begin();
	bulletlen = 0;
	while (it != m_Biu.end())
	{
		bulletlen++;
		pFrame->DrawBmp("小丑", it->x, it->y, 12, 4, 59, 135, 12, 4);	//子弹
		it++;
	}

	pFrame->DrawBmp("小丑", m_x, m_y, 63, 127, 0, 0, 63, 127);				//人
	pFrame->DrawBmp("小丑", m_x + 45, m_y + 45, 64, 33, 67, 26, 64, 33);	//枪


	if (pFrame->GetKeyState(_GI_K_W) == _KS_DH) m_y -= PLAYERMOVESPEED;
	else if (pFrame->GetKeyState(_GI_K_S) == _KS_DH) m_y += PLAYERMOVESPEED;
	if (pFrame->GetKeyState(_GI_K_A) == _KS_DH)m_x -= PLAYERMOVESPEED;
	else if (pFrame->GetKeyState(_GI_K_D) == _KS_DH)m_x += PLAYERMOVESPEED;


	it = m_Biu.begin();
	while (it != m_Biu.end())
	{
		int c = pFrame->GetCX();
		if (it->x > 1600)
			it = m_Biu.erase(it);
		else
		{
			it->x += BULLETSPEED;
			it->y += rand() % (BULLETYOFF * 2) - BULLETYOFF;
			it++;
		}
	}
	if (pFrame->GetKeyState(_GI_K_J) == _KS_DH)
	{

		POINT temp;


		if (bulletlen <= BULLETMAX)
		{
			temp.x = m_x + 67 + 40;//枪偏移+枪口偏移
			temp.y = m_y + 26 + 22;
			m_Biu.push_back(temp);
			bulletlen++;
		}
	}
	Sleep(15);
}
void CS1::End()
{
	pFrame->ClearBmp();
}