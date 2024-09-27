#pragma once
#include "Layer.h"

namespace WE
{
	class Scene : public Tag
	{
	public:
		Scene();
		~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(const HDC& hdc);

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

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


