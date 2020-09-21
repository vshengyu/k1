#pragma once
#include"Moster.h"
#include<vector>

class CSuperBoss : public CMoster
{
	int m_mp;
	int m_hp;
public:
	void Init();
	void Run();
	void End();

	int GetHp();//
	int GetMp();
};