#include"Frame.h"
#include"Hero.h"
#include"SuperBoss.h"
CFrame* CFrame::pCFrame = 0;//����ָ��
CFrame::CFrame()
{
	m_gi = 0;
	m_go = 0;
	m_CurS = 0;
	m_NextS = 0;
	m_X = 0;
	m_Y = 0;
	srand((unsigned int)time(0));
	rand();
}



//�̷߳ǰ�ȫ�汾
CFrame* CFrame::GetFrame()
{
	//����ʹ�õ���ģʽ������0��new����
	if (pCFrame == 0)
		pCFrame = new CFrame;
	return pCFrame;
}
bool CFrame::AddScen(const char* id, CScene* s)
{
	if (s == 0 || id == 0)
		return 0;
	std::map<const char*, CScene*>::iterator it;
	it = m_SceneList.find(id);
	if (it != m_SceneList.end())
		return 0;
	m_SceneList.insert(std::pair<const char*, CScene*>(id, s));
	return 1;
}

//��һ������
bool CFrame::SetFistScene(const char* id)
{
	if (id == 0)
		return 0;
	std::map<const char*, CScene*>::iterator it;
	it = m_SceneList.find(id);
	if (it == m_SceneList.end())
		return 0;
	m_CurS = it->second;
	return 1;


}
//��һ������
bool CFrame::SetNextScene(const char* id)
{
	if (id == 0)
		return 0;
	std::map<const char*, CScene*>::iterator it;
	it = m_SceneList.find(id);
	if (it == m_SceneList.end())
		return 0;
	m_NextS = it->second;
	return 1;


}
//��Ϣ
_w64 long __stdcall WindowProc(HWND hWnd,	//������Ϣ�Ĵ���
	unsigned int uMsg,	//��Ϣ����
	_w64 unsigned int wParam,	//��Ϣ���Ӳ��� 1
	_w64 long lParam)//��Ϣ���Ӳ��� 2
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
					   PostQuitMessage(0);
					   return 0;
	}
	case WM_ACTIVATEAPP:
	{
						   CFrame::GetFrame()->SetAct(wParam);
						   return 0;
	}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



//��ʼ������
void CFrame::Init(int w, int h, HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (w < 320)
		w = 320;
	if (h < 280)
		h = 280;
	m_ClientW = w;
	m_ClientH = h;

	//1) ��䴰�ڽṹ��
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpszMenuName = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = "ʮ��";

	//2��ע�ᴰ�ڣ��ô��ڽṹ������������ݣ�
	RegisterClass(&wc);

	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);

	RECT rect
		=
	{
		(sw - m_ClientW) / 2,
		(sh - m_ClientH) / 2,
		m_ClientW + (sw - m_ClientW) / 2,
		m_ClientH + (sh - m_ClientH) / 2
	};

	AdjustWindowRect(&rect, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, FALSE);

	//3���ô��ڽṹ������������
	m_hWnd = CreateWindow(wc.lpszClassName, "����",
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		HWND_DESKTOP, 0, wc.hInstance, 0);

	//4����ʾ���ڣ����ھ������ʾ��ʽ��
	ShowWindow(m_hWnd, nCmdShow);

	//5�����´��ڣ����ھ����
	UpdateWindow(m_hWnd);
	m_Act = 1;


	m_go = new CGameOutput(m_hWnd);
	m_gi = new CGameInput;
	m_go->SetFont(15, 15);

	m_Hero = new CHero;
	m_Hero->Init();
	m_Hero->SetPos(500,400);

	m_Moster = new CMoster;
	m_Moster->Init();
}
void CFrame::Run()
{
	if (m_CurS == 0)
		return;

	m_CurS->Init();
	//6����Ϣѭ��
	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		//�������Ϣ�ʹ�����Ϣ ����ִ����Ϸ
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else if (m_Act)
		{
			m_gi->Run();
			m_go->Begin();
			if (m_CurS)
				m_CurS->Run();
			m_go->End();
			if (m_NextS)
			{
				m_CurS->End();
				m_NextS->Init();
				m_CurS = m_NextS;
				m_NextS = 0;
			}
			Sleep(5);
		}
		else
		{
			WaitMessage();
		}
	}
}
void CFrame::End()
{
	if (m_CurS)
		m_CurS->End();
	std::map<const char*, CScene*>::iterator it;
	for (it = m_SceneList.begin(); it != m_SceneList.end(); ++it)
	{
		delete it->second;//�ڶ���
	}
	m_SceneList.clear();
	if (m_Hero)delete m_Hero;
	if (m_Moster)delete m_Moster;
}
int CFrame::GetAct()
{
	return m_Act;
}
void CFrame::SetAct(int n)
{
	m_Act = n;
}
void CFrame::GetRand(int min, int max, int num, int *out)
{
	if (min > max)
	{
		int iTmp = min;
		min = max;
		max = iTmp;
	}
	max = max - min + 1;
	for (int i = 0; i < num; i++)
	{
		out[i] = rand() % max + min;
	}
}
//****************************************
//��ȡ������꺯��
//�����������ڿͻ����� ������ ���򷵻ؼ�
POINT CFrame::GetCursorPoint()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(m_hWnd, &p);
	return p;
}
int CFrame::GetKeyState(unsigned char Key)
{
	return m_gi->Get(Key);
}

void CFrame::DrawLine(int x1, int y1, int x2, int y2, int w, unsigned int c)
{
	m_go->DrawLine(x1, y1, x2, y2, w, c);
}
//ʵ�ľ���
void CFrame::DrawSolidRect(int rx, int ry, int rw, int rh,
	int w, unsigned int c1, unsigned int c2)
{
	m_go->DrawSolidRect(rx, ry, rw, rh, w, c1, c2);
}
//���ľ���
void CFrame::DrawRect(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	m_go->DrawRect(rx, ry, rw, rh, w, c);
}

//ʵ��Բ
void CFrame::DrawSolidEllipse(int rx, int ry, int rw, int rh,
	int w, unsigned int c1, unsigned int c2)
{
	m_go->DrawSolidEllipse(rx, ry, rw, rh, w, c1, c2);
}
//����Բ
void CFrame::DrawEllipse(int rx, int ry, int rw, int rh, int w, unsigned int c)
{
	m_go->DrawEllipse(rx, ry, rw, rh, w, c);
}
void CFrame::SetFont(int w, int h)
{
	m_go->SetFont(w, h);
}//������

//���Ƶ�����
void CFrame::DrawString(int x, int y, const char* t, unsigned int c)
{
	m_go->DrawString(x, y, t, c);

}//�������Ͻ�λ��,Ҫ���������,��ɫ

//���ƶ������� (����)
void CFrame::DrawString(int x, int y, int w, int h, const char* t, unsigned int c)
{

	m_go->DrawString(x, y, t, c);
}

//λͼ���
//           ͼƬID ͼƬ·����ͨ��ID����·����
int CFrame::LoadBmp(const char* id, const char* fn)
{
	return m_go->LoadBmp(id, fn);
}

bool CFrame::ReleaseBmp(const char* id)
{
	return m_go->ReleaseBmp(id);
}

//����ʲôλ�� �����ȡ��Դͼ��λ��  Ҳ���Ǵ�Դͼ�۶�������
bool CFrame::DrawBmp(const char* id, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, unsigned int c)
{
	dx -= m_CX;
	dy -= m_CY;
	return m_go->DrawBmp(id, dx, dy, dw, dh, sx, sy, sw, sh, c);
}//ȥ����ɫ


//ɾ��ͼ��
void CFrame::ClearBmp()
{
	m_go->Clear();
}
int CFrame::GetClientW()
{
	return m_ClientW;
}
int CFrame::GetClientH()
{
	return m_ClientH;
}
/************************���������*************************/
void CFrame::LookAt(const int* x, const int* y)
{
	m_X = x;
	m_Y = y;
}
void CFrame::SetWinDow(int x, int y)
{
	m_CX = x;
	m_CY = y;
}
void CFrame::CameraMove()
{
	if (!m_X)return;
	int x = *m_X - m_CX;
	if (x < 400 && m_CX>0)m_CX -= 10;
	if (x > 1200 && m_CX <300)m_CX += 10;
	//if (x < 0)m_CX = *m_X;
}
int CFrame::GetCX()
{
	return m_CX;
}
//�ͻ��˿��
int CFrame::GetCY()
{
	return m_CY;
}

//�����ϰ���12.18
void CFrame::AddMoster(CMoster* moster)
{
	m_MosterList.push_back(moster);
}
void CFrame::AddWall(CBarrier* Barrier)
{
	m_WallList.push_back(Barrier);
}
std::list<CMoster*>* CFrame::GetMosterList()
{
	return &m_MosterList;
}
std::list<CBarrier*>* CFrame::GetWallList()
{
	return &m_WallList;
}
CHero* CFrame::GetHero()
{
	return m_Hero;
}


CMoster* CFrame::GetMoster()
{
	return m_Moster;
}



//���������ϰ���

void CFrame::ClearMoster()
{
	std::list<CMoster*>::iterator it2;
	for (it2 = m_MosterList.begin(); it2 != m_MosterList.end(); it2++)delete *it2;
	m_MosterList.clear();
}
void CFrame::ClearWall()
{
	std::list<CBarrier*>::iterator it1;
	for (it1 = m_WallList.begin(); it1 != m_WallList.end(); it1++)delete *it1;
	m_WallList.clear();
}