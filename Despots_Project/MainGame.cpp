#include "stdafx.h"
#include "MainGame.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "BMPImage.h"



HRESULT MainGame::Init()
{
	AddFontResource(TEXT("Font/Perfect DOS VGA 437.ttf")); // 폰트 추가해주는 기능

	ImageManager::GetSingleton()->Init();
	TimerManager::GetSingleton()->Init();
	SceneManager::GetSingleton()->Init();
	KeyManager::GetSingleton()->Init();
	GameManager::GetSingleton()->Init();
	// 키매니저 초기화
	Input::Init(g_hWnd);

	SceneManager::GetSingleton()->AddScene("게임씬", new GameScene());
	SceneManager::GetSingleton()->AddScene("타이틀씬", new TitleScene());


	// GDI+ 초기화
	GdiplusStartup(&g_gpToken, &g_gpsi, NULL);

	SceneManager::GetSingleton()->ChangeScene("게임씬");

	srand((unsigned int)time(nullptr));

	m_hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);


	m_backBuffer = ImageManager::GetSingleton()->FindImage("Image/mapImage.bmp");

	return S_OK;
}

void MainGame::Update()
{

	TimerManager::GetSingleton()->Update();
	Input::Update();
	SceneManager::GetSingleton()->Update();

	InvalidateRect(g_hWnd, NULL, false);

}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = m_backBuffer->GetMemDC();

	SceneManager::GetSingleton()->Render(hBackBufferDC);

	TimerManager::GetSingleton()->Render(hBackBufferDC);

	m_backBuffer->Render(hdc);

}

void MainGame::Release()
{
	TimerManager::GetSingleton()->Release();

	ImageManager::GetSingleton()->Release();

	KeyManager::GetSingleton()->Release();

	SceneManager::GetSingleton()->Release();

	GameManager::GetSingleton()->Release();

	// GDI+ 객체 종료
	GdiplusShutdown(g_gpToken);

	KillTimer(g_hWnd, 0);
}

