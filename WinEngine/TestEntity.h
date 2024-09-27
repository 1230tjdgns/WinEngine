#pragma once
#include "Entity.h"

namespace WE
{
	class TestEntity : public Entity
	{
	public:
		TestEntity();
		~TestEntity();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

	private:
	};
}


