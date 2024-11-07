#include "PathAgent.h"


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
	

	//calculate distance to next node
	//Both currentnode and pathagent have a vec2 position value, calculate the distance between them and store in a float var

	float dist = (m_position.x + m_position.y) - (m_currentNode->position.x + m_currentNode->position.y);

	if (dist < 0) { // Check to See if Distance is < 0;
		dist *= -1; // Makes the Number Positive
	}


	//Unit Vector (calculate a normalized directional vector from pathagent to the current node)
	//To calculate unit vector, calculate translation vector from pathagent position to currentnode position
	//divide vector components by it's magnitude (divide this translation vector by the distance calculated earlier)

	float result = dist - m_speed * deltaTime; // need more here
	glm::vec2 direction = m_currentNode->position;
	direction.x /= dist;
	direction.y /= dist;


		//Subtract speed * deltaTime from the distance (how much we’re going to move this frame)
	//Distance = how far away from current node
	//speed * deltaTime = how far pathagent can travel this frame
	//distance -= speed*deltatime  /=/  can we fully travel to the node this frame?

	if (result > 0) {
		m_position += m_speed * deltaTime; // need more here
	}

	//if we cannot fully travel, (distance > 0 still)
	//this frame we move our pathagent towards our current node 
	//unit vector * speed * deltatime added to pathagent m_position

	if (dist > 0) {

	}

	//if we can fully travel (distance < 0)
	//we will be overshooting/moving past our current node so we cannot use same logic as above
	//increment currentIndex (the value we are using to step through the vector of nodes (our path)
	// 
	// STORE CURRENTNODE IN A TEMP NODE* PREVIOUS NODE
	// 
	//if we are at the end of our path (vector of nodes) we can snap to the end node position and clear the path
	// 
	// SET CURRENTNODE TO BE M_PATH[CURRENTINDEX]
	
	

	// 
	//if not then we need to calculate a new unit vector from our previous node to our new currentNode
	//move along this vector by how much we overshot the distance (inverse distance value from negative to positive, multiply by this unit vector)

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

}

void AIForGames::PathAgent::Draw(Color Colour)
{
	DrawCircle((int)m_position.x, (int)m_position.y, 8, Colour); // Setting the Agent To be a Circle and the colour.
}