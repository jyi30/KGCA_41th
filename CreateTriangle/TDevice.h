#pragma once
#include "TWindow.h"

class TDevice : public TWindow
{	
public:
	//인터페이스 -> 하드웨어 직접 제어 권한 획득
	ID3D11Device* m_pd3dDevice = nullptr; //디바이스 객체
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
	IDXGIFactory* m_pGIFactory = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11RenderTargetView* m_pRTV = nullptr;

public:
	//1. 디바이스 생성
	HRESULT CreateDevice();
	//2. 팩토리 생성
	HRESULT CreateDXGIDevice();
	//3. 스왑체인 생성
	HRESULT CreateSwapChain();
	//4. 랜터타겟뷰 생성
	HRESULT CreateRenderTargetView();
	//5. 뷰포트 설정
	void CreateViewport();

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

private:
	bool TCoreInit() override;
	bool TCoreFrame() override;
	bool TCorePreRender();
	bool TCoreRender() override;
	bool TCorePostRender();
	bool TCoreRelease() override;
};

