#ifndef HUMAN_B
#define HUMAN_B


#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *p;
        std::string name;
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon& p);
};

#endif