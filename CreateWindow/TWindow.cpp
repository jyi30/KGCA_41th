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
		PostQuitMessage(0); //�޼���ť�� ���� WM_QUIT
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
	//�޼��� ó�� �Ұ��� �ѱ�
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
	wcex.cbSize = sizeof(WNDCLASSEX); //����ü�� ũ�⸦ ����
	wcex.style = CS_HREDRAW | CS_VREDRAW; //������ ��Ÿ��(���� ��Ʈ�����ڸ� ����Ͽ� ����
	wcex.hInstance = m_hInstance; //�ν��Ͻ� �ڵ��� ����
	wcex.hbrBackground = CreateSolidBrush(RGB(100, 100, 100)); //������ ���ȭ���� ����
	wcex.lpszClassName = L"KGCA ������"; // Ŭ���� �̸� ����
	wcex.lpfnWndProc = WndProc; //������ �޼��� �ݹ��Լ��� ����
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); // �����쿡 ����� Ŀ�� ����

	return RegisterClassEx(&wcex);
}

BOOL TWindow::InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight)
{
	m_dwWindowStyle = WS_OVERLAPPEDWINDOW;
	RECT rc = { 0, 0, iWidth, iHeight };
	AdjustWindowRect(&rc, m_dwWindowStyle, FALSE); //�۾� ����, ������ ��Ÿ��, �޴� ����
	
	HWND hWnd = CreateWindowW(L"KGCA������", szTitle, m_dwWindowStyle, 0, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, m_hInstance, nullptr);
	
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