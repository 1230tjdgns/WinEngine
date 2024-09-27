#pragma once
#include "Component.h"

namespace WE
{
	class Transform : public Component
	{
	public:
		Transform();
		Transform(const Vector2& vec);
		Transform(const float& x, const float& y);
		~Transform();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		inline void SetPosition(const Vector2 pos) { mPosition = pos; }
		inline void SetPosition(const float x, const float y)
		{
			mPosition.x = x;
			mPosition.y = y;
		}
		inline Vector2 GetPosition() const { return mPosition; }

	private:
		Vector2 mPosition;
	};
}

