#ifndef GAME_DEBUGRENDERER_H
#define GAME_DEBUGRENDERER_H

#include "IService.h"
#include "Primitive.h"
#include "Constants.h"
#include <vector>

class Vector2;

namespace AIProject {

class DebugRenderer : public IService {
public:
	virtual bool Initialize() override { return true; };

	virtual void Update() override {};

	virtual void Render(SDL_Renderer *renderer) override;

	virtual void Shutdown() override {};

	void DrawLine(const Vector2 &start, const Vector2 &end, SDL_Color color);

	void DrawCircle(const Vector2 &position, float radius, SDL_Color color);

private:
	std::vector<std::unique_ptr<Primitive>> mRenderQueue;
};


}

#endif //GAME_DEBUGRENDERER_H
