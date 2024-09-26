#pragma once
#include "Scene.h"

namespace WE
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(const HDC& hdc);
		static void Release();

		template<typename T>
		static void AddScene(const std::wstring& name)
		{
			T* scene = new T;
			if (mActiveScene == nullptr)
			{
				mActiveScene = scene;
			}

			scene->SetName(name);

			mScenes.insert(std::make_pair(name, scene));
		}

		static HRESULT LoadScene(const std::wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }

	private:
		typedef std::unordered_map<std::wstring, Scene*> SceneMap;
	private:
		static std::unordered_map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
	};
}

