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


/************************英雄状态********************/
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

	//矩形
	CRect* m_Rect;
	//子弹
	std::list<MYPOINT>m_Biu;
	_POINT m_Pos;//矩形获取位置

	std::vector<CAction*>m_ActList;

	//障碍物
	std::list<CBarrier*>* m_Barrier;
	
	//
	int m_x;
	int m_y;
	
	int m_CurAct;	//当前动作
	int m_CurF;		//当前动作的第几张图片
	int m_CurCF;	//当前图片已经持续的循环数记录
	
	//？？				
	int m_W;
	int m_H;

	int m_MoveFlag;  //移动判断

	int m_CurAct1;

	int m_Speed;   //速度 
	int m_State;  //英雄状态
	int m_Dir;   //朝向

	int m_isLive;//存活判断
	int m_hp;//血  1900
	int m_mp;//蓝  1900

public:

	int GetHP();
	int GetMP();



	void Init();
	void Run();
	void End();

	//按键
	void PressA();
	void PressD();
	void PressW();
	void PressS();
	void PressJ();
	void PressK();

	
	//移动、状态
	void Move();
	void Idle();
	/*int GetX();
	int GetY();*/
	
	//矩形12.18
	CRect* GetRect();
	void SetPos(int x, int y);
	void SetState(int state);//设置状态

	const int* GetPosX();
	const int* GetPosY();
	_POINT GetPos();//设置矩形

	CFrame* m_Frame;  //框架指针
	


	/************12.23****************/
	void SetisLive(int flag);
	int GetisLive();  //存活
	int GetCurAct();
	void SetCurAct(int act); 
	void blood(); //扣血

};

