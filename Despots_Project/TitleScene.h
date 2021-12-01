#pragma once
#include "Scene.h"

#define LOGO_POS_X WIN_SIZE_X / 2
#define LOGO_POS_Y WIN_SIZE_Y / 2 - 150



class TitleScene : public Scene
{
private:
	Image* backGroundImg;
	Image* despotsLogo;

	RECT startTextBox;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

