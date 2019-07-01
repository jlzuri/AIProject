#include "DebugRenderer.h"
#include "CirclePrimitive.h"
#include "LinePrimitive.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
void DebugRenderer::Render(SDL_Renderer *renderer) {
	for (auto &primitive : mRenderQueue) {
		primitive->Render(renderer);
	}
	mRenderQueue.clear();
}

//----------------------------------------------------------------------------------------------------------------------
void DebugRenderer::DrawLine(const Vector2 &start, const Vector2 &end, SDL_Color color) {
	mRenderQueue.emplace_back(std::make_unique<LinePrimitive>(start, end, color));
}

//----------------------------------------------------------------------------------------------------------------------
void DebugRenderer::DrawCircle(const Vector2 &position, float radius, SDL_Color color) {
	mRenderQueue.emplace_back(std::make_unique<CirclePrimitive>(position, radius, color));
}

}