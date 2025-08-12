#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "The WrongAnimal Constructor called on "<< this->getType() << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The WrongAnimal Deconstructor called on " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    std::cout << "The WrongAnimal Copy Constructor is called"<< std::endl;
    if(this != &wrongAnimal)
        this->type = wrongAnimal.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    std::cout << "The WrongAnimal Copy Assignment Operator is called"<< std::endl;
    if(this != &wrongAnimal)
        this->type = wrongAnimal.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->getType() << " makes wrong sounds" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
