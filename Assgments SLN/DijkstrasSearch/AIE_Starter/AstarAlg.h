#pragma once
#include "Pathfinding.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace AIForGames
{
    static bool CompareFscore(const Node* Ihs, const Node* Rhs) {return Ihs->fScore < Rhs->fScore;} 

    // https://aie.instructure.com/courses/1344/pages/artificial-intelligence-for-games-a-star The Link the the course Page For this assigment


    float Heuristic(Node* a, Node* b)
    {
        //return distance from a position to b position
        //glm::distance(a->position, b->position);

        //float thisFloat = 4.0f;
        //return thisFloat;
        //return 4.0f;


        //float newFloat = glm::distance(a->position, b->position);
        //return newFloat;
        //return glm::distance(a->position, b->position);

        return glm::distance(a->position, b->position);
    }

    static std::vector<Node*> Astar(Node* startNode, Node* endNode) 
    {

        if (startNode == nullptr || endNode == nullptr){
            std::cout << "StartNode / End Node was Nullprt\n";
            return std::vector<Node*>();
        }

        if (startNode == endNode) {
            std::cout << "Start Node and end Node are on the Same point\n";
            return std::vector<Node*>();
        }

        // Setting The Nodes Up
        startNode->gScore = 0;
        startNode->previous = nullptr;

        // Making the Temp List for holding Node data
        std::vector<Node*> openlist;
        std::vector<Node*> closeList;

        Node* currentNode; // making the current node verable

        openlist.push_back(startNode);

        while (!openlist.empty()) 
        {

            std::sort(openlist.begin(), openlist.end(), CompareFscore);
            currentNode = openlist.front();

            if (currentNode == endNode) {
                break;
            }

            openlist.erase(openlist.begin());
            closeList.push_back(currentNode);

            for (Edge c : currentNode->connections) {
                if (std::find(closeList.begin(), closeList.end(), c.target) == closeList.end()) {

                    int gScore = currentNode->gScore + c.cost;
                    int hScore = Heuristic(c.target, endNode);
                    int fScore = gScore + hScore; // should be gScore + hScore

                    if (std::find(openlist.begin(), openlist.end(), c.target) == openlist.end()) {
                        c.target->gScore = gScore;
                        c.target->fScore = fScore;
                        c.target->previous = currentNode;
                        openlist.push_back(c.target);
                    }
                    else if (fScore < c.target->fScore)
                    {
                        c.target->gScore = gScore;
                        c.target->fScore = fScore;
                        c.target->previous = currentNode;
                    }
                }
            }
        }

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