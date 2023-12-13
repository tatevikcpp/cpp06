#include "real_type.hpp"

int main() 
{
    Base *ptr;
    ptr = generate();
    Base &a = *ptr;
    identify(ptr);
    identify(a);
}