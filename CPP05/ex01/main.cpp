#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Bure1", 3);
        b1.increment();
        b1.decrement();
        Form f1("f1", 4, 23);
        f1.beSigned(b1);
        b1.signForm(f1);
        std::cout << "--------------------------------------------------\n";
        Bureaucrat b2("Bure2", 45);
        b2.increment();
        b2.decrement();
        Form f2("f2", 100, 145);
        f2.beSigned(b2);
        b2.signForm(f2);
        std::cout << "--------------------------------------------------\n";
        Bureaucrat b3("Bure3", 65);
        b3.increment();
        b3.decrement();
        Form f3("f3", 67, 155);
        f3.beSigned(b3);
        b3.signForm(f3);  
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}