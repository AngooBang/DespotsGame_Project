#pragma once
#include "Scene.h"

#define LOGO_POS_X WIN_SIZE_X / 2 - 350
#define LOGO_POS_Y WIN_SIZE_Y / 2 - 350

#define STARTBUTTON_POS_X WIN_HALF_X - 200
#define STARTBUTTON_POS_Y 600

#define EXITBUTTON_POS_X WIN_HALF_X + 200
#define EXITBUTTON_POS_Y 600


template <typename T>
class Button;

class TitleScene : public Scene
{
	using Button = Button<TitleScene>;

private:
	Image* m_backGroundImg = nullptr;
	Image* m_despotsLogo = nullptr;

	RECT m_startTextBox = {};

	Button* m_startButton = nullptr;
	Button* m_exitButton = nullptr;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void GameStart();
	void GameExit();
};

