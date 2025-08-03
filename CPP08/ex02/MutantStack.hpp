#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &m);
        MutantStack& operator=(const MutantStack &m);
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include"MutantStack.tpp"