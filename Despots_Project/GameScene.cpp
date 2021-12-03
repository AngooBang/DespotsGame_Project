#include "stdafx.h"
#include "GameScene.h"
#include "BMPImage.h"
#include "FullMap.h"

HRESULT GameScene::Init()
{
	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);


	m_backGroundImg = ImageManager::GetSingleton()->FindImage("Image/Title/BackGround.bmp");
	m_fullMap = new FullMap();
	m_fullMap->Init();

	return S_OK;
}

void GameScene::Update()
{
	SAFE_UPDATE(m_fullMap);
}

void GameScene::Render(HDC hdc)
{
	m_backGroundImg->Render(hdc);
	m_fullMap->Render(hdc);
}

void GameScene::Release()
{
	SAFE_RELEASE(m_fullMap);
}
