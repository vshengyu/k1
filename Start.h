#pragma once

#include "Scene.h"

class CFrame;
class CStart :public CScene
{
	CFrame* pFrame;
public:
	//开始，运行，结束
	void Init();
	void Run();
	void End();
};
