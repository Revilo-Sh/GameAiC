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
		glm::vec2 m_position;
		std::vector<Node*> m_path;
		int m_currentindex;
		Node* m_currentNode;

	public:
		void Update(float deltaTime);
		void GoToNode(Node* node);
		void Draw(Color Colour);
	};
}


