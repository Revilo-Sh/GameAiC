#pragma once
#include "Pathfinding.h"
#include "PathAgent.h"
#include "BehavioursFSM.h"
#include <iostream>

//https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-decision-making-1-agents-and-behaviours


namespace AIForGames{

    class AgentsFSM
    {
    public:
        AgentsFSM() {}
        ~AgentsFSM() {}
        AgentsFSM(NodeMap* nodeMap, BehavioursFSM* Behaviour) : m_current(Behaviour), m_nodeMap(nodeMap), m_colour({255, 255, 0, 255}) {}
        
    private:
        PathAgent m_pathAgent;
        BehavioursFSM* m_current;
        NodeMap* m_nodeMap;
        Color m_colour;
    };
}


