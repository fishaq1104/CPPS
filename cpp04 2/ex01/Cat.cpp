#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brains = new Brain();
    std::cout << "The Cat Constructor is called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "The Cat Deconstructor is called" << std::endl;
    if(this->brains)
        delete brains;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
    std::cout << "The Cat Copy Constructor is called" << std::endl;
    if (this != &cat)
    {
        this->type = cat.type;
        this->brains = new Brain(*cat.brains);
    }
}

Cat& Cat::operator=(const Cat &cat)
{
    std::cout << "The Cat Copy Assignment Operator is called" << std::endl;
    if(this != &cat)
    {
        this->type = cat.type;
        if(this->brains)
            delete this->brains;
        this->brains = new Brain(*cat.brains);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->getType()<< ": Meeeeeeeooooowwwwwww................" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brains;
}
