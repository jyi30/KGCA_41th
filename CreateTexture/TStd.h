#pragma once
#include <windows.h>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

extern HWND g_hWnd;
extern RECT g_rtClient;

#define GAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLint, int nCmdShow){
#define GAME_WINDOW(s, x ,y) Main demo; demo.setWindow(hInstance, L#s,x,y);demo.Run();return 1;
#define GAME_END }
#define GAME_RUN(s,x,y) GAME_START GAME_WINDOW(s,x,y) GAME_END