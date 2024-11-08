#include "PathAgent.h"

using namespace std;

// https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-pathfinding-3-agents // WebLink To Course Page
// https://cplusplus.com/reference/vector/vector/ Vectors Page


void AIForGames::PathAgent::GoToNode(Node* node)
{
	m_path = DijkstrasSearch(m_currentNode, node); // Setting the DijkstrasSearch to Map m_path
	m_currentindex = 0; // Setting the current Index to 0 in the follow array
}


void AIForGames::PathAgent::Update(float deltaTime)
{

	if (m_path.empty()) return; //if there is no path do nothing

	// Setup For the Ai To Walk to The Next Point 

	glm::vec2 toNext = m_path[m_currentindex]->position - m_position; // makes a vector of the path current index to the m_position
	//  which it dose by subtracting m_path currentindex by m_pos
	glm::vec2 directionToNext = glm::normalize(toNext); // Get the Deretion of the Next Point Vector by normalizing the toNext Node Pos

	float distance = glm::length(toNext); // returns a float value of the ToLocal vector langth
	float moveOnNextFrame = distance - m_speed * deltaTime; // get the distance and subtracts its my the speed of the agent and to keep it
	// in sync do it by deltaTime; 


	//if we cannot fully travel, pathagent towards our current node 
	if (moveOnNextFrame > 0){ 
		m_position += (m_speed * deltaTime * directionToNext); // if so the pos of the agent added and equal to the speed and what direction to go to woth delta To Keep it synced
	}

	//if we can fully travel 
	else
	{
		
		m_currentindex++; // increase the current Node by 1

		if (m_currentindex < m_path.size())	{
			m_currentNode = m_path[m_currentindex]; // set the Current Node pos to the m_path current index Node pos
			toNext = m_path[m_currentindex]->position - m_path
				[m_currentindex - 1]->position; // Checks to see if there is any more nodes to walk to
			// intill it gets to to end

			directionToNext = glm::normalize(toNext); // Normalizes the Vector 

			m_position = m_path[m_currentindex - 1]->position + (-moveOnNextFrame * directionToNext);
			//Updates the agents m_position based on speed, time, distance, and direction of 
			// the m_path next node point
		}
		else {
			m_position = m_path.back()->position;  // setting the m_position to the m_path poistion
			m_path.clear(); // clearing the m_path
		}
	}
}


void AIForGames::PathAgent::SetNode(Node* i_node)
{
	m_currentNode = i_node; // Set the current Node of the Inputed Node
	m_position = i_node->position; // Set the position to to the inputed position
}

void AIForGames::PathAgent::SetSpeed(float Speed)
{
	m_speed = Speed; // Sets The speed of the Agent Based on the Function Speed
}

void AIForGames::PathAgent::GetNode()
{
	// will come back to this
}

void AIForGames::PathAgent::Draw(Color Colour)
{
	DrawCircle((int)m_position.x, (int)m_position.y, 8, Colour); // Setting the Agent To be a Circle and the colour.

	if (!m_path.empty())
	{
		DrawPath(m_path, Colour);
	}
}