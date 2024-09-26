#pragma once
#include "framework.h"

namespace WE
{
	class CameraManager
	{
	public:
		CameraManager();
		~CameraManager();

		static void Initialize();
		static void LateUpdate();
		static void Clear();

		static Vector2 CalculateWorldPos(const Vector2& pos);
		static Vector2 CalculateScreenPos(const Vector2& pos);

		static void SetTargetCamera(class Camera* const cameraComp) { mTargetCamera = cameraComp; }
		static class Camera* GetTargetCameraComp() { return mTargetCamera; }

		static void SetResolution(Vector2 size) { mResolution = size; }
		static Vector2 GetResolution() { return mResolution; }

	private:
		static class Camera* mTargetCamera;
		static Vector2 mResolution;

		static Vector2 mDistance;
	};
}

