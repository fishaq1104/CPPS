#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    this->brains = new Brain();
    std::cout << "The Dog Constructor is called" << std::endl;
}

Dog::~Dog() 
{
    std::cout << "The Dog Deconstructor is called" << std::endl;
    if(this->brains)
        delete this->brains;
}

Dog::Dog(const Dog &dog) : AAnimal(dog)
{
     std::cout << "The Dog Copy Constructor is called" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
        this->brains = new Brain(*dog.brains);
    }
}

Dog& Dog::operator=(const Dog &dog)
{
    std::cout << "The Dog Copy Assignment Operator is called" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
        if (this->brains)
            delete this->brains;
        this->brains = new Brain(*dog.brains);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << this->getType()<< ": Barrrkkkk...Baaaarrrrkkkkk................" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->brains;
}