#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:

    public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(const FragTrap &frag);
    FragTrap& operator=(const FragTrap &frag);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
