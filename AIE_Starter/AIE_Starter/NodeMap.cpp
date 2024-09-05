#include "NodeMap.h"
#include <iostream>


using namespace AIForGames;

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

}



