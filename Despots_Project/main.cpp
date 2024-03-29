// main.cpp

#include "stdafx.h"
#include "MainGame.h"
#include "resource.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// 전역변수
POINT		g_ptMouse;
HINSTANCE	g_hInstance;
HWND		g_hWnd;
LPWSTR		g_lpszClass = (LPWSTR)TEXT("Despot's Game");
MainGame	g_mainGame;
WNDCLASS g_wndClass;

ULONG_PTR g_gpToken;
GdiplusStartupInput g_gpsi;




void SetWindowSize(int startX, int startY, int sizeX, int sizeY);

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance,
	LPWSTR _lpszCmdParam, int nCmdShow)
{


	// 윈도우를 생성하기 위한 기본 셋팅
	g_hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 핸들형변환
	wndClass.hCursor = LoadCursor(_hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = WndProc;				// 함수포인터(콜백함수)
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = g_lpszClass;
	wndClass.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;	// bit연산
	
	g_wndClass = wndClass;

	// 윈도우 클래스 등록
	RegisterClass(&wndClass);

	// 윈도우 생성
	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW,
		WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y,
		NULL, NULL, _hInstance, NULL);

	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y,
		WIN_SIZE_X, WIN_SIZE_Y);


	// 메인게임 초기화
	g_mainGame.Init();
	

	// 윈도우 출력
	ShowWindow(g_hWnd, nCmdShow);


	// 메시지 큐에 있는 메시지 처리
	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	// 메인게임 해제
	g_mainGame.Release();


	return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	static bool isUpdate = true;

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			//isUpdate = !isUpdate;
			break;
		}
		break;
	case WM_TIMER:
		if (isUpdate)
		{
			g_mainGame.Update();
		}

		break;
	case WM_PAINT:		// 윈도우 화면이 다시 그려지는 경우 발생하는 메시지
		hdc = BeginPaint(g_hWnd, &ps);

		// 윈도우 창 크기 조절 해주기
		RECT rect;
		SetMapMode(hdc, MM_ANISOTROPIC);
		SetWindowExtEx(hdc, WIN_SIZE_X, WIN_SIZE_Y, NULL);
		GetClientRect(g_hWnd, &rect);
		SetViewportExtEx(hdc, rect.right, rect.bottom, NULL);

		g_mainGame.Render(hdc);

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:	// 닫기 버튼 메시지처리 (프로그램 종료)
		PostQuitMessage(0);
		break;

	case WM_MOUSEMOVE:
		g_ptMouse.x = LOWORD(lParam);
		g_ptMouse.y = HIWORD(lParam);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
