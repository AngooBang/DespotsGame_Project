#pragma once
#include "Config.h"
class Timer
{
private:
	bool isHardware;				// ���� Ÿ�̸Ӹ� �� �� �ִ��� ����.
	__int64 periodFrequency;		// ���� Ÿ�̸��� ���ļ�(�ʴ� ������), �������� ������ 0
	float timeScale;				// 1�ʸ� �ʴ� �������� ������ ��� �������� �ð� ������ ��ȯ
	__int64 currTime;				// ���� ������ (���� �ð�)
	__int64 lastTime;				// ���� ������ (���� �ð�)
	float deltaTime;				// ��� �ð� (currTime - lastTime) * timeScale

	float fpsTimeElapsed;			// ������ ��� �ð�
	unsigned long fpsFrameCount;	// �ʴ� ������ ���� ����ϱ����� ī��Ʈ
	unsigned long fps;				// �ʴ� ������ ��

public:
	void Init();
	void Tick();

	inline unsigned long GetFPS() { return this->fps; }
	inline float GetDeltaTime() { return deltaTime; }
};

