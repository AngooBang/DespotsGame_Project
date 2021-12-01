#include "MainGame.h"
#include "Image.h"
#include "GameScene.h"
#include "TitleScene.h"



HRESULT MainGame::Init()
{

	AddFontResource("Font/Perfect DOS VGA 437.ttf"); // ��Ʈ �߰�.

	KeyManager::GetSingleton()->Init();
	ImageManager::GetSingleton()->Init();
	TimerManager::GetSingleton()->Init();
	SceneManager::GetSingleton()->Init();

	SceneManager::GetSingleton()->AddScene("���Ӿ�", new GameScene());
	SceneManager::GetSingleton()->AddScene("Ÿ��Ʋ��", new TitleScene());


	SceneManager::GetSingleton()->ChangeScene("Ÿ��Ʋ��");

	srand((unsigned int)time(nullptr));
	// Ÿ�̸� ����
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	// �����
	backBuffer = new Image;
	backBuffer->Init("Image/mapImage.bmp", WIN_SIZE_X, WIN_SIZE_Y);

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
	SAFE_RELEASE(backBuffer);

	TimerManager::GetSingleton()->Release();
	TimerManager::GetSingleton()->ReleaseSingleton();

	ImageManager::GetSingleton()->Release();
	ImageManager::GetSingleton()->ReleaseSingleton();

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();

	SceneManager::GetSingleton()->Release();
	SceneManager::GetSingleton()->ReleaseSingleton();

	KillTimer(g_hWnd, 0);
}

