#include "BehavioursFSM.h"
#pragma once

namespace AIForGames {

	class FollowBehaviourFSM : public BehavioursFSM
	{
	public:
		void Update(AgentsFSM* agent, float deltaTime) override;

	private:
		glm::vec2 LastTargetPosition;
		
	};
}


