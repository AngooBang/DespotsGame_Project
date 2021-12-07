#pragma once
#include "GameEntity.h"

#define TILE_MAXNUM_Y 9
#define TILE_MAXNUM_X 20
#define TILE_SIZE 45







template <typename T>
class Door;
class TileMap : public GameEntity
{
	using Door = Door<TileMap>;

private:
	Image* m_wallImg = nullptr;
	Image* m_bottomImg = nullptr;


	POINT m_startPos;

	int m_wallPosX = 0;
	int m_wallPosY = 0;
	int m_wallWidth = 0;
	int m_wallHeight = 0;

	int m_bottomPosX = 0;
	int m_bottomPosY = 0;
	int m_bottomWidth = 0;
	int m_bottomHeight = 0;

	Tile node[TILE_MAXNUM_Y][TILE_MAXNUM_X];
	vector<pair<int, int>> nodeRelationShip[9];

	Door* m_leftDoor = nullptr;
	Door* m_upDoor = nullptr;
	Door* m_rightDoor = nullptr;
	Door* m_downDoor = nullptr;

	bool m_moveRoom[DoorDir::End] = { false };

public:
	HRESULT Init(POINT start);
	void Update();
	void Render(HDC hdc);
	void Release();

	void InitNode();
	void RenderNode(const HDC& hdc, Graphics& g);

	void MoveLeftRoom();
	void MoveUpRoom();
	void MoveRightRoom();
	void MoveDownRoom();

	void MoveCam(DoorDir dir);

};

