#pragma once
#include "framework.h"

namespace WE
{
	class GDIPManager
	{
	public:
		GDIPManager();
		~GDIPManager();

		static void Initialize();
		static void Release();

	private:
		static ULONG_PTR mToken;
		static Gdiplus::GdiplusStartupInput mStartupInput;
		static Gdiplus::GdiplusStartupOutput mStartupOutput;
	};
}

