#pragma once
#include<Windows.h>
class CVector
{
	float x;
	float y;

	float speed;  //�ٶ�
	float x2;
	float y2;

	int times;   //ʱ��ˢ��
	int cur;     //��ǰ

	POINT p;

public:
	void Init();
	void Run();
	void End();
};