#pragma once
#include "BehavioursFSM.h"

namespace AIForGames {

	class _UtilityAi : public BehavioursFSM
	{
	private:
		std::vector<BehavioursFSM*> m_behaviours;
		BehavioursFSM* currnetBehaviour;

	public:
		_UtilityAi() {};
		~_UtilityAi();
		virtual void Update(AgentsFSM* agent, float deltaTime);
		void AddBehaviour(BehavioursFSM* Behavour) {
			m_behaviours.push_back(Behavour);
		}

	};
}



