#pragma once

#include<windows.h>
#include<map>

class CGameOutput
{
	HWND m_hWnd; //窗口
	int m_ClientW;//客户区宽
	int m_ClientH;//客户区高
	HDC m_MainDC;//主设备
	HDC m_BackDC;//后备设备

	std::map<const char*, HDC>m_Bmp; //位图映射
public:
	CGameOutput(HWND hWnd);
	~CGameOutput();

	//开始绘制
	void Begin();

	//结束绘制
	void End();

	//画线
	void DrawLine(int Bx1, int Ey1, int Bx2, int Ey2, unsigned int c = RGB(0, 0, 0), int w = 1);//起始点，结束点，颜色，粗细

	//实心矩形
	void DrawSolidRect(int rx, int ry, int rw, int rh, 
		int w = 1, unsigned int c1 = RGB(0,0,0), unsigned int c2 = RGB(255, 255, 255));

	//空心矩形
	void DrawRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));
	//空心圆
	void DrawEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//实心圆
	void DrawSolidEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c1 = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));

	//**********************字体相关**********************//
	//加载字体

	void SetFont(int w, int h, //字体宽高
		const char* st = "宋体",//字体外观
		int we = 400,//字体粗细
		bool i = false,//斜体
		bool u = false,//下划线
		bool s = false//穿越线
		);

	//文字位置左上角，要输出的文字，颜色
	void DrawString(int x, int y, const char* t, unsigned int c);

	//绘制多行文字（重载）
	void DrawString(int x, int y, int w, int h, const char* t, unsigned int c);



	//**********************位图相关**********************//

	int LoadBmp(const char* id, const char* fn);//图片id,图片路径,(通过id,找路径)

	//释放bmp图片
	bool ReleaseBmp(const char* id);

	//画图素
	bool DrawBmp(const char* id,
		int dx, int dy, int dw, int dh, //画在什么位置 ，要画多大
		int sx, int sy, int sw, int sh, //取得原图的位置，从原图扣出多大出来画
		unsigned int c = RGB(0, 255, 0));//去除颜色

	void Clear();

};

