#pragma once
#include "Component.h"

namespace WE
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		void AddForce(const Vector2& force) { mForce = force; }
		void SetVelocity(const Vector2& velocity) { mVelocity = velocity; }

	private:
		void applyGravity();
		void applyMaxVelocity();
		void applyFriction();

	private:
		Vector2 mAcceleration;
		Vector2 mVelocity;
		Vector2 mVelocityTemp;
		
		Vector2 mForce;
		Vector2 mGravity;
		Vector2 mMaxVelocity;
		float mMass;
		float mFriction;

		bool mGround;
	};
}

