#ifndef GAME_PRIMITIVE_H
#define GAME_PRIMITIVE_H

#include "Constants.h"

class SDL_Renderer;

namespace AIProject {

class Primitive {
public:

	Primitive(SDL_Color color) : mColor(color) {}

	virtual ~Primitive() {}

	virtual void Render(SDL_Renderer *renderer) = 0;

protected:
	SDL_Color mColor;
};


}

#endif //GAME_PRIMITIVE_H
