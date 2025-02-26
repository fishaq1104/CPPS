#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"


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
        const int getGradeSign() const ;
        const int getGradeExcute() const ;
        bool getSign() const ;
        void beSigned(const Bureaucrat &bure);
};

std::ostream &operator<<(std::ostream &os,const Form &form);
