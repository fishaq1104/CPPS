/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:54:44 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/06 14:24:37 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
}
        
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("Presidential Pardon Form", 25 , 5), _target(target){  
}

PresidentialPardonForm::~PresidentialPardonForm(){
}
        
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &sc) :AForm(sc) , _target(sc._target){

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
    if(bure.getGrade() > getGradeExcute())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}