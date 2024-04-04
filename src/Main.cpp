#include <stdio.h>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    GumBallMachine gumBallMachine(5);
    // if(gumBallMachine.count > 0)
    // {
    //     gumBallMachine.state = gumBallMachine.noQuarterState;
    //     currentState->LoadGumballs(5);
    // }
    // currentState->InsertQuarter();
    // currentState->EjectQuarter();
    // currentState->TurnCrank();
    
    //Run GumBall machine tests
    gumBallMachine.TestGumballMachine();
    return 0;
}