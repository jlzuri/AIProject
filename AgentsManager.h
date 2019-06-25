#ifndef GAME_AGENTSMANAGER_H
#define GAME_AGENTSMANAGER_H

#include <vector>
#include "Agent.h"
#include "IService.h"
#include "InputListener.h"

namespace AIProject
{

class AgentsManager : public IService, InputListener
{
public:
	//IService interface
	virtual bool Initialize() override;
	virtual void Update() override;
	virtual void Render(SDL_Renderer *renderer) override;
	virtual void Shutdown() override;

	//InputListener interface
	virtual void OnInputEvent(SDL_Event * event) override ;

	void AddAgent(const Vector2& position);

private:
	std::vector<Agent> mAgents;
};

}

#endif //GAME_AGENTSMANAGER_H
