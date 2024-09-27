#pragma once
#include "ResourceManager.h"
#include "Texture.h"

namespace WE
{
	namespace Loader
	{
		void LoadResource()
		{
			ResourceManager::Load<Texture>(L"cow2", L"res//image//flycow2.bmp");
			ResourceManager::Load<Texture>(L"pixel", L"res//image//pixel.bmp");
			ResourceManager::Load<Texture>(L"pixels", L"res//image//pixels.bmp");
			ResourceManager::Load<Texture>(L"cow", L"res//image//flycow.bmp");
			ResourceManager::Load<Texture>(L"cowmask", L"res//image//cowmask.bmp");
			ResourceManager::Load<Texture>(L"cowmask2", L"res//image//cowmask2.bmp");
			ResourceManager::Load<Texture>(L"snipe", L"res//image//Snipe.jpg");
			ResourceManager::Load<Texture>(L"plgblt", L"res//image//plgblt.bmp");
			ResourceManager::Load<Texture>(L"mask", L"res//image//mask.bmp");
			ResourceManager::Load<Texture>(L"mask2", L"res//image//mask2.bmp");
		}
	}
}