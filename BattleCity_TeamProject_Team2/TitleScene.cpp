#include "TitleScene.h"
#include "Image.h"


HRESULT TitleScene::Init()
{
	backGroundImg = ImageManager::GetSingleton()->FindImage("Image/BackGround.bmp");
	despotsLogo = ImageManager::GetSingleton()->FindImage("Image/Despot_Logo.bmp");

	return S_OK;
}

void TitleScene::Update()
{
	if (KeyManager::GetSingleton()->IsOnceKeyDown(MK_LBUTTON))
	{
		SceneManager::GetSingleton()->ChangeScene("°ÔÀÓ¾À");
	}

}

void TitleScene::Render(HDC hdc)
{
	backGroundImg->Render(hdc);
	despotsLogo->Render(hdc, LOGO_POS_X, LOGO_POS_Y);

	
}

void TitleScene::Release()
{
}
