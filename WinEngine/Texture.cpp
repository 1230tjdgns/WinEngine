#include "Texture.h"
#include "CoreFunction.h"

namespace WE
{
	Texture::Texture() :
		Resource(eResourceType::TEXTURE),
		mBitmap(NULL),
		mMask(NULL),
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
		else
		{
			assert(false);
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

		if (mAlpha == false)
		{
			generateMask();
		}
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

	void Texture::generateMask()
	{
		BITMAP bitmap = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitmap);

		std::unique_ptr<BITMAPINFO[]> info { new BITMAPINFO[2] };
		info[0].bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		info[0].bmiHeader.biWidth = mWidth;
		info[0].bmiHeader.biHeight = mHeight;
		info[0].bmiHeader.biPlanes = 1;
		info[0].bmiHeader.biBitCount = bitmap.bmBitsPixel;
		info[0].bmiHeader.biCompression = BI_RGB;

		size_t bytePerPixel = bitmap.bmBitsPixel / 8;
		size_t dataSize = bitmap.bmWidthBytes * bitmap.bmHeight;
		std::unique_ptr<BYTE[]> pixels { new BYTE[dataSize] };

		HDC hdc = GetDC(NULL);
		GetDIBits(hdc, mBitmap, 0, info[0].bmiHeader.biHeight, pixels.get(), &info[0], DIB_RGB_COLORS);

		for (size_t i = 0; i < bitmap.bmWidth * bitmap.bmHeight * bytePerPixel; i+= bytePerPixel)
		{
			int b = (int)pixels[i];
			int g = (int)pixels[i+1];
			int r = (int)pixels[i+2];
		}

		ReleaseDC(NULL, hdc);
	}

}