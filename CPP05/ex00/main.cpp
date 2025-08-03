/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:53:19 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/07 19:40:40 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // try
    // {
        Bureaucrat bru("Bureaucrat" , 3);
        bru.increment();
        bru.decrement();
        std::cout << "Grade : "<< bru.getGrade() << std::endl;
        std::cout << "___________________________________________" << std::endl;
        Bureaucrat bru1("Bureaucrat" , 122);
        bru1.decrement();
        bru1.increment();
        std::cout << "Grade : "<< bru1.getGrade() << std::endl;
        std::cout << "___________________________________________" << std::endl;
        Bureaucrat bru2("Bureaucrat" , 150);
        bru2.decrement();
        bru2.increment();
        std::cout << bru2;
        std::cout << "Grade : "<< bru2.getGrade() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}