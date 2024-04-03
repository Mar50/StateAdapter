#include <stdio.h>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    //Create a new GumballMachine object with 5 gumballs loaded
    State* pState = new State(5);
    
    //Run Gumball machine tests
    pState->TestGumballMachine();
    return 0;
}