#include "_UtilityAi.h"

AIForGames::_UtilityAi::~_UtilityAi()
{
	for (BehavioursFSM* b : m_behaviours) {
		delete b;
	}
}

void AIForGames::_UtilityAi::Update(AgentsFSM* agent, float deltaTime)
{
	float bestEval = 0;
	BehavioursFSM* newBehaviour = nullptr;
	for (BehavioursFSM* b : m_behaviours) {
		float eval = b->Evaluate(agent);
		if (eval > bestEval) {
			bestEval = eval;
			newBehaviour = b;
		}
	}

	if (newBehaviour != nullptr && newBehaviour != currnetBehaviour) 
	{
		if (currnetBehaviour != nullptr)
		{
			currnetBehaviour->Exit(agent);
		}
		currnetBehaviour = newBehaviour;
		currnetBehaviour->Enter(agent);
	}
	currnetBehaviour->Update(agent, deltaTime);
}
