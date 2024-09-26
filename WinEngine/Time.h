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
		static void Render(const HDC& hdc);

		static inline float GetDeltaTime() { return mDeltaTime; }

		static inline UINT64 GetRunningTime() { return mRunningTime; }

	private:
		static LARGE_INTEGER mCpuFreq;
		static LARGE_INTEGER mPrevCounter;
		static LARGE_INTEGER mNowCounter;
		static LARGE_INTEGER mStartCounter;

		static float mDeltaTime;
		static UINT64 mRunningTime;

		static UINT count;
	};
}
