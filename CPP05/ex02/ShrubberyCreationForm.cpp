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
        subtree << "               *\n";
        subtree << "              /#\\\n";
        subtree << "             /###\\\n";
        subtree << "            /#####\\\n";
        subtree << "           /#######\\\n";
        subtree << "          /#########\\\n";
        subtree << "         /###########\\\n";
        subtree << "        /#############\\\n";
        subtree << "       /###############\\\n";
        subtree << "      /#################\\\n";
        subtree << "     /###################\\\n";
        subtree << "    /#####################\\\n";
        subtree << "   /#######################\\\n";
        subtree << "      |||||||||||||||||\n";
        subtree << "      |||||||||||||||||\n";
        subtree << "      |||||||||||||||||\n";
    }
    else
        std::cout<<"the file was not being able to open :(" << std::endl;
}