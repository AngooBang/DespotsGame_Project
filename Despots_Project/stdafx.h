#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "resource.h"
#include <gdiplus.h>

using namespace std;
using namespace Gdiplus;


#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdiplus")

#include "TimerManager.h"
#include "ImageManager.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "CameraManager.h"
#include "GameManager.h"
#include "CharacterManager.h"
#include "Input.h"

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
extern POINT g_ptMouse;
extern ULONG_PTR g_gpToken;
extern GdiplusStartupInput g_gpsi;
extern WNDCLASS g_wndClass;