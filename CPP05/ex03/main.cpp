#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* shrub  = 0;
    AForm* robo   = 0;
    AForm* pardon = 0;
    AForm* bad    = 0;

    try
    {
        Bureaucrat clerk("Clerk", 143);
        Bureaucrat boss ("Boss",   1);

        shrub  = someRandomIntern.makeForm("shrubbery creation",  "Garden");
        robo   = someRandomIntern.makeForm("robotomy request",    "Bender");
        pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        bad    = someRandomIntern.makeForm("coffee request",      "Nobody");

        std::cout << "--------------------------------------------------\n";

        clerk.signForm(*shrub);
        clerk.signForm(*robo);
        clerk.signForm(*pardon);

        std::cout << "--------------------------------------------------\n";

        boss.signForm(*shrub);
        boss.signForm(*robo);
        boss.signForm(*pardon);

        std::cout << "--------------------------------------------------\n";

        boss.executeForm(*shrub);
        boss.executeForm(*robo);
        boss.executeForm(*pardon);

        std::cout << "--------------------------------------------------\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << '\n';
    }

    delete shrub;  
    delete robo; 
    delete pardon;
    delete bad;

    return 0;
}
