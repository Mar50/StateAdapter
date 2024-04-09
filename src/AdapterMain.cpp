#include "Adapter.hpp"

int main (int argc, char** argv)
{
    void testduck (const std::shared_ptr<IDuck>& duck);

    std::shared_ptr<IDuck> duck = std::make_shared<MallardDuck>();

    std::shared_ptr<ITurkey> turkey = std::make_shared<WildTurkey>();
    std::shared_ptr<IDuck> turkeyAdapter = std::make_shared<TurkeyAdapter>(turkey);

    std::cout << "The Turkey says..." << '\n';
    turkey->Gobble();
    turkey->Fly();

    std::cout << "\nThe Duck says..." << '\n';
    testduck(duck);

    std::cout << "\nThe TurkeyAdapter says..." << '\n';
    testduck(turkeyAdapter);
    return 0;
}