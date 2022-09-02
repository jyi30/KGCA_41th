#include "Main.h"
bool Main::Init()
{
	TDevice::Init();

	HRESULT hr;

	hr = DirectX::CreateWICTextureFromFile(m_pd3dDevice, m_pImmediateContext, L"../../data/KGCABK.bmp", &m_Texture
		, &m_pTextureSRV);
	
	return true;
}

bool Main::Frame()
{
	TDevice::Frame();
	return true;
}

bool Main::Render()
{
	TDevice::Render();
	return true;
}

bool Main::Release()
{
	TDevice::Release();

	if (m_Texture)
	{
		m_Texture->Release();
	}
	if (m_pTextureSRV)
	{
		m_pTextureSRV->Release();
	}

	return true;
}

GAME_RUN(CreateTexture, 1024, 768)