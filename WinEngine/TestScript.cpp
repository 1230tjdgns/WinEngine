#include "TestScript.h"
#include "Input.h"
#include "Transform.h"
#include "Entity.h"
#include "Time.h"
#include "Global.h"

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

	void TestScript::Render(const HDC hdc)
	{
		Vector2 pos = tr->GetPosition();

		Rectangle(hdc, pos.x - 10.f, pos.y - 10.f, pos.x + 10.f, pos.y + 10.f);
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