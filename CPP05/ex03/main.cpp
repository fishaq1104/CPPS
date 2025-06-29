
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"                  

int main()
{
    Intern      someRandomIntern;
    Bureaucrat  clerk("Clerk", 155);
    
    Bureaucrat  boss("Boss", 1);

    AForm* shrub = 0;
    AForm* robo  = 0;
    AForm* pardon= 0;
    AForm* bad   = 0;
    
    try
    {
        shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
        robo  = someRandomIntern.makeForm("robotomy request",  "Bender");
        pardon= someRandomIntern.makeForm("presidential pardon","Marvin");
        bad   = someRandomIntern.makeForm("coffee request",    "Nobody");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << '\n';
        delete shrub;
        delete robo;
        delete pardon;
        delete bad;
        return 0;
    }
    try
    {
        std::cout << "--------------------------------------------------\n";

        clerk.signForm(*shrub);
        clerk.signForm(*robo);
        clerk.signForm(*pardon);

        std::cout << "--------------------------------------------------\n";

        boss.signForm(*shrub);
        boss.signForm(*robo);
        boss.signForm(*pardon);

        boss.executeForm(*shrub);
        boss.executeForm(*robo);
        boss.executeForm(*pardon);

        std::cout << "--------------------------------------------------\n";

        delete shrub;
        delete robo;
        delete pardon;
        delete bad;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << '\n';
        delete shrub;
        delete robo;
        delete pardon;
        delete bad;
    }
    return 0;
}