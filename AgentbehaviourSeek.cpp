#include <Vector2.h>
#include <SDL_render.h>
#include <SDL2_gfxPrimitives.h>
#include "AgentBehaviourSeek.h"
#include "MathUtils.h"
#include "Agent.h"
#include "Constants.h"

namespace AIProject
{

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
	if(magnitude < radius * radius)
	{
		speed = MathUtils::Map(magnitude, 0, radius, 0, maxSpeed);
	}

	desired.Normalize();
	desired *= speed;

	Vector2 steeringForce = desired - velocity;
	if(steeringForce.LengthSqr() > maxForce * maxForce)
	{
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

	return steeringForce;
}

void AgentBehaviourSeek::Render(SDL_Renderer * renderer) {
	filledCircleRGBA(renderer, mTarget.x, mTarget.y, 3, Color::Green.r, Color::Green.g, Color::Green.b, Color::Green.a);
}

}
