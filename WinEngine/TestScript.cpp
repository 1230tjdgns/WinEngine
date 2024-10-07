#include "TestScript.h"
#include "Input.h"
#include "Transform.h"
#include "Entity.h"
#include "Time.h"
#include "Global.h"
#include "Sprite.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "CameraManager.h"
#include "Renderer.h"
#include "Animator.h"

namespace WE
{
	TestScript::TestScript() :
		tr(nullptr)
	{
	}

	TestScript::~TestScript()
	{
	}

	void TestScript::OnInitialize()
	{
		tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(Vector2(-400, 0));

		Animator* anim = GetOwner()->AddComponent<Animator>();
		anim->AddAnimation(L"forward", ResourceManager::Get<Animation>(L"CatForward"));
		anim->AddAnimation(L"right", ResourceManager::Get<Animation>(L"CatRight"));
		anim->AddAnimation(L"backward", ResourceManager::Get<Animation>(L"CatBackward"));
		anim->AddAnimation(L"left", ResourceManager::Get<Animation>(L"CatLeft"));
		anim->AddAnimation(L"sit", ResourceManager::Get<Animation>(L"CatSit"));
		anim->SetAnimation(L"sit");
		anim->SetScale(Vector2(2,2));

		Camera* cam = GetOwner()->AddComponent<Camera>();
		cam->SetTarget(GetOwner());
		CameraManager::SetTargetCamera(cam);

		GetOwner()->AddComponent<Renderer>();
	}

	void TestScript::OnUpdate()
	{
		Animator* anim = GetOwner()->GetComponent<Animator>();
		Vector2 pos = tr->GetPosition();
		if (Input::IsKeyStay(VK_LEFT))
		{
			pos.x -= 200 * Time::GetDeltaTime();
			anim->SetAnimation(L"left");
		}
		if (Input::IsKeyStay(VK_RIGHT))
		{
			pos.x += 200 * Time::GetDeltaTime();
			anim->SetAnimation(L"right");
		}
		if (Input::IsKeyStay(VK_UP))
		{
			pos.y -= 200 * Time::GetDeltaTime();
			anim->SetAnimation(L"backward");
		}
		if (Input::IsKeyStay(VK_DOWN))
		{
			pos.y += 200 * Time::GetDeltaTime();
			anim->SetAnimation(L"forward");
		}

		tr->SetPosition(pos);

		if (Input::IsKeyDown('D'))
		{
			Global::Destroy(GetOwner());
		}
		if (Input::IsKeyDown('Z'))
		{
			Camera* cam = GetOwner()->GetComponent<Camera>();
			CameraManager::SetTargetCamera(cam);
		}
	}

	void TestScript::OnLateUpdate()
	{
	}

	void TestScript::OnRender(const HDC& hdc)
	{
	}

	void TestScript::OnCollisionEnter()
	{
	}

	void TestScript::OnCollisionStay()
	{
	}

	void TestScript::OnCollisionExit()
	{
	}

}