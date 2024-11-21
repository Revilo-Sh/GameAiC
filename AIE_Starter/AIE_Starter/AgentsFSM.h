#pragma once
#include "Pathfinding.h"
#include "PathAgent.h"
#include <iostream>

//https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-decision-making-1-agents-and-behaviours


namespace AIForGames
{

    class BehavioursFSM;

    class AgentsFSM
    {
    public:
       AgentsFSM() {}
       ~AgentsFSM() {}
       AgentsFSM(NodeMap* nodeMap, BehavioursFSM* Behaviour);
       

    public:
       void Update(float deltaTime);
       void GoTo(glm::vec2 pos);
       void Reset();
       void SetNode(Node* Startpoint) { m_pathAgent.SetNode(Startpoint); }
       void Draw(Color Colour);
       void SetSpeed(float Speed) { m_pathAgent.SetSpeed(Speed); }

       bool PathComplete();

       void SetTarget(AgentsFSM* Target) { m_Target = Target; }
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


