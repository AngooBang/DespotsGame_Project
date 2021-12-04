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
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{
		CameraManager::GetSingleton()->SetCameraPos({ -10, 0 });
	}
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 10, 0 });
	}
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_UP))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 0, -10 });
	}
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_DOWN))
	{
		CameraManager::GetSingleton()->SetCameraPos({ 0, 10 });
	}
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
