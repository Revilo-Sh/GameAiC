#include "FollowBehaviourFSM.h"

void AIForGames::FollowBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	PathAgent* target = agent->GetTarget();

	float dist = glm::distance(target->GetPosition(), LastTargetPosition);
	if (dist > agent->GetNodeMap()->GetcellSize()) {
		LastTargetPosition = target->GetPosition();
		agent->GoTo(LastTargetPosition);
	}
}
