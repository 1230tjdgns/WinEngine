#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include "CameraManager.h"
#include "CommonFunctions.h"

namespace WE
{

	BoxCollider::BoxCollider() :
		Collider(eColliderType::BOX),
		mWidth(0.f),
		mHeight(0.f)
	{
	}

	BoxCollider::~BoxCollider()
	{
	}

	void BoxCollider::OnInitialize()
	{
	}

	void BoxCollider::OnRender(const HDC& hdc)
	{
		Vector2 renderPos = CameraManager::CalculateWorldPos(mPosition + mOffset);

		DrawRectCenter(hdc, renderPos.x, renderPos.y, mWidth, mHeight, RGB(0, 255, 0), 3);
	}

}