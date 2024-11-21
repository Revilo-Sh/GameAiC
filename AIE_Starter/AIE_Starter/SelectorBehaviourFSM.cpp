#include "SelectorBehaviourFSM.h"

void AIForGames::SelectorBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	if (glm::distance(agent->m_pathAgent.GetPosition(), agent->GetTarget()->m_pathAgent.GetPosition()) < agent->GetNodeMap()->GetcellSize() * 5) {
		SetBehaviour(m_b1, agent);
		agent->Draw({ YELLOW });
	}
	else
	{
		SetBehaviour(m_b2, agent);
		agent->Draw({ 0, 255, 255, 255 });
	}
	m_selected->Update(agent, deltaTime);
}

void AIForGames::SelectorBehaviourFSM::SetBehaviour(BehavioursFSM* b, AgentsFSM* agent)
{
	if (m_selected != b) {
		m_selected = b;
		agent->Reset();
	}
}
