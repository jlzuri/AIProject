#include "AgentsManager.h"
#include "ServiceLocator.h"
#include "InputService.h"
#include "SDLService.h"
#include "AgentBehaviourSeek.h"
#include "AgentBehaviourFollowField.h"
#include "AgentBehaviourFollowPath.h"

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
AgentsManager::AgentsManager() : mFlowField(nullptr)
{
}

//----------------------------------------------------------------------------------------------------------------------
bool AgentsManager::Initialize() {
	auto inputService = (InputService*)ServiceLocator::GetService(ServiceType::InputService);
	inputService->AddListener(this, SDL_MOUSEBUTTONDOWN);
	inputService->AddListener(this, SDL_MOUSEMOTION);

	auto sdlService = (SDLService *)ServiceLocator::GetService(ServiceType::SDLService);
	auto [width, height] = sdlService->GetWindowSize();

	mFlowField = std::make_unique<FlowField>(width, height, 20);
	std::vector<Vector2> points = {{100, 200}, {200, 300}, {300, 250}, {400, 300}, {500, 200}, {400, 100}, {300, 150}, {200, 100}, {100, 200}};
	mPath = std::make_unique<Path>(40, std::move(points));
	mAgents.reserve(20);

	return true;
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::Update() {
	for(auto& agent : mAgents) {
		agent->Update();
	}
}

//----------------------------------------------------------------------------------------------------------------------
void AgentsManager::Render(SDL_Renderer *renderer) {
//	mFlowField->Render(renderer);
	mPath->Render(renderer);
	for(auto& agent : mAgents) {
		agent->Render(renderer);
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
			auto position = Vector2(static_cast<float>(event->button.x), static_cast<float>(event->button.y));

			//Add Seek Agent
//			auto agent = std::make_unique<Agent>(AgentBehaviourType::Seek, position);

			//Add FollowField Agent
//			auto agent = std::make_unique<Agent>(AgentBehaviourType::FollowField, position);
//			dynamic_cast<AgentBehaviourFollowField*>(agent->GetBehaviour())->SetFlowField(mFlowField.get());

			//Add FollowPath Agent
			auto agent = std::make_unique<Agent>(AgentBehaviourType::FollowPath, position);
			dynamic_cast<AgentBehaviourFollowPath*>(agent->GetBehaviour())->SetPath(mPath.get());

			mAgents.emplace_back(std::move(agent));

		}
	}
	else if(event->type == SDL_MOUSEMOTION)
	{
		//Order all agents to seek this position
		for(auto& agent : mAgents)
		{
			auto* behaviour = agent->GetBehaviour();
			if(behaviour != nullptr && behaviour->BehaviourType() == AgentBehaviourType::Seek)
			{
				dynamic_cast<AgentBehaviourSeek*>(behaviour)->SetTarget({static_cast<float>(event->motion.x), static_cast<float>(event->motion.y)});
			}
		}
	}
}

}
