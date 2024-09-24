#pragma once
#include "framework.h"

namespace WE
{
	class GameCore
	{
	public:
		GameCore();
		~GameCore();

		void Run();

		void Initialize(HWND hWnd);
		void Update();
		void LateUpdate();
		void Render();
		void Destroy();

		void Release();

		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }

	private:
		void createBackHDC();
		void setWindowSize();
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

