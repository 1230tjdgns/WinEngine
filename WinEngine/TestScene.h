#pragma once
#include "Scene.h"

namespace WE
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:

	};
}

