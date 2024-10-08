#pragma once
#include "Script.h"

namespace WE
{
	class TestScript : public Script
	{
	public:
		TestScript();
		~TestScript();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		void OnCollisionEnter() override;
		void OnCollisionStay() override;
		void OnCollisionExit() override;

		void TEST();

	private:
		class Transform* tr;
	};
}

