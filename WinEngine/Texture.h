#pragma once
#include "Resource.h"

namespace WE
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;
		// GDI
		inline eTextureType GetTextureType() const { return mType; }
		HDC GetHDC() const { return mHdc; }
		bool IsAlpha() const { return mAlpha; }
		// GDI+
		Gdiplus::Image* GetImage() const { return mImage; }

		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }

		HBITMAP GetMask() { return NULL; }
	private:
		HBITMAP mBitmap;
		HBITMAP mMask;
		HDC mHdc;

		Gdiplus::Image* mImage;

		eTextureType mType;

		float mWidth;
		float mHeight;

		bool mAlpha;
	};
}

