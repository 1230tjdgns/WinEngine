#include "GameCore.h"
#include "Time.h"
#include "Input.h"
#include "SceneManager.h"

namespace WE
{
	GameCore::GameCore() :
		mHWnd(NULL),
		mHdc(NULL),
		mBackHdc(NULL),
		mBitmap(NULL),
		mWidth(0.f),
		mHeight(0.f)
	{
	}

	GameCore::~GameCore()
	{
	}

	void GameCore::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void GameCore::Initialize(HWND hWnd)
	{
		mHWnd = hWnd;
		mHdc = GetDC(mHWnd);

		setWindowSize();
		createBackHDC();

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void GameCore::Update()
	{
		Time::Tick();
		SceneManager::Update();
	}

	void GameCore::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void GameCore::Render()
	{
		clearScreen();

		SceneManager::Render(mBackHdc);
		Time::Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	void GameCore::Destroy()
	{
		SceneManager::Destroy();
	}

	void GameCore::Release()
	{
		SceneManager::Release();
	}

	void GameCore::createBackHDC()
	{
		mBackHdc = CreateCompatibleDC(mHdc);
		mBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBitmap);
		DeleteObject(oldBitmap);
	}

	void GameCore::setWindowSize()
	{
		RECT rect = {};
		GetWindowRect(mHWnd, &rect);
		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;
	}

	void GameCore::clearScreen()
	{
		SelectObject(mBackHdc, GetStockObject(DC_BRUSH));
		SetDCBrushColor(mBackHdc, RGB(128, 128, 128));
		Rectangle(mBackHdc, -1.f, -1.f, mWidth + 1.f, mHeight + 1.f);
		SetDCBrushColor(mBackHdc, RGB(255, 255, 255));
	}	
}