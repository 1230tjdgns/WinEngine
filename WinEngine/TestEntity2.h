#pragma once
#include "Entity.h"

namespace WE
{
	class TestEntity2 : public Entity
	{
	public:
		TestEntity2();
		~TestEntity2();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

	private:
	};
}

