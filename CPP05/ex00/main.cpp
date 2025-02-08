#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bee("la" , 1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}