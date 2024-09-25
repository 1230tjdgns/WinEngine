#pragma once
#include <math.h>

#define PI	3.141592f

namespace WE
{
	static float Radian(const float degree)
	{
		return (degree / 180.f) * PI;
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
			x /= this->Length();
			y /= this->Length();
			return *this;
		}

		void Rotate(const float degree)
		{
			float radian = Radian(degree);
			Vector2 normal = this->Normalize();

			x = cosf(radian) * normal.x - sinf(radian) * normal.y;
			y = sinf(radian) * normal.x + cosf(radian) * normal.y;
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


