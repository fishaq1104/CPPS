/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:55:03 by fishaq            #+#    #+#             */
/*   Updated: 2025/07/05 18:37:33 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :AForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:AForm("Shrubbery Creation Form", 145, 137), _target(target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sc) :AForm(sc), _target(sc._target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sc)
{
    if(this != &sc)
        this->_target = sc._target;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bure) const
{
    if(bure.getGrade() > 137)
        throw ShrubberyCreationForm::GradeTooLowException();
    if(!this->getSign())
        throw ShrubberyCreationForm::NonSignException(); 
    std::ofstream subtree((this->_target + "_shrubbery").c_str());
    if(subtree.is_open())
    {
        subtree << "                                  # #### ####\n";
        subtree << "                                ### \\\\/#|### |/####\n";
        subtree << "                               ##\\/#/ \\||/##/_/##/_#\n";
        subtree << "                             ###  \\/###|/ \\/ # ###\n";
        subtree << "                           ##_\\_#\\_\\## | #/###_/_####\n";
        subtree << "                          ## #### # \\\\ #| /  #### ##/##\n";
        subtree << "                           __#_--###`  |{,###---###-~\n";
        subtree << "                                     \\\\ }{\n";
        subtree << "                                      }}{\n";
        subtree << "                                      }}{\n";
        subtree << "                                      {{}}\n";
    }
    else
        std::cout<<"The file could not be opened :(" << std::endl;
}