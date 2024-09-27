#include "TestEntity2.h"
#include "TestScript2.h"

namespace WE
{
	TestEntity2::TestEntity2()
	{
		AddComponent<TestScript2>(true);
	}

	TestEntity2::~TestEntity2()
	{
	}

	void TestEntity2::OnInitialize()
	{
	}

	void TestEntity2::OnUpdate()
	{
	}

	void TestEntity2::OnLateUpdate()
	{
	}

	void TestEntity2::OnRender(const HDC& hdc)
	{
	}

}