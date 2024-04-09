#include "DuckAdapter.hpp"
#include "TurkeyAdapter.hpp"
#include <memory>
#include <iostream>

class Duck
{
    public:
    virtual void Quack() = 0;
    virtual void Fly() = 0;
};

class MallardDuck : public Duck
{
    void Quack() override;
    void Fly() override;
};

class Turkey
{
    virtual void Gobble() = 0;
    virtual void Fly() = 0;
};

class WildTurkey : public Turkey
{
    void Gobble() override;
    void Fly() override;
};