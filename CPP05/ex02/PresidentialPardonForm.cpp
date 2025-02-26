#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(){
}
        
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("Presidential Pardon Form", 145 , 137), _target(target){  
}

PresidentialPardonForm::~PresidentialPardonForm(){
}
        
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &sc) :AForm(sc){

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &sc)                                                                           
{
    if(this != &sc)
        this->_target = sc._target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &bure) const
{
    if(!this->getSign())
        throw PresidentialPardonForm::NonSignException();
    if(bure.getGrade() > 5)
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}