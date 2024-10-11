#include "CircleCollider.h"
#include "CameraManager.h"

namespace WE
{

	CircleCollider::CircleCollider() :
		Collider(eColliderType::CIRCLE),
		mRadius(0.f)
	{
	}

	CircleCollider::~CircleCollider()
	{
	}

	void CircleCollider::OnInitialize()
	{
	}

	void CircleCollider::OnRender(const HDC& hdc)
	{
		Vector2 renderPos = CameraManager::CalculateWorldPos(mPosition);

		DrawCircleCenter(hdc, renderPos.x, renderPos.y, mRadius, RGB(0, 255, 0), 3);
	}

}