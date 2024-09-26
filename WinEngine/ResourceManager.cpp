#include "ResourceManager.h"
#include "ResourceLoader.h"

namespace WE
{
	std::unordered_map<std::wstring, Resource*> ResourceManager::mResources;
}

namespace WE
{
	ResourceManager::ResourceManager()
	{
	}

	ResourceManager::~ResourceManager()
	{
	}

	void ResourceManager::Initialize()
	{
		Loader::LoadResource();
	}

	void ResourceManager::Release()
	{
		for (auto& resPair : mResources)
		{
			if (resPair.second != nullptr)
			{
				delete resPair.second;
				resPair.second = nullptr;
			}
		}

		mResources.clear();
	}
}