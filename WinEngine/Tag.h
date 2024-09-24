#pragma once
#include "framework.h"

namespace WE
{
	class Tag
	{
	public:
		Tag();
		~Tag();

		void SetName(const std::wstring& name)
		{
			this->name = name;
		}
		std::wstring GetName() const { return name; }

	private:
		std::wstring name;
	};
}


