#pragma once
#include "Script.h"

namespace WE
{
	class TestScript2 : public Script
	{
	public:
		TestScript2();
		~TestScript2();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		void OnCollisionEnter() override;
		void OnCollisionStay() override;
		void OnCollisionExit() override;

	private:

	};
}

