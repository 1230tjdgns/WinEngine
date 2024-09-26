#pragma once
#include "Tag.h"

namespace WE
{
	class Component : public Tag
	{
	public:
		Component(eComponentType type);
		~Component();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render(const HDC& hdc) = 0;

		inline eComponentType GetType() const { return mType; }

		inline void SetOwner(class Entity* const ent)
		{
			mOwner = ent;
		}
		inline Entity* GetOwner() const { return mOwner; }

	private:
		eComponentType mType;
		class Entity* mOwner;
	};
}


