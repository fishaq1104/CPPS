#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie* Zombie1 = newZombie("Zombie1");
    Zombie1->announce();
    randomChump("Zombie2");
    delete Zombie1;
    return 0;
}
