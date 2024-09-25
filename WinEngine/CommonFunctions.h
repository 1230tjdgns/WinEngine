#pragma once
#include "framework.h"

namespace WE
{
	template<typename... T>
	void TOut(const HDC hdc, const float x, const float y, const std::wstring& format, const T... args)
	{
		TCHAR str[100];
		_swprintf(str, format.c_str(), args...);
		TextOutW(hdc, x, y, str, wcslen(str));
	}

	template<typename T, typename F>
	void EraseVector(std::vector<T>& vec, F func)
	{
		typedef std::vector<T>::iterator TIter;
		for (TIter iter = vec.begin(); iter != vec.end();)
		{
			if (func(*iter))
			{
				iter = vec.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}