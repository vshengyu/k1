#pragma once
#include<vector>
#include<list>
#include<windows.h>
#include"Rect.h"
class COrth;
class CRect;
class CFrame;
class CAction;
class CBarrier;



#define M_LEFT 0	
#define M_RIGHT 1
#define M_UP 2
#define M_DOWN 3
#define M_UPLEFT 4
#define M_UPRIGHT 5
#define M_DOWNLEFT 6
#define M_DOWNRIGHT 8


/************************Ӣ��״̬********************/
#define _LEFT 0
#define _RIGHT 1
#define _UP 2
#define _DOWN 3
#define _ATTACK 4
#define _LIVE 5
#define _DIE 6
#define IDLE 11

struct _POINT
{
	int x;
	int y;
	
};


class CHero
{

	CRect m_Rup;
	CRect m_Rdown;
	CRect m_Rleft;
	CRect m_Rright;


	struct MYPOINT
	{
		int x;
		int y;
		int dir;
	};

	//����
	CRect* m_Rect;
	//�ӵ�
	std::list<MYPOINT>m_Biu;
	_POINT m_Pos;//���λ�ȡλ��

	std::vector<CAction*>m_ActList;

	//�ϰ���
	std::list<CBarrier*>* m_Barrier;
	
	//
	int m_x;
	int m_y;
	
	int m_CurAct;	//��ǰ����
	int m_CurF;		//��ǰ�����ĵڼ���ͼƬ
	int m_CurCF;	//��ǰͼƬ�Ѿ�������ѭ������¼
	
	//����				
	int m_W;
	int m_H;

	int m_MoveFlag;  //�ƶ��ж�

	int m_CurAct1;

	int m_Speed;   //�ٶ� 
	int m_State;  //Ӣ��״̬
	int m_Dir;   //����

	int m_isLive;//����ж�
	int m_hp;//Ѫ  1900
	int m_mp;//��  1900

public:

	int GetHP();
	int GetMP();



	void Init();
	void Run();
	void End();

	//����
	void PressA();
	void PressD();
	void PressW();
	void PressS();
	void PressJ();
	void PressK();

	
	//�ƶ���״̬
	void Move();
	void Idle();
	/*int GetX();
	int GetY();*/
	
	//����12.18
	CRect* GetRect();
	void SetPos(int x, int y);
	void SetState(int state);//����״̬

	const int* GetPosX();
	const int* GetPosY();
	_POINT GetPos();//���þ���

	CFrame* m_Frame;  //���ָ��
	


	/************12.23****************/
	void SetisLive(int flag);
	int GetisLive();  //���
	int GetCurAct();
	void SetCurAct(int act); 
	void blood(); //��Ѫ

};

