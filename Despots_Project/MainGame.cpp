#include "stdafx.h"
#include "MainGame.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "BMPImage.h"



HRESULT MainGame::Init()
{
	AddFontResource(TEXT("Font/Perfect DOS VGA 437.ttf")); // 폰트 추가해주는 기능

	KeyManager::GetSingleton()->Init();
	ImageManager::GetSingleton()->Init();
	TimerManager::GetSingleton()->Init();
	SceneManager::GetSingleton()->Init();

	SceneManager::GetSingleton()->AddScene("게임씬", new GameScene());
	SceneManager::GetSingleton()->AddScene("타이틀씬", new TitleScene());

	// GDI+ 초기화
	GdiplusStartup(&g_gpToken, &g_gpsi, NULL);

	SceneManager::GetSingleton()->ChangeScene("타이틀씬");

	srand((unsigned int)time(nullptr));

	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);


	backBuffer = ImageManager::GetSingleton()->FindImage("Image/mapImage.bmp");

	return S_OK;
}

void MainGame::Update()
{

	TimerManager::GetSingleton()->Update();
	SceneManager::GetSingleton()->Update();

	InvalidateRect(g_hWnd, NULL, false);

}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	SceneManager::GetSingleton()->Render(hBackBufferDC);


	//TimerManager::GetSingleton()->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	TimerManager::GetSingleton()->Release();
	TimerManager::GetSingleton()->ReleaseSingleton();

	ImageManager::GetSingleton()->Release();
	ImageManager::GetSingleton()->ReleaseSingleton();

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();

	SceneManager::GetSingleton()->Release();
	SceneManager::GetSingleton()->ReleaseSingleton();

	// GDI+ 객체 종료
	GdiplusShutdown(g_gpToken);

	KillTimer(g_hWnd, 0);
}

