#include <stdio.h>
#include "State.hpp"
#include <iostream>

int main (int argc, char** argv) 
{
    auto gumBallMachine = std::make_shared<GumBallMachine>(5);

    gumBallMachine->GetMachineState();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    
    gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->EjectQuarter();
    gumBallMachine->TurnCrank();
gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->EjectQuarter();
    gumBallMachine->TurnCrank();

    gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->EjectQuarter();

    gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();

    gumBallMachine->GetMachineState();
    gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->EjectQuarter();

    gumBallMachine->GetMachineState();

    gumBallMachine->InsertQuarter();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();
    gumBallMachine->InsertQuarter();
    gumBallMachine->TurnCrank();

    gumBallMachine->GetMachineState();

    return 0;
}