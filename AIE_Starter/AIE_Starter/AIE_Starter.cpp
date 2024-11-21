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

#include "_Condition.h"
#include "_DistanceCondition.h"
#include "_FiniteStateMachine.h"
#include "_State.h"


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

    AgentsFSM FSM_Agent(&map, new GotoPointBehaviourFSM());
    FSM_Agent.SetNode(start);
    FSM_Agent.SetSpeed(200);

    AgentsFSM FSM_Agent2(&map, new FollowBehaviourFSM());
    FSM_Agent2.SetNode(map.GetRandomNode());
    FSM_Agent2.SetTarget(&FSM_Agent);
    FSM_Agent2.SetSpeed(25);
    

    // Setting Up the FSM  COnditions
    
    _DistanceCondition* closerThan5 = new _DistanceCondition(5.0f * map.GetcellSize(), true);
    _DistanceCondition* furtherThan7 = new _DistanceCondition(7.0f * map.GetcellSize(), false);

    // Setting Up all the States
    _State* wanderState = new _State(new WanderBehaviourFSM());
    _State* followState = new _State(new FollowBehaviourFSM());
    wanderState->AddTransitions(closerThan5, followState);
    followState->AddTransitions(furtherThan7, wanderState);
    
    _FiniteStateMachine* fsm = new _FiniteStateMachine(wanderState);
    fsm->AddState(wanderState);
    fsm->AddState(followState);

    AgentsFSM FSM_Agent3(&map, fsm); 
    FSM_Agent3.SetNode(map.GetRandomNode());
    FSM_Agent3.SetTarget(&FSM_Agent);
    FSM_Agent3.SetSpeed(150);



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

        FSM_Agent.Update(deltaTime);
        FSM_Agent2.Update(deltaTime);
        FSM_Agent3.Update(deltaTime);


        ClearBackground(BLACK);
        map.Draw(); // Rendering the Map
       


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


        FSM_Agent.Draw(BLUE);
        FSM_Agent2.Draw(RED);
        FSM_Agent3.Draw(YELLOW);


        AIForGames::DrawPath(nodeMapPath, GREEN);

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}