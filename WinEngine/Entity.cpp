#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace WE
{
	Entity::Entity(
		const eLayerType& layer,
		const eState& state) :
		mState(state),
		mLayerType(layer),
		mComponents{}
	{
		mComponents.resize((UINT)eComponentType::END, nullptr);
		AddComponent<Transform>();
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
			if(comp != nullptr)
				comp->Initialize();
		}
	}

	void Entity::Update()
	{
		for (Component*& comp : mComponents)
		{
			if (comp != nullptr)
				comp->Update();	
		}
	}

	void Entity::LateUpdate()
	{
		for (Component*& comp : mComponents)
		{
			if (comp != nullptr)
				comp->LateUpdate();
		}
	}

	void Entity::Render(const HDC hdc)
	{
		for (Component*& comp : mComponents)
		{
			if (comp != nullptr)
				comp->Render(hdc);
		}
	}
}