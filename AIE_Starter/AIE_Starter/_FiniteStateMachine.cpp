#include "_FiniteStateMachine.h"

AIForGames::_FiniteStateMachine::~_FiniteStateMachine()
{
	for (_State* s : m_states) {
		delete s;
	}
}

void AIForGames::_FiniteStateMachine::Update(AgentsFSM* agents, float deltaTime)
{
	

	_State* newState = nullptr;

	for (_State::Transition t : m_currentState->GetTransitions()) {
		if (t.condition->IsTrue(agents)) {
			newState = t.TargetState;
		}
	}

	if (newState != nullptr && newState != m_currentState) {
		m_currentState->Exit(agents);
		m_currentState = newState;
		m_currentState->Enter(agents);
	}

	m_currentState->Update(agents, deltaTime);
}
