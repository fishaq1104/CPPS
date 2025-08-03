#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& p) : p(p), name(name)
{
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << p.getType() << std::endl;
}