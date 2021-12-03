#pragma once

#include "stdafx.h"


#define WIN_START_POS_X	10
#define WIN_START_POS_Y	10
#define WIN_SIZE_X	1280
#define WIN_SIZE_Y	720

#define WIN_HALF_X WIN_SIZE_X / 2
#define WIN_HALF_Y WIN_SIZE_Y / 2


#define FROM_FILE Image::FromFile


#define PI 3.14159265357989
#define PI2 (3.14159265357989 * 2)

#define DEGREE_TO_RADIAN(x)		(x * PI / 180.0f)

#define SAFE_RELEASE(p)	{ if (p) { p->Release(); delete p; p = nullptr; } } 
#define SAFE_DELETE(p)	{ if (p) { delete p; p = nullptr; } }
#define SAFE_UPDATE(p) { if (p) { p->Update();} } 

enum MoveDir { Left, Right, Up, Down };

enum class ButtonType { Normal, Exit, End };

typedef struct ArgumentFuncPtr
{
	string sceneName;
	string loadingSceneName;
} ARGUMENT_PTR, * LPARGUMENT_PTR;
