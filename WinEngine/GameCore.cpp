#include "GameCore.h"

namespace WE
{
	GameCore::GameCore() :
		mHWnd(NULL),
		mHdc(NULL)
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
	}

	void GameCore::Update()
	{
	}

	void GameCore::LateUpdate()
	{
	}

	void GameCore::Render()
	{
		clearScreen();

		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}

	void GameCore::Destroy()
	{
	}

	void GameCore::Release()
	{
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