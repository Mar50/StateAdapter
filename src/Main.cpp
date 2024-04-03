#include <stdio.h>
#include <string>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    State* pState = new State();
    //pState->SetState(1); //Set current state to 1
    std::cout << "State of machine is: " << pState->GetState() << std::endl;
    return 0;
}