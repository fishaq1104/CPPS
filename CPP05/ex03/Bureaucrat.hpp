/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:02:41 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/05 18:02:43 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
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
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &bure);
        Bureaucrat& operator=(const Bureaucrat &bure);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bure);
