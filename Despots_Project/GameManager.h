#pragma once
#include "Singleton.h"

class TileMap;
class GameManager : public Singleton<GameManager>
{
	
public:
	void Init();
	void Update();
	void Release();

	inline void SetTileMap(TileMap* tileMap) { m_tilemap = tileMap; }

private:
	TileMap* m_tilemap = nullptr;
};

