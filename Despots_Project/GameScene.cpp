#include "stdafx.h"
#include "GameScene.h"
#include "BMPImage.h"
#include "FullMap.h"
#include "Character.h"

HRESULT GameScene::Init()
{
	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);


	m_backGroundImg = ImageManager::GetSingleton()->FindImage("Image/Title/BackGround.bmp");
	m_fullMap = new FullMap;
	m_fullMap->Init();

	m_char = new Character;
	m_char->Init();
	return S_OK;
}

void GameScene::Update()
{
	if (INPUT_KEY_STAY(VK_LEFT))
	{
		CameraManager::GetSingleton()->SetCameraPos({ -10, 0 });
	}
	if (INPUT_KEY_STAY(VK_RIGHT))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 10, 0 });
	}
	if (INPUT_KEY_STAY(VK_UP))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 0, -10 });
	}
	if (INPUT_KEY_STAY(VK_DOWN))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 0, 10 });
	}
	SAFE_UPDATE(m_fullMap);
	SAFE_UPDATE(m_char);
}

void GameScene::Render(HDC hdc)
{
	m_backGroundImg->Render(hdc);
	m_fullMap->Render(hdc);
	m_char->Render(hdc);
}

void GameScene::Release()
{
	SAFE_RELEASE(m_fullMap);
	SAFE_RELEASE(m_char);
}
