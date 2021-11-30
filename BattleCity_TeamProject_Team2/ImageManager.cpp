#include "ImageManager.h"
#include "Image.h"

void ImageManager::Init()
{
}

void ImageManager::Release()
{
	map<string, Image*>::iterator it;
	for (it = mapImages.begin(); it != mapImages.end();)
	{
		SAFE_RELEASE(it->second);
		// erase���� ���ϰ����� it�� ���� iterator�� �����ְԵ�. ��� �����ؼ� �ݺ���Ŵ
		it = mapImages.erase(it);

	}

}

Image* ImageManager::AddImage(const char* fileName, int width, int height, bool isTrans, COLORREF transColor)
{
	// �̹����� ã�ƺ��� ���� ������ �߰�����.
	if (FindImage(fileName))
	{
		return nullptr;
	}
	Image* img = new Image;
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

Image* ImageManager::AddImage(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	if (FindImage(fileName))
	{
		return nullptr;
	}
	Image* img = new Image;
	if (FAILED(img->Init(fileName, width, height, maxFrameX, maxFrameY, isTrans, transColor)))
	{
		SAFE_RELEASE(img);
		return nullptr;
	}

	mapImages.insert(make_pair(fileName, img));
	return img;
}

Image* ImageManager::FindImage(const char* fileName)
{

	map<string, Image*>::iterator it = mapImages.find(fileName);
	if (it == mapImages.end())
	{
		return nullptr;
	}


	return it->second;
}

void ImageManager::DeleteImage(const char* fileName)
{
	map<string, Image*>::iterator it = mapImages.find(fileName);
	if (it == mapImages.end())
	{
		return;
	}

	SAFE_RELEASE(it->second);		// Image* // Image �����Ҵ� ����
	mapImages.erase(it);			// �ʿ��� ��� ����



}
