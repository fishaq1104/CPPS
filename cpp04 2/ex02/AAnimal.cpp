#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal Constructor called on " << this->type << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Deconstructor called on " << this->type << std::endl;
}

AAnimal::AAnimal(const AAnimal &Aanimal)
{
    std::cout << "AAnimal Copy Constructor called on " << this->type << std::endl;
    if(this != &Aanimal)
        this->type = Aanimal.type;
}

AAnimal& AAnimal::operator=(const AAnimal &Aanimal)
{
    std::cout << "AAnimal Copy Assignment Operator called on " << this->type << std::endl;
    if(this != &Aanimal)
        this->type = Aanimal.type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->type;
}
