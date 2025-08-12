#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal &Aanimal);
        AAnimal& operator=(const AAnimal &Aanimal);
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif