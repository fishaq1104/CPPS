/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:56:23 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/07 18:59:38 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat  Robin("Robin", 150);  
        Bureaucrat  bob("Bob", 50); 
        Bureaucrat  alice("Alice", 1);

        std::cout << Robin << bob  << alice;
        std::cout << "--------------------------------------------------" << std::endl;

        ShrubberyCreationForm   shrub("Home");
        RobotomyRequestForm     robo("Bender");
        PresidentialPardonForm  pardon("Marvin");

        std::cout << shrub  << '\n' << robo   << '\n' << pardon <<  std::endl;
        std::cout << "--------------------------------------------------" << std::endl;

        try 
        {
            Robin.signForm(shrub);
        }
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "--------------------------------------------------" << std::endl;

        bob.signForm(shrub);
        
        try 
        {
            bob.executeForm(shrub); 
        } catch (const std::exception& e) 
        {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "--------------------------------------------------" << std::endl;
        alice.signForm(robo);
        alice.signForm(pardon);

        alice.executeForm(shrub);
        alice.executeForm(robo);
        alice.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << std::endl;
    }
    return 0;
}