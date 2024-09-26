#pragma once
#include "Component.h"

namespace WE
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const HDC& hdc) override;

		void SetTarget(class Entity* const entity) { mTarget = entity; }
		void ClearTarget() { mTarget = nullptr; }

		Vector2 GetPosition() const { return mPosition; }

		void SetOffset(const Vector2 offset) { mOffset = offset; }
		Vector2 GetOffset() const { return mOffset; }

	private:
		class Entity* mTarget;
		Vector2 mPosition;
		Vector2 mOffset;
	};
}

