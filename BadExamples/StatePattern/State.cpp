#include "State.hpp"

State::State(int a_num)
{
    LoadGumballs(a_num);
}

int State::TestGumballMachine()
{
    GetMachineState();
    InsertQuarter();
    TurnCrank();
    
    GetMachineState();

    InsertQuarter();
    EjectQuarter();
    TurnCrank();

    GetMachineState();

    InsertQuarter();
    TurnCrank();
    InsertQuarter();
    TurnCrank();
    EjectQuarter();

    GetMachineState();

    InsertQuarter();
    InsertQuarter();
    TurnCrank();
    InsertQuarter();
    TurnCrank();
    InsertQuarter();
    TurnCrank();

    GetMachineState();
    return 0;
}

void State::GetMachineState()
{
    std::cout << "\nMighty Gumball, Inc." << std::endl;
    std::cout << "Inventory: " << m_iCount << " gumballs" << std::endl;
    std::cout << "Machine is wating for quarter\n" << std::endl;
}

int State::GetCount()
{
    std::cout << "Inventory: " << m_iCount << std::endl;
    return 0;
}

int State::LoadGumballs(int a_iLoadAmount)
{
    m_iCount = a_iLoadAmount;
    m_pCurrentState = m_pNoQuarterState;
    return 0;
}

int State::InsertQuarter()
{
    if(m_pCurrentState->m_pHasQuarterState)
        std::cout << "You can't insert another quarter!" << std::endl;
    else if(m_pCurrentState==m_pNoQuarterState)
    {
        m_pCurrentState = m_iHAS_QUARTER;
        std::cout << "You inserted a quarter" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldOutState)
    {
        std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldState)
    {
        std::cout << "Please wait, we're already giving you a gumball" << std::endl;
    }
    return 0;
}

int State::EjectQuarter()
{
    if(m_pCurrentState->m_pHasQuarterState)
    {
        m_pCurrentState = m_pNoQuarterState;
        std::cout << "Quarter returned" << std::endl;
    }
    else if(m_pCurrentState==m_pNoQuarterState)
    {
        std::cout << "You haven't inserted a quarter" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldState)
    {
        std::cout << "Sorry, you already turned the crank" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldOutState)
    {
        std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
    }
    return 0;
}

int State::TurnCrank()
{
    if(m_pCurrentState==m_pSoldState)
        std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
    else if(m_pCurrentState==m_pNoQuarterState)
    {
        std::cout << "You turned but there's no quarter" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldOutState)
    {
        std::cout << "You turned but there's no gumballs" << std::endl;
    }
    else if(m_pCurrentState->m_pHasQuarterState)
    {
        m_pCurrentState = m_pSoldState;
        std::cout << "You turned..." << std::endl;
        Dispense();
    }
    return 0;
}

int State::Dispense()
{
    if(m_pCurrentState==m_pSoldState)
    {
        std::cout << "A gumball comes rolling out of the slot" << std::endl;
        m_iCount--;
            if(m_iCount==0)
            {
                std::cout << "Oops, out of gumballs!" << std::endl;
                m_pCurrentState = m_pSoldOutState;
            }
            else
                m_pCurrentState = m_pNoQuarterState;
    }
    else if(m_pCurrentState==m_pNoQuarterState)
    {
        std::cout << "You need to pay first" << std::endl;
    }
    else if(m_pCurrentState==m_pSoldOutState)
    {
        std::cout << "No gumball dispensed" << std::endl;
    }
    else if(m_pCurrentState->m_pHasQuarterState)
    {
        std::cout << "No gumball dispensed" << std::endl;
    }
    return 0;
}

State::~State()
{

}