#pragma once
#include "ResourceManager.h"
#include "Texture.h"

namespace WE
{
	namespace Loader
	{
		void LoadResource()
		{
			ResourceManager::Load<Texture>(L"cow", L"res//image//flycow.bmp");
			ResourceManager::Load<Texture>(L"snipe", L"res//image//Snipe.jpg");
		}
	}
}