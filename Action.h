#pragma once
#include <vector>
#include"Rect.h"
struct  _PIC
{
	const char* id;	//ͼƬid
	int sw;			//ԭͼ��
	int sh;			//ԭͼ��
	int sx;			//ԭͼ���
	int sy;			//ԭͼ�յ�
	int cw;			//ͼƬ�߼���
	int ch;			//ͼƬ�߼���
	int offx;		//ê��x
	int offy;		//ê��y
	int cf;			//����ѭ������1
	unsigned int c;	//�۳���ɫ

	CRect AttRect;


};
class CAction
{
	std::vector<_PIC>m_PicList;
	int m_NextAct;
public:
	void AddPic(_PIC pic);
	//��������
	void AddPic(const char* id, int sw, int sh, int sx, int sy,
		int cw, int ch, int offx, int offy, int cf, unsigned int c);
	_PIC* GetPic(int f);

	int PicLen();
	void SetNextAct(int next);
	int GetNextAct();
	/***********12.15**************/
	int GetActLen();//��ȡ������
};