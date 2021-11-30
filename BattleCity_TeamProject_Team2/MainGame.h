#pragma once
#include "Config.h"
#include "GameEntity.h"



// 우리가 구성할 게임 월드
class Image;
class MainGame : public GameEntity
{
private:
	// 타이머
	HANDLE hTimer;

	HCURSOR hCursorIn;


	int clickedMousePosX;
	int clickedMousePosY;

	// 백버퍼
	Image* backBuffer;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	// 오버로딩
	void Release();

};
