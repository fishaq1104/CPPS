#include "Base.hpp"

int main()
{
    Base *s;

    s = generate();
    identify(s);
    identify(*s);

    delete s;
    return 0;
}
