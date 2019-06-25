#ifndef __VECTOR_2D_H__
#define __VECTOR_2D_H__

#include<math.h>

class Vector2 {
public:

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

	Vector2 operator*(float scalar) {
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

	Vector2 operator/(float scalar) {
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

public:
	float x;
	float y;
};

#endif
