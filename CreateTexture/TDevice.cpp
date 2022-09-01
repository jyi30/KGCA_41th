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

// 1) 디바이스 생성
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
		&m_pd3dDevice, // 디바이스 객체
		&pFeatureLevel,
		&m_pImmediateContext
	);

	//m_pd3dDevice : 다른 인터페이스 생성시 사용한다.
	//m_pImmediateContext : 생성된 인터페이스를 사용(관리, 제어)할 때
	return hr;
}

// 2) 팩토리 생성
HRESULT TDevice::CreateDXGIDevice()
{
	HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&m_pGIFactory);

	return hr;
}

// 3) 스왑체인 생성
HRESULT TDevice::CreateSwapChain()
{
	// BufferDesc : 후면 버퍼의 속성(넓이, 높이 등) 구조체
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1; //스왑체인에서 사용할 후면 버퍼의 갯수
	sd.BufferDesc.Width = g_rtClient.right;
	sd.BufferDesc.Height = g_rtClient.bottom;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	//BufferUsage : 버퍼의 용도를 서술하는 구조체, 지금은 후면 버퍼를 렌더 대상으로 사용할 것
	sd.OutputWindow = g_hWnd; //렌더링 결과를 표시할 창의 핸들
	sd.Windowed = true; //창모드를 원하면 true, 전체화면은 false
	
	//Numerator : 유리수의 맨 위를 나타내는 부호 없는 정수 값
	//Denominator : 유리수의 맨 아래를 나타내는 부호 없는 정수 값
	sd.BufferDesc.RefreshRate.Numerator = 60; 
	sd.BufferDesc.RefreshRate.Denominator = 1; 
	
	//SampleDesc : 다중 표본화 구조체. 사용을 원하지 않으면 Count = 1, Quality = 0으로 설정한다.
	sd.SampleDesc.Count = 1; //픽셀당 추출할 표본의 개수 지정
	sd.SampleDesc.Quality = 0; //원하는 품질 수준을 지정

	//현재 Flags 설정은 응용 프로그램이 전체화면 모드로 전환할 때 현재의 후면 버퍼 설정에 가장 잘 부합하는
	//디스플레이 모드가 자동으로 선택된다.
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	return m_pGIFactory->CreateSwapChain(m_pd3dDevice, &sd, &m_pSwapChain);
}

//4) 렌더 타겟 뷰 생성
HRESULT TDevice::CreateRenderTargetView()
{
	HRESULT hr;
	ID3D11Texture2D* pBackBuffer = nullptr;
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer); //스왑 체인을 가리키는 포인터 획득
	hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRTV); // 렌더 타겟 뷰 생성
	pBackBuffer->Release();//GetBuffer를 호출하면 후면버퍼에 대한 COM 참조 횟수가 증가하는데, 이를 초기화 하기 위함

	return hr;
}

//5) 뷰포트 설정
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