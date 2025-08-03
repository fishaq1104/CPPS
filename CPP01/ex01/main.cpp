#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name);

int main()
{
    int n = 3;
    Zombie* zombie = ZombieHorde(n, "Fathima");
    for(int i = 0; i < n; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}