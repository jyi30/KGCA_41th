#pragma once
#include "TWindow.h"

class Main : public TWindow
{
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

};

