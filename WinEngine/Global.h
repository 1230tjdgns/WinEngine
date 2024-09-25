#pragma once
#include "Entity.h"
#include "SceneManager.h"

namespace WE
{
	namespace Global
	{
		template<typename T>
		static T* CreateEntity(eLayerType layerType)
		{
			T* entity = new T;
			entity->SetLayerType(layerType);
			entity->Initialize();

			Scene* activeScene = SceneManager::GetActiveScene();
			activeScene->AddEntity(entity);

			return entity;
		}

		static inline void Destroy(Entity* entity)
		{
			entity->Destroy();
		}
	}
}