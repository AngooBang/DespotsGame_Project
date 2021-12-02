#pragma once
#include "GameObject.h"

template <typename SceneType>
class Button : public GameObject
{
public:
	using scene_t = SceneType;
	using callback_t = void(SceneType::*)();

public:
	enum class eButtonState { Idle, Hover, Click, None, };
	Button(scene_t* scene, callback_t callback)
		: GameObject()
	{
		static_assert(is_base_of_v<Scene, SceneType>, "Button can be used in a scene");

		_scene = scene;
		_callback = callback;
	}
	virtual ~Button() = default;

	HRESULT Init(ButtonType type, POINT pos, int sizeX, int sizeY, const WCHAR* name = {})
	{
		
		switch (type)
		{
		case ButtonType::Normal:
			buttonPutImage = FROM_FILE(L"Image/Title/Normal_Hover.png");
			buttonClickImage = FROM_FILE(L"Image/TItle/Normal_Active.png");
			imgCorrectionValue = 40;
			break;
		default:
			break;
		}
		this->pos = pos;
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->state = eButtonState::Idle;
		this->buttonName = name;

		renderPos = { pos.x - (sizeX / 2), pos.y - (sizeY / 2) };
		collisionRect = { renderPos.X, renderPos.Y, pos.x + (sizeX / 2), pos.y + (sizeY / 2) };

		return S_OK;
	}

	virtual void Update() override
	{
		switch (state)
		{
		case Button::eButtonState::Idle:
			if (PtInRect(&collisionRect, g_ptMouse))
				state = eButtonState::Hover;
			break;
		case Button::eButtonState::Hover:
			if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_LBUTTON))
				state = eButtonState::Click;
			else if (false == PtInRect(&collisionRect, g_ptMouse))
				state = eButtonState::Idle;
			break;
		case Button::eButtonState::Click:
			if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_LBUTTON))
			{
				if (PtInRect(&collisionRect, g_ptMouse))
				{
					//(*scene.*buttonFunction)();
					(_scene->*_callback)();
				}
				state = eButtonState::Idle;
			}
			break;
		case Button::eButtonState::None:
			break;
		default:
			break;
		}
	}

	virtual void Render(HDC hdc) override
	{
		Graphics g(hdc);

		// 확대 시 계단현상 제거 (안티앨리어싱 모드 변경)
		g.SetInterpolationMode(InterpolationModeNearestNeighbor);

		Font eng(L"Perfect DOS VGA 437", 20);
		Font kor(L"Noto Sans CJK JP Regular", 20);
		Font font(L"반달", 25);
		SolidBrush idleBrush(Color(111, 107, 128));
		SolidBrush hoverBrush(Color(111, 107, 128));
		SolidBrush clickBrush(Color(111, 107, 128));
		PointF posf = { (FLOAT)pos.x, (FLOAT)pos.y };

		StringFormat SF;

		SF.SetAlignment(StringAlignmentCenter);
		SF.SetLineAlignment(StringAlignmentCenter);

		switch (state)
		{
		case Button::eButtonState::Idle:
			g.DrawImage(buttonIdleImage, renderPos.X, renderPos.Y, sizeX, sizeY);			
			g.DrawString(buttonName, -1, &font, posf, &SF, &idleBrush);
			break;
		case Button::eButtonState::Hover:
			g.DrawImage(buttonPutImage, renderPos.X, renderPos.Y, sizeX, sizeY);
			g.DrawString(buttonName, -1, &font, posf, &SF, &hoverBrush);
			break;
		case Button::eButtonState::Click:
			g.DrawImage(buttonClickImage, renderPos.X-(imgCorrectionValue / 2), renderPos.Y-(imgCorrectionValue / 2 / 2), sizeX + (imgCorrectionValue), sizeY + (imgCorrectionValue / 2));
			g.DrawString(buttonName, -1, &font, posf, &SF, &clickBrush);
			break;
		case Button::eButtonState::None:
		default:
			break;
		}
	}

	virtual void Release() override
	{

	}

private:
	scene_t* _scene;
	callback_t _callback;

	POINT pos = {};
	int sizeX = 0;
	int sizeY = 0;
	Image* buttonIdleImage = nullptr;
	Image* buttonPutImage = nullptr;
	Image* buttonClickImage = nullptr;
	int imgCorrectionValue = 0;
	const WCHAR* buttonName = nullptr;
	
	eButtonState state = eButtonState::None;

	Point renderPos = {};
	RECT collisionRect = {};

};