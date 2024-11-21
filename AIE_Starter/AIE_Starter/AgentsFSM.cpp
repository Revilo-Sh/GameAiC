#include "BehavioursFSM.h"
#include "AgentsFSM.h"


AIForGames::AgentsFSM::AgentsFSM(NodeMap* nodeMap, BehavioursFSM* Behaviour) : m_current(Behaviour), m_nodeMap(nodeMap), m_colour(RED) 
{
    m_current->Enter(this);
}

void AIForGames::AgentsFSM::Update(float deltaTime)
{
    if (m_current) {
        m_current->Update(this, deltaTime);
    }
    m_pathAgent.Update(deltaTime);
}

void AIForGames::AgentsFSM::GoTo(glm::vec2 pos)
{
    //translate vec2 -> node
    m_pathAgent.GoToNode(m_nodeMap->GetClosestNode(pos));
}

void AIForGames::AgentsFSM::Reset()
{
    // DONT KNOW HOW I WOULD CLEAR THIS MY HEAD IS FUCKING HEARTING I BEEN WORKING
    // ON THIS ALL DAY AND IM BURING OUT
}

void AIForGames::AgentsFSM::Draw(Color Colour)
{
    m_pathAgent.Draw(Colour);
}

bool AIForGames::AgentsFSM::PathComplete()
{
    return m_pathAgent.m_path.empty();
}












