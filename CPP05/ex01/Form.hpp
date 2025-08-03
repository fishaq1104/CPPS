/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:33 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/05 18:05:23 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExcute;
    class GradeTooHighException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    public:
        Form();
        ~Form();
        Form(const std::string &name, const int gradeSign, const int gradeExcute);
        Form(const Form &form);
        Form& operator=(const Form &form);
        const std::string getName()const ;
        int getGradeSign() const ;
        int getGradeExcute() const ;
        bool getSign() const ;
        void beSigned(const Bureaucrat& bure);
};

std::ostream &operator<<(std::ostream &os,const Form &form);
