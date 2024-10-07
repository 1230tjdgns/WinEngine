#pragma once
#include "Component.h"

namespace WE
{
	class RenderComponent : public Component
	{
	public:
		struct RenderValue
		{
			class Texture* texture;
			Vector2 renderPos;
			Vector2 renderSize;
			Vector2 sourcePos;
			Vector2 sourceSize;

			RenderValue() :
				texture(nullptr),
				renderPos(Vector2::Zero),
				renderSize(Vector2::Zero),
				sourcePos(Vector2::Zero),
				sourceSize(Vector2::Zero)
			{}
		};

	public:
		RenderComponent(eComponentType type);
		virtual ~RenderComponent();

		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

		virtual void GetRenderValue(RenderValue& values) = 0;

	private:

	};
}

