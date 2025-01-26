#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{

}
        
PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const int gradeSign, const int gradeExcute, const std::string &target)
:AForm(name, gradeSign, gradeExcute), _target(target)
{
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
        
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &sc) :AForm(sc){

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &sc)                                                                           
{
    if(this != &sc)
        this->_target = sc._target;
    return *this;
}

void PresidentialPardonForm::excute(const Bureaucrat &bure) const
{
    if(this->getGradeSign() > 25 ||  this->getGradeExcute() > 5)
        throw PresidentialPardonForm::GradeTooLowException();
    if(this->getGradeSign() < 25 ||  this->getGradeExcute() < 5)
        throw PresidentialPardonForm::GradeTooHighException();
    std::cout << "Informs that "<< this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}