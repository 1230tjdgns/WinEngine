#include "CoreFunction.h"
#include "GameCore.h"

extern WE::GameCore core;

namespace WE
{
	namespace Global
	{
		HDC GetCoreDC()
		{
			return core.GetHDC();
		}

		Vector2 GetWindowSize()
		{
			return Vector2(core.GetWidth(), core.GetHeight());
		}
	}
}
