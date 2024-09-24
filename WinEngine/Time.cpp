#include "Time.h"

namespace WE
{
	LARGE_INTEGER Time::mCpuFreq = {};
	LARGE_INTEGER Time::mPrevCounter = {};
	LARGE_INTEGER Time::mNowCounter = {};
	float Time::mDeltaTime = 0.f;
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
	}

	void Time::Tick()
	{
		QueryPerformanceCounter(&mNowCounter);

		float deltaCounter = mNowCounter.QuadPart - mPrevCounter.QuadPart;

		mDeltaTime = deltaCounter / mCpuFreq.QuadPart;

		mPrevCounter = mNowCounter;

		++count;
	}

	void Time::Render(const HDC hdc)
	{
		static float second = 0.f;

		second += mDeltaTime;
		float fps = count / second;

		TOut(hdc, 10, 10, L"deltaTime : %f", fps);

		if (second >= 1.f)
		{
			count = 0;
			second = 0.f;
		}
	}
}