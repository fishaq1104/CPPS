#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    this->guard = false;
    std::cout << "ScapTrap Default Constructor called : "<< Name << std::endl;
}

ScavTrap::ScavTrap(std::string Name): ClapTrap(Name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    this->guard = false;
    std::cout << "ScapTrap has been Created for : "<< Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &sca)
{
    *this = sca;
    std::cout << "ScapTrap has been ReCreated" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav)
{
    if (this != &scav)
    {
        this->Name = scav.Name;
        this->HitPoints = scav.HitPoints;
        this->EnergyPoints = scav.EnergyPoints;
        this->EnergyPoints = scav.EnergyPoints;
        this->AttackDamage = scav.AttackDamage;
        this->guard = scav.guard;
    }
    std::cout << "ScapTrap has been Assigned" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScapTrap has been Destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
if(EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ScavTrap "<< this->Name << " attacks " << target << " causing "<< this->AttackDamage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ScavTrap Can't Attack  No Energy Points Left or Health point left :( " << std::endl; 
}
void ScavTrap::guardGate()
{
    if(!this->guard)
    {
        std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
        this->guard = true;
    }
    else
    {
        std::cout<< "ScavTrap is now not in Gatekeeper mode" << std::endl;
        this->guard = false;
    }
}
