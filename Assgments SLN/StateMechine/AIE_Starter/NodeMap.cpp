#include "NodeMap.h"
#include <iostream>
#include "Color.hpp"

//using namespace AIForGames;

namespace AIForGames
{
	void NodeMap::Initialise(std::vector<std::string> asciiMap, int cellSize)
	{
		m_cellsize = cellSize;
		const char emptySquare = '0';


		m_height = asciiMap.size();
		m_with = asciiMap[0].size();

		m_nodes = new Node * [m_with * m_height];

		for (int y = 0; y < m_height; y++)
		{
			std::string& line = asciiMap[y];
			if (line.size() != m_with) {
				std::cout << "Mismatched line #" << y << " in ASCII map (" << line.size() << " instead of " << m_with << ")" << std::endl;
			}

			for (int x = 0; x < m_with; x++)
			{
				char tile = x < line.size() ? line[x] : emptySquare;
				m_nodes[x + m_with * y] = tile == emptySquare ? nullptr
					: new Node(((float)x + 0.5f) * m_cellsize, ((float)y + 0.5f) * m_cellsize); // ?? It red
			}
		}

		for (int y = 0; y < m_height; y++) {  //gose throught the array up to down on the array axis
			for (int x = 0; x < m_with; x++) { // gose throught the array left to right on the array axis
				Node* node = GetNode(x, y);
				if (node) {
					// Will Check To See If there iS a node on the west, Checking For array overruns
					Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
					if (nodeWest) {
						node->ConnectTo(nodeWest, 1); 
						nodeWest->ConnectTo(node, 1);
					}

					Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
					if (nodeSouth) {
						node->ConnectTo(nodeSouth, 1);
						nodeSouth->ConnectTo(node, 1);
					}
				}
			}
		}
	}
	void NodeMap::Draw()
	{
		Color cellcolor;
		cellcolor.a = 255;
		cellcolor.r = 255;
		cellcolor.g = 0;
		cellcolor.b = 0;

		Color lineColor;
		lineColor.a = 255;
		lineColor.r = 128;
		lineColor.g = 128;
		lineColor.b = 128;


		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_with; x++) {
				Node* node = GetNode(x, y);
				if (node == nullptr) {
					// This will Draw the Solid blocks in Empty Squares where there is no NAV node
					DrawRectangle((int)(x * m_cellsize), (int)(y * m_cellsize),
						(int)m_cellsize - 1, (int)m_cellsize - 1, cellcolor);
				}
				else
				{
					for (int i = 0; i < node->connections.size(); i++)
					{
						Node* other = node->connections[i].target;
						DrawLine((x + 0.5f) * m_cellsize, (y + 0.5f) * m_cellsize,
							(int)other->position.x, (int)other->position.y,
							lineColor);
					}
				}
			}
		}
	}
	Node* NodeMap::GetClosestNode(glm::vec2 worldPos)
	{
		int i = (int)(worldPos.x / m_cellsize);
		if (i < 0 || i >= m_with) {
			return nullptr;
		
		}

		int j = (int)(worldPos.y / m_cellsize);
		if (j < 0 || j >= m_height) {
			return nullptr;

		}

		return GetNode(i, j);
		
	}
	Node* NodeMap::GetRandomNode()
	{
		Node* node = nullptr;
		while (node == nullptr)
		{
			int x = rand() % m_with;
			int y = rand() % m_height;
			node = GetNode(x, y);
		}
		return node;
	}
}





