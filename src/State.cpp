#include "State.hpp"

GumBallMachine::GumBallMachine(const int a_numGumballs)
{
    this->soldState = std::make_shared<SoldState>(this);
    this->soldOutState = std::make_shared<SoldOutState>(this);
    this->noQuarterState = std::make_shared<NoQuarterState>(this);
    this->hasQuarterState = std::make_shared<HasQuarterState>(this);
    this->winnerState = std::make_shared<WinnerState>(this);

    count = a_numGumballs;

    if(a_numGumballs > 0)
    {
        this->currentState = hasQuarterState;
    }
}

SoldState::SoldState(const std::weak_ptr<GumBallMachine> a_gumBallMachine){ m_gumBallMachine = a_gumBallMachine.lock(); }
SoldOutState::SoldOutState(const std::weak_ptr<GumBallMachine> a_gumBallMachine){ m_gumBallMachine = a_gumBallMachine.lock(); }
NoQuarterState::NoQuarterState(const std::weak_ptr<GumBallMachine> a_gumBallMachine){ m_gumBallMachine = a_gumBallMachine.lock(); }
HasQuarterState::HasQuarterState(const std::weak_ptr<GumBallMachine> a_gumBallMachine){ m_gumBallMachine = a_gumBallMachine.lock(); }
WinnerState::WinnerState(const std::weak_ptr<GumBallMachine> a_gumBallMachine){ m_gumBallMachine = a_gumBallMachine.lock(); }

void GumBallMachine::SetState(const std::weak_ptr<State> a_state)
{
    this->currentState = a_state.lock();
}

void GumBallMachine::ReleaseBall()
{
    std::cout << "A gumball comes rolling out of the slot..." << std::endl;
    if(this->count != 0)
        this->count--;
}

void GumBallMachine::GetMachineState()
{
    std::cout << "\nMighty Gumball, Inc." << std::endl;
    std::cout << "Inventory: " << this->count << " gumballs" << std::endl;
    std::cout << "Machine is wating for quarter" << std::endl;
}

void GumBallMachine::InsertQuarter()
{
    this->currentState->InsertQuarter();
}

void GumBallMachine::EjectQuarter()
{
    this->currentState->EjectQuarter();
}

void GumBallMachine::TurnCrank()
{
    this->currentState->TurnCrank();
    this->currentState->Dispense();
}

void NoQuarterState::InsertQuarter()
{
    std::cout << "You inserted a quarter." << std::endl;
    this->m_gumBallMachine->hasQuarterState;
}

void NoQuarterState::EjectQuarter()
{
    std::cout << "You haven't inserted a quarter!" << std::endl;
}

void NoQuarterState::TurnCrank()
{
    std::cout << "You turned, but there's no quarter." << std::endl;
}

void NoQuarterState::Dispense()
{
    std::cout << "You need to pay first." << std::endl;
}

void SoldState::InsertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball." << std::endl;
}

void SoldState::EjectQuarter()
{
    std::cout << "Sorry, you've already turned the crank." << std::endl;
}

void SoldState::TurnCrank()
{
    std::cout << "Sorry, you've already turned the crank." << std::endl;
}

void SoldState::Dispense()
{
    std::cout << "A gumball comes rolling out of the slot..." << std::endl;
    if(this->m_gumBallMachine->count > 1)
    {
        this->m_gumBallMachine->SetState(m_gumBallMachine->noQuarterState);
    }
    else
    {
        std::cout << "Oops, out of gumballs" << std::endl;
        this->m_gumBallMachine->SetState(m_gumBallMachine->soldOutState);
    }
}

void HasQuarterState::InsertQuarter()
{
    std::cout << "You can't insert another quarter." << std::endl;
}

void HasQuarterState::EjectQuarter()
{
    std::cout <<"Quarter returned" << std::endl;
    this->m_gumBallMachine->SetState(this->m_gumBallMachine->noQuarterState);
}

void HasQuarterState::TurnCrank()
{
    auto randomNumber = []() {return (std::rand()/RAND_MAX)*10;};
    std::cout << "you turned..." << std::endl;
    if(randomNumber() and this->m_gumBallMachine->count > 1)
        this->m_gumBallMachine->SetState(m_gumBallMachine->winnerState);
    else
        this->m_gumBallMachine->SetState(m_gumBallMachine->soldState);
}

void HasQuarterState::Dispense()
{
    std::cout << "No gumball dispensed." << std::endl;
}

void SoldOutState::InsertQuarter()
{
    std::cout << "Please wait, we are already giving you a gumball." << std::endl;
}

void SoldOutState::EjectQuarter()
{
    std::cout << "Sorry, you already turned the crank." << std::endl;
}

void SoldOutState::TurnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball." << std::endl;
}

void SoldOutState::Dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

void WinnerState::InsertQuarter()
{
    std::cout << "Please wait we are already giving you a gumball." << std::endl;
}

void WinnerState::EjectQuarter()
{
    std::cout << "Sorry you already turned the crank." << std::endl;
}

void WinnerState::TurnCrank()
{
    std::cout << "Turning twice doesnt get you another gumball." << std::endl;
}

void WinnerState::Dispense()
{
    //Win 2 gumballs
    std::cout << "YOU ARE A WINNER! You get 2 gumballs." << std::endl;
    this->m_gumBallMachine->ReleaseBall();
    if(this->m_gumBallMachine->count == 0)
    {
        this->m_gumBallMachine->SetState(m_gumBallMachine->soldOutState);
    }
    else //Win 1 Gumball
    {
        this->m_gumBallMachine->ReleaseBall();
    }
    if(this->m_gumBallMachine->count > 0) //No win
    {
        this->m_gumBallMachine->SetState(m_gumBallMachine->noQuarterState);
    }
    else //Machine sold out
    {
        this->m_gumBallMachine->SetState(m_gumBallMachine->soldOutState);
    }
}