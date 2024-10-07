#include "Renderer.h"
#include "Entity.h"
#include "Sprite.h"
#include "Animator.h"
#include "Texture.h"

#define NO_ROTATE

namespace WE
{
	Renderer::Renderer() :
		Component(eComponentType::RENDERER),
		mRenderValue{},
		mRenderComp(nullptr)
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::OnInitialize()
	{
		mRenderComp = GetOwner()->GetComponent<Sprite>();
		RenderComponent* temp = GetOwner()->GetComponent<Animator>();
		if (temp)
			mRenderComp = temp;
	}

	void Renderer::OnUpdate()
	{
	}

	void Renderer::OnLateUpdate()
	{
	}

	void Renderer::OnRender(const HDC& hdc)
	{
		if (mRenderComp == nullptr)
			return;

		mRenderComp->GetRenderValue(mRenderValue);

		if (mRenderValue.texture == nullptr)
			return;

		switch (mRenderValue.texture->GetTextureType())
		{
		case eTextureType::BMP:
			gdiRender(hdc);
			break;
		case eTextureType::PNG:
		case eTextureType::JPG:
			gdipRender(hdc);
			break;
		default:
			assert(false);
			break;
		}
	}

	void Renderer::gdiRender(const HDC& hdc)
	{
		#ifdef NO_ROTATE
		if (mRenderValue.texture->IsAlpha())
		{
			BLENDFUNCTION blendFunc;
			blendFunc.BlendOp = AC_SRC_OVER;
			blendFunc.BlendFlags = 0;
			blendFunc.AlphaFormat = AC_SRC_ALPHA;
			blendFunc.SourceConstantAlpha = 255;

			AlphaBlend(
				hdc,
				mRenderValue.renderPos.x,
				mRenderValue.renderPos.y,
				mRenderValue.renderSize.x,
				mRenderValue.renderSize.y,
				mRenderValue.texture->GetHDC(),
				mRenderValue.sourcePos.x,
				mRenderValue.sourcePos.y,
				mRenderValue.sourceSize.x,
				mRenderValue.sourceSize.y,
				blendFunc);
		}
		else
		{

			TransparentBlt(
				hdc,
				mRenderValue.renderPos.x,
				mRenderValue.renderPos.y,
				mRenderValue.renderSize.x,
				mRenderValue.renderSize.y,
				mRenderValue.texture->GetHDC(),
				mRenderValue.sourcePos.x,
				mRenderValue.sourcePos.y,
				mRenderValue.sourceSize.x,
				mRenderValue.sourceSize.y,
				RGB(255, 0, 255)
			);
		}
			
		#else
		Vector2 lt = Vector2(-(mRenderValue.renderSize.x / 2), -(mRenderValue.renderSize.y / 2));
		Vector2 rt = Vector2(mRenderValue.renderSize.x / 2, -(mRenderValue.renderSize.y / 2));
		Vector2 lb = Vector2(-(mRenderValue.renderSize.x / 2), mRenderValue.renderSize.y / 2);

		lt = Vector2::Rotate(lt, 0);
		rt = Vector2::Rotate(rt, 0);
		lb = Vector2::Rotate(lb, 0);

		lt += mRenderValue.renderPos;
		rt += mRenderValue.renderPos;
		lb += mRenderValue.renderPos;

		POINT point[3];
		point[0] = { (long)round(lt.x), (long)round(lt.y) };
		point[1] = { (long)round(rt.x), (long)round(rt.y) };
		point[2] = { (long)round(lb.x), (long)round(lb.y) };

		PlgBlt(
			hdc,
			point,
			mRenderValue.texture->GetHDC(),
			mRenderValue.sourcePos.x,
			mRenderValue.sourcePos.y,
			mRenderValue.sourceSize.x,
			mRenderValue.sourceSize.y,
			mRenderValue.texture->GetMask(),
			mRenderValue.sourcePos.x,
			mRenderValue.sourcePos.y
		#endif
	}

	void Renderer::gdipRender(const HDC& hdc)
	{
		Gdiplus::Graphics graphic(hdc);

		Gdiplus::Rect rect;
		rect.X = mRenderValue.renderPos.x - (mRenderValue.sourceSize.x / 2.f);
		rect.Y = mRenderValue.renderPos.y - (mRenderValue.sourceSize.y / 2.f);
		rect.Width = mRenderValue.sourceSize.x;
		rect.Height = mRenderValue.sourceSize.y;

		graphic.DrawImage(
			mRenderValue.texture->GetImage(),
			rect);
	}

}