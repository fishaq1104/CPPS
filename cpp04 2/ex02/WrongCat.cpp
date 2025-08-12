#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "The WrongCat Constructor is called" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << "The WrongCat Deconstructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "The WrongCat Copy Constructor is called" << std::endl;
    if(this != &wrongCat)
        this->type = wrongCat.type;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongCat)
{
    std::cout << "The WrongCat Copy Assignment Operator is called" << std::endl;
    if(this != &wrongCat)
        this->type = wrongCat.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong: Meeeeeoooooowwwwwwww......." << std::endl;
}
