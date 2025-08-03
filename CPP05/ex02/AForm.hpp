/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:00:41 by fishaq            #+#    #+#             */
/*   Updated: 2025/08/03 15:59:36 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExcute;
    protected:
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
        class NonSignException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
    public:
        AForm();
        virtual ~AForm();
        AForm(const std::string &name, const int gradeSign, const int gradeExcute);
        AForm(const AForm &form);
        AForm& operator=(const AForm &form);
        const std::string getName()const ;
        int getGradeSign() const ;
        int getGradeExcute() const ;
        bool getSign() const ;
        void beSigned(const Bureaucrat &bure);
        virtual void execute(const Bureaucrat &bure)const = 0;
};

std::ostream &operator<<(std::ostream &os,const AForm &form);
