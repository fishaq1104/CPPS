#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include "Animal.hpp" 
#include "Dog.hpp"    
#include "Cat.hpp"    

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() 
{
    std::cout << "Creating individual Dog and Cat objects..." << std::endl;
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    std::cout << std::endl;

    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;
    std::cout << std::endl;

    std::cout << "Testing deep copy of Dog..." << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea("Fetch the ball!", 0);
    originalDog.getBrain()->setIdea("Chase the mailman.", 1);

    Dog copiedDog = originalDog; // Deep copy
    copiedDog.getBrain()->setIdea("Sleep all day!", 0);

    std::cout << "Original Dog's Brain Idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's Brain Idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "Creating an array of Animals (Dogs and Cats)..." << std::endl;
    Animal* animals[6];
    for (int i = 0; i < 3; ++i)
        animals[i] = new Dog();
    for (int i = 3; i < 6; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 6; ++i)
        animals[i]->makeSound();
    std::cout << std::endl;

    for (int i = 0; i < 6; ++i)
        delete animals[i];
    std::cout << std::endl;

    std::cout << "Check for memory leaks using Valgrind or similar tools!" << std::endl;

    return 0;
}

