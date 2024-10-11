#include "TestScene.h"
#include "TestEntity.h"
#include "TestEntity2.h"
#include "Global.h"
#include "CollisionManager.h"

namespace WE
{
	TestScene::TestScene()
	{
	}

	TestScene::~TestScene()
	{
	}

	void TestScene::OnInitialize()
	{
		CollisionManager::SetCollisionLayer(eLayerType::NONE, eLayerType::NONE);


		TestEntity* test = Global::CreateEntity<TestEntity>(eLayerType::NONE);
		TestEntity2* test2 = Global::CreateEntity<TestEntity2>(eLayerType::NONE);

	}

	void TestScene::OnUpdate()
	{
	}

	void TestScene::OnLateUpdate()
	{
	}

	void TestScene::OnRender(const HDC& hdc)
	{
		TOut(hdc, 10, 50, GetName());
	}

	void TestScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void TestScene::OnExit()
	{
		Scene::OnExit();
	}
}