#include "TestScene.h"
#include "TestEntity.h"
#include "Global.h"
#include "TestScript.h"

namespace WE
{
	TestScene::TestScene()
	{
	}

	TestScene::~TestScene()
	{
	}

	void TestScene::Initialize()
	{
		Scene::Initialize();

		TestEntity* test = Global::CreateEntity<TestEntity>(eLayerType::NONE);
		test->AddComponent<TestScript>();
	}

	void TestScene::Update()
	{
		Scene::Update();
	}

	void TestScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TestScene::Render(const HDC& hdc)
	{
		Scene::Render(hdc);

		TOut(hdc, 10, 50, L"TEST");
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