#ifndef GAME_AGENT_H
#define GAME_AGENT_H

#include <Vector2.h>

struct SDL_Renderer;

namespace AIProject
{
class Agent {
public:
	Agent(const Vector2& position);

	void Update();
	void Render(SDL_Renderer * renderer);

	void SetTarget(const Vector2& target);
private:
	void Seek();
	void Arrive();
	void Follow();
	void WrapAround();

private:
	static constexpr float mRadius = 6.f;
	static constexpr float maxForce = 4.f;
	static constexpr float maxSpeed = 0.1f;

	Vector2 mPosition;
	Vector2 mVelocity;
	Vector2 mAcceleration;
	Vector2 mTarget;
};

}

#endif //GAME_AGENT_H
