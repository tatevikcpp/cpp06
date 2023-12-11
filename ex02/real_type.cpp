#include "real_type.hpp"
#include <cstdlib>

Base * generate(void)
{
    std::srand(time(NULL));
    int r = rand() % 3 + 1;

    switch (r)
    {
        case 1:
            return (new A);
        case 2:
            return (new B);
        case 3:
            return (new C);
        default:
        {
            std::cout << "error\n";
            break ;
        }
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << "\n";
        return ;
    }

    if (dynamic_cast<B*>(p))
    {
        std::cout<< "B" << "\n";
        return ;
    }

    if (dynamic_cast<C*>(p))
    {
        std::cout<< "C" << "\n";
        return ;
    }
    std::cout << "error\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
    }
    std::cout<<"Caught bad cast\n";
}
