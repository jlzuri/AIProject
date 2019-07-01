#include "Path.h"
#include <SDL2_gfxPrimitives.h>

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
Path::Path(float radius, std::vector<Vector2> &&points) :
	mPoints(std::move(points)),
	mRadius(radius) {

}

//----------------------------------------------------------------------------------------------------------------------
void Path::Render(SDL_Renderer *renderer) {
	for (int i = 0; i < mPoints.size(); ++i) {
		filledCircleRGBA(
			renderer,
			mPoints[i].x, mPoints[i].y,
			mRadius,
			Color::Cyan.r, Color::Cyan.g, Color::Cyan.b, Color::Cyan.a
		);
	}

	for (int i = 0, j = i + 1; j < mPoints.size(); ++i, ++j) {
		thickLineRGBA(renderer,
					  mPoints[i].x, mPoints[i].y,
					  mPoints[j].x, mPoints[j].y,
					  mRadius * 2,
					  Color::Cyan.r, Color::Cyan.g, Color::Cyan.b, Color::Cyan.a);
	}

	for (int i = 0, j = i + 1; j < mPoints.size(); ++i, ++j) {
		lineRGBA(
			renderer,
			mPoints[i].x, mPoints[i].y,
			mPoints[j].x, mPoints[j].y,
			Color::Black.r, Color::Black.g, Color::Black.b, Color::Black.a);
	}
}

}