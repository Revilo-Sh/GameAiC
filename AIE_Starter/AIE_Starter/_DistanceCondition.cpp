#include "_DistanceCondition.h"

bool AIForGames::_DistanceCondition::IsTrue(AgentsFSM* agent)
{
    return (glm::distance(agent->m_pathAgent.GetPosition(), agent->GetTarget()->m_pathAgent.GetPosition()) < m_distance) == m_lessThan;
}
