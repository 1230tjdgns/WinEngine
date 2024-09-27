#pragma once
#include "Tag.h"

namespace WE
{
	class Component : public Tag
	{
	public:
		Component(const eComponentType type);
		~Component();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(const HDC& hdc);

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

		inline eComponentType GetType() const { return mType; }

		inline void SetOwner(class Entity* const ent)
		{
			mOwner = ent;
		}
		inline Entity* GetOwner() const { return mOwner; }

	private:
		eComponentType mType;
		class Entity* mOwner;

		bool mInitialized;
	};
}


