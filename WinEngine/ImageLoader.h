#pragma once
#include "framework.h"
#include "CoreFunction.h"

namespace WE
{
	namespace Image
	{
		struct ImageInfo
		{
			eTextureType type;
			float width;
			float height;
			bool alpha;
		};

		static HRESULT LoadBMP(const std::wstring& path, HBITMAP& bitmap, HDC& hdc, ImageInfo& info)
		{
			bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
			hdc = CreateCompatibleDC(Global::GetCoreDC());

			#ifdef _DEBUG
			assert(bitmap);
			#else
			return E_FAIL;
			#endif

			HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap);
			DeleteObject(oldBitmap);

			BITMAP bitmapInfo = {};
			GetObject(bitmap, sizeof(BITMAP), &bitmapInfo);

			info.type = eTextureType::BMP;
			info.width = bitmapInfo.bmWidth;
			info.height = bitmapInfo.bmHeight;
			info.alpha = bitmapInfo.bmBitsPixel == 32 ? true : false;

			return S_OK;
		}
		static HRESULT LoadPNG(const std::wstring& path, Gdiplus::Image** image, ImageInfo& info)
		{
			*image = Gdiplus::Image::FromFile(path.c_str());

			#ifdef _DEBUG
			assert(*image);
			#else
			return E_FAIL;
			#endif

			info.type = eTextureType::PNG;

			info.width = (*image)->GetWidth();
			info.height = (*image)->GetHeight();

			return S_OK;
		}

		static HRESULT LoadJPG(const std::wstring& path, Gdiplus::Image** image, ImageInfo& info)
		{
			HRESULT result = LoadPNG(path, image, info);

			info.type = eTextureType::JPG;

			return result;
		}

		static void generateMask(size_t move)
		{
			// 연구 필요
			/*
			
			BITMAP bitmap = {};
			GetObject(mBitmap, sizeof(BITMAP), &bitmap);

			std::unique_ptr<BITMAPINFO> info{ new BITMAPINFO };

			info.get()->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
			info.get()->bmiHeader.biWidth = bitmap.bmWidth;
			info.get()->bmiHeader.biHeight = -bitmap.bmHeight;
			info.get()->bmiHeader.biPlanes = 1;
			info.get()->bmiHeader.biBitCount = bitmap.bmBitsPixel;
			info.get()->bmiHeader.biCompression = BI_RGB;

			size_t bytePerPixel = bitmap.bmBitsPixel / 8;

			if (bytePerPixel < 1)
				bytePerPixel = 1;

			size_t dataSize = (size_t)bitmap.bmWidthBytes * (size_t)bitmap.bmHeight;
			std::unique_ptr<BYTE[]> pixels{ new BYTE[dataSize] };
			ZeroMemory(pixels.get(), sizeof(BYTE) * dataSize);

			size_t maskSize = (size_t)bitmap.bmWidth * (size_t)bitmap.bmHeight;
			std::unique_ptr<BYTE[]> maskPixels{ new BYTE[dataSize] };
			ZeroMemory(maskPixels.get(), sizeof(BYTE) * dataSize);

			GetDIBits(
				Global::GetCoreDC(),
				mBitmap,
				0,
				bitmap.bmHeight,
				pixels.get(),
				info.get(),
				DIB_RGB_COLORS);

			size_t count2 = 0;
			size_t count = 0;
			size_t maskPixelIndex = 0;

			for (size_t h = 0; h < bitmap.bmHeight; h++)
			{
				for (size_t w = 0; w < bitmap.bmWidthBytes; w += bytePerPixel)
				{
					size_t index = (h * (bitmap.bmWidthBytes)) + w;

					short b = (short)pixels[index];
					short g = (short)pixels[index + 1];
					short r = (short)pixels[index + 2];

					//if (w >= bitmap.bmWidth * bytePerPixel)
					//	continue;
					count2++;

					if ((b == 255 && g == 0 && r == 255) == true) {
						maskPixels[maskPixelIndex] = maskPixels[maskPixelIndex] | 1;
						if (GetName() == L"pixels")
							std::cout << "1";
					}
					else
					{
						if (GetName() == L"pixels")
							std::cout << "0";
					}

					if (count % 8 == 7)
					{
						maskPixelIndex++;
					}
					else
					{
						maskPixels[maskPixelIndex] = maskPixels[maskPixelIndex] << 1;
					}

					count++;
				}

				if (GetName() == L"pixels")
					std::cout << std::endl;
			}

			if (count % 8 != 0)
			{
				maskPixels[maskPixelIndex] = maskPixels[maskPixelIndex] << 7 - (count % 8);
			}

			mMask = CreateBitmap(
				//bitmap.bmWidth,
				//bitmap.bmHeight,
				7,5,
				1,
				1,
				maskPixels.get());

			if (GetName() == L"pixels")
			{
				for (size_t i = 0; i < bitmap.bmWidth * bitmap.bmHeight; ++i) {
					std::bitset<8> binary(maskPixels[i]); // BYTE는 8비트
					std::cout << "byteArray[" << i << "] = " << binary << std::endl;
				}
			}
			//std::cout << count2 << std::endl;

			int end = 0;
			
			*/
		}
	}
}