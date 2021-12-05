#pragma once
#include "GameObject.h"
#include "Animator.h"

#define LDOOR_POS_X 160
#define LDOOR_POS_Y 345

#define UDOOR_POS_X WIN_SIZE_X / 2
#define UDOOR_POS_Y WIN_SIZE_Y / 2 - 200

#define RDOOR_POS_X LDOOR_POS_X + 945
#define RDOOR_POS_Y LDOOR_POS_Y


#define DDOOR_POS_X WIN_SIZE_X / 2
#define DDOOR_POS_Y WIN_SIZE_Y / 2 + 300

enum class DoorDir { Left, Up, Right, Down, End };

template <typename TileMap>
class Door : public GameObject
{

public:
	using callback_t = void(TileMap::*)();

	
public:
	enum class eDoorState { Idle, Hover, Click, None };
	Door(TileMap* tMap, callback_t callback)
		: GameObject()
	{
		//static_assert(is_base_of_v<Scene, SceneType>, "Button can be used in a scene");

		m_tileMap = tMap;
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
			m_doorAni->Init(L"Image/Map/Left_Door.png", POINT({pos.x - (m_width / 2), pos.y - (m_height / 2)}), m_width, m_height, 3, 0);
			m_collisionRect = { LDOOR_POS_X - (m_width / 2), LDOOR_POS_Y - (m_height / 2) + 70, LDOOR_POS_X + (m_width / 2) - 10, LDOOR_POS_Y + (m_height / 2) - 30};
			break;
		case DoorDir::Up:
			m_width = 260;
			m_height = 260;
			m_doorAni->Init(L"Image/Map/Up_Open.png", POINT({ pos.x - (m_width / 2), pos.y - (m_height / 2) }), m_width, m_height, 2, 0);
			m_collisionRect = { UDOOR_POS_X - (m_width / 2) + 30, UDOOR_POS_Y - (m_height / 2) + 50, UDOOR_POS_X + (m_width / 2) - 50, UDOOR_POS_Y + (m_height / 2) - 100 };
			break;
		case DoorDir::Right:
			m_width = 60;
			m_height = 350;
			m_doorAni->Init(L"Image/Map/Left_Door.png", POINT({ pos.x - (m_width / 2), pos.y - (m_height / 2) }), m_width, m_height, 3, 0, true);
			m_collisionRect = { RDOOR_POS_X - (m_width / 2), RDOOR_POS_Y - (m_height / 2) + 70, RDOOR_POS_X + (m_width / 2) - 10, RDOOR_POS_Y + (m_height / 2) - 30 };
			break;
		case DoorDir::Down:
			m_width = 260;
			m_height = 260;
			m_doorAni->Init(L"Image/Map/Down_Reveal.png", POINT({ pos.x - (m_width / 2), pos.y - (m_height / 2) }), m_width, m_height, 7, 0);
			m_collisionRect = { DDOOR_POS_X - (m_width / 2) + 30, DDOOR_POS_Y - (m_height / 2) + 80, DDOOR_POS_X + (m_width / 2) - 50, DDOOR_POS_Y + (m_height / 2) - 100 };
			break;
		default:
			break;
		}
		m_state = eDoorState::Idle;

		return S_OK;
	}

	virtual void Update()
	{
		switch (m_state)
		{
		case eDoorState::Idle:
			if (PtInRect(&m_collisionRect, g_ptMouse))
			{
				m_state = eDoorState::Hover;
				mb_changeState = true;
			}
			break;
		case eDoorState::Hover:
			if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_LBUTTON))
			{
				m_state = eDoorState::Click;
				mb_changeState = true;
			}
			else if (false == PtInRect(&m_collisionRect, g_ptMouse))
			{
				m_state = eDoorState::Idle;
				mb_changeState = true;
			}
			break;
		case eDoorState::Click:
			if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_LBUTTON))
			{
				if (PtInRect(&m_collisionRect, g_ptMouse))
				{
					(m_tileMap->*_callback)();
				}
			}
			if (false == PtInRect(&m_collisionRect, g_ptMouse))
			{
				m_state = eDoorState::Idle;
				mb_changeState = true;
			}
			break;
		case eDoorState::None:
			break;
		default:
			break;
		}
		switch (m_dir)
		{
		case DoorDir::Left:
			if (m_state == eDoorState::Hover)
				SAFE_UPDATE(m_doorAni);
			if (m_state == eDoorState::Idle)
				m_doorAni->DownFrame();
			break;
		case DoorDir::Up:
			if (m_state == eDoorState::Click)
				SAFE_UPDATE(m_doorAni);
			if (m_state == eDoorState::Idle)
				m_doorAni->DownFrame();
			break;
		case DoorDir::Right:
			if (m_state == eDoorState::Hover)
				m_doorAni->DownFrame();
			if (m_state == eDoorState::Idle)
				SAFE_UPDATE(m_doorAni);
			break;
		case DoorDir::Down:
			if (m_state == eDoorState::Hover)
				SAFE_UPDATE(m_doorAni);
			if (m_state == eDoorState::Idle)
			{
				if(mb_changeState)
					m_doorAni->ChangeImg(L"Image/Map/Down_Reveal.png", 7, 0, 7);
				mb_changeState = false;
				m_doorAni->DownFrame();
			}
			if (m_state == eDoorState::Click)
			{
				if(mb_changeState)
					m_doorAni->ChangeImg(L"Image/Map/Up_Open.png", 2, 0, 0);
				mb_changeState = false;
				SAFE_UPDATE(m_doorAni);
			}
			break;

		}
	}
	virtual void Render(HDC hdc)
	{
		//Rectangle(hdc, m_collisionRect.left, m_collisionRect.top, m_collisionRect.right, m_collisionRect.bottom);
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
	bool mb_changeState = false;
	DoorDir m_dir = DoorDir::End;
	RECT m_collisionRect = {};
	

	Animator* m_doorAni = nullptr;
};