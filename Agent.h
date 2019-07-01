#ifndef GAME_AGENT_H
#define GAME_AGENT_H

#include <memory>
#include <Vector2.h>
#include "AgentBehaviour.h"

struct SDL_Renderer;

namespace AIProject
{

class FlowField;

class Agent {
public:
	Agent(AgentBehaviourType behaviour, const Vector2& position);

	virtual void Update();
	void Render(SDL_Renderer * renderer);

	float GetRadius() const { return mRadius; }
	float GetMaxForce() const { return mMaxForce; }
	float GetMaxSpeed() const { return mMaxSpeed; }

	const Vector2& GetPosition() const { return mPosition; }
	const Vector2& GetVelocity() const { return mVelocity; }
	const Vector2& GetAcceleration() const { return mAcceleration; }

	const AgentBehaviour* GetBehaviour() const { return mBehaviour.get(); }
	AgentBehaviour* GetBehaviour() { return mBehaviour.get(); }
private:
	void WrapAround();

private:
	const float mRadius = 6.f;
	const float mMaxForce = .002f;
	const float mMaxSpeed = .3f;

	Vector2 mPosition;
	Vector2 mVelocity;
	Vector2 mAcceleration;

	std::unique_ptr<AgentBehaviour> mBehaviour;
};

}

#endif //GAME_AGENT_H
