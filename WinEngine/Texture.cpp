#include "Texture.h"
#include "ImageLoader.h"

namespace WE
{
	Texture::Texture() :
		Resource(eResourceType::TEXTURE),
		mBitmap(NULL),
		mMask(NULL),
		mHdc(NULL),
		mImage(nullptr),
		mType(eTextureType::BMP),
		mWidth(0.f),
		mHeight(0.f),
		mAlpha(false)
	{
	}

	Texture::~Texture()
	{
		DeleteDC(mHdc);
		DeleteObject(mBitmap);
		//DeleteObject(mMask);
		delete mImage;
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of('.') + 1);
		ToUpper(ext);

		Image::ImageInfo info;
		HRESULT result;

		if (ext == L"BMP")
		{
			result = Image::LoadBMP(path, mBitmap, mHdc, info);
		}
		else if (ext == L"PNG")
		{
			result = Image::LoadPNG(path, &mImage, info);
		}
		else if (ext == L"JPG" || ext == L"JPEG")
		{
			result = Image::LoadJPG(path, &mImage, info);
		}
		else
		{
			assert(false);
		}

		if (result == E_FAIL)
			return result;

		mType = info.type;
		mWidth = info.width;
		mHeight = info.height;
		mAlpha = info.alpha;

		return S_OK;
	}
}