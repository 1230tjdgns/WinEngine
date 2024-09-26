#pragma once
#include "framework.h"

namespace WE
{
	class GC
	{
	public:
		GC();
		~GC();

		static void Initialize();
		static void Run();
		static void Release();
		static void CollectDestroyedEntities();
		static void DeleteDestroyedEntities();

		static void SetStorageDuration(const float duration) { mStorageDuration = duration; }
		static float GetStorageDuration() { return mStorageDuration; }

	private:
		static bool FilterFunc(class Entity* ent);

	private:
		static std::vector<class Entity*> mDestroyedEntities;
		static float mDeleteTimer;
		static float mStorageDuration;
	};
}

