#pragma once
class CRect;
class CHero;

class CBarrier
{
	int m_X;
	int m_Y;
	int m_W;
	int m_H;

	CRect* m_Rect;

public:
	CBarrier();
	virtual~CBarrier();
	//初始化宽高
	virtual void Init(int w, int h);

	//删除
	virtual void Clear();

	//英雄的位置
	virtual void Colider(CHero* hero, int dir);
	//小怪的位置
	virtual void Colider(CBarrier* moster, int dir);

	//设置位置
	virtual void SetPos(int x, int y);
	//设置大小
	virtual void SetSize(int w, int h);


	virtual int GetPosX();
	virtual int GetPosY();
	virtual int GetW();

	virtual int GetH();
	virtual CRect* GetRect();
};