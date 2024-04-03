#include <string>
#include <iostream>
#ifndef STATE_H
#define STATE_H
#pragma once

class State {
    public:
    State(int a_num);
    void GetMachineState();
    int GetCount();
    int LoadGumballs(int a_num);
    int TestGumballMachine();
    int InsertQuarter();
    int EjectQuarter();
    int TurnCrank();
    int Dispense();
    ~State();

    private:
    int m_pCurrentState = m_pSoldOutState;
    int m_iCount = 0;
    
    const static int m_pSoldOutState = 0;
    const static int m_pNoQuarterState = 1;
    const static int m_iHAS_QUARTER = 2;
    const static int m_pSoldState = 3;
};
#endif