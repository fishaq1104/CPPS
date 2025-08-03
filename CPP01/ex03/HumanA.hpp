#ifndef HUMAN_A
#define HUMAN_A

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        Weapon& p;
        std::string name;
    public:
    HumanA(std::string name, Weapon& p);
    ~HumanA();
    void attack();
};

#endif