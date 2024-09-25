#include "TestEntity.h"

namespace WE
{
	TestEntity::TestEntity()
	{
	}

	TestEntity::~TestEntity()
	{
	}
	void TestEntity::Initialize()
	{
		Entity::Initialize();
	}
	void TestEntity::Update()
	{
		Entity::Update();
	}
	void TestEntity::LateUpdate()
	{
		Entity::LateUpdate();
	}
	void TestEntity::Render(const HDC hdc)
	{
		Entity::Render(hdc);
	}
}