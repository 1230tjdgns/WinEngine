#pragma once
#include "Component.h"
#include "TestScript.h"

namespace WE
{
	class Collider : public Component
	{
	public:
		struct Event
		{
			std::function<void(Collider*)> func;

			void operator()(Collider* const other)
			{
				if(func)
					func(other);
			}
			
			void operator=(std::function<void(Collider*)> func)
			{
				this->func = func;
			}

			Event()
			{
				func = nullptr;
			}
		};

		struct Events
		{
			Event enter;
			Event stay;
			Event exit;
		};

		enum class eCollisionEventType
		{
			ENTER,
			STAY,
			EXIT
		};

	public:
		Collider() = delete;

		Collider(eColliderType type);
		virtual ~Collider();

		virtual void OnInitialize() = 0;
		void OnUpdate() override;
		void OnLateUpdate() override;
		virtual void OnRender(const HDC& hdc) = 0;

		void CollisionEnter(Collider* const other);
		void CollisionStay(Collider* const other);
		void CollisionExit(Collider* const other);

		UINT64 GetId() const { return mId; }

		Vector2 GetOffset() const { return mOffset; }

		void SetOffset(Vector2 offset) { mOffset = offset; }

		eColliderType GetColliderType() const { return mType; }

		Vector2 GetPosition() const { return mPosition; }

		template<typename T, typename C>
		void BindCollisionEvent(eCollisionEventType eventType, void (C::*func)(Collider*), T&& ref)
		{
			std::function<void(Collider*)> eventFunc = std::bind(func, ref, std::placeholders::_1);
			
			switch (eventType)
			{
			case eCollisionEventType::ENTER:
				mCollisionEvents.enter = eventFunc;
				break;
			case eCollisionEventType::STAY:
				mCollisionEvents.stay = eventFunc;
				break;
			case eCollisionEventType::EXIT:
				mCollisionEvents.exit = eventFunc;
				break;
			default:
				break;
			}
		}

	protected:
		Vector2 mPosition;
		Vector2 mOffset;

	private:
		static UINT32 colliderId;
		UINT32 mId;

		eColliderType mType;

		Events mCollisionEvents;
	};
}

