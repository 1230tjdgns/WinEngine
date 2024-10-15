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
#include "ASTest.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "CoreFunction.h"
#include "Component.h"
#include "Rigidbody.h"

namespace WE
{
	TestScript::TestScript() :
		tr(nullptr),
		mState(eState::IDLE)
	{
	}

	TestScript::~TestScript()
	{
	}

	void TestScript::OnInitialize()
	{
		tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(Vector2(-400, 100));

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

		//BoxCollider* box = GetOwner()->AddComponent<BoxCollider>();
		//box->SetSize(anim->GetScale() * Vector2(32, 32));

		CircleCollider* circle = GetOwner()->AddComponent<CircleCollider>();
		circle->SetRadius(16 * 2);

		circle->BindCollisionEvent(Collider::eCollisionEventType::ENTER, &TestScript::Enter, this);

		Rigidbody* rb = GetOwner()->AddComponent<Rigidbody>();
	}

	void TestScript::OnUpdate()
	{
		switch (mState)
		{
		case eState::IDLE:
			idle();
			break;
		case eState::WALK:
			walk();
			break;
		}

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

	void TestScript::TEST()
	{
		//assert(false);
	}

	void TestScript::Enter(Collider* other)
	{
		//assert(false);
		Global::Destroy(other->GetOwner());
	}

	void TestScript::idle()
	{
		Animator* anim = GetOwner()->GetComponent<Animator>();
		if (Input::IsKeyStay(VK_LEFT))
		{
			anim->SetAnimation(L"left");
			mState = eState::WALK;
		}
		if (Input::IsKeyStay(VK_RIGHT))
		{
			anim->SetAnimation(L"right");
			mState = eState::WALK;
		}
		if (Input::IsKeyStay(VK_UP))
		{
			anim->SetAnimation(L"backward");
			mState = eState::WALK;
		}
		if (Input::IsKeyStay(VK_DOWN))
		{
			anim->SetAnimation(L"forward");
			mState = eState::WALK;
		}
	}

	void TestScript::walk()
	{
		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		Vector2 pos = Vector2::Zero;
		float speed = 10000;
		if (Input::IsKeyStay(VK_LEFT))
		{
			pos.x = -speed;
		}
		if (Input::IsKeyStay(VK_RIGHT))
		{
			pos.x = speed;
		}
		if (Input::IsKeyStay(VK_UP))
		{
			pos.y = -speed;
		}
		if (Input::IsKeyStay(VK_DOWN))
		{
			pos.y = speed;
		}
		if (rb)
			rb->AddForce(pos);

		if (Input::IsKeyUp(VK_LEFT) || Input::IsKeyUp(VK_RIGHT) ||
			Input::IsKeyUp(VK_UP) || Input::IsKeyUp(VK_DOWN))
		{
			mState = eState::IDLE;
			Animator* anim = GetOwner()->GetComponent<Animator>();
			anim->SetAnimation(L"sit");
		}
	}

}