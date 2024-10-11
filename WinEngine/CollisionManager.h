#pragma once
#include "framework.h"

namespace WE
{
	class CollisionManager
	{
	public:
		union CollisionEntities
		{
			struct
			{
				UINT32 target1;
				UINT32 target2;
			} st_ids;

			UINT64 ids;
		};
	public:
		CollisionManager();
		~CollisionManager();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(const HDC& hdc);

		static void SetCollisionLayer(eLayerType type1, eLayerType type2, bool enable = true);

	private:
		static void checkLayer();
		static void checkEntities(class Scene* scene, eLayerType type1, eLayerType type2);
		static void checkCollision(class Collider* collider1, class Collider* collider2);
		static bool Intersect(class Collider* collider1, class Collider* collider2);

		static bool boxCollision(class Collider* collider1, class Collider* collider2);
		static bool circleCollision(class Collider* collider1, class Collider* collider2);
		static bool boxAndCircleCollision(class Collider* boxCollider, class Collider* circleCollider);

	private:
		static constexpr UINT MAX_LAYER = (UINT)eLayerType::END;
		typedef std::unordered_map<UINT64, bool> CollisionStatus;
	private:
		static std::bitset<MAX_LAYER> mLayerCollision[MAX_LAYER];
		static CollisionStatus mCollisionStatus;
	};
}

