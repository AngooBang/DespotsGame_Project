#pragma once
#include "GameObject.h"

enum class CState { Idle, Move, Attack, Hit, End };

class Animator;
class Character : public GameObject
{
private:
	Animator* m_idleAni = nullptr;

	CState m_state = CState::End;

	int m_width = 0;
	int m_height = 0;

public:
	virtual HRESULT Init(POINT pos);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void Drop();
};

