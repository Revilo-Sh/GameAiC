#pragma once

#include <glm/glm.hpp>
#include <vector>
#include "raylib.h"

namespace AIForGames
{
    struct Node;

    //std::vector<Node*> Path; // Making a Vector List


    struct Edge {
        Node* target;
        float cost;

        Edge() { target = nullptr; cost = 0; }
        Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}
    };

    struct Node {
        Node() {}
        Node(float x, float y)
        {
            position = glm::vec2(x, y);
        }

        void ConnectTo(Node* other, float cost)
        {
            connections.push_back(Edge(other, cost));
        }

        glm::vec2 position;
        std::vector<Edge> connections;

        float gScore;
        float hScore;
        float fScore;

        Node* previous = NULL;

        
    };

    void DrawPath(std::vector<Node*> path, Color color);

}
