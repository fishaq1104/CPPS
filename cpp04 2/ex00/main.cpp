#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "\n_______Testing Animal_______" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;
     
    std::cout << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    Animal a;
    a = dog1;

    std::cout << "Dog type: " << dog1.getType() << std::endl;
    std::cout << "Animal type: " << a.getType() << std::endl;
    Cat c;
    a = c;
    std::cout << "Cat type: " << a.getType() << std::endl;


    std::cout << "\n_____Testing WrongAnimal_______" << std::endl;

    WrongAnimal* wrongMeta = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    wrongCat->makeSound();
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
