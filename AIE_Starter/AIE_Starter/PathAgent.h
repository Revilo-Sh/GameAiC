#pragma once
#include "NodeMap.h"
#include "Pathfinding.h"
#include "PathfindingAlg.h"
#include "raylib.h"

#include <vector>
#include <glm/glm.hpp>



namespace AIForGames {

	class PathAgent
	{
	private:
		// All the Pathfinding Movment Verables
		glm::vec2 m_position;
		int m_currentindex;
		Node* m_currentNode;
		float m_speed;

	public:
		std::vector<Node*> m_path;

		void Update(float deltaTime); // updates on Delta Time
		void GoToNode(Node* node); // Set The Point it need to go to
		void Draw(Color Colour); // renders the Agent and set the colour

		void SetNode(Node* i_node); 
		void SetSpeed(float Speed); // Set the Speed Of the Agent
		void GetNode();// Get the Node it is on
	};
}


