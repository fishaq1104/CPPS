#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &brain);
        Brain& operator=(const Brain &brain);
        std::string* getIdea();
        std::string getIdea(int i);
        void setIdea(const std::string &word, int i);
};

#endif