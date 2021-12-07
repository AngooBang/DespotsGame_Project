#include "stdafx.h"
#include "CharacterManager.h"
#include "Character.h"
#include "TileMap.h"

void CharacterManager::Init()
{
}

void CharacterManager::Update()
{
	for (auto iter : m_vecChar)
	{
		iter->Update();
	}
}

void CharacterManager::Render(HDC hdc)
{
	for (auto iter : m_vecChar)
	{
		iter->Render(HDC hdc);
	}
}

void CharacterManager::Release()
{
	for (auto iter : m_vecChar)
	{
		iter->Release();
	}
}

void CharacterManager::AddChar(Tile& tile)
{
	Character* newChar = new Character;

	newChar->Init({tile.pos.x + TILE_SIZE / 2, tile.pos.y + TILE_SIZE / 2});

	tile.smallNode[0][1] = tile.smallNode[1][0] = tile.smallNode[1][1] = tile.smallNode[1][2] = tile.smallNode[2][1] = true;
	m_vecChar.push_back(newChar);
}
