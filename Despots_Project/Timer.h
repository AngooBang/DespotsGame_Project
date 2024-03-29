#pragma once
#include "Config.h"
class Timer
{
private:
	bool isHardware;				// 고성능 타이머를 쓸 수 있는지 여부.
	__int64 periodFrequency;		// 고성능 타이머의 주파수(초당 진동수), 지원하지 않으면 0
	float timeScale;				// 1초를 초당 진동수로 나눠서 경과 진동수를 시간 단위로 변환
	__int64 currTime;				// 현재 진동수 (현재 시간)
	__int64 lastTime;				// 이전 진동수 (이전 시간)
	float deltaTime;				// 경과 시간 (currTime - lastTime) * timeScale

	float fpsTimeElapsed;			// 프레임 경과 시간
	unsigned long fpsFrameCount;	// 초당 프레임 수를 계산하기위한 카운트
	unsigned long fps;				// 초당 프레임 수

public:
	void Init();
	void Tick();

	inline unsigned long GetFPS() { return this->fps; }
	inline float GetDeltaTime() { return deltaTime; }
};

