#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "The Stack: " << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    //the list
    std::cout << "The List: " << std::endl;
    std::list<int> mstackl;
    mstackl.push_back(5);
    mstackl.push_back(17);
    std::cout << mstackl.back() << std::endl;
    mstackl.pop_back();
    std::cout << mstackl.size() << std::endl;
    mstackl.push_back(3);
    mstackl.push_back(5);
    mstackl.push_back(737);
    //[...]
    mstackl.push_back(0);
    std::list<int>::iterator it_l = mstackl.begin();
    std::list<int>::iterator ite_l = mstackl.end();
    ++it_l;
    --it_l;
    while (it_l != ite_l)
    {
        std::cout << *it_l << std::endl;
        ++it_l;
    }
    std::list<int> l(mstackl);
    return 0;
}