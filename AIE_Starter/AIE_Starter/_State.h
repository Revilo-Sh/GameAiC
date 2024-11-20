#pragma once
#include "AgentsFSM.h"
#include "_Condition.h"


//https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-decision-making-2-finite-state-machines

namespace AIForGames {
	class _State
	{
	public:
		struct Transition {
		_Condition* condition;
		_State* TargetState;

		};
	
	private:
		std::vector<BehavioursFSM*> m_Behaviours;
		std::vector<Transition> m_Transition;
		

	public:
		_State();
		~_State();
		virtual void Update(AgentsFSM* agent, float deltaTime);
	};
}



