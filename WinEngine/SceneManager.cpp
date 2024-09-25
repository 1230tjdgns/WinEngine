#include "SceneManager.h"
#include "SceneLoader.h"

namespace WE
{
	std::unordered_map<std::wstring, Scene*> SceneManager::mScenes;
	Scene* SceneManager::mActiveScene;
}

namespace WE
{
	SceneManager::SceneManager()
	{
	}

	SceneManager::~SceneManager()
	{
	}

	void SceneManager::Initialize()
	{
		Loader::LoadScenes();
	}

	void SceneManager::Update()
	{
		if(mActiveScene)
			mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		if (mActiveScene)
			mActiveScene->LateUpdate();
	}

	void SceneManager::Render(const HDC hdc)
	{
		if (mActiveScene)
			mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		if (mActiveScene)
			mActiveScene->RemoveDestroyedEntities();
	}

	void SceneManager::Release()
	{
		for (auto& scenePair : mScenes)
		{
			if (scenePair.second != nullptr)
			{
				delete scenePair.second;
				scenePair.second = nullptr;
			}
		}
		mScenes.clear();
	}

	HRESULT SceneManager::LoadScene(const std::wstring& name)
	{
		SceneMap::iterator sceneIter = mScenes.find(name);
		if (sceneIter == mScenes.end())
			return E_FAIL;

		if (mActiveScene != nullptr)
			mActiveScene->OnExit();

		mActiveScene = sceneIter->second;
		mActiveScene->Initialize();
		mActiveScene->OnEnter();

		return S_OK;
	}
}