#include"Start.h"
#include"Frame.h"

int c = 120;
void CStart::Init()
{
	pFrame = CFrame::GetFrame();
	pFrame->SetWinDow(0, 0);
	pFrame->LoadBmp("开始标题", "pic\\0.bmp");
	pFrame->LoadBmp("框1", "pic\\框.bmp");
	pFrame->LoadBmp("框", "pic\\OP.bmp");
}
void CStart::Run()
{

	pFrame->DrawBmp("开始标题", 0, 0, 1500, 850, 0, 0, 700, 490, RGB(255, 255, 255));
	pFrame->DrawBmp("框1", 115, c, 150, 69, 0, 0, 179, 69, RGB(255, 255, 255));
	pFrame->DrawBmp("框", 100, 50, 101*2, 244*2, 0, 0, 101, 244, RGB(255, 255, 255));
	
	if (pFrame->GetKeyState(_GI_K_W) == _KS_DC) c -= 120;
	else if (pFrame->GetKeyState(_GI_K_S) == _KS_DC) c += 120;
	if (c > 360) c = 120;
	if (c < 120) c = 360;

	//上下框选择
	if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 120)
		pFrame->SetNextScene("游戏场景1");
	else if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 240)
		pFrame->SetNextScene("游戏场景2");
	else if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 360)
		PostQuitMessage(0);
}
void CStart::End()
{
	pFrame->ClearBmp();
}