#include "TWindow.h"
HWND g_hWnd;
RECT g_rtClient;
TWindow* g_pWindow = nullptr;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	_ASSERT(g_pWindow);
	return g_pWindow->MsgProc(hWnd, message, wParam, lParam);
}

LRESULT TWindow::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

BOOL TWindow::InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight)
{
	m_csStyle = WS_OVERLAPPEDWINDOW; //해당 윈도우 창을 제일 위에 배치
	RECT rc = { 0, 0, iWidth, iHeight };
	AdjustWindowRect(&rc, m_csStyle, FALSE);
	HWND hWnd = CreateWindowW(
		L"KGCA윈도우",
		szTitle,
		m_csStyle,
		0, 0,
		rc.right - rc.left,
		rc.bottom - rc.top,
		nullptr, nullptr,
		m_hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}
	m_hWnd = hWnd;
	g_hWnd = hWnd;
	ShowWindow(hWnd, SW_SHOW);
	GetWindowRect(hWnd, &m_rtWindow);
	GetClientRect(hWnd, &m_rtClient);
	g_rtClient = m_rtClient;

	m_iClientWidth = m_rtClient.right - m_rtClient.left;
	m_iClientHeight = m_rtClient.bottom = m_rtClient.top;
	CenterWindow();

	return TRUE;
}

void TWindow::CenterWindow()
{
	UINT iScreenWidth = GetSystemMetrics(SM_CXFULLSCREEN);
	UINT iScreenHeight = GetSystemMetrics(SM_CYFULLSCREEN);
	UINT cx, cy;
	cx = (iScreenWidth - (m_rtWindow.right - m_rtWindow.left)) * 0.5f;
	cy = (iScreenHeight - (m_rtWindow.bottom - m_rtWindow.top)) * 0.5f;

	MoveWindow(m_hWnd, cx, cy, m_rtWindow.right - m_rtWindow.left, m_rtWindow.bottom - m_rtWindow.top, true);
}

ATOM TWindow::MyRegisterClass()
{
	WNDCLASSEXW wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.hInstance = m_hInstance;
	wcex.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));
	wcex.lpszClassName = L"KGCA윈도우";
	wcex.lpfnWndProc = WndProc;
	wcex.hCursor = LoadCursor(nullptr, IDC_WAIT);
	
	return RegisterClassEx(&wcex);
}

bool TWindow::setWindow(HINSTANCE hInstance, const WCHAR* szTitle, UINT iWidth, UINT iHeight)
{
	m_hInstance = hInstance;
	WORD ret = MyRegisterClass();

	if (!InitInstance(szTitle, iWidth, iHeight))
	{
		return FALSE;
	}
	return true;
}

bool TWindow::Init()
{
	return true;
}

bool TWindow::Frame()
{
	return true;
}

bool TWindow::Render()
{
	return true;
}

bool TWindow::Release()
{
	return true;
}

TWindow::TWindow()
{
	g_pWindow = this;
}

bool TWindow::Run()
{
	if (Init() == false)
	{
		return false;
	}

	MSG msg = { 0, };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Frame();
			Render();
		}
	}
	Release();

	return true;
}