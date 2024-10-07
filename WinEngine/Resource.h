#pragma once
#include "Tag.h"

namespace WE
{
	class Resource : public Tag
	{
	public:
		Resource(eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		inline eResourceType GetResourceType() const { return mType; }

		inline void SetPath(const std::wstring& path) { mPath = path; }
		inline std::wstring GetPath() const { return mPath; }

	private:
		eResourceType mType;
		std::wstring mPath;
	};
}

