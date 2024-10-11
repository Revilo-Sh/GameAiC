#include "raylib.h"
#include "string"
#include "Pathfinding.h"
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
    asciiMap.push_back("010100000000");
    asciiMap.push_back("010111111110");
    asciiMap.push_back("010000001000");
    asciiMap.push_back("011111111110");
    asciiMap.push_back("000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 60);


    

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key

        BeginDrawing();

        ClearBackground(RAYWHITE);
        map.Draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}