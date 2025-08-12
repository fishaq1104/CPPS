#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brains;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &dog);
        Dog& operator=(const Dog &dog);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif