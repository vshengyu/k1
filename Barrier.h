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
	//��ʼ�����
	virtual void Init(int w, int h);

	//ɾ��
	virtual void Clear();

	//Ӣ�۵�λ��
	virtual void Colider(CHero* hero, int dir);
	//С�ֵ�λ��
	virtual void Colider(CBarrier* moster, int dir);

	//����λ��
	virtual void SetPos(int x, int y);
	//���ô�С
	virtual void SetSize(int w, int h);


	virtual int GetPosX();
	virtual int GetPosY();
	virtual int GetW();

	virtual int GetH();
	virtual CRect* GetRect();
};