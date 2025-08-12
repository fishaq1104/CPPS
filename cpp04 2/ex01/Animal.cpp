#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Constructor called on " << this->type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called on " << this->type << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal Copy Constructor called on " << this->type << std::endl;
    if(this != &animal)
        this->type = animal.type;
}

Animal& Animal::operator=(const Animal &animal)
{
    std::cout << "Animal Copy Assignment Operator called on " << this->type << std::endl;
    if(this != &animal)
        this->type = animal.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << this->getType() << " makes sound.......!" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}
