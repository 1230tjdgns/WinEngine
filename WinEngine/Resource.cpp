#include "Resource.h"

namespace WE
{
	Resource::Resource(eResourceType type) :
		mType(type),
		mPath{}
	{
	}

	Resource::~Resource()
	{
	}
}