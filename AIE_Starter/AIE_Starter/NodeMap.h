#pragma once
//#include "vector"
#include "string"
#include "Pathfinding.h"


namespace AIForGames
{
	class NodeMap
	{
		int m_with, m_height;
		float m_cellsize;

		Node** m_nodes;


	public:
		void Initialise(std::vector<std::string> asciiMap, int cellSize);
		void Draw();
		Node* GetNode(int x, int y) { return m_nodes[x + m_with * y]; }
		Node* GetClosestNode(glm::vec2 worldPos);
	};

}

