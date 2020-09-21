#pragma once
#include<Windows.h>
#include"Scene.h"
#include<map>
#include<time.h>
#include<list>
#include "GameInput.h"
#include "GameOutput.h"

class CHero;
class CMoster;
class CBarrier;
class CSuperBoss;

class CFrame
{
	//**********************************这是第一天写的************************************///
	std::map<const char*, CScene*>m_SceneList;//创建图素
	CScene* m_CurS;//当前运行场景
	CScene* m_NextS;//切换下一个场景
	
	CFrame();

	static CFrame* pCFrame;//静态内存
	HWND m_hWnd; //窗口句柄

	int m_ClientW;//客户区宽
	int m_ClientH;//客户区高
	int m_Act;
	//输入，输出
	CGameOutput* m_go;
	CGameInput* m_gi;

	/*****************************12.15添加**********************/
	const int* m_X;
	const int* m_Y;

	int m_CX;
	int m_CY;

	/////敌人
	std::list<CMoster*> m_MosterList;
	//障碍物
	std::list<CBarrier*> m_WallList;

	//英雄
	CHero* m_Hero;

	CMoster* m_Moster;
	

public:
	static CFrame* GetFrame(); //静态
	bool AddScen(const char* id, CScene* s);//添加场景
	bool SetFistScene(const char* id);//第一个场景
	bool SetNextScene(const char* id);//下一个场景
	void Init(int w, int h, HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow); //初始化窗口
	void Run();
	void End();
	int GetAct();
	void SetAct(int n);
	void GetRand(int min, int max, int num, int *out);//获取随机数


	//*******************************这是第二天写的*****************************//
	//获取鼠标坐标函数
	POINT GetCursorPoint();

	int GetKeyState(unsigned char Key); //获取键盘的键值

	//画直线
	void DrawLine(int x1, int y1, int x2, int y2, int w = 1, unsigned int c = RGB(0, 0, 0));

	//实心矩形
	void DrawSolidRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));

	//空心矩形
	void DrawRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//实心圆
	void DrawSolidEllipse(int rx, int ry, int rw, int rh,
		int w = 1, unsigned int c1 = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));
	
	//空心圆
	void DrawEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//加载字体

	void SetFont(int w, int h);//字体宽高
	
	//绘制单行字
	void DrawString(int x, int y, const char* t, unsigned int c);//文字左上角位置,要输出的文字,颜色

	//绘制多行文字 (重载)
	void DrawString(int x, int y, int w, int h,	//文字输出的矩形范围
		const char* t, unsigned int c);

	//位图相关
	//           图片ID 图片路径（通过ID，找路径）
	int LoadBmp(const char* id, const char* fn);

	bool ReleaseBmp(const char* id);

	//画在什么位置 画多大，取得源图的位置  也就是从源图扣多大出来画
	bool DrawBmp(const char* id, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, unsigned int c = RGB(0, 255, 0));//去除颜色


	//删除图素
	void ClearBmp();

	int GetClientW();
	int GetClientH();

	/*****************************12.15添加，设置相机**********************/
	void SetWinDow(int x, int y);
	void LookAt(const int* x, const int* y);
	void CameraMove();


	int GetCX(); //客户端宽高
	int GetCY();	


	//设置障碍物12.18
	void AddMoster(CMoster* moster);
	void AddWall(CBarrier* Barrier);
	std::list<CMoster*>* GetMosterList();
	std::list<CBarrier*>* GetWallList();

	//获得英雄坐标
	CHero* GetHero();
	void ClearMoster();
	void ClearWall();

	//怪物
	CMoster* GetMoster();

	CMoster*  CSuperBoss();
};