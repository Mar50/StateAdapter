#include "ITurkey.hpp"
#include "IDuck.hpp"
#include <memory>
#include <iostream>

class TurkeyAdapter : public IDuck
{
    std::shared_ptr<ITurkey> turkey = nullptr;
    public:
    explicit TurkeyAdapter(std::shared_ptr<ITurkey> newTurkey);
    void Quack(std::shared_ptr<ITurkey> newTurkey) override;
    void Fly(std::shared_ptr<ITurkey> newTurkey) override;
};