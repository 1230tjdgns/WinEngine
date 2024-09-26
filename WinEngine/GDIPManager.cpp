#include "GDIPManager.h"

namespace WE
{
	ULONG_PTR GDIPManager::mToken;
	Gdiplus::GdiplusStartupInput GDIPManager::mStartupInput;
	Gdiplus::GdiplusStartupOutput GDIPManager::mStartupOutput;
}

namespace WE
{
	GDIPManager::GDIPManager()
	{
	}

	GDIPManager::~GDIPManager()
	{
	}

	void GDIPManager::Initialize()
	{
		Gdiplus::GdiplusStartup(&mToken, &mStartupInput, &mStartupOutput);
	}

	void GDIPManager::Release()
	{
		Gdiplus::GdiplusShutdown(mToken);
	}

}