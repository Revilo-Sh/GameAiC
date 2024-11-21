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

float AIForGames::FollowBehaviourFSM::Evaluate(AgentsFSM* agent)
{
	AgentsFSM* target = agent->GetTarget();
	float dist = glm::distance(target->m_pathAgent.GetPosition(), agent->m_pathAgent.GetPosition());
	
	float eval = 10 * agent->GetNodeMap()->GetcellSize() - dist;
	if (eval < 0) {
		eval = 0;
	}
	return eval;
}
