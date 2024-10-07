#pragma once
#include "Tag.h"

namespace WE
{
	class Entity : public Tag
	{
	public:
		enum class eState
		{
			ENABLE,
			DISABLE,
			DESTROY
		};

	public:
		Entity(
			const eLayerType& layer = eLayerType::NONE,
			const eState& state = eState::ENABLE);
		virtual ~Entity();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(const HDC& hdc);

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

		template<typename T>
		T* AddComponent(bool LateInit = false)
		{
			T* comp = new T;

			eComponentType type = comp->GetType();
			if (mComponents[(UINT)type] != nullptr)
			{
				delete comp;
				return nullptr;
			}
			comp->SetOwner(this);
			if(LateInit == false)
				comp->Initialize();
			mComponents[(UINT)type] = comp;
			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* resultComp = nullptr;
			for (Component*& comp : mComponents)
			{
				resultComp = dynamic_cast<T*>(comp);
				if (resultComp)
				{
					return resultComp;
				}
			}
			return nullptr;
		}

		inline void Enable()
		{
			mState = eState::ENABLE;
		}
		inline void Disable()
		{
			mState = eState::DISABLE;
		}
		inline void Destroy()
		{
			mState = eState::DESTROY;
		}
		inline bool IsEnable() const
		{
			return mState == eState::ENABLE ? true : false;
		}
		inline bool IsDestroy() const
		{
			return mState == eState::DESTROY ? true : false;
		}

		inline void SetLayerType(const eLayerType type) { mLayerType = type; }
		inline eLayerType GetLayerType() const { return mLayerType; }

	private:
		eState mState;
		eLayerType mLayerType;

		std::vector<class Component*> mComponents;
	};
}


