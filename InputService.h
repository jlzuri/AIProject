#ifndef GAME_INPUTSERVICE_H
#define GAME_INPUTSERVICE_H

#include <SDL2/SDL_events.h>
#include <map>
#include "IService.h"


namespace AIProject {

class InputListener;

class InputService : public IService {

public:
	virtual bool Initialize() override { return true; }

	virtual void Update() override {}

	virtual void Shutdown() override {}

	bool AddListener(InputListener *listener, SDL_EventType eventType);

	bool RemoveListener(InputListener *listener, SDL_EventType eventType);

	bool RemoveListener(InputListener *listener);

	void ProcessInputEvent(SDL_Event *event);

private:
	void NotifyListeners(SDL_Event *event);

private:
	//TODO: why does multimap not work here??!!
	std::map<SDL_EventType, InputListener *> mListeners;
};

}

#endif
