#pragma once
#include <vector>
#include"Rect.h"
struct  _PIC
{
	const char* id;	//图片id
	int sw;			//原图宽
	int sh;			//原图高
	int sx;			//原图起点
	int sy;			//原图终点
	int cw;			//图片逻辑宽
	int ch;			//图片逻辑高
	int offx;		//锚点x
	int offy;		//锚点y
	int cf;			//持续循环次数1
	unsigned int c;	//扣除颜色

	CRect AttRect;


};
class CAction
{
	std::vector<_PIC>m_PicList;
	int m_NextAct;
public:
	void AddPic(_PIC pic);
	//函数重新
	void AddPic(const char* id, int sw, int sh, int sx, int sy,
		int cw, int ch, int offx, int offy, int cf, unsigned int c);
	_PIC* GetPic(int f);

	int PicLen();
	void SetNextAct(int next);
	int GetNextAct();
	/***********12.15**************/
	int GetActLen();//获取到动作
};