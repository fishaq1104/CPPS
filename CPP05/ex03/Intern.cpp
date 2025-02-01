#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &intern)
{

}

Intern& Intern::operator=(const Intern &intern)
{

    return *this;
}

AForm* pred(std:: string name, std::string target)
{
    return (new PresidentialPardonForm("",0,0,target));
}
AForm* shub(std:: string name, std::string target)
{
    return (new ShrubberyCreationForm("",0,0,target));
}

AForm* robo(std:: string name, std::string target)
{
    return (new RobotomyRequestForm("",0,0,target));
}
AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string form[] = {"presidantial pardon" , "shrubbery creation" , "robotomy request"};

    AForm* (*forms[])(std:: string name, std::string target) = {&pred,&shub, &robo};
    for(int i =0 ; i< 3; i++)
    {
        if(form[i] == name)
        {
            std::cout << "Intern creates " << form[i] << std::endl;
            return (*forms[i])(name, target);
        }
    }
    //throw an exception here ...
    throw(Intern::WrongNameException());
}

const char *Intern::WrongNameException::what() const throw()
{
    return "No form with this name ";
}