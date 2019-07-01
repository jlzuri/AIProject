#ifndef GAME_AGENTBEHAVIOUR_H
#define GAME_AGENTBEHAVIOUR_H

class SDL_Renderer;

namespace AIProject
{

class Agent;

enum class AgentBehaviourType {
	Seek,
	FollowField,
	FollowPath,
	Count,
	Invalid
};

class AgentBehaviour {
public:
	virtual AgentBehaviourType BehaviourType() const { return AgentBehaviourType::Invalid; };

	virtual ~AgentBehaviour() {}

	virtual Vector2 Execute(Agent *agent) = 0;
	virtual void Render(SDL_Renderer * renderer) {};
};

}

#endif //GAME_AGENTBEHAVIOUR_H
