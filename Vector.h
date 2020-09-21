#pragma once
#include<Windows.h>
class CVector
{
	float x;
	float y;

	float speed;  //速度
	float x2;
	float y2;

	int times;   //时间刷新
	int cur;     //当前

	POINT p;

public:
	void Init();
	void Run();
	void End();
};