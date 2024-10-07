#include "Animator.h"
#include "Animation.h"
#include "Time.h"
#include "Entity.h"
#include "Transform.h"
#include "CameraManager.h"
#include "Texture.h"

namespace WE
{
	Animator::Animator() :
		RenderComponent(eComponentType::ANIMATOR),
		mAnimations{},
		mActiveAnimation(nullptr),
		mFrameCounter(0),
		mTimer(0.f),
		mFrameDuration(0.f),
		mLength(0),
		mOwnerTransform(nullptr),
		mSpritePos(Vector2::Zero),
		mOffset(Vector2::Zero),
		mScale(Vector2::One)
	{
	}

	Animator::~Animator()
	{
		int a = 0;
	}

	void Animator::OnInitialize()
	{
		mOwnerTransform = GetOwner()->GetComponent<Transform>();
	}

	void Animator::OnUpdate()
	{
		if (mFrameCounter >= mLength - 1 && !mLoop)
			return;

		mTimer += Time::GetDeltaTime();

		if (mTimer >= mFrameDuration)
		{
			mTimer = 0;
			++mFrameCounter;

			if (mFrameCounter >= mLength)
			{
				if (mLoop)
				{
					mFrameCounter = 0;
				}
				else
				{
					mFrameCounter = mLength - 1;
				}

				mEndEvent();
			}
		}
	}

	void Animator::OnLateUpdate()
	{
		if (mOwnerTransform)
		{
			mSpritePos = mOwnerTransform->GetPosition();
			mSpritePos = CameraManager::CalculateWorldPos(mSpritePos);
		}
	}

	void Animator::OnRender(const HDC& hdc)
	{
	}

	HRESULT Animator::AddAnimation(const std::wstring& name, Animation* const animation)
	{
		if (animation == nullptr)
			return E_FAIL;

		Animations::iterator animIter = mAnimations.find(name);
		if (animIter != mAnimations.end())
			return E_FAIL;

		mAnimations.insert(std::make_pair(name, animation));

		return S_OK;
	}

	void Animator::SetAnimation(const std::wstring& name)
	{
		Animations::iterator animIter = mAnimations.find(name);
		if (animIter == mAnimations.end())
			return;

		mActiveAnimation = animIter->second;
		mFrameDuration = mActiveAnimation->GetFrameDuration();
		mLength = mActiveAnimation->GetFrameLength();
		mLoop = mActiveAnimation->IsLoop();

		mFrameCounter = 0;
		mTimer = 0.f;
	}

	void Animator::GetRenderValue(RenderValue& values)
	{
		if (mActiveAnimation)
		{
			if (mActiveAnimation->GetTexture())
			{
				values.texture = mActiveAnimation->GetTexture();
				values.renderPos = mSpritePos + mOffset;
				values.renderSize = Vector2(mActiveAnimation->GetFrameWidth(), mActiveAnimation->GetFrameHeight()) * mScale;
				values.sourcePos = mActiveAnimation->GetFrameLeftTop(mFrameCounter);
				values.sourceSize = Vector2(mActiveAnimation->GetFrameWidth(), mActiveAnimation->GetFrameHeight());
			}
		}
	}
}