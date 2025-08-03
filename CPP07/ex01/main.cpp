#include "iter.hpp"

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    ++x;
}

int main() {
    int intArray[] = {1, 2, 3, 4};
    std::string strArray[] = {"hello", "world"};

    std::cout << "Original ints: ";
    iter(intArray, 4, print<int>);
    std::cout << std::endl;

    iter(intArray, 4, increment<int>);

    std::cout << "After +1 ints: ";
    iter(intArray, 4, print<int>);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(strArray, 2, print<std::string>);
    std::cout << std::endl;

    return 0;
}
