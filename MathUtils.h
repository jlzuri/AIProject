#ifndef GAME_MATHUTILS_H
#define GAME_MATHUTILS_H

#include "Vector2.h"

class MathUtils
{
public:
	static constexpr float Pi = 3.141592f;
	static constexpr float TwoPi = Pi * 2;
	static constexpr float HalfPi = Pi / 2;
	static Vector2 Rotate(const Vector2& point, const Vector2& center, float angle);
	static float Map(float a, float min, float max, float newMin, float newMax);
};

#endif //GAME_MATHUTILS_H
