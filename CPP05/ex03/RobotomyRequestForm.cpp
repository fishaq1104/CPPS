/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:55:53 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/06 14:12:25 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :AForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
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

void RobotomyRequestForm::execute(const Bureaucrat &bure) const
{
    std::srand(std::time(0));
    if(bure.getGrade() > 45)
    throw RobotomyRequestForm::GradeTooLowException();
    if(!this->getSign())
        throw RobotomyRequestForm::NonSignException();
    std::cout << "Drilling Sounds ....." << std::endl;
    if(std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "the robotomy failed :( " << std::endl;
}
