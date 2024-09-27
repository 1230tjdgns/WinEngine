#pragma once
#include "Component.h"

namespace WE
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

		virtual void OnCollisionEnter() = 0;
		virtual void OnCollisionStay() = 0;
		virtual void OnCollisionExit() = 0;

	private:

	};
}

