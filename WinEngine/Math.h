#pragma once
#include <math.h>

#define PI	3.141592f

namespace WE
{
	static float Radian(const float degree)
	{
		return (PI / 180.f) * degree;
	}

	struct Vector2
	{
		Vector2(const float x, const float y)
		{
			this->x = x;
			this->y = y;
		}
		Vector2()
		{
			x = 0.f;
			y = 0.f;
		}

		Vector2 operator+(const Vector2& vec2) const
		{
			return Vector2(x + vec2.x, y + vec2.y);
		}
		Vector2 operator+(const float& scalar) const
		{
			return Vector2(x + scalar, y + scalar);
		}
		Vector2 operator-(const Vector2& vec2) const
		{
			return Vector2(x - vec2.x, y - vec2.y);
		}
		Vector2 operator-(const float& scalar) const
		{
			return Vector2(x - scalar, y - scalar);
		}
		Vector2 operator*(const Vector2& vec2) const
		{
			return Vector2(x * vec2.x, y * vec2.y);
		}
		Vector2 operator/(const float& scalar) const
		{
			return Vector2(x / scalar, y / scalar);
		}
		Vector2 operator*(const float& scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}
		Vector2& operator+=(const Vector2& vec2)
		{
			x += vec2.x;
			y += vec2.y;
			return *this;
		}
		Vector2& operator+=(const float& scalar)
		{
			x += scalar;
			y += scalar;
			return *this;
		}
		Vector2& operator-=(const Vector2& vec2)
		{
			x -= vec2.x;
			y -= vec2.y;
			return *this;
		}
		Vector2& operator-=(const float& scalar)
		{
			x -= scalar;
			y -= scalar;
			return *this;
		}
		Vector2& operator*=(const Vector2& vec2)
		{
			x *= vec2.x;
			y *= vec2.y;
			return *this;
		}
		Vector2& operator/=(const float& scalar)
		{
			x /= scalar;
			y /= scalar;
			return *this;
		}
		Vector2& operator*=(const float& scalar)
		{
			x *= scalar;
			y *= scalar;
			return *this;
		}

		static inline float Dot(const Vector2& vec1, const Vector2& vec2)
		{
			return vec1.x * vec2.x + vec1.x * vec2.x;
		}

		static inline float Cross(const Vector2& vec1, const Vector2& vec2)
		{
			return vec1.x * vec2.y + vec1.y * vec2.x;
		}

		inline float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2& Normalize()
		{
			float len = this->Length();
			x /= len;
			y /= len;
			return *this;
		}

		static Vector2 Rotate(Vector2 vec, const float degree)
		{
			float radian = Radian(degree);
			//vec.Normalize();

			Vector2 result;

			result.x = (cosf(radian) * vec.x) - (sinf(radian) * vec.y);
			result.y = (sinf(radian) * vec.x) + (cosf(radian) * vec.y);

			if (fabs(result.x) < 1e-6 && (long)degree % 90 == 0) {
				result.x = 0;
			}
			if (fabs(result.y) < 1e-6 && (long)degree % 90 == 0) {
				result.y = 0;
			}

			return result;
		}

		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Left;
		static Vector2 Right;
		static Vector2 Up;
		static Vector2 Down;

		float x;
		float y;
	};
}


