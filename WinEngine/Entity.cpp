#include "Entity.h"
#include "Component.h"

namespace WE
{
	Entity::Entity() :
		mState(eState::ALIVE),
		mLayerType(eLayerType::NONE),
		mComponents{}
	{
		mComponents.resize((UINT)eComponentType::END, nullptr);
	}

	Entity::~Entity()
	{
		for (Component*& comp : mComponents)
		{
			if (comp != nullptr)
			{
				delete comp;
				comp = nullptr;
			}
		}
	}

	void Entity::Initialize()
	{
		for (Component*& comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void Entity::Update()
	{
		for (Component*& comp : mComponents)
		{
			comp->Update();
		}
	}

	void Entity::LateUpdate()
	{
		for (Component*& comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void Entity::Render(const HDC hdc)
	{
		for (Component*& comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}