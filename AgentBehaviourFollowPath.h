#ifndef GAME_AGENTBEHAVIOURFOLLOWPATH_H
#define GAME_AGENTBEHAVIOURFOLLOWPATH_H

#include "AgentBehaviourSeek.h"

namespace AIProject
{

class Path;

class AgentBehaviourFollowPath : public AgentBehaviourSeek {
public:
	virtual AgentBehaviourType BehaviourType() const override { return AgentBehaviourType::FollowPath; }
	virtual Vector2 Execute(Agent *agent) override;
	void SetPath(Path * path) { mPath = path; };
private:
	Path* mPath;
};

}

#endif //GAME_AGENTBEHAVIOURFOLLOWPATH_H
