#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main() 
{
    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    delete dog;
    delete cat;

    std::cout << "\nTesting deep copies:" << std::endl;

    Dog originalDog;
    originalDog.getBrain()->setIdea( "Chase the ball!", 100);
    originalDog.getBrain()->setIdea( "Chase the ball!", 0);
    Dog copyDog = originalDog;

    std::cout << "Original Dog's Brain Idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's Brain Idea[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;

    copyDog.getBrain()->setIdea("Guard the house!", 0);
    std::cout << "After modification:" << std::endl;
    std::cout << "Original Dog's Brain Idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog's Brain Idea[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\nTesting Animal array:" << std::endl;

    const AAnimal* animals[4];
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    std::cout << std::endl;
    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << std::endl;

    return 0;
}

