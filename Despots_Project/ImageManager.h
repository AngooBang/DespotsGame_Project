#pragma once
#include "Singleton.h"
#include "Config.h"

class BMPImage;
class ImageManager : public Singleton<ImageManager>
{
private:
	map<string, BMPImage*> mapImages;



public:
	void Init();
	void Release();

	BMPImage* AddImage(const char* fileName, int width, int height,
		bool isTrans = false, COLORREF transColor = NULL);	

	BMPImage* AddImage(const char* fileName, int width, int height,
		int maxFrameX, int maxFrameY,
		bool isTrans = false, COLORREF transColor = NULL);
	BMPImage* FindImage(const char* fileName);		// 등록된 이미지 중에 필요한 이미지를 찾는 기능
	void DeleteImage(const char* fileName);		// 사용이 종료된 이미지를 등록 해제하는 기능
};

