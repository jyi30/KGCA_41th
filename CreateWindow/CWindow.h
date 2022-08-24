#pragma once
#include "TWindow.h"

class CWindow : public TWindow
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

};

