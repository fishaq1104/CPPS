#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &wrongAnimal);
        WrongAnimal& operator=(const WrongAnimal &wrongAnimal);
        void makeSound() const;
        std::string getType() const;
};

#endif

