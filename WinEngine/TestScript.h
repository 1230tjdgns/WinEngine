#pragma once
#include "Script.h"

namespace WE
{
	class TestScript : public Script
	{
	public:
		TestScript();
		~TestScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const HDC hdc) override;

		void OnCollisionEnter() override;
		void OnCollisionStay() override;
		void OnCollisionExit() override;

	private:
		class Transform* tr;
	};
}

