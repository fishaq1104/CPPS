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
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}