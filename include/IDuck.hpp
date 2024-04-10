#include <iostream>

class IDuck
{
    public:
    virtual ~IDuck() = default;
    virtual void Quack() = 0;
    virtual void Fly() = 0;
};