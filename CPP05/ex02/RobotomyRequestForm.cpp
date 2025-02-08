#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :AForm(){
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target) :
AForm("Robotomy Request Form", 72, 45), _target(target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &sc):AForm(sc), _target(sc._target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &sc)
{
    if(this != &sc)
        this->_target = sc._target;
    return *this;
}

void RobotomyRequestForm::excute(const Bureaucrat &bure) const
{
    if(bure.getGrade() > 45)
        throw RobotomyRequestForm::GradeTooLowException();
    if(!this->getSign())
        throw RobotomyRequestForm::NonSignException(); //throw form not signed exception
    std::srand(std::time(0));
    std::cout << "Drilling Sounds ....." << std::endl;
    if(std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "the robotomy failed :( " << std::endl;
}
// i need to do this ... i think i need exception of this