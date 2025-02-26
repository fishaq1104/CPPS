#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &sc);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &sc);
        void execute(const Bureaucrat &bure) const;
};

