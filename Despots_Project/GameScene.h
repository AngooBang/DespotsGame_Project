#pragma once
#include "Scene.h"

class BMPImage;
class FullMap;
class GameScene : public Scene
{
private:
	BMPImage* m_backGroundImg;

	FullMap* m_fullMap;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	
	void Release();
};

