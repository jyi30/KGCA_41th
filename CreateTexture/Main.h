// 1) DirectXTK �ٿ�ε� : https://github.com/microsoft/DirectXTK
// 2) Import DirectXTK_Desktop_2019.sln
// 3) build �� bin ������ DirectXTK.lib ���� �� ������Ʈ �� lib ������ �ٿ��ֱ�
// 4) inc ������ ��� ���� ������Ʈ�� include/dxtk ������ �ٿ��ֱ�
// 5) ������Ʈ -> �Ӽ� -> C/C++(�Ϲ�) -> �߰����� ���丮 -> ../../include/dxtk;
// 6) ������Ʈ -> �Ӽ� -> ��Ŀ -> �߰����̺귯�� ���丮 -> ../../lib;

#pragma once
#include "TDevice.h"
#include "WICTextureLoader.h"
#include "DDSTextureLoader.h"
#pragma comment(lib, "DirectXTK.lib")

// 5, 6�� ���� ���� ������ �ʿ��� �ڵ�
//#include "../../include/dxtk/WICTextureLoader.h"
//#include "../../include/dxtk/DDSTextureLoader.h"
//#pragma comment(lib, "../../lib/DirectXTK.lib")

class Main : public TDevice
{
	ID3D11Resource* m_Texture = nullptr;
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

