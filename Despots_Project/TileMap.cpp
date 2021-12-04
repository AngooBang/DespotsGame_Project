#include "stdafx.h"
#include "TileMap.h"
#include "BMPImage.h"
#include "Door.h"

HRESULT TileMap::Init(POINT start)
{
	m_wallImg = ImageManager::GetSingleton()->FindImage("Image/Map/Wall.bmp");
	m_bottomImg = ImageManager::GetSingleton()->FindImage("Image/Map/Bottom.bmp");


	m_startPos = start;

	m_wallPosX = m_startPos.x + m_wallImg->GetImageInfo()->width / 2;
	m_wallPosY = m_startPos.y + m_wallImg->GetImageInfo()->height / 2;

	m_bottomPosX = m_startPos.x + m_bottomImg->GetImageInfo()->width / 2;
	m_bottomPosY = m_startPos.y + m_wallImg->GetImageInfo()->height + NODE_SIZE * NODE_MAXNUM_Y
				+ m_bottomImg->GetImageInfo()->height / 2;

	m_leftDoor = new Door(this, &TileMap::MoveLeftRoom);
	
	m_leftDoor->Init(DoorDir::Left, POINT({ m_startPos.x - 20, m_startPos.y + m_wallImg->GetImageInfo()->height + (NODE_SIZE * 3) }));
	//m_leftDoor->Init(DoorDir::Left, POINT({ LDOOR_POS_X, LDOOR_POS_Y }));


	InitNode();

	return S_OK;
}

void TileMap::Update()
{
	SAFE_UPDATE(m_leftDoor);
}

void TileMap::Render(HDC hdc)
{
	m_wallImg->Render(hdc, m_wallPosX + CAMERA_VIEW_X, m_wallPosY + CAMERA_VIEW_Y);

	RenderNode(hdc);

	m_leftDoor->Render(hdc);

	
	m_bottomImg->Render(hdc, m_bottomPosX + CAMERA_VIEW_X, m_bottomPosY + CAMERA_VIEW_Y);
}

void TileMap::Release()
{
	SAFE_RELEASE(m_leftDoor);
}

void TileMap::InitNode()
{
	for (int i = 0; i < NODE_MAXNUM_Y; ++i)
	{
		for (int j = 0; j < NODE_MAXNUM_X; ++j)
		{
			node[i][j].img = ImageManager::GetSingleton()->FindImage("Image/Map/Ground_0.bmp");

			node[i][j].pos.x = m_startPos.x + (NODE_SIZE / 2) + j * NODE_SIZE;
			node[i][j].pos.y = m_startPos.y + m_wallImg->GetImageInfo()->height
				+ (NODE_SIZE / 2) + i * NODE_SIZE;


			node[i][j].shape.left = node[i][j].pos.x - (NODE_SIZE / 2);
			node[i][j].shape.right = node[i][j].pos.x + (NODE_SIZE / 2);
			node[i][j].shape.top = node[i][j].pos.y - (NODE_SIZE / 2);
			node[i][j].shape.bottom = node[i][j].pos.y + (NODE_SIZE / 2);

		}
	}

}

void TileMap::RenderNode(const HDC& hdc)
{
	for (int i = 0; i < NODE_MAXNUM_Y; ++i)
	{
		for (int j = 0; j < NODE_MAXNUM_X; ++j)
		{
			node[i][j].img->Render(hdc, node[i][j].pos.x + CAMERA_VIEW_X, node[i][j].pos.y + CAMERA_VIEW_Y);
		}
	}
}

void TileMap::MoveLeftRoom()
{
}
