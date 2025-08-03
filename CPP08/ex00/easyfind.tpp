#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator t;
    t = std::find(container.begin(), container.end(), value);
    
    if(t == container.end())
        throw NotFoundError();
    return t;
}
