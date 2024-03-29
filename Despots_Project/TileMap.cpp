#include "stdafx.h"
#include "TileMap.h"
#include "BMPImage.h"
#include "Door.h"
#include "FullMap.h"

HRESULT TileMap::Init(POINT start)
{
	m_wallImg = FROM_FILE(L"Image/Map/Wall.bmp");
	m_bottomImg = FROM_FILE(L"Image/Map/Bottom.bmp");


	m_startPos = start;

	m_wallPosX = m_startPos.x;
	m_wallPosY = m_startPos.y;

	m_wallWidth = 900;
	m_wallHeight = 140;


	m_bottomPosX = m_startPos.x;
	m_bottomPosY = m_startPos.y + m_wallHeight + TILE_SIZE * TILE_MAXNUM_Y;

	m_bottomWidth = 900;
	m_bottomHeight = 50;


	m_leftDoor = new Door(this, &TileMap::MoveLeftRoom);
	m_upDoor = new Door(this, &TileMap::MoveUpRoom);
	m_rightDoor = new Door(this, &TileMap::MoveRightRoom);
	m_downDoor = new Door(this, &TileMap::MoveDownRoom);
	m_leftDoor->Init(DoorDir::Left, POINT({ m_startPos.x - 20, m_startPos.y + m_wallHeight + (TILE_SIZE * 3) }));
	m_upDoor->Init(DoorDir::Up, POINT({ m_wallPosX + (m_wallWidth / 2), m_wallPosY + (m_wallHeight / 2) - 17}));
	m_rightDoor->Init(DoorDir::Right, POINT({ m_startPos.x + m_wallWidth + 20, m_startPos.y + m_wallHeight + (TILE_SIZE * 3) }));
	m_downDoor->Init(DoorDir::Down, POINT({ m_bottomPosX + (m_bottomWidth / 2), m_bottomPosY - 25}));


	InitNode();

	return S_OK;
}

void TileMap::Update()
{
	SAFE_UPDATE(m_leftDoor);
	SAFE_UPDATE(m_upDoor);
	SAFE_UPDATE(m_rightDoor);
	SAFE_UPDATE(m_downDoor);


	if (m_moveRoom[DoorDir::Left])
		MoveCam(DoorDir::Left);
	if(m_moveRoom[DoorDir::Up])
		MoveCam(DoorDir::Up);
	if (m_moveRoom[DoorDir::Right])
		MoveCam(DoorDir::Right);
	if (m_moveRoom[DoorDir::Down])
		MoveCam(DoorDir::Down);

}

void TileMap::Render(HDC hdc)
{
	Graphics g(hdc);
	g.DrawImage(m_wallImg, m_wallPosX + CAMERA_VIEW_X, m_wallPosY + CAMERA_VIEW_Y, m_wallWidth, m_wallHeight);

	RenderNode(hdc, g);
	g.DrawImage(m_bottomImg, m_bottomPosX + CAMERA_VIEW_X, m_bottomPosY + CAMERA_VIEW_Y, m_bottomWidth, m_bottomHeight);

	m_leftDoor->Render(hdc);
	m_upDoor->Render(hdc);
	m_rightDoor->Render(hdc);
	m_downDoor->Render(hdc);

	
}

void TileMap::Release()
{
	SAFE_RELEASE(m_leftDoor);
	SAFE_RELEASE(m_upDoor);
	SAFE_RELEASE(m_rightDoor);
	SAFE_RELEASE(m_downDoor);
}

void TileMap::InitNode()
{
	for (int i = 0; i < TILE_MAXNUM_Y; ++i)
	{
		for (int j = 0; j < TILE_MAXNUM_X; ++j)
		{
			node[i][j].img = FROM_FILE(L"Image/Map/Ground_0.bmp");

			node[i][j].pos.x = m_startPos.x +  j * TILE_SIZE;
			node[i][j].pos.y = m_startPos.y + m_wallHeight + i * TILE_SIZE;

			
			node[i][j].shape.left = node[i][j].pos.x - (TILE_SIZE / 2);
			node[i][j].shape.right = node[i][j].pos.x + (TILE_SIZE / 2);
			node[i][j].shape.top = node[i][j].pos.y - (TILE_SIZE / 2);
			node[i][j].shape.bottom = node[i][j].pos.y + (TILE_SIZE / 2);

		}
	}
}

void TileMap::RenderNode(const HDC& hdc, Graphics& g)
{
	for (int i = 0; i < TILE_MAXNUM_Y; ++i)
	{
		for (int j = 0; j < TILE_MAXNUM_X; ++j)
		{
			g.DrawImage(node[i][j].img, node[i][j].pos.x + CAMERA_VIEW_X, node[i][j].pos.y + CAMERA_VIEW_Y, TILE_SIZE, TILE_SIZE);
		}
	}
}

void TileMap::MoveLeftRoom()
{
	m_moveRoom[DoorDir::Left] = true;
}


void TileMap::MoveUpRoom()
{
	m_moveRoom[DoorDir::Up] = true;
}

void TileMap::MoveRightRoom()
{
	m_moveRoom[DoorDir::Right] = true;
}

void TileMap::MoveDownRoom()
{
	m_moveRoom[DoorDir::Down] = true;
}

void TileMap::MoveCam(DoorDir dir)
{
	static int moveCamera = 0;
	if (dir == DoorDir::Left || dir == DoorDir::Right)
	{
		if (moveCamera <= ROOM_DISTANCE_X)
		{
			moveCamera += 10;
			switch (dir)
			{
			case DoorDir::Left:
				CameraManager::GetSingleton()->SetCameraPos({ -10, 0 });
				break;
			case DoorDir::Right:
				CameraManager::GetSingleton()->SetCameraPos({ 10, 0 });
				break;
			}
		}
		else
		{
			m_moveRoom[dir] = false;
			moveCamera = 0;
		}
	}
	else if (dir == DoorDir::Up || dir == DoorDir::Down)
	{
		if (moveCamera <= ROOM_DISTANCE_Y)
		{
			moveCamera += 10;
			switch (dir)
			{
			case DoorDir::Up:
				CameraManager::GetSingleton()->SetCameraPos({ 0, -10 });
				break;
			case DoorDir::Down:
				CameraManager::GetSingleton()->SetCameraPos({ 0, 10 });
				break;
			}
		}
		else
		{
			m_moveRoom[dir] = false;
			moveCamera = 0;
		}
	}
}