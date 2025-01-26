#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &name, const int gradeSign, const int gradeExcute, const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &sc);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &sc);
};

