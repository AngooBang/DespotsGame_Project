#pragma once
#include "Scene.h"

#define LOGO_POS_X WIN_SIZE_X / 2 - 350
#define LOGO_POS_Y WIN_SIZE_Y / 2 - 350

template <typename T>
class Button;

class TitleScene : public Scene
{
	using Button = Button<TitleScene>;

private:
	Image* backGroundImg;
	Image* despotsLogo;

	RECT startTextBox;

	Button* m_startButton;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void GameStart();
};

