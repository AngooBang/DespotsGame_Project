#pragma once
#include "Scene.h"

class Image;
class TileMap;
class GameScene : public Scene
{
private:
	Image* backGroundImg;

	TileMap* tileMap;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	
	void Release();
};

