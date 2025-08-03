#pragma once

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename C>
const C& min(const C &a, C const &b)
{
    if(a == b)
        return b;
    if(a < b)
        return a;
    else
        return b;
}

template<typename D>
const D& max(const D &a,const D &b)
{
    if(a == b)
        return b;
    if(a < b)
        return b;
    else
        return a;
}
