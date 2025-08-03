#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
    Zombie* zombie = new Zombie[N];

    for(int i = 0; i < N; i++)
    {
        zombie[i].setName(name);
    }
    return zombie;
}