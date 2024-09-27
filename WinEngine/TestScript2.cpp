#include "TestScript2.h"
#include "Transform.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Entity.h"
#include "Sprite.h"
#include "Camera.h"
#include "Input.h"
#include "CameraManager.h"

namespace WE
{
	TestScript2::TestScript2()
	{
	}

	TestScript2::~TestScript2()
	{
	}

	void TestScript2::OnInitialize()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Texture* tex = ResourceManager::Get<Texture>(L"cow");
		tr->SetPosition(Vector2(tex->GetWidth() / 2, tex->GetHeight() / 2));
		Sprite* sp = GetOwner()->AddComponent<Sprite>();
		sp->SetTexture(tex);
		Camera* cam = GetOwner()->AddComponent<Camera>();
		cam->SetTarget(GetOwner());
	}

	void TestScript2::OnUpdate()
	{
		if (Input::IsKeyDown('X'))
		{
			Camera* cam = GetOwner()->GetComponent<Camera>();
			CameraManager::SetTargetCamera(cam);
		}
	}

	void TestScript2::OnLateUpdate()
	{
	}

	void TestScript2::OnRender(const HDC& hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = CameraManager::CalculateWorldPos(pos);
		Rectangle(hdc, pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10);
	}

	void TestScript2::OnCollisionEnter()
	{
	}

	void TestScript2::OnCollisionStay()
	{
	}

	void TestScript2::OnCollisionExit()
	{
	}

}