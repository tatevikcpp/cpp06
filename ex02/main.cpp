#include "real_type.hpp"
// #include "real_type.cpp"

int main()
{
    // std::cout << "lalala\n";
    Base *base;
    base = generate();
    identify(base);
    identify(*base);
}