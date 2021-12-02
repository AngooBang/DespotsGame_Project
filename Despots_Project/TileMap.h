#pragma once
#include "GameEntity.h"

#define WALLIMG_POS_X WIN_SIZE_X / 2
#define WALLIMG_POS_Y WIN_SIZE_Y / 2  - 220


#define NODE_MAXNUM_Y 9
#define NODE_MAXNUM_X 20
#define NODE_SIZE 45

#define BOTTOMIMG_POS_X WIN_SIZE_X / 2
#define BOTTOMIMG_POS_Y WALLIMG_POS_Y + 90 + NODE_SIZE * NODE_MAXNUM_Y 

#define LEFT_DOOR_POS_X 175
#define LEFT_DOOR_POS_Y WIN_SIZE_Y / 2 + 80


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

// 질문 2. 그래픽 자료구조의 구현이 이런식이 맞는건지
// 질문 3. 맵이동 알고리즘에 대해

class TileMap : public GameEntity
{
private:
	BMPImage* wallImg;
	BMPImage* bottomImg;
	BMPImage* tilemapImg;

	BMPImage* leftDoorFrame;

	int wallImgPosX, wallImgPosY;



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

