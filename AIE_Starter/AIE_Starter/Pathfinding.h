#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace AIForGames
{
    struct Node;

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

        /////
        //Pathing Finding Types
        ////

        //DijkstrasSearch

        std::vector<Node*> DijkstrasSearch(Node* startNode, Node* endNode);









        float gScore;
        Node* previous = NULL;
    };
}
