#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "The Dog Constructor is called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() 
{
    std::cout << "The Dog Deconstructor is called" << std::endl;
}

Dog::Dog(const Dog &dog) :  Animal(dog)
{
    std::cout << "The Dog Copy Constructor is called" << std::endl;
    if(this != &dog)
        this->type = dog.type;
}

Dog& Dog::operator=(const Dog &dog)
{
    std::cout << "The Dog Copy Assignment Operator is called" << std::endl;
    if(this != &dog)
        this->type = dog.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout<< this->getType()<< ": Barrrkkkk...Baaaarrrrkkkkk................" << std::endl;
}
