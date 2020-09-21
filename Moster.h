#pragma once
#include<list>
#include<vector>
#include<windows.h>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define ATTACK 4
#define _IDLE 15
#define LIVE 6

class CBarrier;
class CRect;
class CFrame;
class CAction;
class CMoster
{

protected:

	struct MYPOINT
	{
		int x;
		int y;
		int dir;
	};
	struct _POINT
	{
		int x;
		int y;
	};
	POINT m_Pos;

	int m_Dir;
	CRect* m_Rect;
	std::list<CBarrier*>* m_Barrier;
	int m_State; //状态

	CFrame* m_Frame;
	int m_Speed;


	std::vector<CAction*>m_ActList;

	std::list<_POINT>m_Biu;
	MYPOINT m_ps;

	std::list<MYPOINT>m_Buling;

	int m_CurAct;	//当前动作
	int m_CurF;		//当前动作的第几张图片
	int m_CurCF;	//当前图片已经持续的循环数记录

	int m_x;
	int m_y;
	int leftx;
	int rightx;

	int m_Hp;//血  1900
	int m_Mp;//蓝  1900

	char m_isLive;//判断存活
	int m_LasAct;//持续

	int m_Atkcd;
	int m_Acd; //技能CD

public:
	CMoster();
	virtual ~CMoster();
	virtual void Init();
	virtual void Run();
	virtual void End();
	virtual void SetPos(int x, int y);
	virtual void SetDir(int dir);
	virtual CRect* GetRect();
	virtual POINT GetPos();
	virtual const int* GetPosX();
	virtual const int* GetPosY();
	virtual void Clear();
	virtual int GetCurAct();
	virtual int GetisLive();//是否存活
	virtual void SetisLive(int flag);


	//根据状态改变方向
	virtual void PressUP();
	virtual void PressLEFT();
	virtual void PressRIGHT();
	virtual void PressDOWN();

	//血和蓝
	virtual void blood(); //扣血
	virtual int GetHp();//血
	virtual int GetMp();
	virtual void Actk();//攻击
};