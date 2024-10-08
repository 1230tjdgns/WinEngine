#pragma once
#include "RenderComponent.h"
#include "AnimationScript.h"

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
				if(func)
					func();
			}

			void operator=(std::function<void()>& f)
			{
				func = f;
			}

			Event()
			{
				func = nullptr;
			}

		};
		struct Events
		{
			Event mStartEvent;
			Event mEndEvent;
			Event mStopEvent;
		};
		struct AnimationAndEvents
		{
			class Animation* animation;
			Events events;

			AnimationAndEvents()
			{
				animation = nullptr;
				events = {};
			}

			AnimationAndEvents(class Animation* anim)
			{
				animation = anim;
				events = {};
			}
		};

		enum class eEventType
		{
			START,
			END,
			STOP
		};

	public:
		Animator();
		~Animator();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

		bool AddAnimation(const std::wstring& name, class Animation* const animation);
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

		template<typename F, typename T>
		bool BindEvent(const std::wstring& name, const eEventType type, F&& func, T&& ref)
		{
			Animations::iterator animIter = mAnimations.find(name);
			if (animIter == mAnimations.end())
				return false;

			std::function<void()> bindFunc = std::bind(func, ref);

			switch (type)
			{
			case eEventType::START:
				animIter->second.events.mStartEvent = bindFunc;
				break;
			case eEventType::END:
				animIter->second.events.mEndEvent = bindFunc;
				break;
			case eEventType::STOP:
				animIter->second.events.mStopEvent = bindFunc;
				break;
			default:
				return false;
			}

			return true;
		}

		template<typename T>
		T* GetScript()
		{
			return static_cast<T*>(mScript);
		}

		template<typename T>
		T* SetScript()
		{
			if (mScript)
			{
				delete mScript;
				mScript = nullptr;
			}

			T* script = new T;
			mScript = script;
			mScript->Initialize();

			return script;
		}

	private:
		typedef std::unordered_map<std::wstring, AnimationAndEvents> Animations;

	private:
		Animations mAnimations;
		AnimationAndEvents mActiveAnimation;

		UINT mFrameCounter;
		UINT mLength;

		float mTimer;
		float mFrameDuration;

		AnimationScript* mScript;

	private:
		class Transform* mOwnerTransform;

		Vector2 mSpritePos;
		Vector2 mOffset;
		Vector2 mScale;

		bool mLoop;
	};
}

