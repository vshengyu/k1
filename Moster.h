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
	int m_State; //״̬

	CFrame* m_Frame;
	int m_Speed;


	std::vector<CAction*>m_ActList;

	std::list<_POINT>m_Biu;
	MYPOINT m_ps;

	std::list<MYPOINT>m_Buling;

	int m_CurAct;	//��ǰ����
	int m_CurF;		//��ǰ�����ĵڼ���ͼƬ
	int m_CurCF;	//��ǰͼƬ�Ѿ�������ѭ������¼

	int m_x;
	int m_y;
	int leftx;
	int rightx;

	int m_Hp;//Ѫ  1900
	int m_Mp;//��  1900

	char m_isLive;//�жϴ��
	int m_LasAct;//����

	int m_Atkcd;
	int m_Acd; //����CD

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
	virtual int GetisLive();//�Ƿ���
	virtual void SetisLive(int flag);


	//����״̬�ı䷽��
	virtual void PressUP();
	virtual void PressLEFT();
	virtual void PressRIGHT();
	virtual void PressDOWN();

	//Ѫ����
	virtual void blood(); //��Ѫ
	virtual int GetHp();//Ѫ
	virtual int GetMp();
	virtual void Actk();//����
};