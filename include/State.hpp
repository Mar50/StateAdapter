#include <string>
#include <memory>
#include <iostream>
#ifndef STATE_H
#define STATE_H
#pragma once

class State 
{
    public:
    virtual void InsertQuarter() = 0;
    virtual void EjectQuarter() = 0;
    virtual void TurnCrank() = 0;
    virtual void Dispense() = 0;
};

class GumBallMachine
{
    public:
    explicit GumBallMachine(const int a_numGumBalls);
    void GetMachineState();
    void SetState(const std::weak_ptr<State> a_state);
    void ReleaseBall();
    void InsertQuarter();
    void EjectQuarter();
    void TurnCrank();
    
    int count = 0;

    std::shared_ptr<State> soldState;
    std::shared_ptr<State> soldOutState;
    std::shared_ptr<State> noQuarterState;
    std::shared_ptr<State> hasQuarterState;
    std::shared_ptr<State> winnerState;

    std::shared_ptr<State> currentState;
};

class SoldState : public State
{
    std::shared_ptr<GumBallMachine> m_gumBallMachine;

    public:
    explicit SoldState(std::weak_ptr<GumBallMachine> a_gumBallMachine);
    void InsertQuarter() override;
    void EjectQuarter() override;
    void TurnCrank() override;
    void Dispense() override;
};

class SoldOutState : public State
{
    std::shared_ptr<GumBallMachine> m_gumBallMachine;

    public:
    explicit SoldOutState(std::weak_ptr<GumBallMachine> a_gumBallMachine);
    void InsertQuarter() override;
    void EjectQuarter() override;
    void TurnCrank() override;
    void Dispense() override;
};

class NoQuarterState : public State
{
    std::shared_ptr<GumBallMachine> m_gumBallMachine;

    public:
    explicit NoQuarterState(std::weak_ptr<GumBallMachine> a_gumBallMachine);
    void InsertQuarter() override;
    void EjectQuarter() override;
    void TurnCrank() override;
    void Dispense() override;
};

class HasQuarterState : public State
{
    std::shared_ptr<GumBallMachine> m_gumBallMachine;

    public:
    explicit HasQuarterState(std::weak_ptr<GumBallMachine> a_gumBallMachine);
    void InsertQuarter() override;
    void EjectQuarter() override;
    void TurnCrank() override;
    void Dispense() override;
};

class WinnerState : public State
{
    std::shared_ptr<GumBallMachine> m_gumBallMachine;

    public:
    explicit WinnerState(std::weak_ptr<GumBallMachine> a_gumBallMachine);
    void InsertQuarter() override;
    void EjectQuarter() override;
    void TurnCrank() override;
    void Dispense() override;
};
#endif