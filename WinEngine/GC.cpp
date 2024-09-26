#include "GC.h"
#include "SceneManager.h"
#include "Time.h"

namespace WE
{
	std::vector<Entity*> GC::mDestroyedEntities = {};
	float GC::mDeleteTimer = 0.f;
	float GC::mStorageDuration = 10.f;
}

namespace WE
{
	GC::GC()
	{
	}

	GC::~GC()
	{
	}

	void GC::Initialize()
	{
		mDestroyedEntities.reserve(50);
	}

	void GC::Run()
	{
		CollectDestroyedEntities();
		mDeleteTimer += Time::GetDeltaTime();
		if (mDeleteTimer >= 10.f)
		{
			mDeleteTimer = 0.f;
			DeleteDestroyedEntities();
		}
	}

	void GC::Release()
	{
		DeleteDestroyedEntities();
	}

	void GC::CollectDestroyedEntities()
	{
		SceneManager::GetActiveScene()->GetFilteredEntities(mDestroyedEntities, GC::FilterFunc);
		SceneManager::GetActiveScene()->EraseFilteredEntities(GC::FilterFunc);
	}

	void GC::DeleteDestroyedEntities()
	{
		for (Entity*& ent : mDestroyedEntities)
		{
			if (ent != nullptr)
			{
				delete ent;
				ent = nullptr;
			}
		}

		mDestroyedEntities.clear();
	}

	bool GC::FilterFunc(Entity* ent)
	{
		return ent->IsDestroy();
	}
}