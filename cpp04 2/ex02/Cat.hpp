#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain *brains;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &cat);
        Cat& operator=(const Cat &Cat);
        void makeSound() const;
        Brain *getBrain() const;
};

#endif