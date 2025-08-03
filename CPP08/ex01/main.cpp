#include "Span.hpp"
#include <cstdlib>
#include <ctime> 

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Span 1:" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(99);
    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;
    Span sp2(3);
    std::vector<int> data;
    data.push_back(10);
    data.push_back(20);
    data.push_back(21);
    sp2.addNumber(data.begin(), data.end());

    std::cout << "Span 2:" << std::endl;
    std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span : " << sp2.longestSpan() << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    Span bigSpan(10000);

    std::srand(std::time(0));

    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(std::rand());

    std::cout << "Big Span:" << std::endl;
    std::cout << "Shortest span : " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span : " << bigSpan.longestSpan() << std::endl;

    std::cout << "--------------------------------------" << std::endl;
    try 
    {
        Span emptySpan(2);
        emptySpan.addNumber(5);
        std::cout << "Empty Span:" << std::endl;
        std::cout << "Shortest span : " << emptySpan.shortestSpan() << std::endl;

    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}