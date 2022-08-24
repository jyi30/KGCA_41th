#include "TWindow.h"

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
		PostQuitMessage(0); //메세지큐에 직접 WM_QUIT
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
	//메세지 처리 불가시 넘김
}

bool TWindow::SetWindow(HINSTANCE hInst, const WCHAR* szTitle, UINT iWidth, UINT iHeight)
{
	m_hInstance = hInst;
	WORD ret = MyRegisterClass();

	if (!InitInstance(szTitle, iWidth, iHeight))
	{
		return FALSE;
	}
	return true;
}

ATOM TWindow::MyRegisterClass()
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));
	wcex.cbSize = sizeof(WNDCLASSEX); //구조체의 크기를 결정
	wcex.style = CS_HREDRAW | CS_VREDRAW; //윈도우 스타일(보통 비트연산자를 사용하여 결합
	wcex.hInstance = m_hInstance; //인스턴스 핸들을 지정
	wcex.hbrBackground = CreateSolidBrush(RGB(100, 100, 100)); //윈도우 배경화면을 지정
	wcex.lpszClassName = L"KGCA 윈도우"; // 클래스 이름 지정
	wcex.lpfnWndProc = WndProc; //윈도우 메세지 콜백함수를 지정
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // 윈도우에 사용할 커서 지정

	return RegisterClassEx(&wcex);
}

BOOL TWindow::InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight)
{
	m_dwWindowStyle = WS_OVERLAPPEDWINDOW;
	RECT rc = { 0, 0, iWidth, iHeight };
	AdjustWindowRect(&rc, m_dwWindowStyle, FALSE); //작업 영역, 윈도우 스타일, 메뉴 여부
	
	HWND hWnd = CreateWindowW(L"KGCA윈도우", szTitle, m_dwWindowStyle, 0, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, m_hInstance, nullptr);
	
	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, SW_SHOW);

	return TRUE;
}

void TWindow::CenterWindow()
{
	UINT iScreenWidth = GetSystemMetrics(SM_CXFULLSCREEN);
	UINT iScreenHeight = GetSystemMetrics(SM_CYFULLSCREEN);	
	UINT cx, cy;

	cx = (iScreenWidth - (m_rtWindowBounds.right - m_rtWindowBounds.left)) * 0.5f;
	cy = (iScreenHeight - (m_rtWindowBounds.bottom - m_rtWindowBounds.top)) * 0.5f;
	MoveWindow(m_hWnd, cx, cy, m_rtWindowBounds.right - m_rtWindowBounds.left, m_rtWindowBounds.bottom - m_rtWindowBounds.top, true);
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
	Init();

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