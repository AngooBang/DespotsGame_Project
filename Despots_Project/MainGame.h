#pragma once
#include "GameEntity.h"


class MainGame : public GameEntity
{
private:
	HANDLE m_hTimer = {};

	HCURSOR m_hCursorIn = {};


	int m_clickedMousePosX = 0;
	int m_clickedMousePosY = 0;

	BMPImage* m_backBuffer = nullptr;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

};
