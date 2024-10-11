#pragma once
#include "Collider.h"


namespace WE
{
	class BoxCollider : public Collider
	{
	public:
		BoxCollider();
		~BoxCollider();

		void OnInitialize() override;
		void OnRender(const HDC& hdc) override;

		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }
		void SetWidth(float width) { mWidth = width; }
		void SetHeight(float height) { mHeight = height; }

		void SetSize(Vector2 size) { mWidth = size.x; mHeight = size.y; }

	private:
		float mWidth;
		float mHeight;
	};
}

