#include "CWindow.h"

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