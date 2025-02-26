#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bru("Bureaucrat" , 5);
        bru.increment();
        bru.decrement();
        std::cout << "Name : "<< bru.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}