#include "stdafx.h"
#include "TitleScene.h"
#include "Button.h"


HRESULT TitleScene::Init()
{
	backGroundImg = FROM_FILE(L"Image/Title/BackGround.bmp");
	despotsLogo = FROM_FILE(L"Image/Title/Despot_Logo.bmp");

	m_startButton = new Button(this, &TitleScene::GameStart);
	m_exitButton = new Button(this, &TitleScene::GameExit);


	POINT p = { STARTBUTTON_POS_X, STARTBUTTON_POS_Y };
	m_startButton->Init(ButtonType::Normal, p, 180, 70, TEXT("새로운 게임"));
	p = { EXITBUTTON_POS_X, EXITBUTTON_POS_Y };
	m_exitButton->Init(ButtonType::Exit, p, 180, 70, TEXT("나가기"));

	return S_OK;
}

void TitleScene::Update()
{
	SAFE_UPDATE(m_startButton);
	SAFE_UPDATE(m_exitButton);
}

void TitleScene::Render(HDC hdc)
{
	Graphics G(hdc);

	G.DrawImage(backGroundImg, 0, 0, WIN_SIZE_X, WIN_SIZE_Y);
	G.DrawImage(despotsLogo, LOGO_POS_X, LOGO_POS_Y, 700, 400);

	m_startButton->Render(hdc);
	m_exitButton->Render(hdc);
	
}

void TitleScene::Release()
{
	SAFE_RELEASE(m_startButton);
	SAFE_RELEASE(m_exitButton);
}

void TitleScene::GameStart()
{
	SceneManager::GetSingleton()->ChangeScene("게임씬");
}

void TitleScene::GameExit()
{
	PostQuitMessage(0);
}
