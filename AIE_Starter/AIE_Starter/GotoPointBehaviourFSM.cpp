#include "GotoPointBehaviourFSM.h"

#include "AgentsFSM.h"

using namespace AIForGames;

void AIForGames::GotoPointBehaviourFSM::Update(AgentsFSM* agent, float deltaTime)
{
	if (IsMouseButtonPressed(0)) {
		Vector2 mousePos = GetMousePosition();
		agent->GoTo(glm::vec2(mousePos.x, mousePos.y)); // Still Dose not work idk why
	}
}
