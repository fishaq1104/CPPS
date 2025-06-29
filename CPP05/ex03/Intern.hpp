#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" 

class Intern
{
    private:
        class WrongNameException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    public :
        Intern();
        ~Intern();
        Intern(const Intern &intern);
        Intern& operator=(const Intern &intern);
        AForm* makeForm(const std::string &name, const std::string &target);
};