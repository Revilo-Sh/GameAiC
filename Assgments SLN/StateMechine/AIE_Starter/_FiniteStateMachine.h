#pragma once
#include <vector>
#include "_State.h"
#include "AgentsFSM.h"
#include"BehavioursFSM.h"

namespace AIForGames {

	class _FiniteStateMachine : public BehavioursFSM
	{
	private:
		std::vector<_State*> m_states;

		_State* m_currentState;
		_State* m_newState;

	public:
		_FiniteStateMachine(_State* s) : m_currentState(s), m_newState(nullptr) {}
		virtual ~_FiniteStateMachine();
		
		
		void Update(AgentsFSM* agents, float deltaTime);
		void AddState(_State* t_State) {
			m_states.push_back(t_State);
		}
		void Enter(AgentsFSM* agent) {
			agent->Draw({ RED });
			m_currentState->Enter(agent);
		}
	};
}



