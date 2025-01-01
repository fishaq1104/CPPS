#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal &wrongAnimal);
        virtual void makeSound();
        std::string getType();
};

#endif
