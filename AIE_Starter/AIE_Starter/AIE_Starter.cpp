#include "raylib.h"
#include "string"
#include "Pathfinding.h"
#include "PathfindingAlg.h"
#include "NodeMap.h"
#include "PathAgent.h"
#include <stdexcept>
#include <iostream>


using namespace AIForGames;

int main(int argc, char* argv[])
{
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // WINDOWS SETUP
    /////////////////////////////////////////////////////////////////////////////////////////////////
    int screenWidth = 715;
    int screenHeight = 475;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);


    /////////////////////////////////////////////////////////////////////////////////////////////////
    // SETTING UP THE MAP Visual
    /////////////////////////////////////////////////////////////////////////////////////////////////

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000");
    asciiMap.push_back("010111011100");
    asciiMap.push_back("010101110110");
    asciiMap.push_back("011100000010");
    asciiMap.push_back("010111111110");
    asciiMap.push_back("010000001010");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 60);


    // Setting Up the DijkstrasSearch
    Node* Start = map.GetNode(1, 1); 
    Node* end = map.GetNode(10, 2);
    std::vector<Node*>nodeMapPath = AIForGames::DijkstrasSearch(Start, end); // Setting the Start and the end to the DijkstarasSearch
    Color linecolour = { 255, 255, 255, 255 }; // Setting the Line colour

    
    // Setting Up the Pathing Agent
    PathAgent Agent;
    Agent.SetNode(Start);
    Agent.SetSpeed(64);



    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;
        BeginDrawing();

        ClearBackground(BLACK);
        map.Draw(); // Rendering the Map
        

        // Setting Up the Player Inputs
        if (IsMouseButtonPressed(0)) { // Checking To See if the Left Mouse buttion is press
            Vector2 mousePos = GetMousePosition();
            Node* end = map.GetClosestNode(glm::vec2(mousePos.x, mousePos.y));
            Agent.GoToNode(end);
        }

        Agent.Update(deltaTime);
        Agent.Draw(DARKBLUE);

        AIForGames::DrawPath(nodeMapPath, GREEN);
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}