#include "stdafx.h"
#include "TitleScene.h"


HRESULT TitleScene::Init()
{
	backGroundImg = FROM_FILE(L"Image/Title/BackGround.bmp");
	despotsLogo = FROM_FILE(L"Image/Title/Despot_Logo.bmp");

	return S_OK;
}

void TitleScene::Update()
{
	if (KeyManager::GetSingleton()->IsOnceKeyDown(MK_LBUTTON))
	{
		SceneManager::GetSingleton()->ChangeScene("∞‘¿”æ¿");
	}

}

void TitleScene::Render(HDC hdc)
{
	Graphics G(hdc);

	G.DrawImage(backGroundImg, 500, 500, WIN_SIZE_X, WIN_SIZE_Y);
	G.DrawImage(despotsLogo, 500, 500);

	
}

void TitleScene::Release()
{
}
