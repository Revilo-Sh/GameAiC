#include "WanderBehaviourFSM.h"

void AIForGames::WanderBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	if (agent->PathComplete() == true) {
		Temp = agent->m_nodeMap->GetRandomNode();
	}
	agent->GoTo(glm::vec2(Temp->position));
	
}
