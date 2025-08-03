#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        try
        {
            ScalarConverter::convert(av[1]);
        }
        catch(...)
        {
            std::cout << "Error catch" << std::endl;
        }
    }
    else
        std::cout << "The Argument is Invalid" << std::endl;
}
