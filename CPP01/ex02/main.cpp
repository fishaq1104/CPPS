#include <iostream>
#include <string>

int main()
{
    std::string var1 = "HI THIS IS BRAIN";
    std::string* stringPTR = &var1;
    std::string& stringREF = var1;

    std::cout << "____Memory Address___"<<std::endl;
    std::cout<<"Memory Adress of var1: " << &var1 << "\n";
    std::cout<<"Memory Adress of stringPTR: " << stringPTR << "\n";
    std::cout<<"Memory Adress of stringREF: " << &stringREF << "\n";

    std::cout << "____Value________" <<std::endl;;
    std::cout << "Value of var1: " << var1 << std::endl;;
    std::cout <<"Value of stringPTR: "<< *stringPTR << std::endl;;
    std::cout << "Value of stringREF :" << stringREF << std::endl;;
    return 0;
}
