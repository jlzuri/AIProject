#ifndef GAME_MATHUTILS_H
#define GAME_MATHUTILS_H

#include "Vector2.h"

class MathUtils {
public:
	static constexpr float Pi = 3.141592f;
	static constexpr float TwoPi = Pi * 2;
	static constexpr float HalfPi = Pi / 2;

	static float Map(float a, float min, float max, float newMin, float newMax);

	static Vector2 Rotate(const Vector2 &point, const Vector2 &center, float angle);

	static Vector2 ClosestPointOnLine(const Vector2 &point, const Vector2 &lineOrig, const Vector2 &lineDir);

	static float DistanceToLineSquared(const Vector2 &point, const Vector2 &lineOrig, const Vector2 &lineDir);

	static Vector2 ClosestPointOnSegment(const Vector2 &point, const Vector2 &segmentStart, const Vector2 &segmentEnd);

	static float DistanceToSegmentSquared(const Vector2 &point, const Vector2 &segmentStart, const Vector2 &segmentEnd);
};

#endif //GAME_MATHUTILS_H
