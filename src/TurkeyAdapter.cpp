#include "TurkeyAdapter.hpp"

TurkeyAdapter::TurkeyAdapter(std::shared_ptr<ITurkey> newTurkey)
{

}

void TurkeyAdapter::Quack(std::shared_ptr<ITurkey> newTurkey)
{
    //TODO - Override for IDuck interface
}

void TurkeyAdapter::Fly(std::shared_ptr<ITurkey> newTurkey)
{
    //TODO - Override for IDuck interface
    for(int i = 0;i < 5;++i)
    {
        newTurkey->Fly();
    }
}

// void ITurkey::Fly(std::shared_ptr<ITurkey> newTurkey)
// {
//     for(int i = 0;i < 5;++i)
//     {
//         newTurkey->Fly();
//     }
// }

// void ITurkey::Gobble()
// {

// }