#pragma once
#include "framework.h"

#define KEY_NOT_PREV_PRESS_NOW 0x8000
#define KEY_PRESS_PREV_NOT_NOW 0X0001

namespace WE
{
	class Input
	{
	public:
		Input();
		~Input();

		static void Initialize();

		static bool IsKeyDown(const int key);
		static bool IsKeyUp(const int key);
		static bool IsKeyStay(const int key);
		static bool IsKeyToggle(const int key);

	private:
		static std::bitset<256> mKeyDown;
		static std::bitset<256> mKeyUp;

	};
}

