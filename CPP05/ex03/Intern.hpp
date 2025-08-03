/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:02:51 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/05 18:02:54 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp" 

class Intern
{
    private:
        class WrongNameException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    public :
        Intern();
        ~Intern();
        Intern(const Intern &intern);
        Intern& operator=(const Intern &intern);
        AForm* makeForm(const std::string &name, const std::string &target);
};