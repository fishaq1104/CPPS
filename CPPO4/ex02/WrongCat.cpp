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

WrongCat::WrongCat(const WrongCat &wrongCat)
{
    *this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongCat)
{
    if(this != &wrongCat)
    {
        this->type = wrongCat.type;
    }
    return *this;
}

void WrongCat::makeSound()
{
    std::cout << "Bark......Brak....Bark....." << std::endl;
}
