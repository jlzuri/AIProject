#include "App.h"

using namespace AIProject;

int main() {

	App game;

	if (!game.Initialize()) {
		return -1;
	}

	SDL_Event event;

	while (game.IsRunning()) {
		while (SDL_PollEvent(&event)) {
			game.OnEvent(&event);
		}

		game.Update();
		game.Render();
	}

	game.Shutdown();

	return 0;

}