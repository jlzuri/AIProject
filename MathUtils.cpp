#include "MathUtils.h"

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

//----------------------------------------------------------------------------------------------------------------------
Vector2 MathUtils::ClosestPointOnLine(const Vector2& point, const Vector2& lineOrig, const Vector2& lineDir)
{
	Vector2 w = point - lineOrig;
	float vsq = Vector2::Dot(lineDir, lineDir);
	float proj = Vector2::Dot(w, lineDir);

	return lineOrig + lineDir * (proj / vsq);
}

//----------------------------------------------------------------------------------------------------------------------
float MathUtils::DistanceToLineSquared(const Vector2& point, const Vector2& lineOrig, const Vector2& lineDir)
{
	Vector2 w = point - lineOrig;
	float vsq = Vector2::Dot(lineDir, lineDir);
	float wsq = Vector2::Dot(w, w);
	float proj = Vector2::Dot(w, lineDir);

	return wsq - proj * proj / vsq;
}

//----------------------------------------------------------------------------------------------------------------------
Vector2 MathUtils::ClosestPointOnSegment(const Vector2& point, const Vector2& segmentStart, const Vector2& segmentEnd)
{
	Vector2 w = point - segmentStart;
	Vector2 segmentDir = segmentEnd - segmentStart; //Note: Do not normalize
	float proj = Vector2::Dot(w, segmentDir);
	if(proj <= 0)
	{
		return segmentStart;
	}

	float vsq = Vector2::Dot(segmentDir, segmentDir);
	return (proj >= vsq) ? segmentEnd : segmentStart + segmentDir * (proj / vsq);

}

//----------------------------------------------------------------------------------------------------------------------
float MathUtils::DistanceToSegmentSquared(const Vector2& point, const Vector2& segmentStart, const Vector2& segmentEnd)
{
	Vector2 w = point - segmentStart;
	Vector2 segmentDir = segmentEnd - segmentStart; //Note: Do not normalize
	float proj = Vector2::Dot(w, segmentDir);
	float wsq = Vector2::Dot(w, w);
	if(proj <= 0)
	{
		return wsq;
	}

	float vsq = Vector2::Dot(segmentDir, segmentDir);
	return (proj >= vsq) ? wsq -  2.f * proj + vsq : wsq - proj * proj / vsq;
}
