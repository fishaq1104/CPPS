#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        RPN s(av[1]);
        s.calculate();
    }
    else
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 0;
    }
}
