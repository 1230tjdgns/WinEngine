#include "Animator.h"
#include "Animation.h"
#include "Time.h"
#include "Entity.h"
#include "Transform.h"
#include "CameraManager.h"
#include "Texture.h"
#include "ASTest.h"

namespace WE
{

	Animator::Animator() :
		RenderComponent(eComponentType::ANIMATOR),
		mAnimations{},
		mActiveAnimation{},
		mFrameCounter(0),
		mTimer(0.f),
		mFrameDuration(0.f),
		mLength(0),
		mScript(nullptr),
		mOwnerTransform(nullptr),
		mSpritePos(Vector2::Zero),
		mOffset(Vector2::Zero),
		mScale(Vector2::One),
		mLoop(false)
	{
	}

	Animator::~Animator()
	{
		if (mScript)
		{
			delete mScript;
			mScript = nullptr;
		}
	}

	void Animator::OnInitialize()
	{
		mOwnerTransform = GetOwner()->GetComponent<Transform>();
	}

	void Animator::OnUpdate()
	{

		if ((mFrameCounter >= mLength - 1 && !mLoop) == false)
		{
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

					// End Event Call
					mActiveAnimation.events.mEndEvent();
				}
			}
		}

		if (mScript)
			mScript->Update();
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
		if (mScript)
			mScript->Render(hdc);
	}

	bool Animator::AddAnimation(const std::wstring& name, Animation* const animation)
	{
		if (animation == nullptr)
			return false;

		Animations::iterator animIter = mAnimations.find(name);
		if (animIter != mAnimations.end())
			return false;

		mAnimations.insert(std::make_pair(name, animation));

		return true;
	}

	void Animator::SetAnimation(const std::wstring& name)
	{
		Animations::iterator animIter = mAnimations.find(name);
		if (animIter == mAnimations.end())
			return;

		// End Event Call
		if (mActiveAnimation.animation)
		{
			mActiveAnimation.events.mStopEvent();
		}

		mActiveAnimation = animIter->second;
		mFrameDuration = mActiveAnimation.animation->GetFrameDuration();
		mLength = mActiveAnimation.animation->GetFrameLength();
		mLoop = mActiveAnimation.animation->IsLoop();

		mFrameCounter = 0;
		mTimer = 0.f;

		// Start Event Call
		mActiveAnimation.events.mStartEvent();
	}

	void Animator::GetRenderValue(RenderValue& values)
	{
		if (mActiveAnimation.animation)
		{
			if (mActiveAnimation.animation->GetTexture())
			{
				values.texture = mActiveAnimation.animation->GetTexture();
				values.renderPos = mSpritePos + mOffset;
				values.renderSize = Vector2(mActiveAnimation.animation->GetFrameWidth(), mActiveAnimation.animation->GetFrameHeight()) * mScale;
				values.sourcePos = mActiveAnimation.animation->GetFrameLeftTop(mFrameCounter);
				values.sourceSize = Vector2(mActiveAnimation.animation->GetFrameWidth(), mActiveAnimation.animation->GetFrameHeight());
			}
		}
	}

}