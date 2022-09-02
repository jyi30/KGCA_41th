// 1) DirectXTK 다운로드 : https://github.com/microsoft/DirectXTK
// 2) Import DirectXTK_Desktop_2019.sln
// 3) build 후 bin 폴더의 DirectXTK.lib 복사 후 프로젝트 내 lib 폴더에 붙여넣기
// 4) inc 폴더의 모든 파일 프로젝트의 include/dxtk 폴더에 붙여넣기
// 5) 프로젝트 -> 속성 -> C/C++(일반) -> 추가포함 디렉토리 -> ../../include/dxtk;
// 6) 프로젝트 -> 속성 -> 링커 -> 추가라이브러리 디렉토리 -> ../../lib;

#pragma once
#include "TDevice.h"
#include "WICTextureLoader.h"
#include "DDSTextureLoader.h"
#pragma comment(lib, "DirectXTK.lib")

// 5, 6번 셋팅 하지 않을시 필요한 코드
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

