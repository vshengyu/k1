#include"Start.h"
#include"Frame.h"

int c = 120;
void CStart::Init()
{
	pFrame = CFrame::GetFrame();
	pFrame->SetWinDow(0, 0);
	pFrame->LoadBmp("��ʼ����", "pic\\0.bmp");
	pFrame->LoadBmp("��1", "pic\\��.bmp");
	pFrame->LoadBmp("��", "pic\\OP.bmp");
}
void CStart::Run()
{

	pFrame->DrawBmp("��ʼ����", 0, 0, 1500, 850, 0, 0, 700, 490, RGB(255, 255, 255));
	pFrame->DrawBmp("��1", 115, c, 150, 69, 0, 0, 179, 69, RGB(255, 255, 255));
	pFrame->DrawBmp("��", 100, 50, 101*2, 244*2, 0, 0, 101, 244, RGB(255, 255, 255));
	
	if (pFrame->GetKeyState(_GI_K_W) == _KS_DC) c -= 120;
	else if (pFrame->GetKeyState(_GI_K_S) == _KS_DC) c += 120;
	if (c > 360) c = 120;
	if (c < 120) c = 360;

	//���¿�ѡ��
	if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 120)
		pFrame->SetNextScene("��Ϸ����1");
	else if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 240)
		pFrame->SetNextScene("��Ϸ����2");
	else if (pFrame->GetKeyState(_GI_K_RETURN) == _KS_DC && c == 360)
		PostQuitMessage(0);
}
void CStart::End()
{
	pFrame->ClearBmp();
}