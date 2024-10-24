#include "raylib.h"
#include "string"
#include "Pathfinding.h"
#include "PathfindingAlg.h"
#include "NodeMap.h"
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

    

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key

        BeginDrawing();

        ClearBackground(BLACK);
        map.Draw(); // Rendering the Map
        
        AIForGames::DrawPath(nodeMapPath, GREEN);
        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}