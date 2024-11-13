#pragma once
#include "Pathfinding.h"
#include "PathAgent.h"
#include <iostream>

class BehavioursFSM;

//https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-decision-making-1-agents-and-behaviours


namespace AIForGames
{

    class AgentsFSM
    {
    public:
       AgentsFSM() {}
       ~AgentsFSM() {}
       AgentsFSM(NodeMap* nodeMap, BehavioursFSM* Behaviour) : m_current(Behaviour), m_nodeMap(nodeMap), m_colour(RED) {}
       //AgentsFSM(NodeMap* nodeMap, BehavioursFSM* b)
       //{
       //    m_current = b;
       //    m_nodeMap = nodeMap;
       //    m_colour = RED;
       //}
       //
       

    public:
       void Update(float deltaTime);
       void GoTo(glm::vec2 pos);
       void Reset();
       void SetNode(Node* Startpoint) { m_pathAgent.SetNode(Startpoint); }
       bool PathComplete();

       AgentsFSM* SetTarget(AgentsFSM* Target);
       AgentsFSM* GetTarget() { return m_Target; }
       
    
    public:
       PathAgent m_pathAgent;
       BehavioursFSM* m_current;
       NodeMap* m_nodeMap;
       Color m_colour;
       AgentsFSM* m_Target;
  
       NodeMap* GetNodeMap() { return m_nodeMap; }

    };
    
}


