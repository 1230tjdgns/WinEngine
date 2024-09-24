#pragma once

// Windows
#include <windows.h>
//#define WIN32_LEAN_AND_MEAN

// C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <crtdbg.h>

// C++
#include <vector>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cassert>
#include <string>

// 커스텀 헤더
#include "Enums.h"

// 매크로
#define WINCLASS	L"WinClass"
#define WINTITLE	L"WinEngine"

// 전역
namespace WE
{
	extern class GameCore core;
}
