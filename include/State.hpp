#include <string>
#include <iostream>
#ifndef STATE_H
#define STATE_H
#pragma once

class State {
    public:
    //State(int a_numGumballs);
    //int GetState(State* a_pCurrentState);
    //int SetState(State* a_pCurrentState, State* a_pNewState);
    virtual void InsertQuarter();
    virtual void EjectQuarter();
    virtual void TurnCrank();
    //int LoadGumballs(int a_iLoadAmount);
    virtual void Dispense();
    //virtual void GetCount();
    void TestGumballMachine();
};

class GumBallMachine
{
    public:
    GumBallMachine(int a_iNumberGumBalls);
    int count = 0;
    State soldOutState;
    State noQuarterState;
    State hasQuarterState;
    State soldState;
    State state = soldOutState;
};

class SoldState : public State
{
    void TurnCrank() override
    {
        //TODO - Code for state turncrank
    }
};

class SoldOutState : public State
{
    //SoldOutState();
    void EjectQuarter() override
    {
        //TODO - Code for eject quarter in this state
    }
};

class NoQuarterState : public State
{
    void InsertQuarter() override
    {
        std::cout << "You inserted a quarter" << std::endl;
    }
};

class HasQuarterState : public State
{
    void EjectQuarter() override
    {
        std::cout << "Quarter returned" << std::endl;
    }
};

class WinnerState : public State
{
    //TODO - Actions for this state
};

#endif