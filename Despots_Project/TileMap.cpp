#include "stdafx.h"
#include "TileMap.h"
#include "BMPImage.h"

HRESULT TileMap::Init(POINT start)
{
	wallImg = ImageManager::GetSingleton()->FindImage("Image/Map/Wall.bmp");
	bottomImg = ImageManager::GetSingleton()->FindImage("Image/Map/Bottom.bmp");


	m_startPos = start;

	wallPosX = m_startPos.x + wallImg->GetImageInfo()->width / 2;
	wallPosY = m_startPos.y + wallImg->GetImageInfo()->height / 2;

	bottomPosX = m_startPos.x + bottomImg->GetImageInfo()->width / 2;
	bottomPosY = m_startPos.y + wallImg->GetImageInfo()->height + NODE_SIZE * NODE_MAXNUM_Y
				+ bottomImg->GetImageInfo()->height / 2;



	InitNode();

	return S_OK;
}

void TileMap::Update()
{
}

void TileMap::Render(HDC hdc)
{
	wallImg->Render(hdc, wallPosX, wallPosY);

	RenderNode(hdc);

	
	bottomImg->Render(hdc, bottomPosX, bottomPosY);
}

void TileMap::Release()
{
}

void TileMap::InitNode()
{
	for (int i = 0; i < NODE_MAXNUM_Y; ++i)
	{
		for (int j = 0; j < NODE_MAXNUM_X; ++j)
		{
			node[i][j].img = ImageManager::GetSingleton()->FindImage("Image/Map/Ground_0.bmp");

			node[i][j].pos.x = m_startPos.x + (NODE_SIZE / 2) + j * NODE_SIZE;
			node[i][j].pos.y = m_startPos.y + wallImg->GetImageInfo()->height
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
			node[i][j].img->Render(hdc, node[i][j].pos.x, node[i][j].pos.y);
		}
	}
}
