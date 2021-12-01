#pragma once
#include "GameEntity.h"
class Scene : public GameEntity
{

public:
	virtual HRESULT Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

