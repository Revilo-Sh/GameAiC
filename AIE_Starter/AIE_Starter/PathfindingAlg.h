#pragma once
#include "Pathfinding.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace AIForGames
{
	static bool CompareGScore(const Node* Ihs, const Node* Rhs) { return Ihs->gScore < Rhs->gScore; }

	static std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{

		// https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-pathfinding-2-pathfinding The Weblink to the assiment
		//https://cplusplus.com/reference/vector/vector/ Vectors Page

		// Validate the input
		if (startNode == nullptr || endNode == nullptr) // Check to See If Startpoint // Endpoint is on a nullptr
		{
			std::cout << "Stardnode / Endnode was nullptr:\n"; // Send Error Message
			return std::vector<Node*>();
		}


		if (startNode == endNode) // Check To see if both Start and End Points are on the same Cell/Node
		{
			std::cout << "Starnode + Endnode were same point;\n";// Send Error Message
			return std::vector<Node*>();
		}

		// Set The Startting Node
		startNode->gScore = 0;
		startNode->previous = nullptr;

		// Create our Temp Lists For Holding Nodes
		std::vector<Node*> openList; // Setting Up the Open List
		std::vector<Node*> closeList; // Setting Up the Close List

		Node* currentNode;//// Declares the current node ref and puts it to front of openlist

		openList.push_back(startNode); // add start Node to the list

		// Adding To the List
		while (!openList.empty()) // Check to See If the List Is Not empty If so Then || START ||
		{
			std::sort(openList.begin(), openList.end(), CompareGScore); // sorts list

			// Move Ndoe From Open List To Close List
			currentNode = openList.front(); // adds to the list

			if (currentNode == endNode) { // Check to See if current Node is end node
				break; // end the while loop
			}

			openList.erase(openList.begin()); // Need To Fix Remove
			closeList.push_back(currentNode); // Adds the data to the Vector

			for (Edge c : currentNode->connections) // Gose Throguht the Vector Looking For Cells/Nodes With connections
			{
				if (std::find(closeList.begin(), closeList.end(), c.target) == closeList.end()) // Check to See if target not in CloseList
				{
					int gScore = currentNode->gScore + c.cost; // Add The Points Based Off a distance To see if it the smallest Path

					if (std::find(openList.begin(), openList.end(), c.target) == openList.end())//is the target in the openlist?
					{
						c.target->gScore = gScore; // Setting the c target g score to gscore
						c.target->previous = currentNode; //Setting c.target.previous to the currentNode
						openList.push_back(c.target);//Add c.target to openList
					}
					else if (c.target->gScore > gScore) //is the calculated gscore lower than it's current gscore
					{
						c.target->gScore = gScore; //Set c.target.gScore = gScore
						c.target->previous = currentNode; //Set c.target.previous = currentNode
					}
				}
			}
		}
		// Create a Path in reverse from endnode to start node

		std::vector<Node*> Path;

		currentNode = endNode; // Set the current node to the Endnode Pos/Cell
		while (currentNode != nullptr) // Check to see if current node is not a nullptr
		{
			Path.insert(Path.begin(), currentNode); // Add the Current Node to the frount of the Path Vector List
			currentNode = currentNode->previous; // set the current path to the previous path 
		}

		return Path;
	}


}