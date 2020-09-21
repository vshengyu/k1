#include"GameOutput.h"

#pragma comment(lib,"msimg32.lib")

//********************************���캯��**********************//
CGameOutput::CGameOutput(HWND hWnd)
:m_hWnd(hWnd)
{
	//��ÿͻ����Ŀ���
	RECT r;
	GetClientRect(m_hWnd, &r);
	m_ClientW = r.right - r.left;
	m_ClientH = r.bottom - r.top;

	//������豸
	m_MainDC = GetDC(m_hWnd);
	HBITMAP hbmp = 0;

	//��ú��豸
	m_BackDC = CreateCompatibleDC(m_MainDC);
	hbmp = CreateCompatibleBitmap(m_MainDC, m_ClientW, m_ClientH);

	//ɾ�������豸
	DeleteObject(SelectObject(m_BackDC, hbmp));
	DeleteObject(hbmp);

}

//****************************��������***************************//
CGameOutput::~CGameOutput()
{
	//���
	Clear();
	//ɾ�����ͷ������豸
	DeleteDC(m_BackDC);
	ReleaseDC(m_hWnd, m_MainDC);
}


//***************************��ʼ����***************************//
void CGameOutput::Begin()
{
	//��պ�Ϊ��ɫ
	BitBlt(m_BackDC, 0, 0, m_ClientW, m_ClientH, 0, 0, 0, WHITENESS);
}

//***************************��������***************************//
void CGameOutput::End()
{
	//�Ѻ����õ����ݣ����ݸ����豸
	BitBlt(m_MainDC, 0, 0, m_ClientW, m_ClientH, m_BackDC, 0, 0, SRCCOPY);
}

//***************************����***************************//
void CGameOutput::DrawLine(int Bx1, int Ey1, int Bx2, int Ey2, unsigned int c, int w )//Bx1��ʼ�㣬Ey1�����㣬��ɫ����ϸ
{
	HPEN np = 0, op = 0;//�±ʺ;ɱ�
	//�����ɫ�иĶ���ô�����µı�
	if (RGB(0, 0, 0) != c || 1 != w)//����д���
	{
		//�����±�ʹ����󣬽��ʻ���ȥ����ɾ��
		np = CreatePen(PS_SOLID, w, c);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	//��ͼ��λ��
	POINT p;
	MoveToEx(m_BackDC, Bx1, Ey1, &p);
	LineTo(m_BackDC, Bx2, Ey2);

	if (np)
	{
		//�����±�ʹ����󣬽��ʻ���ȥ����ɾ��
		SelectObject(m_BackDC, op);
		DeleteObject(np);
	}
}

//***************************ʵ�ľ���***************************//
void CGameOutput::DrawSolidRect(int rx, int ry, int rw, int rh,
	int w, unsigned int c1, unsigned int c2)
{
	HPEN newpen = 0, oldpen = 0;
	//�����ɫ�иĶ� ��ô �����µı�
	if (RGB(0, 0, 0) != c1 || 1 != w)
	{
		newpen = CreatePen(PS_SOLID, w, c1);
		oldpen = (HPEN)SelectObject(m_BackDC, newpen);
	}

	HBRUSH newb = 0, oldb = 0;
	//�����ɫ�иĶ� ��ô �����µĻ�ˢ
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

//���ľ���
void CGameOutput::DrawRect(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	HPEN newpen = 0, oldpen = 0;
	//�����ɫ�иĶ� ��ô �����µı�
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
//����Բ
void CGameOutput::DrawEllipse(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	HPEN np = 0, op = 0;//�±ʺ;ɱ�
	if (RGB(0, 0, 0) != c || 1 != w)//����д���
	{
		//�����±�ʹ����󣬽��ʻ���ȥ����ɾ��
		np = CreatePen(PS_SOLID, w, c);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	//NULL_BRUSH Ϊ͸�� ��ˢ
	HBRUSH nb = (HBRUSH)GetStockObject(NULL_BRUSH);
	HBRUSH ob = (HBRUSH)SelectObject(m_BackDC, nb);
	Ellipse(m_BackDC, rx, ry, rx + rw, ry + rh);

	//ֻѡ���ϻ�ˢ����,��Ϊ,�»�ˢ��ϵͳԤ���,��������
	SelectObject(m_BackDC, ob);
	if (np)
	{
		SelectObject(m_BackDC, op);
		DeleteObject(np);
	}
}

//ʵ��Բ
void CGameOutput::DrawSolidEllipse(int rx, int ry, int rw, int rh, int w, unsigned int c1, unsigned int c2)
{
	HPEN np = 0, op = 0;//�±ʺ;ɱ�
	if (RGB(0, 0, 0) != c1 || 1 != w)//����д���
	{
		//�����±�ʹ����󣬽��ʻ���ȥ����ɾ��
		np = CreatePen(PS_SOLID, w, c1);
		op = (HPEN)SelectObject(m_BackDC, np);
	}
	HBRUSH newb = 0, oldb = 0;
	//�����ɫ�иĶ� ��ô �����µĻ�ˢ
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
void CGameOutput::SetFont(int w, int h, //������
	const char* st ,//�������
	int we,//�����ϸ
	bool i,//б��
	bool u,//�»���
	bool s//��Խ��
	)
{
	//��������
	HFONT font = CreateFontA(h, w, 0, 0, we, i, u, s, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, st);

	if (!font)
		return;
	DeleteObject(SelectObject(m_BackDC, font));
}

//****************************����λ�����Ͻǣ�Ҫ��������֣���ɫ************
void CGameOutput::DrawString(int x, int y, const char* t, unsigned int c)
{
	//����������ɫ
	unsigned int fc = SetTextColor(m_BackDC, c);
	TextOutA(m_BackDC, x, y, t, (int)strlen(t));
	SetTextColor(m_BackDC, fc);
}

//************************���ƶ������֣����أ�**********************//
void CGameOutput::DrawString(int x, int y, int w, int h, const char* t, unsigned int c)
{
	RECT r = { x, y, x + w, y + h };
	//����������ɫ
	unsigned int fc = SetTextColor(m_BackDC, c);
	//��������   HDC   ���������   ���ֳ���  ���ַ�Χ   ������ʽ
	DrawTextA(m_BackDC, t, (int)strlen(t), &r, DT_WORDBREAK);
	SetTextColor(m_BackDC, fc);
}



//**************************λͼ���**********************//

int CGameOutput::LoadBmp(const char* id, const char* fn)//ͼƬid,ͼƬ·��,(ͨ��id,��·��)
{
	//����id �Ƿ������ ӳ����
	if (m_Bmp.find(id) != m_Bmp.end())
		return 0;
	//���id û��ʹ�� ��ô����ͼƬ
	HBITMAP hbmp = (HBITMAP)LoadImage(0, fn, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//���ͼƬ����ʧ�� ���� -1
	if (!hbmp)
		return -1;
	//��ͼƬ���� dc �� 
	HDC dc = CreateCompatibleDC(m_MainDC);
	DeleteObject(SelectObject(dc, hbmp));
	DeleteObject(hbmp);

	m_Bmp.insert(std::pair<const char*, HDC>(id, dc));
	return 1;
}

//**************************�ͷ�bmpͼƬ**********************//
bool CGameOutput::ReleaseBmp(const char* id)
{
	//ͨ�������� ����ID �Ƿ����
	std::map<const char*, HDC>::iterator it = m_Bmp.find(id);
	//û�ҵ� ɾ��ʧ��
	if (it == m_Bmp.end())
		return false;
	//�ҵ��� ɾ��HDC  ��ɾ�� ӳ���еĽڵ�
	DeleteDC(it->second);
	m_Bmp.erase(it);
	return true;
}

//**************************��ͼ��**********************//
bool CGameOutput::DrawBmp(const char* id,
	int dx, int dy, int dw, int dh, //����ʲôλ�� ��Ҫ�����
	int sx, int sy, int sw, int sh, //ȡ��ԭͼ��λ�ã���ԭͼ�۳���������
	unsigned int c)//ȥ����ɫ
{
	//ͨ�������� ����ID �Ƿ����
	std::map<const char*, HDC>::iterator it = m_Bmp.find(id);
	//û�ҵ� ɾ��ʧ��
	if (it == m_Bmp.end())
		return 0;
	TransparentBlt(m_BackDC, dx, dy, dw, dh, it->second, sx, sy, sw, sh, c);
	return 1;
}
//**************************�������**********************//
void CGameOutput::Clear()
{
	//ͨ����������ɾ��λͼ��HDC
	std::map<const char*, HDC>::iterator it;
	for (it = m_Bmp.begin(); it != m_Bmp.end();)
	{
		DeleteDC(it->second);//��һ����Ҳ���ǵڶ���
		it = m_Bmp.erase(it);//ɾ��ÿһ��
	}
}