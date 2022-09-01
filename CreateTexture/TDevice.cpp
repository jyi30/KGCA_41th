#include "TDevice.h"

bool TDevice::Init()
{
	HRESULT hr;
	if (FAILED(hr = CreateDXGIDevice()))
	{
		return false;
	}
	if (FAILED(hr = CreateDevice()))
	{
		return false;
	}
	if (FAILED(hr = CreateSwapChain()))
	{
		return false;
	}
	if (FAILED(hr = CreateRenderTargetView()))
	{
		return false;
	}
	CreateViewPort();
	return true;
}

bool TDevice::Frame()
{
	return true;
}

bool TDevice::Render()
{
	m_pImmediateContext->OMSetRenderTargets(1, &m_pRTV, NULL);
	float color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	m_pImmediateContext->ClearRenderTargetView(m_pRTV, color);
	m_pSwapChain->Present(0, 0);

	return true;
}

bool TDevice::Release()
{
	if (m_pd3dDevice)
	{
		m_pd3dDevice->Release();
	}
	if (m_pImmediateContext)
	{
		m_pImmediateContext->Release();
	}
	if (m_pGIFactory)
	{
		m_pGIFactory->Release();
	}
	if (m_pSwapChain)
	{
		m_pSwapChain->Release();
	}
	if (m_pRTV)
	{
		m_pRTV->Release();
	}
	return true;
}

// 1) ����̽� ����
HRESULT TDevice::CreateDevice()
{
	HRESULT hr;
	D3D_FEATURE_LEVEL pFeatureLevel;
	UINT Flags = 0;
	D3D_FEATURE_LEVEL pFeatureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
	};
	UINT FeatureLevels = 1;

	hr = D3D11CreateDevice(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, pFeatureLevels, 1, D3D11_SDK_VERSION,
		&m_pd3dDevice, // ����̽� ��ü
		&pFeatureLevel,
		&m_pImmediateContext
	);

	//m_pd3dDevice : �ٸ� �������̽� ������ ����Ѵ�.
	//m_pImmediateContext : ������ �������̽��� ���(����, ����)�� ��
	return hr;
}

// 2) ���丮 ����
HRESULT TDevice::CreateDXGIDevice()
{
	HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pGIFactory);

	return hr;
}

// 3) ����ü�� ����
HRESULT TDevice::CreateSwapChain()
{
	// BufferDesc : �ĸ� ������ �Ӽ�(����, ���� ��) ����ü
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1; //����ü�ο��� ����� �ĸ� ������ ����
	sd.BufferDesc.Width = g_rtClient.right;
	sd.BufferDesc.Height = g_rtClient.bottom;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	//BufferUsage : ������ �뵵�� �����ϴ� ����ü, ������ �ĸ� ���۸� ���� ������� ����� ��
	sd.OutputWindow = g_hWnd; //������ ����� ǥ���� â�� �ڵ�
	sd.Windowed = true; //â��带 ���ϸ� true, ��üȭ���� false
	
	//Numerator : �������� �� ���� ��Ÿ���� ��ȣ ���� ���� ��
	//Denominator : �������� �� �Ʒ��� ��Ÿ���� ��ȣ ���� ���� ��
	sd.BufferDesc.RefreshRate.Numerator = 60; 
	sd.BufferDesc.RefreshRate.Denominator = 1; 
	
	//SampleDesc : ���� ǥ��ȭ ����ü. ����� ������ ������ Count = 1, Quality = 0���� �����Ѵ�.
	sd.SampleDesc.Count = 1; //�ȼ��� ������ ǥ���� ���� ����
	sd.SampleDesc.Quality = 0; //���ϴ� ǰ�� ������ ����

	//���� Flags ������ ���� ���α׷��� ��üȭ�� ���� ��ȯ�� �� ������ �ĸ� ���� ������ ���� �� �����ϴ�
	//���÷��� ��尡 �ڵ����� ���õȴ�.
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	return m_pGIFactory->CreateSwapChain(m_pd3dDevice, &sd, &m_pSwapChain);
}

//4) ���� Ÿ�� �� ����
HRESULT TDevice::CreateRenderTargetView()
{
	HRESULT hr;
	ID3D11Texture2D* pBackBuffer = nullptr;
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer); //���� ü���� ����Ű�� ������ ȹ��
	hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRTV); // ���� Ÿ�� �� ����
	pBackBuffer->Release();//GetBuffer�� ȣ���ϸ� �ĸ���ۿ� ���� COM ���� Ƚ���� �����ϴµ�, �̸� �ʱ�ȭ �ϱ� ����

	return hr;
}

//5) ����Ʈ ����
void TDevice::CreateViewPort()
{
	D3D11_VIEWPORT vp;
	vp.Width = g_rtClient.right;
	vp.Height = g_rtClient.bottom;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	m_pImmediateContext->RSSetViewports(1, &vp);
}