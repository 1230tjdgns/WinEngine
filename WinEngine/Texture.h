#pragma once
#include "Resource.h"

namespace WE
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path) override;
		// GDI
		inline eTextureType GetTextureType() const { return mType; }
		HDC GetDC() const { return mHdc; }
		bool IsAlpha() const { return mAlpha; }
		// GDI+
		Gdiplus::Image* GetImage() const { return mImage; }

		float GetWidth() const { return mWidth; }
		float GetHeight() const { return mHeight; }
	private:
		void loadBMP(const std::wstring& path);
		void loadPNG(const std::wstring& path);
		void loadJPG(const std::wstring& path);

	private:
		HBITMAP mBitmap;
		HDC mHdc;

		Gdiplus::Image* mImage;

		eTextureType mType;

		float mWidth;
		float mHeight;

		bool mAlpha;
	};
}

