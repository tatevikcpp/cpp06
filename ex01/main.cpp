#include "serialize.hpp"

int main() 
{
    Data data;
    data.a = 5;
    data.b = 5.5;
    uintptr_t ptr;
    ptr = Serializer::serialize(&data);
    Data *dataPtr = Serializer::deserialize(ptr);
    std::cout << &data << std::endl;
    std::cout << dataPtr << std::endl;
    std::cout << dataPtr->a << std::endl;
    std::cout << dataPtr->b << std::endl;
}