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
#include <set>
#include <unordered_set>
#include <memory>

// 그래픽
#include <wingdi.h>
#include <gdiplus.h>

// 라이브러리
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "gdiplus.lib")
#pragma comment (lib, "msimg32.lib")

// 커스텀 헤더
#include "Enums.h"
#include "CommonFunctions.h"
#include "Math.h"

// 매크로
#define WINCLASS	L"WinClass"
#define WINTITLE	L"WinEngine"

