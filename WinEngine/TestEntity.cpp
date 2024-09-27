#include "TestEntity.h"
#include "TestScript.h"

namespace WE
{
	TestEntity::TestEntity()
	{
		AddComponent<TestScript>(true);
	}

	TestEntity::~TestEntity()
	{
	}

	void TestEntity::OnInitialize()
	{
	}

	void TestEntity::OnUpdate()
	{
	}

	void TestEntity::OnLateUpdate()
	{
	}

	void TestEntity::OnRender(const HDC& hdc)
	{
	}

}