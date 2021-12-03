#include "stdafx.h"
#include "FullMap.h"
#include "TileMap.h"

HRESULT FullMap::Init()
{
	m_room1 = new TileMap;
	m_room2 = new TileMap;
	m_room3 = new TileMap;
	m_room4 = new TileMap;

	m_room1->Init(POINT({ 180, 70 }));
	m_room2->Init(POINT({ 1180, 70 }));
	m_room3->Init(POINT({ 180, 1070 }));
	m_room4->Init(POINT({ 1180, 1070 }));
	

	return S_OK;
}

void FullMap::Update()
{
	SAFE_UPDATE(m_room1);
	SAFE_UPDATE(m_room2);
	SAFE_UPDATE(m_room3);
	SAFE_UPDATE(m_room4);
}

void FullMap::Render(HDC hdc)
{
	m_room1->Render(hdc);
	m_room2->Render(hdc);
	m_room3->Render(hdc);
	m_room4->Render(hdc);
}

void FullMap::Release()
{
	SAFE_RELEASE(m_room1);
	SAFE_RELEASE(m_room2);
	SAFE_RELEASE(m_room3);
	SAFE_RELEASE(m_room4);
}
