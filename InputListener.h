#ifndef GAME_INPUTLISTENER_H
#define GAME_INPUTLISTENER_H

union SDL_Event;

namespace AIProject {
class InputListener {
public:
	virtual ~InputListener() {};

	virtual void OnInputEvent(SDL_Event *event) = 0;
};
}

#endif //GAME_INPUTLISTENER_H
