#pragma once
#include "Entity.h"

namespace WE
{
	class TestEntity : public Entity
	{
	public:
		TestEntity();
		~TestEntity();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const HDC hdc) override;

	private:
		bool keytest = false;
	};
}


