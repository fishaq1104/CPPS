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
        class GradeTooHighException : public exception
        {
            public:
                const char* what();
        };
        class GradeTooLowException : public exception
        {
            public:
                const char* what();
        };
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat &bure);
        Bureaucrat& operator=(const Bureaucrat &bure);
        ~Bureaucrat();
        const std::string getName(); const
        int getGrade() const;
        void setGrade(const int &grade);
        void setName(const std::string &name);
        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &os,const Bureaucrat &bure);

#endif