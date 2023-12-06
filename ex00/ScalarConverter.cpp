#include "ScalarConverter.hpp"
#include  <cstdlib> 

void ScalarConverter::checkType(std::string& str)
{
    // str =  42.0f => char = *, int = 42, float = 42.0f, double = 42.0x
    // str = 0 => char =  Non displayabl, int = 0, float = 0.0f, double = 0.0
    
    // int i = 0;
    // while (str.c_str()[i] != '\0')
    // {
    //     if (str[i] < -127 || str[i] > 128)
    //     {
    //         throw std::out_of_range;
    //     }
    //     i++;
    // }


    char c = 0;
    bool float_double = 0;
    if (str.find(".") != std::string::npos)
    {
        float_double = 1;
    }
    std::cout << "float_double = " << float_double << std::endl;
    char *end;
    double tod = strtod(str.c_str(), &end);
    int i = 0;
    if (end != NULL && float_double)
    {
        // std::cout << "end[i] = " << end[i] << std::endl;
        std::cout << "end = " << end << std::endl;
        if (end[i] == 'f')
            std::cout << "is float: " << tod << "f" << "\n";
        else if (end[i] != 'f' && !isalpha(end[i]))
            std::cout << "is double: " << tod << "\n";
        else
            std::cout << "sxal: " << end << std::endl;
    }
    std::cout << "tod = " << tod << "\n";
    if (tod > -128 && tod <= 128)
    {
        // c = static_cast<char>(tod);
        c = tod;
        std::cout << "char c = " << c << "\n";
    }


    // if (end == NULL)
    // {
    //     char a = tod;
    //     std::cout << "strtod = " << a << "\n";
    // }
    // else
    // {
    //     std::cout << "sxal " << end << "\n";
    // }
    // std::cout << "strtod = " << tod << "\n";

}