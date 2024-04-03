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
    int m_iState = m_iSOLD_OUT;
    int m_iCount = 0;
    
    const static int m_iSOLD_OUT = 0;
    const static int m_iNO_QUARTER = 1;
    const static int m_iHAS_QUARTER = 2;
    const static int m_iSOLD = 3;
};
#endif