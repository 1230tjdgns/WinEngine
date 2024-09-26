#include "CameraManager.h"
#include "Camera.h"
#include "CoreFunction.h"

namespace WE
{
	Camera* CameraManager::mTargetCamera = nullptr;
	Vector2 CameraManager::mResolution = Vector2::Zero;
	Vector2 CameraManager::mDistance = Vector2::Zero;
}

namespace WE
{
	CameraManager::CameraManager()
	{
	}

	CameraManager::~CameraManager()
	{
	}

	void CameraManager::Initialize()
	{
		SetResolution(Global::GetWindowSize());
	}

	void CameraManager::LateUpdate()
	{
		if (mTargetCamera)
		{
			mDistance = mTargetCamera->GetPosition() - (mResolution / 2);
		}
		else
		{
			mDistance = Vector2::Zero - (mResolution / 2);
		}
	}

	void CameraManager::Clear()
	{
		mTargetCamera = nullptr;
	}

	Vector2 CameraManager::CalculateWorldPos(const Vector2& pos)
	{
		return pos - mDistance;
	}

	Vector2 CameraManager::CalculateScreenPos(const Vector2& pos)
	{
		return pos + mDistance;
	}

}