#include <stdio.h>
#include <string>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    State* pState = new State(5);
    std::cout << "State of machine is: " << pState->GetState() << std::endl;
    std::cout << "Amount of gumballs in machine is: " << pState->GetCount() << std::endl;
    return 0;
}