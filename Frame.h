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
	//**********************************���ǵ�һ��д��************************************///
	std::map<const char*, CScene*>m_SceneList;//����ͼ��
	CScene* m_CurS;//��ǰ���г���
	CScene* m_NextS;//�л���һ������
	
	CFrame();

	static CFrame* pCFrame;//��̬�ڴ�
	HWND m_hWnd; //���ھ��

	int m_ClientW;//�ͻ�����
	int m_ClientH;//�ͻ�����
	int m_Act;
	//���룬���
	CGameOutput* m_go;
	CGameInput* m_gi;

	/*****************************12.15���**********************/
	const int* m_X;
	const int* m_Y;

	int m_CX;
	int m_CY;

	/////����
	std::list<CMoster*> m_MosterList;
	//�ϰ���
	std::list<CBarrier*> m_WallList;

	//Ӣ��
	CHero* m_Hero;

	CMoster* m_Moster;
	

public:
	static CFrame* GetFrame(); //��̬
	bool AddScen(const char* id, CScene* s);//��ӳ���
	bool SetFistScene(const char* id);//��һ������
	bool SetNextScene(const char* id);//��һ������
	void Init(int w, int h, HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow); //��ʼ������
	void Run();
	void End();
	int GetAct();
	void SetAct(int n);
	void GetRand(int min, int max, int num, int *out);//��ȡ�����


	//*******************************���ǵڶ���д��*****************************//
	//��ȡ������꺯��
	POINT GetCursorPoint();

	int GetKeyState(unsigned char Key); //��ȡ���̵ļ�ֵ

	//��ֱ��
	void DrawLine(int x1, int y1, int x2, int y2, int w = 1, unsigned int c = RGB(0, 0, 0));

	//ʵ�ľ���
	void DrawSolidRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));

	//���ľ���
	void DrawRect(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//ʵ��Բ
	void DrawSolidEllipse(int rx, int ry, int rw, int rh,
		int w = 1, unsigned int c1 = RGB(0, 0, 0), unsigned int c2 = RGB(255, 255, 255));
	
	//����Բ
	void DrawEllipse(int rx, int ry, int rw, int rh, int w = 1, unsigned int c = RGB(0, 0, 0));

	//��������

	void SetFont(int w, int h);//������
	
	//���Ƶ�����
	void DrawString(int x, int y, const char* t, unsigned int c);//�������Ͻ�λ��,Ҫ���������,��ɫ

	//���ƶ������� (����)
	void DrawString(int x, int y, int w, int h,	//��������ľ��η�Χ
		const char* t, unsigned int c);

	//λͼ���
	//           ͼƬID ͼƬ·����ͨ��ID����·����
	int LoadBmp(const char* id, const char* fn);

	bool ReleaseBmp(const char* id);

	//����ʲôλ�� �����ȡ��Դͼ��λ��  Ҳ���Ǵ�Դͼ�۶�������
	bool DrawBmp(const char* id, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, unsigned int c = RGB(0, 255, 0));//ȥ����ɫ


	//ɾ��ͼ��
	void ClearBmp();

	int GetClientW();
	int GetClientH();

	/*****************************12.15��ӣ��������**********************/
	void SetWinDow(int x, int y);
	void LookAt(const int* x, const int* y);
	void CameraMove();


	int GetCX(); //�ͻ��˿��
	int GetCY();	


	//�����ϰ���12.18
	void AddMoster(CMoster* moster);
	void AddWall(CBarrier* Barrier);
	std::list<CMoster*>* GetMosterList();
	std::list<CBarrier*>* GetWallList();

	//���Ӣ������
	CHero* GetHero();
	void ClearMoster();
	void ClearWall();

	//����
	CMoster* GetMoster();

	CMoster*  CSuperBoss();
};