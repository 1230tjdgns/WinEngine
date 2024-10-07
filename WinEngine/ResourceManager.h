#pragma once
#include "Resource.h"
#include "Animation.h"
#include "Texture.h"

namespace WE
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		static void Initialize();

		template<typename T>
		static HRESULT Load(const std::wstring& name, const std::wstring& path)
		{
			if (mResources.find(name) != mResources.end())
				return E_FAIL;
			
			T* res = new T;
			res->SetName(name);
			if (res->Load(path) != S_OK)
			{
				delete res;
				return E_FAIL;
			}

			mResources.insert(std::make_pair(name, res));

			return S_OK;
		}

		template<>
		static HRESULT Load<Animation>(const std::wstring& name, const std::wstring& path)
		{
			return E_FAIL;
		}

		static HRESULT LoadAnimation(const std::wstring& name, const std::wstring& textureName, const float frameWidth, const float frameHeight, Vector2 startLeftTop, const float duration, const UINT length, const bool loop = false)
		{
			if (mResources.find(name) != mResources.end())
				return E_FAIL;

			Animation* animation = new Animation();

			Texture* tex = Get<Texture>(textureName);
			if (tex == nullptr)
				return E_FAIL;

			if (animation->CreateAnimation(tex, frameWidth, frameHeight, startLeftTop, duration, length, loop) == E_FAIL)
				return E_FAIL;

			mResources.insert(std::make_pair(name, animation));

			return S_OK;
		}

		template<typename T>
		static T* Get(const std::wstring& name)
		{
			ResourceMap::iterator resIter = mResources.find(name);
			if (resIter == mResources.end())
				return nullptr;

			T* res = dynamic_cast<T*>(resIter->second);

			return res;
		}

		static void Release();

	private:
		typedef std::unordered_map<std::wstring, Resource*> ResourceMap;
	private:
		static std::unordered_map<std::wstring, Resource*> mResources;
	};
}

