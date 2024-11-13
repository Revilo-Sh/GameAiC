#include "AgentsFSM.h"
#include "BehavioursFSM.h"

namespace AIForGames{

    void AgentsFSM::Update(float deltaTime)
    {
        if (m_current) {
            m_current->Update(this, deltaTime); // this is not working
        }
        m_pathAgent.Update(deltaTime);
    }
    void AgentsFSM::GoTo(glm::vec2 pos)
    {
        //translate vec2 -> node
        m_pathAgent.GoToNode(m_nodeMap->GetClosestNode(pos));
    }
    void AgentsFSM::Reset()
    {
       // DONT KNOW HOW I WOULD CLEAR THIS MY HEAD IS FUCKING HEARTING I BEEN WORKING
       // ON THIS ALL DAY AND IM BURING OUT
    }
    bool AgentsFSM::PathComplete()
    {
        return m_pathAgent.m_path.empty();
    }
    AgentsFSM* AgentsFSM::SetTarget(AgentsFSM* Target)
    {
        Target = m_Target;
    }
}