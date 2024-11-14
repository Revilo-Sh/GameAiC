#include "raylib.h"
#include "string"
#include "Pathfinding.h"
#include "PathfindingAlg.h"
#include "AstarAlg.h"
#include "NodeMap.h"
#include "PathAgent.h"
#include "AgentsFSM.h"

#include "GotoPointBehaviourFSM.h"
#include "FollowBehaviourFSM.h"
#include "WanderBehaviourFSM.h"
#include "SelectorBehaviourFSM.h"

#include <stdexcept>
#include <iostream>


using namespace std;
using namespace AIForGames;


int main(int argc, char* argv[])
{
    int State = 2;
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // WINDOWS SETUP
    /////////////////////////////////////////////////////////////////////////////////////////////////
    int screenWidth = 1200;
    int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);


    /////////////////////////////////////////////////////////////////////////////////////////////////
    // SETTING UP THE MAP Visual
    /////////////////////////////////////////////////////////////////////////////////////////////////

    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000000000000000");
    asciiMap.push_back("010111011100000001111110");
    asciiMap.push_back("010101110111111111000010");
    asciiMap.push_back("011100000010000010000010");
    asciiMap.push_back("010111111110000110111010");
    asciiMap.push_back("010000001010000100001110");
    asciiMap.push_back("011111111111111110001010");
    asciiMap.push_back("000101000000010011111110");
    asciiMap.push_back("011101000000111000010010");
    asciiMap.push_back("010001111111101111111110");
    asciiMap.push_back("011111010000111000000010");
    asciiMap.push_back("000000000000000000000000");

    NodeMap map;
    map.Initialise(asciiMap, 50);


    // Setting Up the DijkstrasSearch
    Node* start = map.GetNode(1, 1); 
    Node* end = map.GetNode(1, 2);

    Node* start2 = map.GetNode(1, 1);
    Node* end2 = map.GetNode(7, 1);
    std::vector<Node*>nodeMapPath = AIForGames::DijkstrasSearch(start, end); // Setting the Start and the end to the DijkstarasSearch
    std::vector<Node*>nodeMapPathStar = AIForGames::Astar(start2, end2);
    Color linecolour = { 255, 255, 255, 255 }; // Setting the Line colour


    
    // Setting Up the Pathing Agent
    PathAgent Agent;
    
    Agent.SetNode(start2);
    Agent.GoToNode(start2);
    Agent.SetSpeed(1000);

    // FSM Agents
    //AgentsFSM FSM_Agent(&map, new GotoPointBehaviourFSM());
    AgentsFSM FSM_Agent(&map, new GotoPointBehaviourFSM());
    FSM_Agent.SetNode(map.GetRandomNode());
    FSM_Agent.SetSpeed(200);

    AgentsFSM FSM_AgentWander(&map, new WanderBehaviourFSM());
    FSM_AgentWander.SetNode(map.GetRandomNode());
    FSM_AgentWander.SetSpeed(200);

    AgentsFSM FSM_AgentFollow(&map, new FollowBehaviourFSM());
    FSM_AgentFollow.SetNode(map.GetRandomNode());
    FSM_AgentFollow.SetTarget(&FSM_Agent);
    FSM_AgentFollow.SetSpeed(50);

    AgentsFSM FSM_AgentsSelctor(&map, new SelectorBehaviourFSM( new FollowBehaviourFSM(), new WanderBehaviourFSM()));
    FSM_AgentsSelctor.SetNode(map.GetRandomNode());
    FSM_AgentsSelctor.SetTarget(&FSM_Agent);
    FSM_AgentsSelctor.SetSpeed(100);


    float time = (float)GetTime();
    float deltaTime;

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
 
        BeginDrawing();

       ///////////////////////
       // Agent Setup
       ///////////////////////

        float fTime = (float)GetTime();
        deltaTime = fTime - time;
        time = fTime;




        ClearBackground(BLACK);
        map.Draw(); // Rendering the Map
        
        if (IsKeyPressed(KeyboardKey::KEY_TAB)) { // Check To See if tab is press Down
            State++; // Increase the state by which will make it which pathfinding ALG will be use
                    // 1 will be DijkstrasSearch
                    // 2 will be A* Search
            if (State >= 3) { 
                State = 1;
            }
            cout << State << endl;
        }


        if (State == 1) { // Check to see if the state is one to use DijkstrasSearch
            if (IsMouseButtonPressed(1)) {
                Vector2 mousepos = GetMousePosition();
                start = map.GetClosestNode(glm::vec2(mousepos.x, mousepos.y));
                nodeMapPath = AIForGames::DijkstrasSearch(start, end);
            }

            if (IsMouseButtonPressed(0)) {
                Vector2 mousepos = GetMousePosition();
                end = map.GetClosestNode(glm::vec2(mousepos.x, mousepos.y));
                nodeMapPath = AIForGames::DijkstrasSearch(start, end);
            }
        }

        if (State == 2) { // Check to see if the state is one to use DijkstrasSearch


        }

        // THE FSM Agents 
        FSM_Agent.Update(deltaTime);
        FSM_Agent.Draw(BLUE);

        FSM_AgentWander.Update(deltaTime);
        FSM_AgentWander.Draw(YELLOW);

        FSM_AgentFollow.Update(deltaTime);
        FSM_AgentFollow.Draw(RED);

        FSM_AgentsSelctor.Update(deltaTime);
        FSM_AgentsSelctor.Draw(BROWN);

        //Agent.Update(deltaTime);
        //Agent.Draw(DARKBLUE);

        AIForGames::DrawPath(nodeMapPath, GREEN);

      

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}