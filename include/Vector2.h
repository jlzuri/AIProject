#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include<math.h>

class Vector2 {
public:
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 UnitX;
	static const Vector2 UnitY;
	static const Vector2 Invalid;

	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}

	float Length() const { return sqrt(x*x+y*y); }

	float LengthSqr() const { return x*x+y*y; }

	Vector2 operator+(const Vector2 &v2) const {
		return Vector2(x+v2.x, y+v2.y);
	}

	friend Vector2& operator+=(Vector2 &v1, const Vector2 &v2) {
		v1.x += v2.x;
		v1.y += v2.y;
		return v1;
	}

	Vector2 operator*(float scalar) const {
		return Vector2(x*scalar, y*scalar);
	}

	Vector2& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2 operator-(const Vector2 &v2) const {
		return Vector2(x - v2.x, y - v2.y);
	}

	friend Vector2& operator-=(Vector2 &v1, const Vector2 &v2) {
		v1.x -= v2.x;
		v1.y -= v2.y;
		return v1;
	}

	Vector2 operator/(float scalar) const {
		return Vector2(x / scalar, y / scalar);
	}

	Vector2 &operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	void Normalize() {
		float l=Length();
		if (l>0) {
			(*this) *= 1/l;
		}
	}

	float Dot(const Vector2 &v2) {
		return this->x * v2.x + this->y * v2.y;
	}

	static Vector2 Normalize(const Vector2 &v1) {
		Vector2 result = v1;
		float l = result.Length();
		if (l>0) {
			result *= 1/l;
		}
		return result;
	}

	static float Dot(const Vector2 &v1, const Vector2 &v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	static float DistanceSquared(const Vector2 &v1, const Vector2 &v2) {
		return pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2);
	}

	static float Distance(const Vector2 &v1, const Vector2 &v2) {
		return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
	}

public:
	float x;
	float y;
};

#endif
