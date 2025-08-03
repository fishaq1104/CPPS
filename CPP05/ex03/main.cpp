/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:56:32 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/16 19:55:39 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    AForm* shrub  = 0;
    AForm* robo   = 0;
    AForm* pardon = 0;
    // AForm* bad    = 0;
    AForm* rrf    = 0;

    try
    {
        Intern someRandomIntern;
        Bureaucrat clerk("Clerk", 143);
        Bureaucrat boss ("Boss",   1);
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        shrub  = someRandomIntern.makeForm("shrubbery creation",  "Garden");
        robo   = someRandomIntern.makeForm("robotomy request",    "Bender");
        pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");
        // bad    = someRandomIntern.makeForm("coffee request",      "Nobody");

        std::cout << "--------------------------------------------------" << std::endl;

        clerk.signForm(*shrub);
        clerk.signForm(*robo);
        clerk.signForm(*pardon);

        std::cout << "--------------------------------------------------" << std::endl;

        boss.signForm(*shrub);
        boss.signForm(*robo);
        boss.signForm(*pardon);

        std::cout << "--------------------------------------------------" << std::endl;

        boss.executeForm(*shrub);
        boss.executeForm(*robo);
        boss.executeForm(*pardon);

        std::cout << "--------------------------------------------------" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Uncaught exception: " << e.what() << std::endl;
    }

    delete shrub;  
    delete robo; 
    delete pardon;
    // delete bad;
    delete rrf;

    return 0;
}
