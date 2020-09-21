#pragma once
class CRect;
class CHero;

/******************ÆÕÍ¨¾ØÐÎ***************/
class COrth
{
protected:
	int m_X;
	int m_Y;
	int m_W;
	int m_H;
	int m_Flag;
	CRect* m_Rect;

public:
	COrth();
	virtual ~COrth();
	virtual void Init(int w, int h);
	virtual void Clear();
	virtual void Colider(CHero* hero, int dir);
	virtual void Colider(COrth* moster, int dir);
	virtual void SetPos(int x, int y);
	virtual void SetSize(int w, int h);
	virtual void SetFlag(int flag);
	virtual int GetPosX();
	virtual int GetPosY();
	virtual int GetW();
	virtual int GetFlag();
	virtual int GetH();
	virtual CRect** GetRect();
};