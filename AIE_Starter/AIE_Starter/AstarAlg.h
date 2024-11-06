#pragma once
#include "Pathfinding.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace AIForGames{
    static bool CompareGscore(const Node* Ihs, const Node* Rhs) {return Ihs->gScore < Rhs->gScore;} 

    static std::vector<Node*> Astar(Node* startNode, Node* endNode) {

        if (startNode == nullptr || endNode == nullptr){
            std::cout << "StartNode / End Node was Nullprt\n";
            return std::vector<Node*>();
        }

        if (startnode == endnode){ // dont know why it not working
            std::cout << "Start Node and end Node are on the Same point\n";
            return std::vector<Node*>();
        }


        // Setting The Nodes Up
        startNode->gScore = 0;
        startNode->previous = nullptr;

        // Making the Temp List for holding Node data
        std::vector<Node*> openlist;
        std::vector<Node*> closeList;

        Node* currentNode;

        openlist.push_back(startNode);


        // NEED TO ADD IN THE FINDING ALG HERE


        std::vector<Node*> Path;
        currentNode = endNode;
        while (currentNode != nullptr)
        {
            Path.insert(Path.begin(), currentNode);
            currentNode = currentNode->previous;
        }
        return Path;
        
    }

}