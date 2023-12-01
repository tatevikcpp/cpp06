#include "serialize.hpp"

// class A
// {
//     public:
//         A(int c){};
// };


// int main()
// {
//     A a(5);

//     a = A(8);
//     short a = 2000;
//     const short  * ptr = &a;
//     short  * ptr1 = (short  *)ptr;
//     *ptr1  = 100;
// std::cout << "a = " << a << "\n";
//     int b;
//     b = (char) a; 
//     std::cout << "b = " << b << "\n";
//     // b = int (a); 
// }


int main()
{
    Data obj;

    obj.a = 10;
    obj.b = 'c';
    Serializer::deserialize(Serializer::serialize(&obj));
    std::cout << "a = " << obj.a << "\n" << "b = " << obj.b << "\n";
}