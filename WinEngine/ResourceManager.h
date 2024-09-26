#pragma once
#include "Resource.h"

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

