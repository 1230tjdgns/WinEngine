#include "Animation.h"
#include "ResourceManager.h"
#include "Texture.h"

namespace WE
{

	Animation::Animation() :
		Resource(eResourceType::ANIMATION),
		mFramePosition{},
		mFrameDuration(0.f),
		mFrameLength(0),
		mFrameWidth(0.f),
		mFrameHeight(0.f),
		mTexture(nullptr),
		mLoop(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::CreateAnimation(class Texture* texture, const float frameWidth, const float frameHeight, Vector2 startLeftTop, const float duration, const UINT length, const bool loop)
	{
		mTexture = texture;
		if (mTexture == nullptr)
			return E_FAIL;

		mFrameDuration = duration;
		mFrameLength = length;

		mFrameWidth = frameWidth;
		mFrameHeight = frameHeight;

		mLoop = loop;

		mFramePosition.reserve(length);

		for (size_t i = 0; i < length; ++i)
		{
			float x = startLeftTop.x + mFrameWidth * i;
			float y = startLeftTop.y;

			mFramePosition.push_back(Vector2(x, y));
		}

		return S_OK;
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_FAIL;
	}

	Vector2 Animation::GetFrameLeftTop(UINT frame) const
	{
		if (frame < mFramePosition.size())
		{
			return mFramePosition[frame];
		}

		return Vector2(-1, -1);
	}

	float Animation::GetWidth() const
	{
		if (mTexture)
		{
			return mTexture->GetWidth();
		}

		return 0.0f;
	}

	float Animation::GetHeight() const
	{
		if (mTexture)
		{
			return mTexture->GetHeight();
		}

		return 0.0f;
	}
}