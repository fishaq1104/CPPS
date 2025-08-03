#include "Serializer.hpp"

int main()
{
    Data data;
    data.s = "School";
    data.value = 42;

    uintptr_t uniptr = Serializer::serialize(&data);
    Data* copy = Serializer::deserialize(uniptr);

    std::cout << "Original: " << data.value << ", " << data.s << std::endl;
    std::cout << "Copy : " << copy->value << ", " << copy->s<< std::endl;
}
