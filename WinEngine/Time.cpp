#include "Time.h"

namespace WE
{
	LARGE_INTEGER Time::mCpuFreq = {};
	LARGE_INTEGER Time::mPrevCounter = {};
	LARGE_INTEGER Time::mNowCounter = {};
	LARGE_INTEGER Time::mStartCounter = {};
	float Time::mDeltaTime = 0.f;
	UINT64 Time::mRunningTime = 0;
	UINT Time::count = 0;
}

namespace WE
{
	Time::Time()
	{
	}

	Time::~Time()
	{
	}

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&mCpuFreq);
		QueryPerformanceCounter(&mNowCounter);
		mPrevCounter = mNowCounter;
		mStartCounter = mNowCounter;
	}

	void Time::Tick()
	{
		QueryPerformanceCounter(&mNowCounter);

		float deltaCounter = mNowCounter.QuadPart - mPrevCounter.QuadPart;

		// 델타 타임
		mDeltaTime = deltaCounter / mCpuFreq.QuadPart;
		// 프로그램 러닝 타임
		mRunningTime = (mNowCounter.QuadPart - mStartCounter.QuadPart) / mCpuFreq.QuadPart;

		mPrevCounter = mNowCounter;

		++count;
	}

	void Time::Render(const HDC& hdc)
	{
		static float second = 0.f;

		second += mDeltaTime;
		float fps = count / second;

		TOut(hdc, 10, 10, L"FPS : %.2f", fps);
		TOut(hdc, 10, 30, L"RunningTime : %llu", mRunningTime);

		if (second >= 1.f)
		{
			count = 0;
			second = 0.f;
		}
	}
}