#include "Collider.h"
#include "Entity.h"
#include "Script.h"
#include "Transform.h"

namespace WE
{
	UINT32 Collider::colliderId = 0;
}

namespace WE
{

	Collider::Collider(eColliderType type) :
		Component(eComponentType::COLLIDER),
		mId(colliderId++),
		mPosition(Vector2::Zero),
		mOffset(Vector2::Zero),
		mType(type)
	{
		
	}

	Collider::~Collider()
	{
	}

	void Collider::OnUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		if (tr)
		{
			mPosition = tr->GetPosition() + mOffset;
		}
	}

	void Collider::OnLateUpdate()
	{
	}

	void Collider::CollisionEnter(Collider* other)
	{
		mCollisionEvents.enter(other);
	}

	void Collider::CollisionStay(Collider* other)
	{
		mCollisionEvents.stay(other);
	}

	void Collider::CollisionExit(Collider* other)
	{
		mCollisionEvents.exit(other);
	}

}