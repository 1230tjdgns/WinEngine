#pragma once
#include "Tag.h"

namespace WE
{
	class Entity : public Tag
	{
	public:
		enum class eState
		{
			ALIVE,
			DISABLE,
			DEAD
		};

	public:
		Entity();
		~Entity();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(const HDC hdc);

		void SetLayerType(const eLayerType type) { mLayerType = type; }
		eLayerType GetLayerType() const { return mLayerType; }

	private:
		eState mState;
		eLayerType mLayerType;

		std::vector<class Component*> mComponents;
	};
}


