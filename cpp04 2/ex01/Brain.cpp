#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = " ";
    std::cout << "Brain Constructor called"<< std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Deconstructor called"<< std::endl;
}

Brain::Brain(const Brain &brain)
{
    if (this == &brain)
    for (int i = 0; i < 100; i++)
        this->ideas[i] = brain.ideas[i];
    std::cout << "Brain Copy Constructor is called" << std::endl;
}

Brain& Brain::operator=(const Brain &brain)
{
    if (this == &brain)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    std::cout << "Brain Copy Assignment Operator is called" << std::endl;
    return *this;
}

std::string* Brain::getIdea()
{
    return this->ideas;
}

std::string Brain::getIdea(int i) const
{
    if(i >= 0 && i < 100)
        return this->ideas[i];
    else
    {
        std::cout << "Brain can't access the index is out of range" << std::endl;
        return "";
    }
}

void Brain::setIdea(const std::string &word, int i)
{
    if(i >= 0 && i < 100)
        this->ideas[i] = word;
    else
    {
        std::cout << "Brain can't set the index is out of range" << std::endl;
        return ;
    }
}