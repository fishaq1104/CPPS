#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat  intern("Intern", 150);  
        Bureaucrat  bob("Bob", 50); 
        Bureaucrat  alice("Alice", 1);

        std::cout << intern << bob  << alice;
        std::cout << "--------------------------------------------------\n";

        ShrubberyCreationForm   shrub("Home");
        RobotomyRequestForm     robo("Bender");
        PresidentialPardonForm  pardon("Marvin");

        std::cout << shrub  << '\n'
                  << robo   << '\n'
                  << pardon << '\n';
        std::cout << "--------------------------------------------------\n";

        try {
            intern.signForm(shrub);
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        std::cout << "--------------------------------------------------\n";

        bob.signForm(shrub);
        try {
            bob.executeForm(shrub); 
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        std::cout << "--------------------------------------------------\n";
        alice.signForm(robo);
        alice.signForm(pardon);

        alice.executeForm(shrub);
        alice.executeForm(robo);
        alice.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << '\n';
    }
    return 0;
}