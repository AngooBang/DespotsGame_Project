#pragma once
#include "Config.h"
#include "GameEntity.h"



// �츮�� ������ ���� ����
class Image;
class MainGame : public GameEntity
{
private:
	// Ÿ�̸�
	HANDLE hTimer;

	int clickedMousePosX;
	int clickedMousePosY;

	// �����
	Image* backBuffer;


public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);	// �����ε�
	void Release();

};
