#ifndef GAME_SDLSERVICE_H
#define GAME_SDLSERVICE_H

#include "IService.h"
#include <tuple>

struct SDL_Window;
struct SDL_Renderer;

namespace AIProject {

class SDLService : public IService {
public:
	bool Initialize();

	void Update() {};

	void Shutdown();

	void BeforeRender();

	void AfterRender();

	SDL_Window *GetWindow() { return mWindow; }

	SDL_Renderer *GetRenderer() { return mRenderer; }

	std::tuple<int, int> GetWindowSize() const;

private:
	SDL_Window *mWindow = nullptr;
	SDL_Renderer *mRenderer = nullptr;
};

}


#endif //GAME_SDLSERVICE_H
