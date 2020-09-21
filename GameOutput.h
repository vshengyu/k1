#pragma once

#include<windows.h>
#include<map>

class CGameOutput
{
	HWND m_hWnd; //����
	int m_ClientW;//�ͻ�����
	int m_ClientH;//�ͻ�����
	HDC m_MainDC;//���豸
	HDC m_BackDC;//���豸

	std::map<const char*, HDC>m_Bmp; //λͼӳ��
public:
	CGameOutput(HWND hWnd);
	~CGameOutput();

	//��ʼ����
	void Begin();

	//��������
	void End();

	//����
	void DrawLine(int Bx1, int Ey1, int Bx2, int Ey2, unsigned int c = RGB(0, 0, 0), int w = 1);//��ʼ�㣬�����㣬��ɫ����ϸ

	//ʵ�ľ���
	void DrawSolidRect(int rx, int ry, int rw, int rh, 
		int w = 1, unsigned int c1 = RGB(0,0,0), unsigned int c2 = RGB(255, 255, 255));

	//���ľ���
	void DrawRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));
	//����Բ
	void DrawEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//ʵ��Բ
	void DrawSolidEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c1 = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));

	//**********************�������**********************//
	//��������

	void SetFont(int w, int h, //������
		const char* st = "����",//�������
		int we = 400,//�����ϸ
		bool i = false,//б��
		bool u = false,//�»���
		bool s = false//��Խ��
		);

	//����λ�����Ͻǣ�Ҫ��������֣���ɫ
	void DrawString(int x, int y, const char* t, unsigned int c);

	//���ƶ������֣����أ�
	void DrawString(int x, int y, int w, int h, const char* t, unsigned int c);



	//**********************λͼ���**********************//

	int LoadBmp(const char* id, const char* fn);//ͼƬid,ͼƬ·��,(ͨ��id,��·��)

	//�ͷ�bmpͼƬ
	bool ReleaseBmp(const char* id);

	//��ͼ��
	bool DrawBmp(const char* id,
		int dx, int dy, int dw, int dh, //����ʲôλ�� ��Ҫ�����
		int sx, int sy, int sw, int sh, //ȡ��ԭͼ��λ�ã���ԭͼ�۳���������
		unsigned int c = RGB(0, 255, 0));//ȥ����ɫ

	void Clear();

};

