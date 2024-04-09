#include "ITurkey.hpp"
#include "IDuck.hpp"
#include <memory>
#include <iostream>

class TurkeyAdapter : public IDuck
{
    std::shared_ptr<ITurkey> turkey = nullptr;

    public:
    explicit TurkeyAdapter(std::shared_ptr<ITurkey> newTurkey);
    void Quack() override;
    void Fly() override;
};