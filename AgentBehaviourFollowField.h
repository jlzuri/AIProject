#ifndef GAME_AGENTBEHAVIOURFOLLOWFIELD_H
#define GAME_AGENTBEHAVIOURFOLLOWFIELD_H

#include "AgentBehaviour.h"

namespace AIProject {

class FlowField;

class AgentBehaviourFollowField : public AgentBehaviour {
public:
	virtual AgentBehaviourType BehaviourType() const override { return AgentBehaviourType::FollowField; }

	virtual Vector2 Execute(Agent *agent) override;

	void SetFlowField(FlowField *flowField) { mFlowField = flowField; };
private:
	FlowField *mFlowField;
};

}

#endif //GAME_AGENTBEHAVIOURFOLLOWFIELD_H
