#pragma once
#include "GameEntity.h"

#define NODE_MAXNUM_Y 9
#define NODE_MAXNUM_X 20
#define NODE_SIZE 45


enum class TILE_TYPE { Normal, Wall, End };



typedef struct Node
{
	RECT shape;
	POINT pos;
	BMPImage* img;
	//int frameX;
	//int frameY;
	TILE_TYPE type;
}*LPNode;

template <typename T>
class Door;
class TileMap : public GameEntity
{
	using Door = Door<TileMap>;

private:
	BMPImage* m_wallImg = nullptr;
	BMPImage* m_bottomImg = nullptr;
	BMPImage* m_tilemapImg = nullptr;


	POINT m_startPos;

	int m_wallPosX = 0;
	int m_wallPosY = 0;

	int m_bottomPosX = 0;
	int m_bottomPosY = 0;

	Node node[NODE_MAXNUM_Y][NODE_MAXNUM_X];
	vector<pair<int, int>> nodeRelationShip[9];

	Door* m_leftDoor = nullptr;
	Door* m_upDoor = nullptr;
	Door* m_rightDoor = nullptr;
	Door* m_downDoor = nullptr;

public:
	HRESULT Init(POINT start);
	void Update();
	void Render(HDC hdc);
	void Release();

	void InitNode();
	void RenderNode(const HDC& hdc);

	void MoveLeftRoom();
	void MoveUpRoom();
	void MoveRightRoom();
	void MoveDownRoom();


};

