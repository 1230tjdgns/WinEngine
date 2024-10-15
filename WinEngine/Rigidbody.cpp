#include "Rigidbody.h"
#include "Time.h"
#include "Transform.h"
#include "Entity.h"
#include "CameraManager.h"
#include "DefaultSetting.h"

namespace WE
{
	Rigidbody::Rigidbody() :
		Component(eComponentType::RIGIDBODY),
		mAcceleration(Vector2::Zero),
		mVelocity(Vector2::Zero),
		mForce(Vector2::Zero),
		mGravity(DEFAULT_RIGIDBODY_GRAVITY),
		mMaxVelocity(DEFAULT_RIGIDBODY_MAXVELOCITY),
		mMass(DEFAULT_RIGIDBODY_MASS),
		mFriction(DEFAULT_RIGIDBODY_FRICTION),
		mGround(false)
	{
	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::OnInitialize()
	{
	}

	void Rigidbody::OnUpdate()
	{
		mAcceleration = mForce / mMass;

		mVelocity += mAcceleration * Time::GetDeltaTime();
		
		applyGravity();
		applyMaxVelocity();
		applyFriction();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos += mVelocity * Time::GetDeltaTime();
		tr->SetPosition(pos);

		mForce = Vector2::Zero;
	}

	void Rigidbody::OnLateUpdate()
	{
	}

	void Rigidbody::OnRender(const HDC& hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		if (tr)
		{
			Vector2 pos = tr->GetPosition();
			pos = CameraManager::CalculateWorldPos(pos);
			TOut(hdc, pos.x, pos.y, L"Velocity: X=%.2f, Y=%.2f", mVelocity.x, mVelocity.y);
		}
	}

	void Rigidbody::applyGravity()
	{
		if (mGround)
		{
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = Vector2::Dot(mVelocity, gravity);

			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * Time::GetDeltaTime();
		}

		
	}

	void Rigidbody::applyMaxVelocity()
	{
		Vector2 gravity = mGravity;
		gravity.Normalize();

		float dot = Vector2::Dot(mVelocity, gravity);

		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;

		if (mMaxVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mMaxVelocity.y;
		}
		if (mMaxVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mMaxVelocity.x;
			int a = 0;
		}

		mVelocity = gravity + sideVelocity;
	}

	void Rigidbody::applyFriction()
	{
		if (mVelocity != Vector2::Zero)
		{
			Vector2 friction = -mVelocity;
			friction = friction.Normalize() * mFriction * mMass * Time::GetDeltaTime();

			if (mVelocity.Length() <= friction.Length())
			{
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}

		}
	}

}