#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called : )"<< std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain deconstructor called : )"<< std::endl;
}


Brain::Brain(const Brain &brain)
{    
    std::cout << "Brain Copy Operator is called : )"<< std::endl;
    *this = brain;
}

Brain& Brain::operator=(const Brain &brain)
{
    if (this == &brain)
    {
        for(unsigned int i = 0; i < brain.ideas->length(); i++)
        {
            if(this->ideas[i] != brain.ideas[i])
                this->ideas[i] = brain.ideas[i];
        }
    }
    return *this;
}

std::string* Brain::getIdea()
{
    return this->ideas;
}

std::string Brain::getIdea(int i)
{
    return this->ideas[i];
}

void Brain::setIdea(const std::string &word, int i)
{
    this->ideas[i] = word;
}