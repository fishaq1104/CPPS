#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "The Cat Constructor is called " << std::endl;
}

Cat::~Cat()
{
    std::cout << "The Cat Deconstructor is called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat)
{
    std::cout << "The Cat Copy Constructor is called" << std::endl;
    if(this != &cat)
        this->type = cat.type;
}

Cat& Cat::operator=(const Cat &cat)
{
    std::cout << "The Cat Copy Assignment Operator is called" << std::endl;
    if(this != &cat)
        this->type = cat.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->getType() << ": Meeeeeeeooooowwwwwww................" << std::endl;
}
