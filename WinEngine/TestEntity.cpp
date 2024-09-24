#include "TestEntity.h"
#include "Input.h"

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
		keytest = false;
	}
	void TestEntity::Update()
	{
		keytest = Input::IsKeyToggle(VK_SPACE);
	}
	void TestEntity::LateUpdate()
	{
	}
	void TestEntity::Render(const HDC hdc)
	{
		if (keytest)
		{
			Rectangle(hdc, 100, 100, 200, 200);

		}
	}
}