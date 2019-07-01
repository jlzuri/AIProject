#ifndef GAME_ISERVICE_H
#define GAME_ISERVICE_H

struct SDL_Renderer;

namespace AIProject {
class IService {
public:
	virtual ~IService() {};

	virtual bool Initialize() = 0;

	virtual void Update() = 0;

	virtual void Render(SDL_Renderer *renderer) {}

	virtual void Shutdown() = 0;
};
}

#endif //GAME_ISERVICE_H
