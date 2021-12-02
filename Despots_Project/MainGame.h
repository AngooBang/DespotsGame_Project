#pragma once
#include "GameEntity.h"


class MainGame : public GameEntity
{
private:
	HANDLE hTimer;

	HCURSOR hCursorIn;


	int clickedMousePosX;
	int clickedMousePosY;

	BMPImage* backBuffer;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

};
