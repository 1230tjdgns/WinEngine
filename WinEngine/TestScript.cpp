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

namespace WE
{
	TestScript::TestScript() :
		tr(nullptr)
	{
	}

	TestScript::~TestScript()
	{
	}

	void TestScript::Initialize()
	{
		tr = GetOwner()->GetComponent<Transform>();
		tr->SetPosition(Vector2(200, 200));

		Sprite* sp = GetOwner()->AddComponent<Sprite>();
		Texture* tex = ResourceManager::Get<Texture>(L"snipe");
		sp->SetTexture(tex);

		Camera* cam = GetOwner()->AddComponent<Camera>();
		cam->SetTarget(GetOwner());
		CameraManager::SetTargetCamera(cam);
	}

	void TestScript::Update()
	{
		Vector2 pos = tr->GetPosition();
		if (Input::IsKeyStay(VK_LEFT))
		{
			pos.x -= 200 * Time::GetDeltaTime();
		}
		if (Input::IsKeyStay(VK_RIGHT))
		{
			pos.x += 200 * Time::GetDeltaTime();
		}
		if (Input::IsKeyStay(VK_UP))
		{
			pos.y -= 200 * Time::GetDeltaTime();
		}
		if (Input::IsKeyStay(VK_DOWN))
		{
			pos.y += 200 * Time::GetDeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::IsKeyDown(VK_SPACE))
		{
			Global::Destroy(GetOwner());
		}
	}

	void TestScript::LateUpdate()
	{
	}

	void TestScript::Render(const HDC& hdc)
	{
		Vector2 pos = tr->GetPosition();

		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				Rectangle(hdc, (pos.x - 10.f) + (30 * i) , (pos.y - 10.f) + (30 * j), (pos.x + 10.f) + (30 * i), (pos.y + 10.f) + (30 * j));
			}
		}
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