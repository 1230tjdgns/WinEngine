#pragma once
#include "AnimationScript.h"

namespace WE
{
	class ASTest : public AnimationScript
	{
	public:
		enum class eState
		{
			STATE1,
			STATE2,
			STATE3,
			STATE4,
		};

	public:
		ASTest();
		~ASTest();

	public:
		bool OneToTwo();

		UINT GetState() const { return (UINT)mNowState; }

	protected:
		void OnInitialize() override;
		void OnUpdate() override;
		void OnRender(const HDC& hdc) override;

	private:
		std::unordered_map<eState, State> mStates;
		eState mNowState;

	private:
		size_t count;
	};
}

