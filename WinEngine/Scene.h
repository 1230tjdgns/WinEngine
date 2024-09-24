#pragma once
#include "Layer.h"

namespace WE
{
	class Scene : public Tag
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(const HDC hdc);

		void AddEntity(Entity* entity);

	private:
		std::vector<Layer*> mLayers;
	};
}


