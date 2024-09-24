#pragma once
#include "framework.h"

namespace WE
{
	class Time
	{
	public:
		Time();
		~Time();

		static void Initialize();
		static void Tick();
		static void Render(const HDC hdc);

		static float GetDeltaTime() { return mDeltaTime; }

	private:
		static LARGE_INTEGER mCpuFreq;
		static LARGE_INTEGER mPrevCounter;
		static LARGE_INTEGER mNowCounter;

		static float mDeltaTime;

		static UINT count;
	};
}
