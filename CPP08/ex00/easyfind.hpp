#pragma once

#include <algorithm>
#include <iterator>
#include <exception>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int value);

class NotFoundError : public std::exception {
    public:
        const char* what() const throw() { return "value not found"; }
};

#include "easyfind.tpp"