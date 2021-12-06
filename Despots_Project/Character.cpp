#include "stdafx.h"
#include "Character.h"
#include "Animator.h"

HRESULT Character::Init()
{
	m_idleAni = new Animator;
	m_pos = { 300, 500 };
	m_width = 40;
	m_height = 90;
	m_idleAni->Init(L"Image/Character/Normal/Normal_Idle.png", { m_pos.x - (m_width / 2), m_pos.y - (m_height / 2) }, m_width, m_height, 5, 0, false, true, 0.15f);
	m_state = CState::Idle;
	return S_OK;
}

void Character::Update()
{
	SAFE_UPDATE(m_idleAni);
}

void Character::Render(HDC hdc)
{
	m_idleAni->Render(hdc);
}

void Character::Release()
{
	SAFE_RELEASE(m_idleAni);
}

void Character::Drop()
{
}
