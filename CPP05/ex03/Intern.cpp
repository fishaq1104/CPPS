#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern has been created"<< std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern has been destroyed"<< std::endl;
}

Intern::Intern(const Intern &intern){
}

Intern& Intern::operator=(const Intern &intern)
{
    return *this;
}

AForm* pred(std::string target)
{
    return (new PresidentialPardonForm(target));
}
AForm* shub(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* robo(std::string target)
{
    return (new RobotomyRequestForm(target));
}
AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string form[] = {"presidantial pardon" , "shrubbery creation" , "robotomy request"};

    AForm* (*forms[])(std::string target) = {&pred,&shub, &robo};
    for(int i = 0; i< 3; i++)
    {
        if(form[i] == name)
        {
            std::cout << "Intern creates " << form[i] << std::endl;
            return (*forms[i])(target);
        }
    }
    throw(Intern::WrongNameException());
    return NULL;
}

const char *Intern::WrongNameException::what() const throw()
{
    return "No form with this name ";
}