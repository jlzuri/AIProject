#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <memory>
#include "InputService.h"
#include "AgentsManager.h"
#include "FlowField.h"
#include "SDLService.h"
#include "DebugRenderer.h"

union SDL_Event;

namespace AIProject {

class App {
public:
	bool Initialize();

	void Update();

	void Render();

	void Shutdown();

	void OnEvent(SDL_Event *event);

	void OnExit();

	bool IsRunning();

private:
	bool mRunning = true;
	std::unique_ptr<SDLService> mSDLService;
	std::unique_ptr<InputService> mInputService;
	std::unique_ptr<AgentsManager> mAgentsManager;
	std::unique_ptr<DebugRenderer> mDebugRenderer;
};
}

#endif