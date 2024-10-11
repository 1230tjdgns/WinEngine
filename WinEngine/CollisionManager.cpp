#include "CollisionManager.h"
#include "SceneManager.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

namespace WE
{
	std::bitset<CollisionManager::MAX_LAYER> CollisionManager::mLayerCollision[CollisionManager::MAX_LAYER];
	CollisionManager::CollisionStatus CollisionManager::mCollisionStatus;
}

namespace WE
{

	CollisionManager::CollisionManager()
	{
	}

	CollisionManager::~CollisionManager()
	{
	}

	void CollisionManager::Initialize()
	{
	}

	void CollisionManager::Update()
	{
		checkLayer();
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(const HDC& hdc)
	{
	}

	void CollisionManager::SetCollisionLayer(eLayerType type1, eLayerType type2, bool enable)
	{
		UINT index1 = (UINT)type1 < (UINT)type2 ? (UINT)type1 : (UINT)type2;
		UINT index2 = (UINT)type1 < (UINT)type2 ? (UINT)type2 : (UINT)type1;

		mLayerCollision[index1][index2] = enable;
	}

	void CollisionManager::checkLayer()
	{
		Scene* scene = SceneManager::GetActiveScene();

		if (scene == nullptr)
			return;

		for (size_t i = 0; i < MAX_LAYER; ++i)
		{
			for (size_t j = 0; j < MAX_LAYER - i; ++j)
			{
				if (mLayerCollision[i][j] == true)
				{
					checkEntities(scene, (eLayerType)i, (eLayerType)j);
				}
			}
		}
	}

	void CollisionManager::checkEntities(Scene* scene, eLayerType type1, eLayerType type2)
	{
		std::vector<Entity*>& entities1 = *scene->GetLayerEntities(type1);
		std::vector<Entity*>& entities2 = *scene->GetLayerEntities(type2);

		for (Entity*& entity1 : entities1)
		{
			if (entity1->IsDestroy() || entity1->IsEnable() == false)
				continue;
			Collider* collider1 = entity1->GetComponent<Collider>();
			if (collider1 == nullptr)
				continue;

			for (Entity*& entity2 : entities2)
			{
				if (entity1 == entity2)
					continue;

				if (entity2->IsDestroy() || entity2->IsEnable() == false)
					continue;

				Collider* collider2 = entity2->GetComponent<Collider>();
				if (collider2 == nullptr)
					continue;

				checkCollision(collider1, collider2);
			}
		}
	}

	void CollisionManager::checkCollision(Collider* collider1, Collider* collider2)
	{
		CollisionEntities ids = {};
		ids.st_ids.target1 = collider1->GetId();
		ids.st_ids.target2 = collider2->GetId();

		CollisionStatus::iterator statusIter = mCollisionStatus.find(ids.ids);
		if (statusIter == mCollisionStatus.end())
		{
			mCollisionStatus.insert(std::make_pair(ids.ids, false));
			statusIter = mCollisionStatus.find(ids.ids);
		}

		if (Intersect(collider1, collider2))
		{
			if (statusIter->second == false)
			{
				collider1->CollisionEnter(collider2);
				collider2->CollisionEnter(collider1);
				statusIter->second = true;
			}
			else
			{
				collider1->CollisionStay(collider2);
				collider2->CollisionStay(collider1);
			}
		}
		else
		{
			if (statusIter->second == true)
			{
				collider1->CollisionEnter(collider2);
				collider2->CollisionEnter(collider1);
				statusIter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* collider1, Collider* collider2)
	{
		eColliderType type1 = collider1->GetColliderType();
		eColliderType type2 = collider2->GetColliderType();

		if (type1 == eColliderType::BOX && type2 == eColliderType::BOX)
		{
			return boxCollision(collider1, collider2);
		}
		if (type1 == eColliderType::CIRCLE && type2 == eColliderType::CIRCLE)
		{
			return circleCollision(collider1, collider2);
		}
		if (type1 == eColliderType::BOX && type2 == eColliderType::CIRCLE)
		{
			return boxAndCircleCollision(collider1, collider2);
		}
		else if (type1 == eColliderType::CIRCLE && type2 == eColliderType::BOX)
		{
			return boxAndCircleCollision(collider2, collider1);
		}

		return false;
	}

	bool CollisionManager::boxCollision(Collider* collider1, Collider* collider2)
	{
		BoxCollider* box1 = static_cast<BoxCollider*>(collider1);
		BoxCollider* box2 = static_cast<BoxCollider*>(collider2);

		Vector2 pos1 = box1->GetPosition();
		Vector2 pos2 = box2->GetPosition();

		float width1 = box1->GetWidth();
		float height1 = box1->GetHeight();

		float width2 = box2->GetWidth();
		float height2 = box2->GetHeight();

		float deltaPosX = fabs(pos1.x - pos2.x);
		float deltaPosY = fabs(pos1.y - pos2.y);

		if (deltaPosX <= width1 / 2 + width2 / 2 &&
			deltaPosY <= height1 / 2 + height2 / 2)
		{
			return true;
		}

		return false;

	}

	bool CollisionManager::circleCollision(Collider* collider1, Collider* collider2)
	{
		CircleCollider* circle1 = static_cast<CircleCollider*>(collider1);
		CircleCollider* circle2 = static_cast<CircleCollider*>(collider2);

		Vector2 pos1 = circle1->GetPosition();
		Vector2 pos2 = circle2->GetPosition();

		float radius1 = circle1->GetRadius();
		float radius2 = circle2->GetRadius();

		float distance = Vector2::Distance(pos1, pos2);

		if (distance <=  radius1 + radius2)
		{
			return true;
		}

		return false;
	}

	bool CollisionManager::boxAndCircleCollision(Collider* boxCollider, Collider* circleCollider)
	{
		BoxCollider* box = static_cast<BoxCollider*>(boxCollider);
		CircleCollider* circle = static_cast<CircleCollider*>(circleCollider);

		Vector2 boxPos = box->GetPosition();
		float width = box->GetWidth();
		float height = box->GetHeight();

		Vector2 boxLT = Vector2(boxPos.x - width / 2, boxPos.y - height / 2);
		Vector2 boxRT = Vector2(boxPos.x + width / 2, boxPos.y - height / 2);
		Vector2 boxLB = Vector2(boxPos.x - width / 2, boxPos.y + height / 2);
		Vector2 boxRB = Vector2(boxPos.x + width / 2, boxPos.y + height / 2);

		Vector2 circlePos = circle->GetPosition();
		float radius = circle->GetRadius();

		float deltaPosX = fabs(circlePos.x - boxPos.x);
		float deltaPosY = fabs(circlePos.y - boxPos.y);

		if (deltaPosX <= width / 2 ||
			deltaPosY <= height / 2)
		{
			if (deltaPosX <= width / 2 + radius &&
				deltaPosY <= height / 2 + radius)
			{
				return true;
			}
		}
		else
		{
			if (Vector2::Distance(boxLT, circlePos) <= radius ||
				Vector2::Distance(boxRT, circlePos) <= radius ||
				Vector2::Distance(boxLB, circlePos) <= radius ||
				Vector2::Distance(boxRB, circlePos) <= radius)
			{
				return true;
			}
		}

		return false;
	}
}