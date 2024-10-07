#pragma once
#include "Component.h"
#include "RenderComponent.h"

namespace WE
{
	class Renderer : public Component
	{
	public:
		Renderer();
		~Renderer();

		void OnInitialize() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender(const HDC& hdc) override;

	private:
		void gdiRender(const HDC& hdc);
		void gdipRender(const HDC& hdc);

	private:
		RenderComponent::RenderValue mRenderValue;
		RenderComponent* mRenderComp;
	};
}

