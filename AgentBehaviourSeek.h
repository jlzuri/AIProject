#ifndef GAME_AGENTBEHAVIOURSEEK_H
#define GAME_AGENTBEHAVIOURSEEK_H

#include "AgentBehaviour.h"

namespace AIProject {

class AgentBehaviourSeek : public AgentBehaviour {
public:
	virtual AgentBehaviourType BehaviourType() const override { return AgentBehaviourType::Seek; }

	virtual Vector2 Execute(Agent *agent) override;

	void SetTarget(const Vector2 &target) { mTarget = target; }

private:
	Vector2 mTarget;
};


}

#endif //GAME_AGENTBEHAVIOURSEEK_H
