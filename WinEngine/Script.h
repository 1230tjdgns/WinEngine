#pragma once
#include "Component.h"

namespace WE
{
	class Script : public Component
	{
	public:
		Script();
		~Script();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(const HDC hdc) = 0;

		virtual void OnCollisionEnter() = 0;
		virtual void OnCollisionStay() = 0;
		virtual void OnCollisionExit() = 0;

	private:

	};
}

