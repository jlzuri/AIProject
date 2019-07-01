#include "Agent.h"
#include "Constants.h"
#include "MathUtils.h"
#include "SDLService.h"
#include "ServiceLocator.h"
#include "FlowField.h"
#include "AgentBehaviourSeek.h"
#include "AgentBehaviourFollowField.h"
#include "AgentBehaviourFollowPath.h"
#include <SDL2_gfxPrimitives.h>

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
Agent::Agent(AgentBehaviourType behaviour, const Vector2& position) :
	mPosition(position),
	mVelocity(),
	mAcceleration(),
	mBehaviour(nullptr)
{
	switch(behaviour)
	{
		case AgentBehaviourType::Seek:
			mBehaviour = std::make_unique<AgentBehaviourSeek>();
			break;
		case AgentBehaviourType::FollowField:
			mBehaviour = std::make_unique<AgentBehaviourFollowField>();
			break;
		case AgentBehaviourType::FollowPath:
			mBehaviour = std::make_unique<AgentBehaviourFollowPath>();
			break;
		default:
			break;
	}
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Update()
{
	mAcceleration = mBehaviour->Execute(this);

	mVelocity += mAcceleration;

	if(mVelocity.LengthSqr() > mMaxSpeed * mMaxSpeed)
	{
		mVelocity.Normalize();
		mVelocity *= mMaxSpeed;
	}

	mPosition += mVelocity;

	WrapAround();

	mAcceleration = Vector2();
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Render(SDL_Renderer * renderer)
{
//	mBehaviour->Render(renderer);

	Vector2 point1 = mPosition + Vector2(0, - mRadius);
	Vector2 point2 = mPosition + Vector2(- mRadius, mRadius);
	Vector2 point3 = mPosition + Vector2(mRadius, mRadius);

	//rotate points
	auto angle = atan2(mVelocity.y, mVelocity.x) + MathUtils::HalfPi;
	point1 = MathUtils::Rotate(point1, mPosition, angle);
	point2 = MathUtils::Rotate(point2, mPosition, angle);
	point3 = MathUtils::Rotate(point3, mPosition, angle);

	trigonRGBA(
		renderer,
		point1.x, point1.y,
		point2.x, point2.y,
		point3.x, point3.y,
		Color::Black.r, Color::Black.g, Color::Black.b, Color::Black.a);
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::WrapAround() {
	auto sdlService = (SDLService *)ServiceLocator::GetService(ServiceType::SDLService);
	auto [width, height] = sdlService->GetWindowSize();

	if(mPosition.x < -mRadius) {
		mPosition.x = width + mRadius;
	}
	if(mPosition.y < -mRadius) {
		mPosition.y = height + mRadius;
	}
	if(mPosition.x > width + mRadius) {
		mPosition.x = -mRadius;
	}
	if(mPosition.y > height + mRadius) {
		mPosition.y = -mRadius;
	}
}

}