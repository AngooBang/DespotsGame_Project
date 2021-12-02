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
	BMPImage* FindImage(const char* fileName);		// ��ϵ� �̹��� �߿� �ʿ��� �̹����� ã�� ���
	void DeleteImage(const char* fileName);		// ����� ����� �̹����� ��� �����ϴ� ���
};

