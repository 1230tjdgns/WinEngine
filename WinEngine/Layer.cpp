#include "Layer.h"

namespace WE
{
	Layer::Layer() :
		mEntities{},
		mType(eLayerType::NONE)
	{
	}

	Layer::Layer(eLayerType type) :
		mEntities {},
		mType(type)
	{
	}

	Layer::~Layer()
	{
		for (Entity*& ent : mEntities)
		{
			if (ent != nullptr)
			{
				delete ent;
				ent = nullptr;
			}
		}
	}

	void Layer::Initialize()
	{
		for (Entity*& ent : mEntities)
		{
			ent->Initialize();
		}
	}

	void Layer::Update()
	{
		for (Entity*& ent : mEntities)
		{
			if (ent->IsEnable())
				ent->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (Entity*& ent : mEntities)
		{
			if (ent->IsEnable())
				ent->LateUpdate();
		}
	}

	void Layer::Render(const HDC hdc)
	{
		for (Entity*& ent : mEntities)
		{
			if (ent->IsEnable())
				ent->Render(hdc);
		}
	}

	void Layer::AddEntity(Entity* entity)
	{
		mEntities.push_back(entity);
	}

	void Layer::CollectDestroyedEntities(std::vector<Entity*>& vec)
	{
		for (Entity*& ent : mEntities)
		{
			if (ent->IsDestroy())
			{
				vec.push_back(ent);
			}
		}

		EraseVector(mEntities, [](Entity* ent) { return ent->IsDestroy(); });
	}
}