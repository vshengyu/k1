#pragma once
#include "Scene.h"
#include<vector>
#include<windows.h>
class CFrame;
class CAction;
class CTS:public CScene
{
	POINT m_Pos;  //获取位置

	int m_W;
	int m_H;

	CFrame* m_Frame;  //框架指针

	std::vector<CAction*> m_ActionList;

	int m_CurAct;	//当前动作
	int m_CurF;		//当前动作的第几张图片
	int m_CurCF;	//当前图片已经持续的循环数记录
	
public:
	void Init();
	void Run();
	void End();


};

