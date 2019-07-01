#ifndef GAME_CIRCLEPRIMITIVE_H
#define GAME_CIRCLEPRIMITIVE_H

#include <Vector2.h>
#include "Primitive.h"
#include <SDL2_gfxPrimitives.h>

namespace AIProject {

class CirclePrimitive : public Primitive {
public:

	CirclePrimitive(const Vector2 &position, float radius, SDL_Color color) :
		Primitive(color),
		mPosition(position),
		mRadius(radius) {

	}

	virtual void Render(SDL_Renderer *renderer) override {
		circleRGBA(renderer, mPosition.x, mPosition.y, mRadius, mColor.r, mColor.g, mColor.b, mColor.a);
	}

private:
	Vector2 mPosition;
	float mRadius;
};

}


#endif //GAME_CIRCLEPRIMITIVE_H
