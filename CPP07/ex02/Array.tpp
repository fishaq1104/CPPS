#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL) , _size(0){
}

template <typename T>
Array<T>::Array(unsigned int n): array(new T[n]), _size(n){
}

template <typename T>
Array<T>::Array(const Array<T> &a):array(new T[a._size]), _size(a._size)
{
    for(unsigned int i = 0; i < this->_size ;i++)
        array[i] = a.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &a)
{
    if(this != &a)
    {
        delete[] (this->array);
        this->_size = a._size;
        this->array = new T[this->_size];
        for(unsigned int i = 0; i < this->_size ;i++)
            array[i] = a.array[i]; 
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{  
    if(index >= this->_size)
        throw(Array::InvalidIndex());
    return this->array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if(index >= (unsigned int)this->_size)
        throw(Array::InvalidIndex());
    return this->array[index];
}

template <typename T>
Array<T>::~Array()
{
    delete [] this->array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
