#pragma once
#include "BehavioursFSM.h"

namespace AIForGames {
	class SelectorBehaviourFSM : BehavioursFSM
	{
	private:
		BehavioursFSM* m_b1;
		BehavioursFSM* m_b2;
		BehavioursFSM* m_selected;

	public:
		SelectorBehaviourFSM(BehavioursFSM* b1, BehavioursFSM* b2) : m_b1(b1), m_b2(b2) {}
		void Update(AgentsFSM* agent, float deltaTime) override;
		void SetBehaviour(BehavioursFSM* b, AgentsFSM* agent);
	};
}



