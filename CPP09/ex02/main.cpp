#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac > 1)
    {
        PmergeMe sc(ac, av);
        sc.sort();
    } 
    else
    {
        std::cout << "Error: too few arguments " << std::endl;
        return 0;
    }
}
