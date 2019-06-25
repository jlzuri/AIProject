#include "MathUtils.h"
#include <math.h>

//----------------------------------------------------------------------------------------------------------------------
Vector2 MathUtils::Rotate(const Vector2& point, const Vector2& center, float angle)
{
	float s = sin(angle);
	float c = cos(angle);
	Vector2 diff = point - center;

	return {
		diff.x * c - diff.y * s + center.x,
		diff.x * s + diff.y * c + center.y
	};
}

//----------------------------------------------------------------------------------------------------------------------
float MathUtils::Map(float a, float min, float max, float newMin, float newMax)
{
	return (((newMax - newMin) * (a - min)) / (max  - min)) + a;
}
