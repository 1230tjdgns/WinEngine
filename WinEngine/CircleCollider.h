#pragma once
#include "Collider.h"

namespace WE
{
	class CircleCollider : public Collider
	{
	public:
		CircleCollider();
		~CircleCollider();
		 
		void OnInitialize() override;
		void OnRender(const HDC& hdc) override;

		void SetRadius(const float radius) { mRadius = radius; }
		float GetRadius() const { return mRadius; }

	private:
		float mRadius;


	};
}

