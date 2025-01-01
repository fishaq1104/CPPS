#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool guard;
    public:
    ScavTrap();
    ScavTrap(std::string Name);
    ~ScavTrap();
    ScavTrap(const ScavTrap &scav);
    ScavTrap& operator=(const ScavTrap &scav);
    void guardGate();
    void attack(const std::string& target);
};

#endif