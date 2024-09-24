#pragma once
#include "Entity.h"

namespace WE
{
	class Layer : public Tag
	{
	public:
		Layer();
		Layer(eLayerType type);
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(const HDC hdc);

		void AddEntity(Entity* entity);

	private:
		std::vector<Entity*> mEntities;
		eLayerType mType;

	};
}

