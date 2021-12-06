#pragma once
#include "Scene.h"

class BMPImage;
class FullMap;
class Character;
class GameScene : public Scene
{
private:
	BMPImage* m_backGroundImg = nullptr;

	FullMap* m_fullMap = nullptr;

	Character* m_char = nullptr;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	
	void Release();
};

