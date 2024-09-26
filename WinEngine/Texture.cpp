#include "Texture.h"
#include "CoreFunction.h"

namespace WE
{
	Texture::Texture() :
		Resource(eResourceType::TEXTURE),
		mBitmap(NULL),
		mHdc(NULL),
		mType(eTextureType::BMP),
		mWidth(0.f),
		mHeight(0.f),
		mAlpha(false)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of('.') + 1);
		ToUpper(ext);

		if (ext == L"BMP")
		{
			loadBMP(path);
		}
		else if (ext == L"PNG")
		{
			loadPNG(path);
		}
		else if (ext == L"JPG" || ext == L"JPEG")
		{
			loadJPG(path);
		}

		return S_OK;
	}

	void Texture::loadBMP(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
		mHdc = CreateCompatibleDC(Global::GetCoreDC());

		assert(mBitmap);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(oldBitmap);

		BITMAP info = {};
		GetObject(mBitmap, sizeof(BITMAP), &info);

		mType = eTextureType::BMP;
		mWidth = info.bmWidth;
		mHeight = info.bmHeight;
		mAlpha = info.bmBitsPixel == 32 ? true : false;
	}

	void Texture::loadPNG(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());

		assert(mImage);

		mType = eTextureType::PNG;

		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}

	void Texture::loadJPG(const std::wstring& path)
	{
		loadPNG(path);

		mType = eTextureType::JPG;
	}

}