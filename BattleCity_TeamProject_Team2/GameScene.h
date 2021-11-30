#pragma once
#include "Scene.h"

class Image;
class GameScene : public Scene
{
private:
	Image* backGroundImg;



public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	
	void Release();
};

