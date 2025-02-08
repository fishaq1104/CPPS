#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &sc);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &sc);
        void excute(const Bureaucrat &bure) const;
};
