#include <Vector2.h>
#include "AgentBehaviourFollowPath.h"
#include "Path.h"
#include "Agent.h"
#include "MathUtils.h"
#include "DebugRenderer.h"

namespace AIProject {

//----------------------------------------------------------------------------------------------------------------------
Vector2 AgentBehaviourFollowPath::Execute(Agent *agent) {
	if (mPath == nullptr) {
		return Vector2();
	}

	auto position = agent->GetPosition();
	auto velocity = agent->GetVelocity();

	//look ahead in our current direction
	auto futurePos = position + Vector2::Normalize(velocity) * 50;
	auto distanceSqrToPath = std::numeric_limits<float>::max();
	auto closestPointToPath = Vector2::Invalid;

	auto pathRadius = mPath->GetRadius();
	auto pathPoints = mPath->GetPoints();
	for (int i = 0, j = i + 1; j < pathPoints.size(); ++i, ++j) {
		auto segmentStart = pathPoints[i];
		auto segmentEnd = pathPoints[j];

		auto closestPoint = MathUtils::ClosestPointOnSegment(futurePos, segmentStart, segmentEnd);
		auto distanceSqr = Vector2::DistanceSquared(futurePos, closestPoint);

		if (distanceSqr < distanceSqrToPath) {
			distanceSqrToPath = distanceSqr;
			closestPointToPath = closestPoint;

			auto segmentDir = Vector2::Normalize(segmentEnd - segmentStart);
			SetTarget(closestPointToPath + segmentDir * 10);
		}
	}

//	auto debugRenderer = (DebugRenderer *)ServiceLocator::GetService(ServiceType::DebugRenderer);
//	debugRenderer->DrawCircle(futurePos, 2, Color::Red);
//	debugRenderer->DrawLine(position, futurePos, Color::Red);
//	debugRenderer->DrawCircle(closestPointToPath, 2, Color::Blue);
//	debugRenderer->DrawLine(futurePos, closestPointToPath, Color::Blue);

	return AgentBehaviourSeek::Execute(agent);
}

}