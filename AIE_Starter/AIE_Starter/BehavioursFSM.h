#pragma once
#include "AgentsFSM.h"

//class AgentsFSM;

namespace AIForGames 
{

	class BehavioursFSM 
	{
	public:
		virtual void Update(AgentsFSM* agent, float deltaTime) = 0;
	};

}

