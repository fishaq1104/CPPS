#include "Base.hpp"

Base::~Base(){
}

Base * generate(void)
{
    std::srand(time(NULL));
    int r = std::rand() % 3;

    if(r == 0)
    {
        std::cout << "Type A is Generated" << std:: endl;
        return new A();
    }
    else if(r == 1)
    {
        std::cout << "Type B is Generated" << std:: endl;
        return new B();
    }
    else if(r == 2)
    {
        std::cout << "Type C is Generated " << std:: endl;
        return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Type A is Identified : Pointer" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Type B is Identified : Pointer" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Type C is Identified : Pointer" << std::endl;
    else
        std::cout << "Error" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
            std::cout << "Type A is Identified : Reference" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
            std::cout << "Type B is Identified : Reference" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
            std::cout << "Type C is Identified : Reference" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
		std::cout << e.what() << std::endl;
    }
}
