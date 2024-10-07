#pragma once
#include "RenderComponent.h"

namespace WE
{
	class Sprite : public RenderComponent
	{
	public:
		Sprite();
		~Sprite();

		void OnInitialize()  override;
		void OnUpdate()  override;
		void OnLateUpdate()  override;
		void OnRender(const HDC& hdc) override;

		void SetTexture(class Texture* const texture);
		inline class Texture* GetTexture() const { return mTexture; }

		inline void SetOffset(Vector2 pos) { mOffset = pos; }
		inline void SetOffset(float x, float y)
		{
			mOffset.x = x;
			mOffset.y = y;
		}
		inline Vector2 GetOffset() const { return mOffset; }

		inline void SetScale(Vector2 scale) { mScale = scale; }
		inline void SetScale(float w, float h)
		{
			mScale.x = w;
			mScale.y = h;
		}
		inline Vector2 GetScale() const { return mScale; }

		void GetRenderValue(RenderValue& values) override;

	private:
		class Texture* mTexture;
		class Transform* mOwnerTransform;

		Vector2 mSpritePos;
		Vector2 mOffset;
		Vector2 mScale;
	};
}

