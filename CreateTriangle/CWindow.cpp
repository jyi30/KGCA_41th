#include "CWindow.h"

HRESULT CWindow::CreateVertexBuffer()
{
	HRESULT hr;

	VertexEx ex[] =
	{
		// x, y, z, r, g, b, a ����
		-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, //v0
		+0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //v1
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //v2

		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, //v3
		+0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //v4
		+0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, //v5
	};
	
	UINT NumVertex = sizeof(ex) / sizeof(ex[0]);
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.ByteWidth = sizeof(VertexEx) * NumVertex; //����Ʈ �뷮 �Ҵ�(GPU�� �Ҵ�)
	bd.Usage = D3D11_USAGE_DEFAULT; //������ �Ҵ� ��� ������ ���� �뵵
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	//bd.CPUAccessFlags = 0;//CPU�� ���� ���� ����
	//UINT MiscFlags = 0; // ��Ÿ �÷��� ��� ���� 
	//UINT StructureByteStride = 0; //���۰� ����ȭ�� ���۸� ��Ÿ���� ��� ���� �������� �� ����� ũ��

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = ex; //�ʱ�ȭ �����Ϳ� ���� ������
	hr = m_pd3dDevice->CreateBuffer(
		&bd,
		&sd,
		&m_pVertexBuffer
	);

	return hr;
	//UINT SysMemPitch = 0; //�ؽ�ó�� �� �� ���ۺκп��� ������ ������ �Ÿ�(����Ʈ)
	//UINT SysMemSlicePitch = 0; //�� ������ ������ ���ۿ��� ���� ���ر����� �Ÿ�(����Ʈ)
}

HRESULT CWindow::CreateShader()
{
	HRESULT hr;
	//�������̴� ������
	ID3DBlob* pErrorCode = nullptr;
	hr = D3DCompileFromFile(
		L"VertexShader.txt",
		NULL,
		NULL,
		"main",
		"vs_5_0",
		0,
		0,
		&m_pVSCode,
		&pErrorCode
	);

	if (FAILED(hr))
	{
		if (pErrorCode)
		{
			OutputDebugStringA((char*)pErrorCode->GetBufferPointer());
			pErrorCode->Release();
		}
		return hr;
	}

	hr = m_pd3dDevice->CreateVertexShader(
		m_pVSCode->GetBufferPointer(),
		m_pVSCode->GetBufferSize(),
		NULL,
		&m_pVS
		);

	hr = D3DCompileFromFile(
		L"PixelShader.txt",
		NULL,
		NULL,
		"PSMain",
		"ps_5_0",
		0,
		0,
		&m_pPSCode,
		&pErrorCode
	);

	if (FAILED(hr))
	{
		if (pErrorCode)
		{
			OutputDebugStringA((char*)pErrorCode->GetBufferPointer());
			pErrorCode->Release();
		}
		return hr;

	}

	hr = m_pd3dDevice->CreatePixelShader(
		m_pPSCode->GetBufferPointer(),
		m_pPSCode->GetBufferSize(),
		NULL,
		&m_pPS
	);

	if (FAILED(hr))
	{
		if (pErrorCode)
		{
			OutputDebugStringA((char*)pErrorCode->GetBufferPointer());
			pErrorCode->Release();
		}
		return hr;
	}
	return hr;
}

HRESULT CWindow::CreateVertexLayout()
{
	HRESULT hr;

	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	//�������
}

bool CWindow::Init()
{
	TDevice::Init();
	return true;
}

bool CWindow::Frame()
{
	TDevice::Frame();
	return true;
}

bool CWindow::Render()
{
	TDevice::Render();
	return true;
}

bool CWindow::Release()
{
	TDevice::Release();
	return true;
}

GAME_RUN(CreateDevice_0, 1024, 768)