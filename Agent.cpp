#include "Agent.h"
#include "Constants.h"
#include "MathUtils.h"
#include "SDLService.h"
#include "ServiceLocator.h"
#include "FlowFieldManager.h"
#include <SDL_render.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>

namespace AIProject
{

//----------------------------------------------------------------------------------------------------------------------
Agent::Agent(const Vector2& position) :
	mPosition(position),
	mVelocity(),
	mAcceleration(),
	mTarget()
{

}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Update()
{
	Follow();

	mVelocity += mAcceleration;

	if(mVelocity.LengthSqr() > maxSpeed * maxSpeed)
	{
		mVelocity.Normalize();
		mVelocity *= maxSpeed;
	}

	mPosition += mVelocity;

	WrapAround();

	mAcceleration = Vector2();
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Render(SDL_Renderer * renderer)
{
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
void Agent::SetTarget(const Vector2 &target) {
	mTarget = target;
}

//Calculate a steering force towards a target
//----------------------------------------------------------------------------------------------------------------------
void Agent::Seek()
{
	Vector2 desired = mTarget - mPosition;
	desired.Normalize();
	desired *= maxSpeed;

	Vector2 steeringForce = desired - mVelocity;
	if(steeringForce.LengthSqr() > maxForce * maxForce)
	{
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

	mAcceleration = steeringForce;
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Arrive() {
	Vector2 desired = mTarget - mPosition;
	float magnitude = desired.LengthSqr();
	constexpr float radius = 20;
	float speed = maxSpeed;
	if(magnitude < radius * radius)
	{
		speed = MathUtils::Map(magnitude, 0, radius, 0, maxSpeed);
	}

	desired.Normalize();
	desired *= speed;

	Vector2 steeringForce = desired - mVelocity;
	if(steeringForce.LengthSqr() > maxForce * maxForce)
	{
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

	mAcceleration = steeringForce;
}

//----------------------------------------------------------------------------------------------------------------------
void Agent::Follow() {
	auto flowManager = (FlowFieldManager *)ServiceLocator::GetService(ServiceType::FlowFieldManager);
	auto desired = flowManager->GetElement(mPosition);
	desired *= maxForce;

	Vector2 steeringForce = desired - mVelocity;
	if(steeringForce.LengthSqr() > maxForce * maxForce)
	{
		steeringForce.Normalize();
		steeringForce *= maxForce;
	}

	mAcceleration = steeringForce;
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