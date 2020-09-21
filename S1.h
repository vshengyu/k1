#pragma once
#include "Scene.h"
#include<list>
#include<windows.h>
class CFrame;

#define BULLETMAX 20  //子弹个数
#define BULLETYOFF 3	 //
#define BULLETSPEED 20		//速度

#define PLAYERMOVESPEED 10  //移动速度

class CS1 :public CScene //继承顶级场景类
{
	//坐标，宽高，框架指针
	int m_x;
	int m_y;
	int bulletlen;

	CFrame* pFrame;

	//子弹
	std::list<POINT>m_Biu;

public:
	//开始，运行，结束
	void Init();
	void Run();
	void End();
};