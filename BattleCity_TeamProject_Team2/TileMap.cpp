#include "TileMap.h"
#include "Image.h"

HRESULT TileMap::Init()
{
	wallImg = ImageManager::GetSingleton()->FindImage("Image/Map/Wall.bmp");
	bottomImg = ImageManager::GetSingleton()->FindImage("Image/Map/Bottom.bmp");

	leftDoorFrame = ImageManager::GetSingleton()->FindImage("Image/Map/Door_LeftFrame.bmp");

	InitNode();

	return S_OK;
}

void TileMap::Update()
{
}

void TileMap::Render(HDC hdc)
{
	wallImg->Render(hdc, WALLIMG_POS_X, WALLIMG_POS_Y);

	RenderNode(hdc);

	leftDoorFrame->Render(hdc, LEFT_DOOR_POS_X, LEFT_DOOR_POS_Y);
	
	bottomImg->Render(hdc, BOTTOMIMG_POS_X, BOTTOMIMG_POS_Y);
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
			node[i][j].pos.x = WALLIMG_POS_X - 500 + (NODE_SIZE / 2) + j * NODE_SIZE;
			node[i][j].pos.y = WALLIMG_POS_Y + 100 + (NODE_SIZE / 2) + i * NODE_SIZE;


			node[i][j].shape.left = node[i][j].pos.x - (NODE_SIZE / 2);
			node[i][j].shape.right = node[i][j].pos.x + (NODE_SIZE / 2);
			node[i][j].shape.top = node[i][j].pos.y - (NODE_SIZE / 2);
			node[i][j].shape.bottom = node[i][j].pos.y + (NODE_SIZE / 2);

			node[i][j].img = ImageManager::GetSingleton()->FindImage("Image/Map/Ground_0.bmp");
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
