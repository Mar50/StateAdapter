#include <stdio.h>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    State currentState = new 
    if(currentState->m_iCount > 0)
    {
        currentState->SetState(currentState, noQuarterState);
        currentState->LoadGumballs(5);
    }
    currentState->InsertQuarter();
    currentState->EjectQuarter();
    currentState->TurnCrank();
    
    //Run GumBall machine tests
    currentState->TestGumballMachine();
    return 0;
}