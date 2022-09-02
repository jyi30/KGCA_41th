#pragma once
#include "TStd.h"

class TWindow
{
public:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	RECT m_rtWindow;
	RECT m_rtClient;
	DWORD m_csStyle;
	UINT m_iClientWidth;
	UINT m_iClientHeight;
public:
	bool setWindow(HINSTANCE hInst, const WCHAR* szTitle, UINT iWidth = 1024, UINT iHeight = 768);
	ATOM MyRegisterClass();
	BOOL InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight);
	bool  Run();
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

