#pragma once
#include "TStd.h"

class TWindow
{
public:
	HINSTANCE m_hInstance; // 인스턴스 핸들
	HWND m_hWnd; // 윈도우 핸들
	DWORD m_dwWindowStyle; // 윈도우 스타일
	RECT m_rtWindowBounds; // 윈도우 영역
	RECT m_rtWindowClient; // 클라이언트 영역
	UINT m_iWindowWidth; // 클라이언트 영역 가로 크기
	UINT m_iWindowHeight; // 클라이언트 영역 세로 크기
#ifdef _DEBUG
	std::vector<UINT> msglist;
#endif

public:
	bool SetWindow(HINSTANCE hInst, const WCHAR* szTitle, UINT iWidth = 1024, UINT iHeight = 768);
	ATOM MyRegisterClass();
	BOOL InitInstance(const WCHAR* szTitle, UINT iWidth, UINT iHeight);
	bool Run();
	void CenterWindow();
public:
	virtual bool TCoreInit(); //초기화
	virtual bool TCoreFrame(); //실시간 계산
	virtual bool TCoreRender(); // 실시간 렌더링
	virtual bool TCoreRelease(); // 소멸 및 삭제
	virtual LRESULT MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	TWindow();
};

