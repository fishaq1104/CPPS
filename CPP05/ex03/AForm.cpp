/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:55:12 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/06 14:12:59 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :_name("name"), _sign(0), _gradeSign(0), _gradeExcute(0){
}

AForm::~AForm(){
    std::cout << "The AForm has been destroyed" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeSign, const int gradeExcute): 
                _name(name),  _sign(false), _gradeSign(gradeSign), _gradeExcute(gradeExcute)
{
    if(gradeSign > 150 || gradeExcute > 150)
        throw AForm::GradeTooLowException();
    else if(gradeSign < 1 || gradeExcute < 1)
        throw AForm::GradeTooHighException();
    std::cout << "The AForm has been created" << std::endl;
}

AForm::AForm(const AForm &form): _name(form._name), _sign(form._sign), _gradeSign(form._gradeSign), 
 _gradeExcute(form._gradeExcute){
}

AForm& AForm::operator=(const AForm &form)
{
    if (this != &form)
        this->_sign = form._sign;
    return *this;
}

const std::string AForm::getName() const
{
    return this->_name;
}

int AForm::getGradeSign() const
{
    return this->_gradeSign;
}

int AForm::getGradeExcute() const
{
    return this->_gradeExcute;
}

bool AForm::getSign() const
{
    return this->_sign;
}

void AForm::beSigned(const Bureaucrat &bure)
{
    if(getSign())
    {
        std::cout<< "the form is already signed" << std::endl;
        return ;
    }
    if(bure.getGrade() <= this->_gradeSign)
        this->_sign = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os,const AForm &form)
{
    os << form.getName() << ", Form can be signed by grade " << form.getGradeSign() << " and executed by grade " << form.getGradeExcute() << ".";
    return os;
}

const char *AForm::GradeTooHighException:: what() const throw()
{
    return "Form: The grade is High";
}

const char *AForm::GradeTooLowException:: what() const throw()
{
    return "Form: The grade is Low";
}

const char *AForm::NonSignException::what() const throw()
{
	return "The Form is not signed yet!";
}
