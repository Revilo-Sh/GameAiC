#pragma once
#include "vector"
#include "string"
#include "Pathfinding.h"

class NodeMap
{
	int m_with, m_height;
	float m_cellsize;

	Node** m_nodes;
	Node* GetNode(int x, int y) { return m_nodes[x + m_with * y]; }

public:
	void Initialise(std::vector<std::string> asciiMap, int cellSize);
};

