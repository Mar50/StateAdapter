#include "State.hpp"

// #define SOLD_OUT = m_iSOLD_OUT;
// #define NO_QUARTER = m_iNO_QUARTER;
// #define HAS_QUARTER = m_iHAS_QUARTER;
// #define SOLD = m_iSOLD;

State::State()
{
    //LoadGumballs(a_num);
}

int State::GetState()
{
    return m_iState;
}

// int State::SetState(int a_State)
// {
//     try{
//         switch (a_State)
//         {
//             case(1):
//                 m_iState = 1;
//                 break;
//             case(2):
//                 m_iState = 2;
//                 break;
//             case(3):
//                 m_iState = 3;
//                 break;
//             break;
//         default:
//             m_iState = 0;
//             std::cout << "State cannot be set to higher than 3!" << std::endl;
//             break;
//         }
//     }catch(std::errc err)
//     {
//         std::cout << "Error:" << &err << std::endl;
//     }
//     return 0;
// }

int State::LoadGumballs(int a_iLoadAmount)
{
    m_iCount = a_iLoadAmount;
    return 0;
}

int State::InsertQuarter()
{
    if(m_iState==m_iHAS_QUARTER)
        std::cout << "You can't insert another quarter!" << std::endl;
    else if(m_iState==m_iNO_QUARTER)
    {
        m_iState = m_iHAS_QUARTER;
        std::cout << "You inserted a quarter" << std::endl;
    }
    else if(m_iState==m_iSOLD_OUT)
    {
        std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
    }
    else if(m_iState==m_iSOLD)
    {
        std::cout << "Please wait, we're already giving you a gumball" << std::endl;
    }
    return 0;
}

int State::EjectQuarter()
{
    if(m_iState==m_iHAS_QUARTER)
    {
        m_iState = m_iNO_QUARTER;
        std::cout << "Quarter returned" << std::endl;
    }
    else if(m_iState==m_iNO_QUARTER)
    {
        std::cout << "You haven't inserted a quarter" << std::endl;
    }
    else if(m_iState==m_iSOLD)
    {
        std::cout << "Sorry, you already turned the crank" << std::endl;
    }
    else if(m_iState==m_iSOLD_OUT)
    {
        std::cout << "You can;t eject, you haven;t inserted a quarter yet" << std::endl;
    }
    return 0;
}

int State::TurnCrank()
{
    if(m_iState==m_iSOLD)
        std::cout << "Turning twice doesn't get you another gumball!" << std::endl;
    else if(m_iState==m_iNO_QUARTER)
    {
        std::cout << "You turned but there's no quarter" << std::endl;
    }
    else if(m_iState==m_iSOLD_OUT)
    {
        std::cout << "You turned but there's no gumballs" << std::endl;
    }
    else if(m_iState==m_iHAS_QUARTER)
    {
        m_iState = m_iSOLD;
        std::cout << "You turned..." << std::endl;
    }
    return 0;
}

int State::Dispense()
{
    if(m_iState==m_iSOLD)
    {
        std::cout << "A gumball comes rolling out fo the slot" << std::endl;
        m_iCount--;
            if(m_iCount==0)
            {
                std::cout << "Oops, out of gumballs!" << std::endl;
                m_iState = m_iSOLD_OUT;
            }
            else
                m_iState = m_iNO_QUARTER;
    }
    else if(m_iState==m_iNO_QUARTER)
    {
        std::cout << "You need to pay first" << std::endl;
    }
    else if(m_iState==m_iSOLD_OUT)
    {
        std::cout << "No gumball dispensed" << std::endl;
    }
    else if(m_iState==m_iHAS_QUARTER)
    {
        std::cout << "No gumball dispensed" << std::endl;
    }
    return 0;
}

State::~State()
{

}