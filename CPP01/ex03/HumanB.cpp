#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
}
void HumanB::setWeapon(Weapon& p)
{
    this->p = &p;
}

void HumanB::attack()
{
    if (p)
       std::cout << name << " attacks with their " << p->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}

