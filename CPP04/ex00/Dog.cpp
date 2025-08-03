#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "The Dog Constructor is called" << std::endl;
}

Dog::~Dog() 
{
    std::cout << "The Dog Deconstructor is called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
    *this = dog;
}

Dog& Dog::operator=(const Dog &dog)
{
    if(this != &dog)
    {
        this->type = dog.type;
    }
    return *this;
}

void Dog::makeSound()
{
    std::cout<< this->getType()<< ": Barrrkkkk...Baaaarrrrkkkkk................" << std::endl;
}
