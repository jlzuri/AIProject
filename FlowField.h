#ifndef GAME_FLOWFIELD_H
#define GAME_FLOWFIELD_H

#include <vector>
#include <Vector2.h>
#include "IService.h"

namespace AIProject {

class FlowField {
public:
	explicit FlowField(int width, int height, int resolution);

	void Render(SDL_Renderer *renderer);

	const Vector2 &GetElement(Vector2 position) const;

private:
	int mRows;
	int mColumns;
	int mResolution;
	std::vector<Vector2> mField;

};

}


#endif //GAME_FLOWFIELD_H
