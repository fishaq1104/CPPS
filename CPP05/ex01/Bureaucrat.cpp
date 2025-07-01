#include "Bureaucrat.hpp"

//Do the things like writing weather it i Build and tsuffs ... and make the main proper  fix the messages

Bureaucrat::Bureaucrat():_name("name"), _grade(0){
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
    if(grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if(grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    std::cout <<"The Bureaucrat " << this->_name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bure) : _name(bure._name), _grade(bure._grade){
}

Bureaucrat::~Bureaucrat(){
    std::cout <<"The Bureaucrat " << this->_name << " has been destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bure)
{
    if (this != &bure)
        this->_grade = bure._grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increment()
{
    if(this->_grade > 1)
        this->_grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
    if(this->_grade < 150)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bure)
{
    os << bure.getName() << ", bureaucrat grade " << bure.getGrade() << std::endl;
    return os;
}

const char *Bureaucrat::GradeTooHighException:: what() const throw()
{
    return "Bureaucrat: The grade is High";
}

const char *Bureaucrat::GradeTooLowException:: what() const throw()
{
    return "Bureaucrat: The grade is Low";
}

void Bureaucrat::signForm(Form &form)
{
    if(form.getSign())
    {
        std::cout<< "the form is already signed" << std::endl;
        return ;
    }
    try
    {
        form.beSigned(*this);
        std::cout << "bureaucrat:: " << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() <<  "couldn’t sign " <<form.getName()  << " because " << e.what() << " ." << std::endl;
    }
}
