#pragma once
#include "GameObject.h"
#include "Animator.h"

#define LDOOR_POS_X 160
#define LDOOR_POS_Y 345

enum class DoorDir { Left, Up, Right, Down, End };

template <typename TileMap>
class Door : public GameObject
{

public:
	using callback_t = void(TileMap::*)();

	
public:
	enum class eDoorState { Idle, Hover, Click, None };
	Door(TileMap* scene, callback_t callback)
		: GameObject()
	{
		//static_assert(is_base_of_v<Scene, SceneType>, "Button can be used in a scene");

		m_tileMap = scene;
		_callback = callback;
	}
	virtual ~Door() = default;


	virtual HRESULT Init(DoorDir dir, POINT pos)
	{
		m_pos = pos;
		m_dir = dir;
		m_doorAni = new Animator();
		switch (m_dir)
		{
		case DoorDir::Left:
			m_width = 60;
			m_height = 350;
			m_doorAni->Init(L"Image/Map/Left_Door.png", POINT({pos.x - (m_width / 2), pos.y - (m_height / 2)}), m_width, m_height, 3, 0, false);
			break;
		default:
			break;
		}
		m_state = eDoorState::Idle;
		collisionRect = { LDOOR_POS_X - (m_width / 2), LDOOR_POS_Y - (m_height / 2), LDOOR_POS_X + (m_width / 2), LDOOR_POS_Y + (m_height / 2) };

		return S_OK;
	}

	virtual void Update()
	{
		switch (m_state)
		{
		case eDoorState::Idle:
			if (PtInRect(&collisionRect, g_ptMouse))
				m_state = eDoorState::Hover;
			break;
		case eDoorState::Hover:
			if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_LBUTTON))
				m_state = eDoorState::Click;
			else if (false == PtInRect(&collisionRect, g_ptMouse))
				m_state = eDoorState::Idle;
			break;
		case eDoorState::Click:
			if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_LBUTTON))
			{
				if (PtInRect(&collisionRect, g_ptMouse))
				{
					(m_tileMap->*_callback)();
				}
				m_state = eDoorState::Idle;
			}
			break;
		case eDoorState::None:
			break;
		default:
			break;
		}

		if(m_state == eDoorState::Hover)
			SAFE_UPDATE(m_doorAni);
		if (m_state == eDoorState::Idle)
			m_doorAni->DownFrame();
	}
	virtual void Render(HDC hdc)
	{
		m_doorAni->Render(hdc);
	}
	virtual void Release()
	{
		SAFE_RELEASE(m_doorAni);
	}


private:
	TileMap* m_tileMap;
	callback_t _callback;

	eDoorState m_state = eDoorState::None;

	int m_width, m_height = 0;
	DoorDir m_dir = DoorDir::End;
	RECT collisionRect = {};

	Animator* m_doorAni = nullptr;
};