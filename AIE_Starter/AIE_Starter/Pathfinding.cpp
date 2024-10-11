#include "Pathfinding.h"
#include <iostream>

namespace AIForGames {
	std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode)
	{

		//std::vector<Node*> openList;
		//bool found;
		//Node* test;

		//if (std::find(openList.begin(), openList.end(), test) == openList.end()) {
		//	found == false;
		//}
		//else
		//{
		//	found == true;
		//}


		// Validate the input
		if (startNode == nullptr || endNode == nullptr) 
		{
			std::cout << "Stardnode / Endnode was nullptr:\n";
			return std::vector<Node*>();
		}


		if (startNode == endNode) 
		{
			std::cout << "Starnode + Endnode were same point;\n";
			return std::vector<Node*>();
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
//
//
//    Procedure dijkstrasSearch(startNode, endNode) // COME BACK TO ?? //
//        // Validate the input
//        if startNode is null OR endNode is null
//            Raise Error
//
//            if startNode == endNode
//                return empty Path
//
//                // Initialise the starting node
//                Set startNode.gScore to 0
//                Set startNode.previous to null
//
//                // Create our temporary lists for storing nodes we’re visiting/visited
//                Let openList be a List of Nodes
//                Let closedList be a List of Nodes
//
//                Add startNode to openList
//
//                While openList is not empty
//                Sort openList by Node.gScore
//
//                Let currentNode = first item in openList
//
//                // If we visit the endNode, then we can exit early.
//                // Sorting the openList above guarantees the shortest path is found,
//                // given no negative costs (a prerequisite of the algorithm).
//                // This is an optional optimisation that improves performance,
//                // but doesn’t always guarantee the shortest path.
//                If currentNode is endNode
//                Exit While Loop
//
//                Remove currentNode from openList
//                Add currentNode to closedList
//
//                For all connections c in currentNode
//                If c.target not in closedList
//                Let gScore = currentNode.gScore + c.cost
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


