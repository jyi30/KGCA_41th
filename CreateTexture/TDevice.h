#pragma once
#include "TWindow.h"
class TDevice : public TWindow
{
public:
	ID3D11Device* m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
	IDXGIFactory* m_pGIFactory = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11RenderTargetView* m_pRTV = nullptr;
public:
	// 1) 디바이스 생성
	HRESULT CreateDevice();
	// 2) 팩토리 생성
	HRESULT CreateDXGIDevice();
	// 3) 스왑체인 생성
	HRESULT CreateSwapChain();
	// 4) 렌더 타겟 뷰 생성
	HRESULT CreateRenderTargetView();
	// 5) 뷰 포트 설정
	void CreateViewPort();
public:
	bool Init(); //초기화
	bool Frame(); //실시간 계산
	bool Render(); //실시간 렌더링
 	bool Release(); //소멸
};

