#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string _name; 
        int _grade;
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &bure);
        Bureaucrat& operator=(const Bureaucrat &bure);
        ~Bureaucrat();
        const std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bure);

#endif