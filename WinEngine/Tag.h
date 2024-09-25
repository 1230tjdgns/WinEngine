#pragma once
#include "framework.h"

namespace WE
{
	class Tag
	{
	public:
		Tag();
		~Tag();

		inline void SetName(const std::wstring& name)
		{
			this->name = name;
		}
		inline std::wstring GetName() const { return name; }

	private:
		std::wstring name;
	};
}


