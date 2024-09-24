#include "Input.h"

namespace WE
{
	std::bitset<256> Input::mKeyDown = {};
	std::bitset<256> Input::mKeyUp = {};
}

namespace WE
{
	Input::Input()
	{
	}

	Input::~Input()
	{
	}

	void Input::Initialize()
	{
		mKeyDown.reset();
		mKeyUp.reset();
	}

	bool Input::IsKeyDown(const int key)
	{
		if (GetAsyncKeyState(key) & KEY_NOT_PREV_PRESS_NOW)
		{
			if (mKeyDown[key] == false)
			{
				mKeyDown[key] = true;
				return true;
			}
		}
		else
		{
			mKeyDown[key] = false;
		}

		return false;
	}

	bool Input::IsKeyUp(const int key)
	{
		if (GetAsyncKeyState(key) & KEY_NOT_PREV_PRESS_NOW)
		{
			mKeyUp[key] = true;
		}
		else
		{
			if (mKeyUp[key] == true)
			{
				mKeyUp[key] = false;
				return true;
			}
		}

		return false;
	}

	bool Input::IsKeyStay(const int key)
	{
		if (GetAsyncKeyState(key) & KEY_NOT_PREV_PRESS_NOW)
			return true;
		return false;
	}

	bool Input::IsKeyToggle(const int key)
	{
		if (GetKeyState(key) & KEY_PRESS_PREV_NOT_NOW)
			return true;
		return false;
	}
}