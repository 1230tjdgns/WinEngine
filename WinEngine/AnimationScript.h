#pragma once
#include "Tag.h"

namespace WE
{
	class AnimationScript : public Tag
	{
	public:
		struct Transition
		{
			std::function<bool()> transitionFunc;
			UINT targetState;

			Transition(std::function<bool()> func, UINT state) :
				transitionFunc(func),
				targetState(state)
			{}
		};

		struct State
		{
			std::function<void()> initFunc;
			std::vector<Transition> transitions;

			State() :
				initFunc(nullptr),
				transitions{}
			{}
		};

	public:
		AnimationScript();
		virtual ~AnimationScript();

		void Initialize();
		void Update();
		void Render(const HDC& hdc);

		template<typename T>
		void CheckTransition(T& nowState, std::unordered_map<T, State>& states)
		{
			states[nowState];
			
			for (Transition& transition : states[nowState].transitions)
			{
				bool result = false;
				if (transition.transitionFunc)
					result = transition.transitionFunc();

				if (result)
					ChangeState(states, nowState, (T)transition.targetState);
			}
		}

		template<typename T, typename F, typename R>
		void SetStateInitFunction(std::unordered_map<T, State>& states, T state, F&& func, R&& ref)
		{
			states[state];

			states[state].initFunc = std::bind(func, ref);
		}

		template<typename T, typename F, typename R>
		void AddTransition(std::unordered_map<T, State>& states, T state, T otherState, F&& func, R&& ref)
		{
			;

			std::function<bool()> bindFunc = std::bind(func, ref);

			states[state].transitions.emplace_back(bindFunc, (UINT)otherState);
		}

		template<typename T>
		void ChangeState(std::unordered_map<T, State>& states, T& nowState, T changeState)
		{
			if (nowState == changeState)
				return;

			nowState = changeState;

			if (states[nowState].initFunc)
				states[nowState].initFunc();
		}

		virtual UINT GetState() const = 0;

	protected:
		virtual void OnInitialize() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender(const HDC& hdc) = 0;

	};
}

