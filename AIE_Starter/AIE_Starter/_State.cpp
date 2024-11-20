#include "_State.h"


AIForGames::_State::_State(){
    for (BehavioursFSM* b : m_Behaviours){
        delete b;
    }

    for (Transition t : m_Transition){
        delete t.condition;
    }
}