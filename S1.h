#pragma once
#include "Scene.h"
#include<list>
#include<windows.h>
class CFrame;

#define BULLETMAX 20  //�ӵ�����
#define BULLETYOFF 3	 //
#define BULLETSPEED 20		//�ٶ�

#define PLAYERMOVESPEED 10  //�ƶ��ٶ�

class CS1 :public CScene //�̳ж���������
{
	//���꣬��ߣ����ָ��
	int m_x;
	int m_y;
	int bulletlen;

	CFrame* pFrame;

	//�ӵ�
	std::list<POINT>m_Biu;

public:
	//��ʼ�����У�����
	void Init();
	void Run();
	void End();
};