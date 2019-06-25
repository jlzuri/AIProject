#include "AgentsManager.h"
#include "Vector2.h"
#include "ServiceLocator.h"
#include "InputService.h"
#include <algorithm>
#include <SDL2/SDL_events.h>

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
bool AgentsManager::Initialize() {
	auto inputService = (InputService*)ServiceLocator::GetService(ServiceType::InputService);
	inputService->AddListener(this, SDL_MOUSEBUTTONDOWN);
	inputService->AddListener(this, SDL_MOUSEMOTION);

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::Update() {
	for(auto& agent : mAgents) {
		agent.Update();
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::Render(SDL_Renderer *renderer) {
	for(auto& agent : mAgents) {
		agent.Render(renderer);
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::Shutdown() {
	auto inputService = (InputService*)ServiceLocator::GetService(ServiceType::InputService);
	inputService->RemoveListener(this);
	mAgents.clear();
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::OnInputEvent(SDL_Event *event) {
	if(event->type == SDL_MOUSEBUTTONDOWN)
	{
		if(event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2 position = {static_cast<float>(event->button.x), static_cast<float>(event->button.y)};
			AddAgent(position);
		}
	}
	else if(event->type == SDL_MOUSEMOTION)
	{
		//Order all agents to seek this position
		for(auto& agent : mAgents)
		{
			agent.SetTarget({static_cast<float>(event->motion.x), static_cast<float>(event->motion.y)});
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::AddAgent(const Vector2& position) {
	mAgents.emplace_back(position);
}

}
