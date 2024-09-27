#include "Component.h"

namespace WE
{
	Component::Component(const eComponentType type) :
		mType(type),
		mOwner(nullptr),
		mInitialized(false)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
		mInitialized = true;
		OnInitialize();
	}

	void Component::Update()
	{
		if (mInitialized == false)
			Initialize();
		OnUpdate();
	}

	void Component::LateUpdate()
	{
		OnLateUpdate();
	}

	void Component::Render(const HDC& hdc)
	{
		OnRender(hdc);
	}
}