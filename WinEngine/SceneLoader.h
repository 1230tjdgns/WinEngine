#pragma once
#include "SceneManager.h"
#include "TestScene.h"

namespace WE
{
	namespace Loader
	{
		void LoadScenes()
		{
			SceneManager::AddScene<TestScene>(L"TestScene");

			SceneManager::LoadScene(L"TestScene");
		}
	}
}