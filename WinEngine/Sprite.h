#pragma once
#include "Component.h"

namespace WE
{
	class Sprite : public Component
	{
	public:
		Sprite();
		~Sprite();

		void Initialize()  override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(const HDC& hdc) override;

		inline void SetTexture(class Texture* const texture) { mTexture = texture; }
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

	private:
		void gdiRender(const HDC& hdc);
		void gdipRender(const HDC& hdc);

	private:
		class Texture* mTexture;
		class Transform* mOwnerTransform;

		Vector2 mSpritePos;
		Vector2 mOffset;
		Vector2 mScale;
	};
}

