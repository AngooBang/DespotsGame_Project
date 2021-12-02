#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus")

#include "TimerManager.h"
#include "ImageManager.h"
#include "KeyManager.h"
#include "SceneManager.h"

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
extern POINT g_ptMouse;
extern ULONG_PTR g_gpToken;
extern GdiplusStartupInput g_gpsi;