#pragma once
#include "Scene.h"

class BMPImage;
class TileMap;
class GameScene : public Scene
{
private:
	BMPImage* backGroundImg;

	TileMap* tileMap;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	
	void Release();
};

