#include "Sprite.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"
#include "CoreFunction.h"
#include "CameraManager.h"
#include "ResourceManager.h"
#include "Time.h"

namespace WE
{
	Sprite::Sprite() :
		Component(eComponentType::SPRITE),
		mTexture(nullptr),
		mOwnerTransform(nullptr),
		mSpritePos(Vector2::Zero),
		mOffset(Vector2::Zero),
		mScale(Vector2::One),
		ang(0)
	{
	}

	Sprite::~Sprite()
	{
	}

	void Sprite::OnInitialize()
	{
		mOwnerTransform = GetOwner()->GetComponent<Transform>();
	}

	void Sprite::OnUpdate()
	{
		if (mOwnerTransform)
		{
			mSpritePos = mOwnerTransform->GetPosition();
			mSpritePos = CameraManager::CalculateWorldPos(mSpritePos);

			ang += 90 * Time::GetDeltaTime();
			if (ang >= 360)
				ang = 0;
		}
	}

	void Sprite::OnLateUpdate()
	{
	}

	void Sprite::OnRender(const HDC& hdc)
	{
		if (mTexture == nullptr)
			return;
		/*
		Vector2 renderStartPos;
		renderStartPos.x = mSpritePos.x - ((mTexture->GetWidth() / 2.f) * mScale.x) + mOffset.x;
		renderStartPos.y = mSpritePos.y - ((mTexture->GetHeight() / 2.f) * mScale.y) + mOffset.y;
		
		Vector2 renderSize;
		renderSize.x = mTexture->GetWidth() * mScale.x;
		renderSize.y = mTexture->GetHeight() * mScale.y;

		Vector2 renderEndPos;
		renderEndPos.x = renderStartPos.x + renderSize.x;
		renderEndPos.y = renderStartPos.y + renderSize.y;

		Vector2 renderCenterPos;
		renderCenterPos.x = renderEndPos.x / 2.f;
		renderCenterPos.y = renderEndPos.y / 2.f;

		Vector2 textureStartPos;
		textureStartPos.x = 0.f;
		textureStartPos.y = 0.f;

		Vector2 textureEndPos;
		textureEndPos.x = mTexture->GetWidth();
		textureEndPos.y = mTexture->GetHeight();

		Vector2 windowSize = Global::GetWindowSize();
		Vector2 windowCenterPos = windowSize / 2.f;

		if (fabs(renderCenterPos.x - windowCenterPos.x) > renderSize.x / 2.f + windowSize.x / 2.f ||
			fabs(renderCenterPos.y - windowCenterPos.y) > renderSize.y / 2.f + windowSize.y / 2.f)
		{
			return;
		}
		*/
		
		switch (mTexture->GetTextureType())
		{
		case eTextureType::BMP:
			gdiRender(hdc);
			break;
		case eTextureType::PNG:
		case eTextureType::JPG:
			gdipRender(hdc);
			break;
		default:
			assert(false);
			break;
		}
	}

	void Sprite::gdiRender(const HDC& hdc)
	{
		if (mTexture->IsAlpha())
		{
			assert(false);
		}
		else
		{
			/*TransparentBlt(
				hdc,
				mSpritePos.x - ((mTexture->GetWidth() / 2.f) * mScale.x) + mOffset.x,
				mSpritePos.y - ((mTexture->GetHeight() / 2.f) * mScale.y) + mOffset.y,
				mTexture->GetWidth() * mScale.x,
				mTexture->GetHeight() * mScale.y,
				mTexture->GetDC(),
				0, 0,
				mTexture->GetWidth(),
				mTexture->GetHeight(),
				RGB(255, 0, 255)
			);*/

			Vector2 lt = Vector2(-(mTexture->GetWidth() / 2) * mScale.x, -(mTexture->GetHeight() / 2) * mScale.y);
			Vector2 rt = Vector2((mTexture->GetWidth() / 2) * mScale.x, -(mTexture->GetHeight() / 2) * mScale.y);
			Vector2 lb = Vector2(-(mTexture->GetWidth() / 2) * mScale.x, (mTexture->GetHeight() / 2) * mScale.y);

			lt = Vector2::Rotate(lt, ang);
			rt = Vector2::Rotate(rt, ang);
			lb = Vector2::Rotate(lb, ang);

			lt += mSpritePos;
			rt += mSpritePos;
			lb += mSpritePos;

			POINT point[3];
			point[0] = { (long)round(lt.x), (long)round(lt.y) };
			point[1] = { (long)round(rt.x), (long)round(rt.y) };
			point[2] = { (long)round(lb.x), (long)round(lb.y) };

			bool a = PlgBlt(
				hdc,
				point,
				mTexture->GetHDC(),
				0, 0,
				mTexture->GetWidth(),
				mTexture->GetHeight(),
				mTexture->GetMask(),
				0,0
			);
		}
	}

	void Sprite::gdipRender(const HDC& hdc)
	{
		Gdiplus::Graphics graphic(hdc);

		Gdiplus::Rect rect;
		rect.X = mSpritePos.x - ((mTexture->GetWidth() / 2.f) * mScale.x) + mOffset.x;
		rect.Y = mSpritePos.y - ((mTexture->GetHeight() / 2.f) * mScale.y) + mOffset.y;
		rect.Width = mTexture->GetWidth()* mScale.x;
		rect.Height =mTexture->GetHeight()* mScale.y;

		graphic.DrawImage(
			mTexture->GetImage(),
			rect);
	}

}