#include "Camera.h"
#include "Transform.h"
#include "Entity.h"

namespace WE
{
	Camera::Camera() :
		Component(eComponentType::CAMERA),
		mTarget(nullptr),
		mPosition(Vector2::Zero),
		mOffset(Vector2::Zero)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::OnInitialize()
	{
	}

	void Camera::OnUpdate()
	{
	}

	void Camera::OnLateUpdate()
	{
		if (mTarget)
		{
			mPosition = mTarget->GetComponent<Transform>()->GetPosition() + mOffset;
		}
		else
		{
			mPosition = Vector2::Zero + mOffset;
		}
	}

	void Camera::OnRender(const HDC& hdc)
	{
	}

}