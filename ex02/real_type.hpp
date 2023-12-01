#pragma once
#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base() {};
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);



Base * generate(void)
{
    switch (rand() % 3 + 1)
    {
        case 1:
        {
            std::cout << "A" << "\n";
            return (new A);
        }
        case 2:
        {
            std::cout << "B" << "\n";
            return (new B);
        }
        case 3:
        {
            std::cout << "C" << "\n";
            return (new C);
        }
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
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cout<<"caught bad cast\n" ;
    }
    
    try
    {
        B& a = dynamic_cast<B&>(p);
        std::cout << "B" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cout<<"caught bad cast\n";
    }

    try
    {
        C& a = dynamic_cast<C&>(p);
        std::cout << "C" << "\n";
        return ;
    }
    catch(const std::exception& e)
    {
        // std::cout<<"caught bad cast\n";
    }

    std::cout << "error\n";
}
