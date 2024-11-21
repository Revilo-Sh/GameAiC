#include "FollowBehaviourFSM.h"

void AIForGames::FollowBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	AgentsFSM* target = agent->GetTarget();

	float dist = glm::distance(target->m_pathAgent.GetPosition(), LastTargetPosition);
	if (dist > agent->GetNodeMap()->GetcellSize()) {
		LastTargetPosition = target->m_pathAgent.GetPosition();
		agent->GoTo(LastTargetPosition);
	}
}
