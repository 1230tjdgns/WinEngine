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

	void Camera::Initialize()
	{
	}

	void Camera::Update()
	{
	}

	void Camera::LateUpdate()
	{
		if (mTarget)
		{
			mPosition = mTarget->GetComponent<Transform>()->GetPosition();
		}
		else
		{
			mPosition = Vector2::Zero;
		}
	}

	void Camera::Render(const HDC& hdc)
	{
	}

}