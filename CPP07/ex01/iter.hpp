#pragma once

#include <string>
#include <iostream>

template<typename T>
void iter(T* array, int size, void (*func)(T&))
{
    if (array == NULL || func == NULL || size <= 0)
      return ;
    for(int i = 0; i < size; i++)
        func(array[i]);
}

template<typename T>
void iter(T* array, int size, void (*func)(const T&))
{
    if (array == NULL || func == NULL || size <= 0)
      return ;
    for(int i = 0; i < size; i++)
        func(array[i]);
}
