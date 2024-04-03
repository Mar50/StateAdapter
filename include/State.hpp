#include <string>
#include <iostream>
#ifndef STATE_H
#define STATE_H
#pragma once

class State {
    public:
    State(int a_numGumballs);
    int GetState(State* a_pCurrentState);
    int SetState(State* a_pCurrentState, State* a_pNewState);
    int InsertQuarter();
    int EjectQuarter();
    int TurnCrank();
    //int LoadGumballs(int a_iLoadAmount);
    int Dispense();
    int GetCount();
    int TestGumballMachine();
    //~State();

    private:
    // const static int m_pSoldOutState = 0;
    // const static int m_pNoQuarterState = 1;
    // const static int m_iHAS_QUARTER = 2;
    // const static int m_pSoldState = 3;
};

class GumBallMachine : public State
{
    State soldOutState;
    State noQuarterState;
    State hasQuarterState;
    State soldState;
    State state = soldOutState;

    GumBallMachine(int a_iNumberGumBalls);

    int count = 0;
};

class SoldState : public State
{

};

class SoldOutState : public State
{
    SoldOutState();
};

class NoQuarterState : public State
{

};

class HasQuarterState : public State
{

};

class WinnerState : public State
{

};

#endif