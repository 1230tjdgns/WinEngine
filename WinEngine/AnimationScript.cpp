#include "AnimationScript.h"

namespace WE
{

	AnimationScript::AnimationScript()
	{
	}

	AnimationScript::~AnimationScript()
	{
	}

	void AnimationScript::Initialize()
	{
		OnInitialize();
	}

	void AnimationScript::Update()
	{
		OnUpdate();
	}

	void AnimationScript::Render(const HDC& hdc)
	{
		OnRender(hdc);
	}

}