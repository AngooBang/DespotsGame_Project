#pragma once
#include "GameEntity.h"

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

