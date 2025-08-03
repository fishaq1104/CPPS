#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        BitcoinExchange  sc(av[1]);
        sc.calculate();
    }
    else
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
}
