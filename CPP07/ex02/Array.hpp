#pragma once

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array{
    private:
        T *array;
        unsigned int _size;
        class InvalidIndex : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: Index is invalid");
                }
        };
        
    public:
        Array(); 
        ~Array();
        Array(const Array &a);
        Array& operator=(const Array &a);
        Array(unsigned int n);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

#include "Array.tpp"
