#pragma once
#include "AgentsFSM.h"
#include "BehavioursFSM.h"
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
		_State(BehavioursFSM* b1) { m_Behaviours.push_back(b1); }
		~_State();

		virtual void Update(AgentsFSM* agent, float deltaTime);
		virtual void Enter(AgentsFSM* agent) {}
		virtual void Exit(AgentsFSM* agent) {}

		std::vector<Transition> GetTransitions() { return m_Transition;}

		void AddTransitions(_Condition* Condition, _State* State) {
			Transition NewTransition;

			NewTransition.condition = Condition;
			NewTransition.TargetState = State;

			m_Transition.push_back(NewTransition);
		}

	};
}



