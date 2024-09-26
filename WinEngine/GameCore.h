#pragma once
#include "framework.h"
#include "Scene.h"
#include "TestEntity.h"

namespace WE
{
	class GameCore
	{
	public:
		GameCore();
		~GameCore();

		void Run();

		void Initialize(const HWND hWnd);
		void Update();
		void LateUpdate();
		void Render();
		void Destroy();

		void Release();

		inline float GetWidth() const { return mWidth; }
		inline float GetHeight() const { return mHeight; }

		inline HDC GetHDC() const { return mHdc; }

		void UpdateWindow();

	private:
		void createBackHDC();
		void updateWindowSize();
		void clearScreen();

	private:
		HWND mHWnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBitmap;

		float mWidth;
		float mHeight;
	};
}

