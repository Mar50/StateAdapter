#include <stdio.h>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    auto gumBallMachine = std::make_shared<GumBallMachine>(5);
    return 0;
}