#include "Pathfinding.h"
#include <iostream>
#include <algorithm>

namespace AIForGames {
	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{

		// https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-pathfinding-2-pathfinding The Weblink to the assiment

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

		openList.push_back(startNode); // add start Node to the list
		
		// Adding To the List
		while (!openList.empty()) // Check to See If the List Is Not empty If so Then || START ||
		{
			std::sort(openList.begin(), openList.end(), CompareGScore); // sorts list

			Node* currentNode = openList.front(); // Add Node to List

			if (currentNode == endNode) { // Check to See if current Node is end node
				break; // end the while loop
			}

			// Move Ndoe From Open List To Close List
			Node* currentNode = openList.front(); // adds to the list
			openList.erase(openList.begin()); // Need To Fix Remove
			closeList.push_back(currentNode); // Adds the data to the Vector
		
			for (Edge c : currentNode->connections) // Gose Throguht the Vector Looking For Cells/Nodes With connections
			{
				if (std::find(closeList.begin(), closeList.end(), c.target) != closeList.end()) // Check to See if target not in CloseList
				{
					int gScore = currentNode->gScore + c.cost; // Add The Points Based Off a distance To see if it the smallest Path

					if (std::find(openList.begin(), openList.end(), c.target) != closeList.end())//is the target in the openlist?
					{
						c.target->gScore = gScore; //Set c.target.gScore = gScore
						c.target->previous = currentNode; //Set c.target.previous = currentNode
						openList.push_back(currentNode);//Add c.target to openList
					}
					else if (c.target->gScore > gScore) //is the calculated gscore lower than it's current gscore
					{
						c.target->gScore = gScore; //Set c.target.gScore = gScore
						c.target->previous = currentNode; //Set c.target.previous = currentNode
					}
				}	
			}
		}
	}
}

//std::vector<Node*> AIForGames::Node::DijkstrasSearch(Node* startNode, Node* endNode)
//{
//
////////////////////    // CONVERT ALL OF THIS TO REAL CODE
////////////////////
////////////////////
////////////////////    std::vector<Node*> openList;
////////////////////    bool found;
////////////////////    Node* test;
////////////////////    if (std::find(openList.begin(), openList.end(), test) == openList.end()) {
////////////////////        found == false;
////////////////////    }
////////////////////    else
////////////////////    {
////////////////////        found == true;
////////////////////    }
//    Procedure dijkstrasSearch(startNode, endNode) // COME BACK TO ?? //
//        // Validate the input
//        if startNode is null OR endNode is null
//            Raise Error
//
//            if startNode == endNode
//                return empty Path
//                // Initialise the starting node
//                Set startNode.gScore to 0
//                Set startNode.previous to null
//////////        // Create our temporary lists for storing nodes we’re visiting/visited
//////////                Let openList be a List of Nodes
//////////                Let closedList be a List of Nodes
//////////
//                Add startNode to openList
//
//                While openList is not empty
//                Sort openList by Node.gScore
//
//                Let currentNode = first item in openList
//                // If we visit the endNode, then we can exit early.
//                // Sorting the openList above guarantees the shortest path is found,
//                // given no negative costs (a prerequisite of the algorithm).
//                // This is an optional optimisation that improves performance,
//                // but doesn’t always guarantee the shortest path.
//                If currentNode is endNode
//                Exit While Loop
//                Remove currentNode from openList
//                Add currentNode to closedList
//                For all connections c in currentNode
//                If c.target not in closedList
//                Let gScore = currentNode.gScore + c.cost
// 
// 
// 
// 
//                // Have not yet visited the node.
//                // So calculate the Score and update its parent.
//                // Also add it to the openList for processing.
//                If c.target not in openList
//                Set c.target.gScore = gScore
//                Set c.target.previous = currentNode
//                Add c.target to openList
//
//                // Node is already in the openList with a valid Score.
//                // So compare the calculated Score with the existing
//                // to find the shorter path.
//                Else if (gScore < c.target.gScore)
//                Set c.target.gScore = gScore
//                Set c.target.previous = currentNode
//
//                // Create Path in reverse from endNode to startNode
//                Let Path be a list of Nodes
//                Let currentNode = endNode
//
//                While currentNode is not null
//                Add currentNode to beginning of Path
//                Set currentNode = currentNode.previous
//
//                // Return the path for navigation between startNode/endNode
//                Return Path
//}


