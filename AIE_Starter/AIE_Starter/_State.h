#pragma once
#include "AgentsFSM.h"

//https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-decision-making-2-finite-state-machines

namespace AIForGames {
	class _State
	{
	private:
		std::vector<BehavioursFSM*> m_Behaviours;

	public:
		_State();
		~_State();
		virtual void Update(AgentsFSM* agent, float deltaTime);
	};
}



