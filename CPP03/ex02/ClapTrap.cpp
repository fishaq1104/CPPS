#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :Name(""), 
            HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor Has Been Created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :Name(name), 
            HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Has Been Created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) :Name(clap.Name), 
            HitPoints(clap.HitPoints), EnergyPoints(clap.EnergyPoints), 
            AttackDamage(clap.AttackDamage)
{
    std::cout << "ClapTrap Has Been Succesfull Copied :)" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
{
    if (this != &clap) 
    {
        this->Name = clap.Name;
        this->EnergyPoints = clap.EnergyPoints;
        this->HitPoints = clap.HitPoints;
        this->AttackDamage = clap.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Has Been Destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(EnergyPoints > 0 && this->HitPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap "<< this->Name << " attacks " << target << " causing "<< this->AttackDamage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ClapTrap: Can't Attack  No Energy Points Left or Health point left :( " << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->HitPoints > 0)
    {
        std::cout << "ClapTrap is taking Damage " << std::endl; 
        if(HitPoints - amount >= 0)
            this->HitPoints -= amount;
        else
        {
            this->HitPoints = 0;   
            std::cout << "Can't Take Damage ClapTrap has dead :( " << std::endl; 
        }
    }
    else
        std::cout << "ClapTrap: Can't Take Damage Aleardy Died " << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->EnergyPoints > 0 && (HitPoints + amount <= 10))
    {
        this->HitPoints += amount;
        this->EnergyPoints--;
        std::cout << "ClapTrap"  << this->Name << "has been successfully repaired "<< std::endl; 
    }
    else if(HitPoints == 10)
        std::cout << "ClapTrap is already full health" << std::endl;
    else
        std::cout << "Can't be Repaied No Engery Points Left :( " << std::endl; 
}
