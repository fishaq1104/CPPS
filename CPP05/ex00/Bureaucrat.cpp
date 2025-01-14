#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("name"), _grade(0)
{

}

Bureaucrat::Bureaucrat(int grade): _name("name"), _grade(0)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &bure)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bure)
{
    
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::setGrade()
{

}

void Bureaucrat::setName()
{
    
}

void Bureaucrat::increment()
{

}

void Bureaucrat::decrement()
{
    
}

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bure);
{

}
