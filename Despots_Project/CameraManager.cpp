#include "stdafx.h"
#include "CameraManager.h"

void CameraManager::ResetCamera()
{
	camera.x = WIN_SIZE_X;
	camera.y = WIN_SIZE_Y;
}

void CameraManager::SetCameraPos(POINT pos)
{
	camera.x += pos.x;
	camera.y += pos.y;
}
