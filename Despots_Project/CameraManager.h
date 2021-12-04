#pragma once
#include "Singleton.h"

class CameraManager : public Singleton<CameraManager>
{
private:
	POINT camera = { WIN_SIZE_X, WIN_SIZE_Y };
	RECT cameraShape = { 0, 0, WIN_SIZE_X, WIN_SIZE_Y };

public:
	void ResetCamera();

	inline POINT GetCameraPos() { return camera; }
	void SetCameraPos(POINT pos);

};

