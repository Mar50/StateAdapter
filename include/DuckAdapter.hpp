#include "IDuck.hpp"
#include "ITurkey.hpp"
#include <memory>
#include <iostream>


class DuckAdapter : public ITurkey
{
    std::shared_ptr<IDuck> m_duck = nullptr;

    public:
    explicit DuckAdapter(std::shared_ptr<IDuck> newDuck);
    void Gobble() override;
    void Fly() override;
};