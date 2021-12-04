#pragma once
#include "GameEntity.h"
class Animator : public GameEntity
{
public:
	Animator() = default;
	~Animator() = default;

	virtual HRESULT Init(const WCHAR* path, POINT pos, int renderSizeX, int renderSizeY, int maxFrameX, int maxFrameY, bool isLoop = false, float motionSpeed = 0.05f, float scale = 1.0f);
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	void DownFrame();
private:
	Image* m_img = nullptr;
	POINT m_renderPos;
	int m_renderSizeX;
	int m_renderSizeY;
	
	const WCHAR* m_path = nullptr;

	float m_animationElapsed = 0.0f;
	float m_motionSpeed = 0.0f;

	int m_maxFrameX = 0;
	int m_maxFrameY = 0;

	int m_currFrameX = 0;
	int m_currFrameY = 0;
	int m_frameSizeX = 0;
	int m_frameSizeY = 0;

	float m_scale = 1.0f;
	bool mb_isLoop = false;
};

