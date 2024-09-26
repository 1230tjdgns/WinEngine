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
		virtual void Render(const HDC& hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddEntity(Entity* entity);

		template<typename F>
		void GetFilteredEntities(std::vector<Entity*>& vec, F func)
		{
			for (Layer*& layer : mLayers)
			{
				layer->GetFilteredEntities(vec, func);
			}
		}

		template<typename F>
		void EraseFilteredEntities(F func)
		{
			for (Layer*& layer : mLayers)
			{
				layer->EraseFilteredEntities(func);
			}
		}

	private:
		std::vector<Layer*> mLayers;
	};
}


