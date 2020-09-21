#pragma once 
#include"Scene.h"

class CFrame;
class CHero;
class CBarrier;

class CS3 :public CScene
{
	struct MYPOINT
	{
		int x;
		int y;
		int dir;
	};
	MYPOINT m_Pos;
	/*int m_W;
	int m_H;*/

	CFrame* m_Frame;


public:
	void Init();
	void Run();
	void End();
};