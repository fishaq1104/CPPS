/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:53:35 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/06 13:53:44 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :_name("name"), _sign(0),_gradeSign(0), _gradeExcute(0){
}

Form::~Form()
{
    std::cout << "The Form has been destroyed" << std::endl;
}

Form::Form(const std::string &name, const int gradeSign, const int gradeExcute): 
                _name(name), _sign(false), _gradeSign(gradeSign), _gradeExcute(gradeExcute) 
{
    if(gradeSign > 150 || gradeExcute > 150)
        throw Form::GradeTooLowException();
    else if(gradeSign < 1 || gradeExcute < 1)
        throw Form::GradeTooHighException();
    std::cout << "The Form has been created" << std::endl;
}

Form::Form(const Form &form): _name(form._name), _sign(form._sign), _gradeSign(form._gradeSign), 
            _gradeExcute(form._gradeExcute){
}

Form& Form::operator=(const Form &form)
{
    if (this != &form)
        this->_sign = form._sign;
    return *this;
}

const std::string Form::getName() const
{
    return this->_name;
}

int Form::getGradeSign() const
{
    return this->_gradeSign;
}

int Form::getGradeExcute() const
{
    return this->_gradeExcute;
}

bool Form::getSign() const
{
    return this->_sign;
}

void Form::beSigned(const Bureaucrat& bure)
{
    if(getSign())
    {
        std::cout<< "the form is already signed" << std::endl;
        return ;
    }
    if(bure.getGrade() <= this->_gradeSign)
    {
        this->_sign = true;
        std::cout << "The form has been signed for "  << bure.getName() << std::endl;
    }
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os,const Form &form)
{    
    os << form.getName() << ", Form can be signed by grade " << form.getGradeSign() << " and executed by grade " << form.getGradeExcute() << ".";
    return os;
}

const char *Form::GradeTooHighException:: what() const throw()
{
    return "Form: The grade is High";
}

const char *Form::GradeTooLowException:: what() const throw()
{
    return "Form: The grade is Low";
}
