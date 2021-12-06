#pragma once
#include "GameEntity.h"

#define ROOM_DISTANCE_X 1140
#define ROOM_DISTANCE_Y 700

#define START_ROOM_X 180
#define START_ROOM_Y 70

class TileMap;
class FullMap : public GameEntity
{
public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

private:
	TileMap* m_room1;
	TileMap* m_room2;
	TileMap* m_room3;
	TileMap* m_room4;
};

