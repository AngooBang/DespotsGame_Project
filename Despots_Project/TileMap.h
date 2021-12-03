#pragma once
#include "GameEntity.h"

#define NODE_MAXNUM_Y 9
#define NODE_MAXNUM_X 20
#define NODE_SIZE 45



enum class TILE_TYPE { Normal, Wall, End };



struct Node
{
	RECT shape;
	POINT pos;
	BMPImage* img;
	//int frameX;
	//int frameY;
	TILE_TYPE type;
};


class TileMap : public GameEntity
{
private:
	BMPImage* wallImg;
	BMPImage* bottomImg;
	BMPImage* tilemapImg;


	POINT m_startPos;


	int wallPosX, wallPosY;
	int bottomPosX, bottomPosY;



	Node node[NODE_MAXNUM_Y][NODE_MAXNUM_X];

	vector<pair<int, int>> nodeRelationShip[9];

public:
	HRESULT Init(POINT start);
	void Update();
	void Render(HDC hdc);
	void Release();

	void InitNode();
	void RenderNode(const HDC& hdc);


};

