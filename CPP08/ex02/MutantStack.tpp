#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){
}

template<typename T>
MutantStack<T>::~MutantStack(){
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &m): std::stack<T>(){
    *this = m;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &m){
    if(this != &m)
        std::stack<T>::operator=(m);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}
