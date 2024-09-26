#include "Transform.h"

namespace WE
{
	Transform::Transform() :
		Component(eComponentType::TRANSFORM),
		mPosition(Vector2::Zero)
	{
	}

	Transform::Transform(const Vector2& vec) :
		Component(eComponentType::TRANSFORM),
		mPosition(vec.x, vec.y)
	{
	}

	Transform::Transform(const float& x, const float& y) :
		Component(eComponentType::TRANSFORM),
		mPosition(x, y)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{
	}

	void Transform::LateUpdate()
	{
	}

	void Transform::Render(const HDC& hdc)
	{
	}
}