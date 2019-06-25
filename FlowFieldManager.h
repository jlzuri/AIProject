#ifndef GAME_FLOWFIELD_H
#define GAME_FLOWFIELD_H

#include <vector>
#include <Vector2.h>
#include "IService.h"

namespace AIProject
{

class FlowFieldManager : public IService {
public:
	explicit FlowFieldManager(int resolution);

	bool Initialize();
	void Update() {};
	void Render(SDL_Renderer* renderer);
	void Shutdown() {};

	const Vector2& GetElement(Vector2 position) const;
private:
	std::vector<Vector2> mField;
	int mRows;
	int mColumns;
	int mResolution;

};

}



#endif //GAME_FLOWFIELD_H
