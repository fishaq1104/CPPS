#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bru2("Bureaucrat" , 122);
        bru2.increment();
        bru2.decrement();
        std::cout << bru2;
        std::cout << "Grade : "<< bru2.getGrade() << std::endl;
        Bureaucrat bru("Bureaucrat" , 1);
        bru.increment();
        bru.decrement();
        std::cout << "Grade : "<< bru.getGrade() << std::endl;
        Bureaucrat bru1("Bureaucrat" , 150);
        bru1.decrement();
        bru1.increment();
        std::cout << "Grade : "<< bru1.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}