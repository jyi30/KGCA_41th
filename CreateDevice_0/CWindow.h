#pragma once
#include "TDevice.h"

class CWindow : public TDevice
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

};

