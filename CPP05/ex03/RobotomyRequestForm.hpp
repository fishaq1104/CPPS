#pragma once

#include <cstdlib>
#include <ctime>
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
        void excute(const Bureaucrat &bure) const;
};

