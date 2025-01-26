#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bee("la" , 157);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}