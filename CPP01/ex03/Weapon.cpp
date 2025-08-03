#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string name)
{
    this->type = name;
}

std::string Weapon::getType()const
{
    return this->type;
}