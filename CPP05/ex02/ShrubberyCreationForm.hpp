#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &sc);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &sc);
        void execute(const Bureaucrat &bure) const;
};
