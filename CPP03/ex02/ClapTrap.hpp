#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

//do orthodox
class ClapTrap
{
    protected:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &clap);
        ClapTrap& operator=(const ClapTrap &clap);
        virtual ~ClapTrap();
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif