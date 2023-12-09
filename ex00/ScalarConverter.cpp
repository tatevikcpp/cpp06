#include "ScalarConverter.hpp"
#include  <cstdlib>
#include <limits.h>
#include <bits/stdc++.h>
#include <math.h> // nan inf

int ScalarConverter::valid_string(std::string& str)
{
    bool float_double = 0;
    int f_count = 0;
    int point = 1;
    double tod = 0;
    char *end = NULL;
    int i = 0;

    if (std::strcmp(str.c_str(), "inf") == 0)
    {
        return (0);
    }

    if (isalpha(str[i]) && !str[i + 1])
    {
        return (2);
    }

    if ((str[i] == '0' && !str[i + 1]))
    {
        return (1);
    }

    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    if (str[i] == '-' || str[i] == '+')
    {
        return (0);
    }

    if (str[i] == '.')
    {
        return (0);
    }

    if (str[i] == '0' &&  str[i + 1] != '.')
    {
        std::cout << "0-ov sksvox\n";
        return (0);
    }

    tod = strtod(str.c_str(), &end);
    point = 1;
    while(end[i] != '\0')
    {
        if (end[i] == 'f')
            f_count++;
        if (end[i] == '.')
            point++;
        if (end[i] != 'f' && isalpha(end[i]))
        {
            return (0);
        }
        i++;
    }

    if (f_count > 1 || point > 2)
    {
        return (0); 
    }

    int k = 0;
    while (str.c_str()[k] != '\0')
    {
        if (str.c_str()[k] == '.' && str.c_str()[k + 1] == '\0')
            return (0);
        k++;
    }
    return (1);
}

void ScalarConverter::Char(double tod)
{
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "char: impossible" << std::endl;
        return ;
    }

    if (tod >= 32 && tod <= 126)
    {
        std::cout << "char: " << "'" <<static_cast<char>(tod) << "'" <<std::endl;
    }
    else 
    {
        std::cout << "char: " << "Non displayable" << std::endl;
    }
}

void ScalarConverter::Int(double tod) // TO DO toxel void te poxel int?
{
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    if (tod >= INT_MIN && tod <= INT_MAX)
    {
        std::cout << "int: " << static_cast<int>(tod) << std::endl;
    }
    else 
    {
        std::cout << "int: " << "Non displayable" << std::endl;
        return ;
    }
}

void ScalarConverter::Float(double tod)
{
    double a = 0;
    double p = 0;
    float f = 0.0f;

    if (isnan(tod) || isinf(tod))
    {
        std::cout << "float: " << tod << "f" << std::endl;
        return ;
    }

    if (tod >= -FLT_MAX && tod <= FLT_MAX)
    {
        f = static_cast<float>(tod);
        a = modf(f, &p);
        if (a)
            std::cout << "float: " << f << "f" << std::endl;
        else
            std::cout << "float: " << f << ".0f" << std::endl;
    }
    else 
    {
        std::cout << "float: " << "Non displayable" << std::endl;
    }
}

void ScalarConverter::Double(double tod)
{
    double a = 0;
    double p = 0;
    a = modf(tod, &p);
    if (a || isnan(tod) || isinf(tod))
        std::cout << "double: " << tod << std::endl;
    else
        std::cout << "double: " << tod << ".0" << std::endl;
}

void ScalarConverter::checkType(std::string& str)
{
    double tod = 0;
    char *end;

    if (valid_string(str) == 2)
    {
        double tod = static_cast<double>(str.c_str()[0]);
        Char(tod);
        Int(tod);
        Float(tod);
        Double(tod);
    }
    else if (valid_string(str) == 1)
    {
        tod = strtod(str.c_str(), &end);
        Char(tod);

        // if (Int(tod) == 0);
        //     return ;
        Int(tod);
        Float(tod);
        Double(tod);
    }
    else
        std::cout << "sxal tox\n";
}
