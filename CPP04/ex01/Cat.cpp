#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    brains = new Brain();
    std::cout << "The Cat Constructor is called" << std::endl;
}

Cat::~Cat() 
{
    std::cout << "The Cat Deconstructor is called" << std::endl;
}


Cat::Cat(const Cat &cat)
{
    *this = cat;
}

Cat& Cat::operator=(const Cat &cat)
{
    if(this != &cat)
    {
        this->type = cat.type;
    }
    return *this;
}

void Cat::makeSound()
{
    std::cout << this->getType()<< ": Meeeeeeeooooowwwwwww................" << std::endl;
}

Brain *Cat::getBrain()
{
    return this->brains;
}
