#pragma once
#include "Scene.h"

namespace WE
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}

