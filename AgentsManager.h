#ifndef GAME_AGENTSMANAGER_H
#define GAME_AGENTSMANAGER_H

#include <vector>
#include "Agent.h"
#include "IService.h"
#include "InputListener.h"
#include "FlowField.h"
#include "Path.h"

namespace AIProject {

class AgentsManager : public IService, InputListener {
public:
	AgentsManager();

	//IService interface
	virtual bool Initialize() override;

	virtual void Update() override;

	virtual void Render(SDL_Renderer *renderer) override;

	virtual void Shutdown() override;

	//InputListener interface
	virtual void OnInputEvent(SDL_Event *event) override;

private:
	std::vector<std::unique_ptr<Agent>> mAgents;
	std::unique_ptr<FlowField> mFlowField;
	std::unique_ptr<Path> mPath;
};

}

#endif //GAME_AGENTSMANAGER_H
