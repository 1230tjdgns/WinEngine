#include "ASTest.h"

namespace WE
{

	ASTest::ASTest() :
		mStates{},
		mNowState(eState::STATE1),
		count(0)
	{
	}

	ASTest::~ASTest()
	{
	}

	void ASTest::OnInitialize()
	{
		AddTransition(mStates, eState::STATE1, eState::STATE2, &ASTest::OneToTwo, this);

		ChangeState(mStates, mNowState, eState::STATE1);
	}

	void ASTest::OnUpdate()
	{
		count++;

		CheckTransition(mNowState, mStates);
	}

	void ASTest::OnRender(const HDC& hdc)
	{
		TOut(hdc, 10, 400, L"State : %d", (UINT)mNowState);
		TOut(hdc, 10, 420, L"count : %d", count);
	}

	bool ASTest::OneToTwo()
	{
		if (count >= 1000)
			return true;

		return false;
	}

}