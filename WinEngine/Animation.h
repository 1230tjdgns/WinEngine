#pragma once
#include "Resource.h"

namespace WE
{
	class Animation : public Resource
	{
	public:
		Animation();
		~Animation();

		HRESULT CreateAnimation(class Texture* texture, const float frameWidth, const float frameHeight, Vector2 startLeftTop, const float duration, const UINT length, const bool loop);

		HRESULT Load(const std::wstring& path) override;

		inline float GetFrameDuration() const { return mFrameDuration; }
		inline float GetFrameLength() const { return mFrameLength; }
		inline float GetFrameWidth() const { return mFrameWidth; }
		inline float GetFrameHeight() const { return mFrameHeight; }
		inline Texture* GetTexture() const { return mTexture; }
		inline bool IsLoop() const { return mLoop; }
		Vector2 GetFrameLeftTop(UINT frame) const;
		float GetWidth() const;
		float GetHeight() const;

	private:
		std::vector<Vector2> mFramePosition;
		float mFrameDuration;
		UINT mFrameLength;
		float mFrameWidth;
		float mFrameHeight;
		bool mLoop;

		class Texture* mTexture;
	};
}

