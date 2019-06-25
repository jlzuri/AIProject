#include "SDLService.h"
#include <SDL.h>
#include <memory>

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
bool SDLService::Initialize() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	mWindow = SDL_CreateWindow(
		"App",                     // window title
		SDL_WINDOWPOS_UNDEFINED,    // initial x position
		SDL_WINDOWPOS_UNDEFINED,    // initial y position
		640,                        // width, in pixels
		480,                        // height, in pixels
		SDL_WINDOW_OPENGL           // flags - see below
	);

	if (mWindow == nullptr) {
		// In the case that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return false;
	}

	// We must call SDL_CreateRenderer in order for draw calls to affect this window.
	mRenderer = SDL_CreateRenderer(mWindow, -1, 0);

	if(mRenderer == nullptr) {
		// In the case that the window could not be made...
		printf("Could not create renderer: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------------------------------------
void SDLService::BeforeRender() {
	// Select the color for drawing the background.
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(mRenderer);

	// Select the color for drawing the scene.
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
}

//----------------------------------------------------------------------------------------------------------------------
void SDLService::AfterRender() {
	//Update screen
	SDL_RenderPresent(mRenderer);
}

//----------------------------------------------------------------------------------------------------------------------
void SDLService::Shutdown() {
	//Destroy window
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mRenderer = nullptr;
	mWindow = nullptr;

	SDL_Quit();
}

std::tuple<int, int> SDLService::GetWindowSize() const {
	int width, height;
	SDL_GetWindowSize(mWindow, &width, &height);

	return std::make_tuple(width, height);
}

}
