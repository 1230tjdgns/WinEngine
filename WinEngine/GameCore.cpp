#include "GameCore.h"
#include "GDIPManager.h"
#include "Time.h"
#include "Input.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "GC.h"
#include "CameraManager.h"

//#define USE_DIB

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

	void GameCore::Initialize(const HWND hWnd)
	{
		mHWnd = hWnd;
		mHdc = GetDC(mHWnd);

		updateWindowSize();
		createBackHDC();

		GDIPManager::Initialize();
		Time::Initialize();
		Input::Initialize();
		ResourceManager::Initialize();
		GC::Initialize();
		CameraManager::Initialize();
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
		CameraManager::LateUpdate();
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
		GC::Run();
	}

	void GameCore::Release()
	{
		CameraManager::Clear();
		SceneManager::Release();
		GC::Release();
		ResourceManager::Release();
		GDIPManager::Release();
	}

	void GameCore::UpdateWindow()
	{
		updateWindowSize();
		createBackHDC();
		CameraManager::SetResolution(Vector2(mWidth, mHeight));
	}

	void GameCore::createBackHDC()
	{
		mBackHdc = CreateCompatibleDC(mHdc);

	#ifdef USE_DIB
		BITMAPINFO info = {};
		info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		info.bmiHeader.biWidth = mWidth;
		info.bmiHeader.biHeight = -mHeight;
		info.bmiHeader.biPlanes = 1;
		info.bmiHeader.biBitCount = 32;
		info.bmiHeader.biCompression = BI_RGB;
		
		void* pBits = nullptr;
		
		mBitmap = CreateDIBitmap(mHdc, &info.bmiHeader, DIB_RGB_COLORS, &pBits, NULL, 0);
	#else
		mBitmap = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
	#endif
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBitmap);
		DeleteObject(oldBitmap);
	}

	void GameCore::updateWindowSize()
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