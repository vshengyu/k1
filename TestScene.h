#pragma once
#include "Scene.h"
#include<vector>
#include<windows.h>
class CFrame;
class CAction;
class CTS:public CScene
{
	POINT m_Pos;  //��ȡλ��

	int m_W;
	int m_H;

	CFrame* m_Frame;  //���ָ��

	std::vector<CAction*> m_ActionList;

	int m_CurAct;	//��ǰ����
	int m_CurF;		//��ǰ�����ĵڼ���ͼƬ
	int m_CurCF;	//��ǰͼƬ�Ѿ�������ѭ������¼
	
public:
	void Init();
	void Run();
	void End();


};

