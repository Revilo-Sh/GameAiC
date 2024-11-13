#pragma once
#include "BehavioursFSM.h"


//class AgentsFSM;


namespace AIForGames {

	class WanderBehaviourFSM : public BehavioursFSM
	{
	public:
		void Update(AgentsFSM* agent, float deltaTime) override;
	};
}


