#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :AForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const int gradeSign, const int gradeExcute, const std::string &target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &sc):AForm(sc), _target(sc._target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &sc)
{
    if(this != &sc)
        this->_target = sc._target;
    return *this;
}

void RobotomyRequestForm::excute(const Bureaucrat &bure) const
{
    if(this->getGradeSign() > 72 || this->getGradeExcute() > 45)
        throw RobotomyRequestForm::GradeTooLowException();
    if(this->getGradeSign() < 72 || this->getGradeExcute() < 45)
        throw RobotomyRequestForm::GradeTooHighException();

}