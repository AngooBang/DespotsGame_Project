#include "GameScene.h"
#include "Image.h"

HRESULT GameScene::Init()
{
	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);


	backGroundImg = ImageManager::GetSingleton()->FindImage("Image/BackGround.bmp");


	return S_OK;
}

void GameScene::Update()
{
}

void GameScene::Render(HDC hdc)
{
	backGroundImg->Render(hdc);
}

void GameScene::Release()
{
}
