#pragma once
#include "Tag.h"

namespace WE
{
	class Component : public Tag
	{
	public:
		Component(eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		eComponentType mType;
	};
}


