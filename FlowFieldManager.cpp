#include "FlowFieldManager.h"
#include "SDLService.h"
#include "ServiceLocator.h"
#include "Constants.h"
#include "MathUtils.h"
#include "PerlinNoise.h"
#include <SDL.h>
#include <algorithm>
#include <SDL2/SDL2_gfxPrimitives.h>

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
FlowFieldManager::FlowFieldManager(int resolution) : mResolution(resolution) {
}

//----------------------------------------------------------------------------------------------------------------------
bool FlowFieldManager::Initialize() {
	auto sdlService = (SDLService *)ServiceLocator::GetService(ServiceType::SDLService);
	auto [width, height] = sdlService->GetWindowSize();

	mRows = height / mResolution;
	mColumns = width / mResolution;
	mField.resize(mRows * mColumns);

	PerlinNoise perlin(0);
	float yOffset = 0;
	for(int row = 0; row < mRows; ++row) {
		float xOffset = 0;
		for(int col = 0; col < mColumns; ++col) {
			float angle = MathUtils::Map(perlin.noise(xOffset, yOffset, 0), 0, 1, 0,MathUtils::TwoPi);
			mField[row * mColumns + col] = {cos(angle), sin(angle)};
			xOffset += 0.1f;
		}
		yOffset += 0.1f;
	}
	return true;
}

//----------------------------------------------------------------------------------------------------------------------
void FlowFieldManager::Render(SDL_Renderer *renderer) {
	for(int row = 0; row < mRows; ++row) {
		for(int col = 0; col < mColumns; ++col) {
			Vector2 fieldEntry = mField[row * mColumns + col];
			Vector2 point1 = {static_cast<float>(col * mResolution), static_cast<float>(row * mResolution)};
			Vector2 point2 = point1 + fieldEntry * mResolution;

			lineRGBA(
				renderer,
				point1.x, point1.y,
				point2.x, point2.y,
				Color::Black.r, Color::Black.g, Color::Black.b, Color::Black.a);
		}
	}
}
//----------------------------------------------------------------------------------------------------------------------
const Vector2& FlowFieldManager::GetElement(Vector2 position) const {
	int column = std::clamp((int)position.x / mResolution, 0, mColumns - 1);
	int row = std::clamp((int)position.y / mResolution, 0, mRows - 1);
	return mField[row * mColumns + column];
}

}