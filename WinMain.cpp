#include"Frame.h"
#include"S2.h"
#include"Start.h"
#include"S1.h"
#include"TestScene.h"




#define _CLIENT_W 1600
#define _CLIENT_H 900

int __stdcall WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)



{
	CFrame* p = CFrame::GetFrame();
	//���ɳ���
	p->Init(_CLIENT_W, _CLIENT_H, hInstance, hPrevInstance, lpCmdLine,
	nCmdShow);

	//��Ϸ��ʼ����
	p->AddScen("��ʼ", new CStart);
	p->AddScen("��Ϸ����1", new CS2);

	p->SetFistScene("��ʼ");
	//���ó�ʼ����
	p->Run();
	p->End();
	
}