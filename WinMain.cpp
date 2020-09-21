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
	//生成场景
	p->Init(_CLIENT_W, _CLIENT_H, hInstance, hPrevInstance, lpCmdLine,
	nCmdShow);

	//游戏开始界面
	p->AddScen("开始", new CStart);
	p->AddScen("游戏场景1", new CS2);

	p->SetFistScene("开始");
	//设置初始场景
	p->Run();
	p->End();
	
}