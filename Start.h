#pragma once

#include "Scene.h"

class CFrame;
class CStart :public CScene
{
	CFrame* pFrame;
public:
	//��ʼ�����У�����
	void Init();
	void Run();
	void End();
};
