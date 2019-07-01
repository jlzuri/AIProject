#ifndef GAME_PATH_H
#define GAME_PATH_H

#include <vector>
#include <Vector2.h>
#include "Constants.h"

class SDL_Renderer;

namespace AIProject {

class Path {
public:
	Path(float radius, std::vector<Vector2> &&points);

	void Render(SDL_Renderer *renderer);

	void AddPoint(const Vector2 &point) { mPoints.emplace_back(point); }

	const std::vector<Vector2> &GetPoints() const { return mPoints; }

	float GetRadius() const { return mRadius; }

private:
	std::vector<Vector2> mPoints;
	float mRadius;
};

}

#endif //GAME_PATH_H
