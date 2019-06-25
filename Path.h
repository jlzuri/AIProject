#ifndef GAME_PATH_H
#define GAME_PATH_H

#include <vector>
#include <Vector2.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Constants.h"

namespace AIProject
{

class Path {
public:
	explicit Path(float radius) : mRadius(radius) {}
	void Render(SDL_Renderer * renderer) {
		for (int i = 0, j = i + 1; j < mPoints.size(); ++i, ++j) {
			lineRGBA(
				renderer,
				mPoints[i].x, mPoints[i].y,
				mPoints[j].x, mPoints[j].y,
				Color::Black.r, Color::Black.g, Color::Black.b, Color::Black.a);
		}
	}

	void AddPoint(const Vector2& point) {
		mPoints.emplace_back(point);
	}

private:
	std::vector<Vector2> mPoints;
	float mRadius;
};

}

#endif //GAME_PATH_H
