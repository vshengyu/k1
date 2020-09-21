#include"GameOutput.h"

#pragma comment(lib,"msimg32.lib")

//********************************构造函数**********************//
CGameOutput::CGameOutput(HWND hWnd)
:m_hWnd(hWnd)
{
	//获得客户区的宽、高
	RECT r;
	GetClientRect(m_hWnd, &r);
	m_ClientW = r.right - r.left;
	m_ClientH = r.bottom - r.top;

	//获得主设备
	m_MainDC = GetDC(m_hWnd);
	HBITMAP hbmp = 0;

	//获得后备设备
	m_BackDC = CreateCompatibleDC(m_MainDC);
	hbmp = CreateCompatibleBitmap(m_MainDC, m_ClientW, m_ClientH);

	//删除两个设备
	DeleteObject(SelectObject(m_BackDC, hbmp));
	DeleteObject(hbmp);

}

//****************************析构函数***************************//
CGameOutput::~CGameOutput()
{
	//清除
	Clear();
	//删除，释放主副设备
	DeleteDC(m_BackDC);
	ReleaseDC(m_hWnd, m_MainDC);
}


//***************************开始绘制***************************//
void CGameOutput::Begin()
{
	//清空后备为白色
	BitBlt(m_BackDC, 0, 0, m_ClientW, m_ClientH, 0, 0, 0, WHITENESS);
}

//***************************结束绘制***************************//
void CGameOutput::End()
{
	//把后备设置的数据，传递给主设备
	BitBlt(m_MainDC, 0, 0, m_ClientW, m_ClientH, m_BackDC, 0, 0, SRCCOPY);
}

//***************************画线***************************//
void CGameOutput::DrawLine(int Bx1, int Ey1, int Bx2, int Ey2, unsigned int c, int w )//Bx1起始点，Ey1结束点，颜色，粗细
{
	HPEN np = 0, op = 0;//新笔和旧笔
	//如果颜色有改动那么创建新的笔
	if (RGB(0, 0, 0) != c || 1 != w)//常量写左边
	{
		//生成新笔使用完后，将笔还回去，再删除
		np = CreatePen(PS_SOLID, w, c);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	//画图的位置
	POINT p;
	MoveToEx(m_BackDC, Bx1, Ey1, &p);
	LineTo(m_BackDC, Bx2, Ey2);

	if (np)
	{
		//生成新笔使用完后，将笔还回去，再删除
		SelectObject(m_BackDC, op);
		DeleteObject(np);
	}
}

//***************************实心矩形***************************//
void CGameOutput::DrawSolidRect(int rx, int ry, int rw, int rh,
	int w, unsigned int c1, unsigned int c2)
{
	HPEN newpen = 0, oldpen = 0;
	//如果颜色有改动 那么 创建新的笔
	if (RGB(0, 0, 0) != c1 || 1 != w)
	{
		newpen = CreatePen(PS_SOLID, w, c1);
		oldpen = (HPEN)SelectObject(m_BackDC, newpen);
	}

	HBRUSH newb = 0, oldb = 0;
	//如果颜色有改动 那么 创建新的画刷
	if (RGB(255, 255, 255) != c2)
	{
		newb = CreateSolidBrush(c2);
		oldb = (HBRUSH)SelectObject(m_BackDC, newb);
	}

	Rectangle(m_BackDC, rx, ry, rx + rw, ry + rh);

	if (newpen)
	{
		SelectObject(m_BackDC, oldpen);
		DeleteObject(newpen);
	}
	if (newb)
	{
		SelectObject(m_BackDC, oldb);
		DeleteObject(newb);
	}
}

//空心矩形
void CGameOutput::DrawRect(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	HPEN newpen = 0, oldpen = 0;
	//如果颜色有改动 那么 创建新的笔
	if (RGB(0, 0, 0) != c || 1 != w)
	{
		newpen = CreatePen(PS_SOLID, w, c);
		oldpen = (HPEN)SelectObject(m_BackDC, newpen);
	}

	POINT p[]
		=
	{
		{ rx, ry },
		{ rx + rw, ry },
		{ rx + rw, ry + rh },
		{ rx, ry + rh },
		{ rx, ry }
	};
	POINT q;
	for (int i = 0; i < 4; ++i)
	{
		MoveToEx(m_BackDC, p[i].x, p[i].y, &q);
		LineTo(m_BackDC, p[i + 1].x, p[i + 1].y);
	}

	if (newpen)
	{
		SelectObject(m_BackDC, oldpen);
		DeleteObject(newpen);
	}
}
//空心圆
void CGameOutput::DrawEllipse(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	HPEN np = 0, op = 0;//新笔和旧笔
	if (RGB(0, 0, 0) != c || 1 != w)//常量写左边
	{
		//生成新笔使用完后，将笔还回去，再删除
		np = CreatePen(PS_SOLID, w, c);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	//NULL_BRUSH 为透明 画刷
	HBRUSH nb = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH ob = (HBRUSH)SelectObject(m_BackDC, nb);
	Ellipse(m_BackDC, rx, ry, rx + rw, ry + rh);

	//只选会老画刷即可,因为,新画刷是系统预设的,不用销毁
	SelectObject(m_BackDC, ob);
	if (np)
	{
		SelectObject(m_BackDC, op);
		DeleteObject(np);
	}
}

//实心圆
void CGameOutput::DrawSolidEllipse(int rx, int ry, int rw, int rh, int w, unsigned int c1, unsigned int c2)
{
	HPEN np = 0, op = 0;//新笔和旧笔
	if (RGB(0, 0, 0) != c1 || 1 != w)//常量写左边
	{
		//生成新笔使用完后，将笔还回去，再删除
		np = CreatePen(PS_SOLID, w, c1);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	HBRUSH newb = 0, oldb = 0;
	//如果颜色有改动 那么 创建新的画刷
	if (RGB(255, 255, 255) != c2)
	{
		newb = CreateSolidBrush(c2);
		oldb = (HBRUSH)SelectObject(m_BackDC, newb);
	}
	Ellipse(m_BackDC, rx, ry, rx + rw, ry + rh);

	if (np)
	{
		SelectObject(m_BackDC, op);
		DeleteObject(np);
	}
	if (newb)
	{
		SelectObject(m_BackDC, oldb);
		DeleteObject(newb);
	}
}
void CGameOutput::SetFont(int w, int h, //字体宽高
	const char* st ,//字体外观
	int we,//字体粗细
	bool i,//斜体
	bool u,//下划线
	bool s//穿越线
	)
{
	//创建字体
	HFONT font = CreateFontA(h, w, 0, 0, we, i, u, s, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, st);

	if (!font)
		return;
	DeleteObject(SelectObject(m_BackDC, font));
}

//****************************文字位置左上角，要输出的文字，颜色************
void CGameOutput::DrawString(int x, int y, const char* t, unsigned int c)
{
	//设置文字颜色
	unsigned int fc = SetTextColor(m_BackDC, c);
	TextOutA(m_BackDC, x, y, t, (int)strlen(t));
	SetTextColor(m_BackDC, fc);
}

//************************绘制多行文字（重载）**********************//
void CGameOutput::DrawString(int x, int y, int w, int h, const char* t, unsigned int c)
{
	RECT r = { x, y, x + w, y + h };
	//设置文字颜色
	unsigned int fc = SetTextColor(m_BackDC, c);
	//绘制文字   HDC   输出的文字   文字长度  文字范围   文字形式
	DrawTextA(m_BackDC, t, (int)strlen(t), &r, DT_WORDBREAK);
	SetTextColor(m_BackDC, fc);
}



//**************************位图相关**********************//

int CGameOutput::LoadBmp(const char* id, const char* fn)//图片id,图片路径,(通过id,找路径)
{
	//查找id 是否存在于 映射中
	if (m_Bmp.find(id) != m_Bmp.end())
		return 0;
	//如果id 没被使用 那么加载图片
	HBITMAP hbmp = (HBITMAP)LoadImage(0, fn, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//如果图片加载失败 返回 -1
	if (!hbmp)
		return -1;
	//把图片放入 dc 中 
	HDC dc = CreateCompatibleDC(m_MainDC);
	DeleteObject(SelectObject(dc, hbmp));
	DeleteObject(hbmp);

	m_Bmp.insert(std::pair<const char*, HDC>(id, dc));
	return 1;
}

//**************************释放bmp图片**********************//
bool CGameOutput::ReleaseBmp(const char* id)
{
	//通过迭代器 查找ID 是否存在
	std::map<const char*, HDC>::iterator it = m_Bmp.find(id);
	//没找到 删除失败
	if (it == m_Bmp.end())
		return false;
	//找到后 删除HDC  再删除 映射中的节点
	DeleteDC(it->second);
	m_Bmp.erase(it);
	return true;
}

//**************************画图素**********************//
bool CGameOutput::DrawBmp(const char* id,
	int dx, int dy, int dw, int dh, //画在什么位置 ，要画多大
	int sx, int sy, int sw, int sh, //取得原图的位置，从原图扣出多大出来画
	unsigned int c)//去除颜色
{
	//通过迭代器 查找ID 是否存在
	std::map<const char*, HDC>::iterator it = m_Bmp.find(id);
	//没找到 删除失败
	if (it == m_Bmp.end())
		return 0;
	TransparentBlt(m_BackDC, dx, dy, dw, dh, it->second, sx, sy, sw, sh, c);
	return 1;
}
//**************************清空数据**********************//
void CGameOutput::Clear()
{
	//通过迭代器，删除位图的HDC
	std::map<const char*, HDC>::iterator it;
	for (it = m_Bmp.begin(); it != m_Bmp.end();)
	{
		DeleteDC(it->second);//下一个，也就是第二个
		it = m_Bmp.erase(it);//删除每一个
	}
}