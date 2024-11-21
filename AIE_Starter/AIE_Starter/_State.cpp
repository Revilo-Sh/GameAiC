#include "_State.h"


AIForGames::_State::~_State()
{
    for (BehavioursFSM* b : m_Behaviours) {
        delete b;
    }

    for (Transition t : m_Transition) {
        delete t.condition;
    }
}

void AIForGames::_State::Update(AgentsFSM* agent, float deltaTime)
{
    for (BehavioursFSM* b : m_Behaviours) {
        b->Update(agent, deltaTime);
    }
}
