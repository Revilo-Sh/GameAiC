#include "Pathfinding.h"
#include <iostream>
#include <algorithm>
//#include "Color.hpp"

namespace AIForGames 
{

	void DrawPath(std::vector<Node*> path, Color color)
	{
		if (path.empty()) return;


		for (int i = 0; i < path.size() - 1; i++) 
		{
			DrawLine(path[i]->position.x, path[i]->position.y, path[i + 1]->position.x, path[i + 1]->position.y, color);
		}
	}
}



