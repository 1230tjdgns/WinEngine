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

	template<typename T, typename F>
	void CopyIfVector(std::vector<T>& vec1, std::vector<T>& vec2, F func)
	{
		typedef std::vector<T>::iterator TIter;
		for (T& ele : vec1)
		{
			if (func(ele))
			{
				vec2.push_back(ele);
			}
		}
	}

	static void ToUpper(std::wstring& str)
	{
		for (TCHAR& ch : str)
		{
			ch = towupper(ch);
		}
	}

	static void ToLower(std::wstring& str)
	{
		for (TCHAR& ch : str)
		{
			ch = towlower(ch);
		}
	}

	static void DrawRectCenter(const HDC& hdc, const float x, const float y, const float width, const float height, const COLORREF penColor, const int penWidth = 1)
	{
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
		HPEN green = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, green);

		Rectangle(
			hdc,
			x - width / 2,
			y - height / 2,
			x + width / 2,
			y + height / 2);

		SelectObject(hdc, oldBrush);
		oldPen = (HPEN)SelectObject(hdc, oldPen);
		DeleteObject(green);
	}

	static void DrawCircleCenter(const HDC& hdc, const float x, const float y, const float radius, const COLORREF penColor, const int penWidth = 1)
	{
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
		HPEN green = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, green);

		Ellipse(
			hdc,
			x - radius,
			y - radius,
			x + radius,
			y + radius
		);

		SelectObject(hdc, oldBrush);
		oldPen = (HPEN)SelectObject(hdc, oldPen);
		DeleteObject(green);
	}
}