#include "WrongAnimal.hpp"

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Nothing")
{
    std::cout << "WrongAnimal Constructor called : )" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstructor called on " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    *this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    if(this != &wrongAnimal)
    {
        this->type = wrongAnimal.type;
    }
    return *this;
}

void WrongAnimal::makeSound()
{
    std::cout << "I make no wrong sound :(" << std::endl;
}

std::string WrongAnimal::getType()
{
    return this->type;
}
