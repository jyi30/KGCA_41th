#pragma once
#include "TWindow.h"

class TDevice : public TWindow
{	
public:
	//�������̽� -> �ϵ���� ���� ���� ���� ȹ��
	ID3D11Device* m_pd3dDevice = nullptr; //����̽� ��ü
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
	IDXGIFactory* m_pGIFactory = nullptr;
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11RenderTargetView* m_pRTV = nullptr;

public:
	//1. ����̽� ����
	HRESULT CreateDevice();
	//2. ���丮 ����
	HRESULT CreateDXGIDevice();
	//3. ����ü�� ����
	HRESULT CreateSwapChain();
	//4. ����Ÿ�ٺ� ����
	HRESULT CreateRenderTargetView();
	//5. ����Ʈ ����
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

