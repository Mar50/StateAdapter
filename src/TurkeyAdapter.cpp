#include "ITurkey.hpp"
#include <memory>
#include <iostream>

void ITurkey::Fly()
{
    for(int i = 0;i < 5;++i)
    {
        m_turkey->Fly();
    }
}

void ITurkey::Gobble()
{

}