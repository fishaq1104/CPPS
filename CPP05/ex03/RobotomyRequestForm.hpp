#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &name, const int gradeSign, const int gradeExcute, const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &sc);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &sc);
        void excute(const Bureaucrat &bure) const;
};

