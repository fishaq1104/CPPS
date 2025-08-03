#include "easyfind.hpp"

#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << *it << std::endl;
    } catch (const NotFoundError& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 19);
        std::cout << *it << std::endl;
    } catch (const NotFoundError& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
