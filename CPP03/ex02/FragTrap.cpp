#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FlagTrap has beeen created using the defualt constructor " << std::endl;
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FlagTrap has beeen created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag)
{
    *this = frag;
    std::cout << "FlapTrap has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &frag)
{
    if(this != &frag)
    {
        this->Name = frag.Name;
        this->HitPoints = frag.HitPoints;
        this->EnergyPoints = frag.EnergyPoints;
        this->AttackDamage = frag.AttackDamage;
    }
    std::cout << "FragTrap has been recreated" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been Destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap HighFives " << this->Name << "  :)" << std::endl;
}
