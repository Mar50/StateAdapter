#include "Adapter.hpp"

void Duck::Quack()
{
    std::cout << "Quack!" << std::endl;
}

void Duck::Fly()
{
    std::cout << "I'm flying" << std::endl;
}

void MallardDuck::Fly()
{
    std::cout << "I'm flying" << std::endl;
}   

void MallardDuck::Quack()
{
    std::cout << "Quack!" << std::endl;
}

void Turkey::Fly()
{
    std::cout << "I'm flying" << std::endl;
}

void Turkey::Gobble()
{
    std::cout << "Gobble!" << std::endl;
}

void WildTurkey::Fly()
{
    std::cout << "I'm flying a short distance" << std::endl;
}

void WildTurkey::Gobble()
{
    std::cout << "Gobble gobble!" << std::endl;
}