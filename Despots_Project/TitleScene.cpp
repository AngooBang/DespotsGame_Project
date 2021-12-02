#include "stdafx.h"
#include "TitleScene.h"
#include "Button.h"


HRESULT TitleScene::Init()
{
	backGroundImg = ::new Gdiplus::Image(L"Image/Title/BackGround.bmp");
	despotsLogo = FROM_FILE(L"Image/Title/Despot_Logo.bmp");

	m_startButton = new Button(this, &TitleScene::GameStart);
	POINT p = { 100, 100 };
	m_startButton->Init(ButtonType::Normal, p, 100, 100);

	return S_OK;
}

void TitleScene::Update()
{
	m_startButton->Update();
}

void TitleScene::Render(HDC hdc)
{
	Graphics G(hdc);

	G.DrawImage(backGroundImg, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	G.DrawImage(despotsLogo, LOGO_POS_X, LOGO_POS_Y, 700, 400);

	m_startButton->Render(hdc);
	
}

void TitleScene::Release()
{
}

void TitleScene::GameStart()
{
	SceneManager::GetSingleton()->ChangeScene("∞‘¿”æ¿");
}
