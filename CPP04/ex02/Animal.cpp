#include "Animal.hpp"

Animal::Animal() : type("Nothing")
{
    std::cout << "Animal Constructor called : )" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Deconstructor called on " << type << std::endl;
}

Animal::Animal(const Animal &animal)
{
    *this = animal;
}

Animal& Animal::operator=(const Animal &animal)
{
    if(this != &animal)
    {
        this->type = animal.type;
    }
    return *this;
}

std::string Animal::getType()
{
    return this->type;
}