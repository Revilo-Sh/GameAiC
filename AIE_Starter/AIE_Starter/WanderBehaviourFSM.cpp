#include "WanderBehaviourFSM.h"

void AIForGames::WanderBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	if (agent->PathComplete() == true) {
		Temp = agent->m_nodeMap->GetRandomNode();
	}
	agent->GoTo(glm::vec2(Temp->position));
	
}

float AIForGames::WanderBehaviourFSM::Evaluate(AgentsFSM* agent)
{
	AgentsFSM* trarget = agent->GetTarget();
	float dist = glm::distance(trarget->m_pathAgent.GetPosition(), agent->m_pathAgent.GetPosition());

	float eval = dist;
	if (eval < 0) {
		eval = 0;
	}
	return eval;
}
