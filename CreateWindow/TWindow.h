#pragma once
#include "TStd.h"

class TWindow
{
public:
	HINSTANCE m_hInstance; // �ν��Ͻ� �ڵ�
	HWND m_hWnd; // ������ �ڵ�
	DWORD m_dwWindowStyle; // ������ ��Ÿ��
	RECT m_rtWindowBounds; // ������ ����
	RECT m_rtWindowClient; // Ŭ���̾�Ʈ ����
	UINT m_iWindowWidth; // Ŭ���̾�Ʈ ���� ���� ũ��
	UINT m_iWindowHeight; // Ŭ���̾�Ʈ ���� ���� ũ��

public:
	bool SetWindow(HINSTANCE hInst, const WCHAR* szTitle, UINT iWidth = 1024, UINT iHeight = 768);
	ATOM MyRegisterClass();
	BOOL InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight);
	bool Run();
	void CenterWindow();
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	virtual LRESULT MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	TWindow();
};

