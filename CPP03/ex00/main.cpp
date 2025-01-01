#include "ClapTrap.hpp"

//claenup the messages and like the setters and getters if you want and like do the main peroperly kkk
//chcekk if all the fucntions work ....kkk
int main() 
{
    ClapTrap clappy("Clappy");
    std::cout << "Clappy is ready to fight!" << std::endl;
    std::cout << "\nClappy attacks Target1!" << std::endl;
    clappy.attack("Target1");
    std::cout << "\nClappy takes damage of 5 points!" << std::endl;
    clappy.takeDamage(5);
    std::cout << "\nClappy repairs itself by 3 points!" << std::endl;
    clappy.beRepaired(3);
    for (int i = 0; i < 10; i++) 
    {
        std::cout << "\nClappy attacks Target2!" << std::endl;
        clappy.attack("Target2");
    }
    std::cout << "\nClappy tries to repair itself with no energy!" << std::endl;
    clappy.beRepaired(5);
    return 0;
}