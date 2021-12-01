#pragma once
#include "GameEntity.h"

#define WALLIMG_POS_X WIN_SIZE_X / 2
#define WALLIMG_POS_Y WIN_SIZE_Y / 2  - 270


#define NODE_MAXNUM_Y 9
#define NODE_MAXNUM_X 20
#define NODE_SIZE 50

#define BOTTOMIMG_POS_X WIN_SIZE_X / 2
#define BOTTOMIMG_POS_Y WALLIMG_POS_Y + 125 + NODE_SIZE * NODE_MAXNUM_Y 

#define LEFT_DOOR_POS_X 185
#define LEFT_DOOR_POS_Y WIN_SIZE_Y / 2 + 80


enum class TILE_TYPE { Normal, Wall, NM, End };



struct Node
{
	RECT shape;
	POINTFLOAT pos;
	Image* img;
	//int frameX;
	//int frameY;
	TILE_TYPE type;
};


class TileMap : public GameEntity
{
private:
	Image* wallImg;
	Image* bottomImg;
	Image* tilemapImg;

	Image* leftDoorFrame;


	Node node[NODE_MAXNUM_Y][NODE_MAXNUM_X];

	//vector<int> nodeRelation[9];

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void InitNode();
	void RenderNode(const HDC& hdc);


};

