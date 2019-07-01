#include <Vector2.h>
#include "AgentBehaviourFollowField.h"
#include "FlowField.h"
#include "Agent.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
Vector2 AgentBehaviourFollowField::Execute(Agent *agent) {
	if (mFlowField == nullptr) {
		return Vector2();
	}

	auto position = agent->GetPosition();
	auto velocity = agent->GetVelocity();
	auto maxForce = agent->GetMaxForce();

	auto desired = mFlowField->GetElement(position);
	desired *= maxForce;

	Vector2 steeringForce = desired - velocity;
	if (steeringForce.LengthSqr() > maxForce * maxForce) {
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

	return steeringForce;
}

}
