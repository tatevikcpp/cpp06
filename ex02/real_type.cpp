// #include "real_type.hpp"
// #include <cstdlib>

// Base * generate(void)
// {
//     int r = rand() % 3 + 1;

//     switch (r)
//     {
//         case 1:
//             return (new A);
//         case 2:
//             return (new B);
//         case 3:
//             return (new C);
//         default:
//         {
//             std::cout << "error\n";
//             break ;
//         }
//     }
//     return (NULL);
// }

// void identify(Base* p)
// {
//     if (dynamic_cast<A*>(p))
//     {
//         std::cout << "A" << "\n";
//         return ;
//     }

//     if (dynamic_cast<B*>(p))
//     {
//         std::cout<< "B" << "\n";
//         return ;
//     }

//     if (dynamic_cast<C*>(p))
//     {
//         std::cout<< "C" << "\n";
//         return ;
//     }
//     std::cout << "error\n";
// }

// void identify(Base& p)
// {
//     try
//     {
//         A& a = dynamic_cast<A&>(p);
//         std::cout << "A" << "\n";
//     }
//     catch(const std::exception& e)
//     {
//         std::cout<<"Caught bad cast\n";
//     }
    
//     try
//     {
//         B& a = dynamic_cast<B&>(p);
//         std::cout << "B" << "\n";
//     }
//     catch(const std::exception& e)
//     {
//         std::cout<<"Caught bad cast\n";
//     }

//     try
//     {
//         C& a = dynamic_cast<C&>(p);
//         std::cout << "C" << "\n";
//     }
//     catch(const std::exception& e)
//     {
//         std::cout<<"Caught bad cast\n";
//     }
// }
