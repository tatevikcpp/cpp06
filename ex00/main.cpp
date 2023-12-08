#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    try
    {
        if (c == 2)
        {
            std::string str(v[1]);
            ScalarConverter::checkType(str);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}