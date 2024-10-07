#pragma once
#include "RenderComponent.h"

namespace WE
{
	class Animator : public RenderComponent
	{
	public:
		struct Event
		{
			std::function<void()> func;

			void operator()()
			{
				func();
			}
		};
		struct Events
		{
			Event mStartEvent;
			Event mEndEvent;
			Event mStopEvent;
		};

	public:
		Animator();
		~Animator();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		HRESULT AddAnimation(const std::wstring& name, class Animation* const animation);
		void SetAnimation(const std::wstring& name);

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
		typedef std::unordered_map<std::wstring, class Animation*> Animations;
	private:
		Animations mAnimations;
		class Animation* mActiveAnimation;
		UINT mFrameCounter;
		float mTimer;
		float mFrameDuration;
		UINT mLength;
	private:

	private:
		class Transform* mOwnerTransform;

		Vector2 mSpritePos;
		Vector2 mOffset;
		Vector2 mScale;
		bool mLoop;
	};
}

