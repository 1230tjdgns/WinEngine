#include "Scene.h"

namespace WE
{
	Scene::Scene() :
		mLayers{}
	{
		for (size_t i = 0; i < (UINT)eLayerType::END; ++i)
		{
			mLayers.emplace_back(new Layer((eLayerType)i));
		}
	}

	Scene::~Scene()
	{
		for (Layer*& layer : mLayers)
		{
			if (layer != nullptr)
			{
				delete layer;
				layer = nullptr;
			}
		}
	}

	void Scene::Initialize()
	{
		for (Layer*& layer : mLayers)
		{
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer*& layer : mLayers)
		{
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer*& layer : mLayers)
		{
			layer->LateUpdate();
		}
	}

	void Scene::Render(const HDC hdc)
	{
		for (Layer*& layer : mLayers)
		{
			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddEntity(Entity* entity)
	{
		eLayerType type = entity->GetLayerType();

		mLayers[(UINT)type]->AddEntity(entity);
	}

	void Scene::RemoveDestroyedEntities()
	{
		std::vector<Entity*> destroyedEntities;
		for (Layer*& layer : mLayers)
		{
			layer->CollectDestroyedEntities(destroyedEntities);
		}

		for (Entity*& entity : destroyedEntities)
		{
			delete entity;
			entity = nullptr;
		}
	}
}