#include "ScalarConverter.hpp"

int main(int c, char **v)
{
    if (c == 2)
    {
        try
        {
            std::string str(v[1]);
            ScalarConverter::convert(str);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << "Error: invalid argument" << std::endl;
    }
}