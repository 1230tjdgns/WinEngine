#include "Sprite.h"
#include "Entity.h"
#include "Transform.h"
#include "Texture.h"
#include "CoreFunction.h"
#include "CameraManager.h"
#include "ResourceManager.h"

namespace WE
{
	Sprite::Sprite() :
		RenderComponent(eComponentType::SPRITE),
		mTexture(nullptr),
		mOwnerTransform(nullptr),
		mSpritePos(Vector2::Zero),
		mOffset(Vector2::Zero),
		mScale(Vector2::One)
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
	}

	void Sprite::OnLateUpdate()
	{
		if (mOwnerTransform)
		{
			mSpritePos = mOwnerTransform->GetPosition();
			mSpritePos = CameraManager::CalculateWorldPos(mSpritePos);
		}
	}

	void Sprite::OnRender(const HDC& hdc)
	{
	}

	void Sprite::SetTexture(Texture* const texture)
	{
		mTexture = texture;
	}

	void Sprite::GetRenderValue(RenderValue& values)
	{
		values.texture = mTexture;
		values.renderPos = mSpritePos + mOffset;
		values.renderSize = Vector2(mTexture->GetWidth(), mTexture->GetHeight()) * mScale;
		values.sourcePos = Vector2::Zero;
		values.sourceSize = Vector2(mTexture->GetWidth(), mTexture->GetHeight());
	}

}