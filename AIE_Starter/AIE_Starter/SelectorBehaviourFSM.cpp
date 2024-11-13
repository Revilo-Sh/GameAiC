#include "SelectorBehaviourFSM.h"

void AIForGames::SelectorBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	if (Vector2Distance(agent->GetPosition(), agent->GetTarget()->GetNodeMap()) < agent->GetNodeMap()->GetcellSize() * 5) {
		SetBehaviour(m_b1, agent);
	}
	else
	{
		SetBehaviour(m_b2, agent);
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
