#include "GameScene.h"
#include "Image.h"
#include "TileMap.h"

HRESULT GameScene::Init()
{
	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);


	backGroundImg = ImageManager::GetSingleton()->FindImage("Image/BackGround.bmp");
	tileMap = new TileMap();
	tileMap->Init();

	return S_OK;
}

void GameScene::Update()
{
	tileMap->Update();
}

void GameScene::Render(HDC hdc)
{
	backGroundImg->Render(hdc);
	tileMap->Render(hdc);
}

void GameScene::Release()
{
	SAFE_RELEASE(tileMap);
}
