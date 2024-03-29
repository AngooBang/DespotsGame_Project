#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"

Scene* SceneManager::currScene = nullptr;
Scene* SceneManager::readyScene = nullptr;
Scene* SceneManager::loadingScene = nullptr;

DWORD CALLBACK LoadingThread(LPVOID pvParam)
{
	// 레디씬을 초기화한다.
	SceneManager::readyScene->Init();
	SceneManager::currScene = SceneManager::readyScene;

	SceneManager::loadingScene->Release();
	SceneManager::loadingScene = nullptr;
	SceneManager::readyScene = nullptr;

	return 0;
}

void SceneManager::Init()
{


}

void SceneManager::Update()
{
	if (currScene)
		currScene->Update();
}

void SceneManager::Render(HDC hdc)
{
	if (currScene)
		currScene->Render(hdc);
}

void SceneManager::Release()
{
}

void SceneManager::AddScene(string key, Scene* scene)
{
	if (scene == nullptr) return;

	if (mapScenes.find(key) != mapScenes.end())
	{
		return;
	}

	mapScenes.insert(pair<string, Scene*>(key, scene));

}

void SceneManager::AddLoadingScene(string key, Scene* scene)
{
	if (scene == nullptr) return;

	if (mapLoadingScenes.find(key) != mapLoadingScenes.end())
	{
		return;
	}

	mapLoadingScenes.insert(pair<string, Scene*>(key, scene));

}

HRESULT SceneManager::ChangeScene(string sceneName)
{
	map<string, Scene*>::iterator it = mapScenes.find(sceneName);

	if (it == mapScenes.end())
		return E_FAIL;

	if (SUCCEEDED((it->second)->Init()))
	{
		if (currScene)
			currScene->Release();
		currScene = it->second;

		return S_OK;
	}

	return E_FAIL;

}

//HRESULT SceneManager::ChangeScene(string sceneName, string loadingSceneName)
//{
//	map<string, GameEntity*>::iterator it = mapScenes.find(sceneName);
//
//	if (it == mapScenes.end())
//		return E_FAIL;
//
//	//로딩씬 확인
//	map<string, GameEntity*>::iterator itLoading = mapLoadingScenes.find(loadingSceneName);
//	if (itLoading == mapLoadingScenes.end())
//	{
//		return ChangeScene(sceneName);
//	}
//
//	// 로딩씬 있을 때
//	if (SUCCEEDED((itLoading->second)->Init()))
//	{
//		if (currScene)
//			currScene->Release();
//
//		readyScene = it->second;
//		loadingScene = itLoading->second;
//
//		currScene = loadingScene;
//
//		// 멀티쓰레드 처리
//		DWORD loadThread;
//		HANDLE hThread = CreateThread(NULL, 0,
//			LoadingThread/*실행시킬 함수 포인터(함수이름)*/,
//			NULL /*실행시킬 함수에 들어갈 매개변수*/,
//			0, &loadThread /*쓰레드의 주소를 저장할 변수*/);
//
//		CloseHandle(hThread);
//
//		return S_OK;
//	}
//
//	return E_FAIL;
//}
