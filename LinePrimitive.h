#ifndef GAME_LINEPRIMITIVE_H
#define GAME_LINEPRIMITIVE_H

#include <Vector2.h>
#include <SDL2_gfxPrimitives.h>
#include "Primitive.h"

namespace AIProject {

class LinePrimitive : public Primitive {
public:

	LinePrimitive(const Vector2 &start, const Vector2 &end, SDL_Color color) :
		Primitive(color),
		mStart(start),
		mEnd(end) {

	}

	virtual void Render(SDL_Renderer *renderer) override {
		lineRGBA(renderer, mStart.x, mStart.y, mEnd.x, mEnd.y, mColor.r, mColor.g, mColor.b, mColor.a);
	}

private:
	Vector2 mStart;
	Vector2 mEnd;

};

}


#endif //GAME_LINEPRIMITIVE_H
