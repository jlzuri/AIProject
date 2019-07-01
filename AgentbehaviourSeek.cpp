#include <Vector2.h>
#include "AgentBehaviourSeek.h"
#include "MathUtils.h"
#include "Agent.h"
#include "DebugRenderer.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
Vector2 AgentBehaviourSeek::Execute(Agent *agent) {
	auto position = agent->GetPosition();
	auto velocity = agent->GetVelocity();
	auto maxForce = agent->GetMaxForce();
	auto maxSpeed = agent->GetMaxSpeed();

	Vector2 desired = mTarget - position;
	float magnitude = desired.LengthSqr();
	constexpr float radius = 20;
	float speed = maxSpeed;
	if (magnitude < radius * radius) {
		speed = MathUtils::Map(magnitude, 0, radius, 0, maxSpeed);
	}

	desired.Normalize();
	desired *= speed;

	Vector2 steeringForce = desired - velocity;
	if (steeringForce.LengthSqr() > maxForce * maxForce) {
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

//	auto debugRenderer = (DebugRenderer *)ServiceLocator::GetService(ServiceType::DebugRenderer);
//	debugRenderer->DrawCircle(mTarget, 2, Color::Green);

	return steeringForce;
}

}
