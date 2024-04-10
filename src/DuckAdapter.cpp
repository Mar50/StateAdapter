#include "DuckAdapter.hpp"

DuckAdapter::DuckAdapter(std::shared_ptr<IDuck> newDuck)
{
    
}

void IDuck::Fly()
{
    std::cout << "I'm flying" << std::endl;
}

void IDuck::Quack()
{
    std::cout << "Quack!" << std::endl;
}