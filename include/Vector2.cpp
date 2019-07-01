#include "Vector2.h"

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::UnitX = Vector2(1, 0);
const Vector2 Vector2::UnitY = Vector2(0, 1);
const Vector2 Vector2::Invalid = Vector2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());