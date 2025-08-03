#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
    Brain *brains;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &cat);
        Cat& operator=(const Cat &Cat);
        void makeSound();
        Brain *getBrain();
};

#endif