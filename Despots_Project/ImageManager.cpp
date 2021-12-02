#include "stdafx.h"
#include "ImageManager.h"
#include "BMPImage.h"

void ImageManager::Init()
{

	ImageManager::GetSingleton()->AddImage("Image/Title/BackGround.bmp", WIN_SIZE_X, WIN_SIZE_Y);
	ImageManager::GetSingleton()->AddImage("Image/Title/Despot_Logo.bmp", 700, 400);
	ImageManager::GetSingleton()->AddImage("Image/Map/Wall.bmp", 900, 140);
	ImageManager::GetSingleton()->AddImage("Image/Map/Bottom.bmp", 900, 50);
	ImageManager::GetSingleton()->AddImage("Image/Map/Ground_0.bmp", 45, 45);
	ImageManager::GetSingleton()->AddImage("Image/Map/Door_LeftFrame.bmp", 30, 200);


}

void ImageManager::Release()
{
	map<string, BMPImage*>::iterator it;
	for (it = mapImages.begin(); it != mapImages.end();)
	{
		SAFE_RELEASE(it->second);
		// erase에서 리턴값으로 it의 다음 iterator를 돌려주게됨. 계속 대입해서 반복시킴
		it = mapImages.erase(it);

	}

}

BMPImage* ImageManager::AddImage(const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// 이미지를 찾아보고 만약 있으면 추가안함.
	if (FindImage(fileName))
	{
		return nullptr;
	}
	BMPImage* img = new BMPImage;
	if (FAILED(img->Init(fileName, width, height, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapImages.insert(make_pair(fileName, img));

	return img;


}

//void ImageManager::AddImage(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
//{
//	if (FindImage(fileName))
//	{
//		return;
//	}
//	Image* img = new Image;
//	if (FAILED(img->Init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
//	{
//		SAFE_RELEASE(img);
//		return;
//	}
//
//	mapImages.insert(make_pair(fileName, img));
//}

BMPImage* ImageManager::AddImage(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	if (FindImage(fileName))
	{
		return nullptr;
	}
	BMPImage* img = new BMPImage;
	if (FAILED(img->Init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapImages.insert(make_pair(fileName, img));
	return img;
}

BMPImage* ImageManager::FindImage(const char* fileName)
{

	map<string, BMPImage*>::iterator it = mapImages.find(fileName);
	if (it == mapImages.end())
	{
		return nullptr;
	}


	return it->second;
}

void ImageManager::DeleteImage(const char* fileName)
{
	map<string, BMPImage*>::iterator it = mapImages.find(fileName);
	if (it == mapImages.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);		// Image* // Image 동적할당 해제
	mapImages.erase(it);			// 맵에서 노드 삭제



}
