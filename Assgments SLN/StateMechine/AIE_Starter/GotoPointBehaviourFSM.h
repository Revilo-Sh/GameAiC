#pragma once
#include "BehavioursFSM.h"
#include "raylib.h"
#include "vector"


//class AgentsFSM;

namespace AIForGames 
{


	class GotoPointBehaviourFSM : public BehavioursFSM
	{
	public:
		void Update(AgentsFSM* agent, float deltaTime) override;
	};
	
	
}



