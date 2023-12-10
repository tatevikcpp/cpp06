#include "ScalarConverter.hpp"
#include  <cstdlib>
#include <limits.h>
#include <bits/stdc++.h>
#include <math.h> // nan inf

// int ScalarConverter::valid_string(std::string& str)
// {
//     bool float_double = 0;
//     int f_count = 0;
//     int point = 1;
//     double tod = 0;
//     char *end = NULL;
//     int i = 0;

//     // if (std::strcmp(str.c_str(), "inf") == 0)
//     // while(str.c_str()[i] != '\0')
//     // {
//         if (str == "inf")
//         {
//             return (0);
//         }

//         if (isalpha(str[i]) && str[i + 1] == '\0')
//         {
//             return (2);
//         }

//         if ((str[i] == '0' && !str[i + 1]))
//         {
//             return (1);
//         }

//         if (str[i] == '-' || str[i] == '+')
//         {
//             i++;
//         }
//         if (str[i] == '-' || str[i] == '+')
//         {
//             return (0);
//         }

//         if (str[i] == '.')
//         {
//             return (0);
//         }

//         if (str[i] == '0' &&  str[i + 1] != '.')
//         {
//             std::cout << "0-ov sksvox\n";
//             return (0);
//         }
//     //     i++;
//     // }

//     tod = strtod(str.c_str(), &end);
//     point = 1;
//     while(end[i] != '\0')
//     {
//         if (end[i] == 'f')
//             f_count++;
//         if (end[i] == '.')
//             point++;
//         if (end[i] != 'f' && isalpha(end[i]))
//         {
//             return (0);
//         }
//         i++;
//     }

//     if (f_count > 1 || point > 2)
//     {
//         return (0); 
//     }

//     int k = 0;
//     while (str.c_str()[k] != '\0')
//     {
//         if (str.c_str()[k] == '.' && str.c_str()[k + 1] == '\0')
//             return (0);
//         k++;
//     }
//     return (1);
// }



int ScalarConverter::valid_string(std::string& str)
{
    int point = 0;
    int flt = 0;

    if (str == "inf")
    {
        return (0);
    }
    
    int i = 0;
    if (str.c_str()[i] == '-' || str.c_str()[i] == '+')
    {
        i++;
    }

    if (str.c_str()[i] == '0' && str.c_str()[i + 1] != '.')
    {
        return (0);
    }
    
    if (isalpha(str[i]) && str[i + 1] == '\0')
    {
        return (2);
    }

    while (isdigit(str.c_str()[i]))
    {
        i++;
    }

    if (str.c_str()[i] == '\0')
    {
        return (1);
    }

    if (str.c_str()[i] == '.')
    {
        // std::cout << "mtav\n";
        if (isdigit(str.c_str()[i - 1]) && (isdigit(str.c_str()[i + 1]) || str.c_str()[i + 1] == 'f'))
        {
            point++;
            i++;
        }
        else 
        {
            return (0);
        }
    }

    while (isdigit(str.c_str()[i]))
    {
        i++;
    }

    if (isalpha(str.c_str()[i]))
    {
        std::cout << "is alpha \n";
        if (str.c_str()[i] == 'f' && str.c_str()[i+ 1] == '\0' && point)
        {
            flt++;
        }
        else
        {
            return (0);
        }
    }

    if (!isalpha(str.c_str()[i]) && !isdigit(str.c_str()[i]) && str.c_str()[i] != '\0')
    {
        std::cout << "aregak ?\n";
        return (0);
    }

    if (point == 1)
    {
        if (flt == 1)
        {
            return (3);
        }
        else
        {
            return (4);
        }
    }
    return (1);
}

void ScalarConverter::Char(double tod, int flag)
{
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "char: impossible" << std::endl;
        return ;
    }

    if (flag == 1)
    {
        int i = static_cast<int> (tod);
        if (i >= 32 && i <= 126)
        {
            std::cout << "qast em aneum int - i \n";
            std::cout << "char: " << "'" << static_cast<char>(i) << "'" <<std::endl;
            return ;
        }
        else if ((i >= -128 && i <= 31) || (i == 127))
        {
            std::cout << "char: " << "Non displayable" << std::endl;
            return ;
        }
        else
        {
            std::cout << "char: " << "impossible" << std::endl;
            return ;
        }
    }
    else if (flag == 2) // TO DO parsingy uxxel CH tareri hamar !!!
    {
        char c = static_cast<char>(tod);
        std::cout << "c =" << c << std::endl;
        if (tod >= 32 && tod <= 126)
        {
            std::cout << "char: " << "'" << c << "'" <<std::endl;
            return ;
        }
        else if ((c >= -128 && c <= 31) || (c == 127))
        {
            std::cout << "char: " << "Non displayable" << std::endl;
            return ;
        }
    }
    else if (flag == 3)
    {
        float f = static_cast<float> (tod);
        if (tod >= 32 && tod <= 126)
        {
            std::cout << "qast em aneum int - i \n";
            std::cout << "char: " << "'" << static_cast<char>(f) << "'" <<std::endl;
            return ;
        }
        else if ((f >= -128 && f <= 31) || (f == 127))
        {
            std::cout << "char: " << "Non displayable" << std::endl;
            return ;
        }
        else
        {
            std::cout << "char: " << "impossible" << std::endl;
            return ;
        }
    }
    else if (flag == 4)
    {
        // std::cout << "double char-um\n";
        std::cout << "tod = " << tod << std::endl;
        if (tod >= 32 && tod <= 126)
        {
            std::cout << "qast em aneum int - i \n";
            std::cout << "char: " << "'" << static_cast<char>(tod) << "'" <<std::endl;
            return ;
        }
        else if ((tod >= -128 && tod <= 31) || (tod == 127))
        {
            std::cout << "char: " << "Non displayable" << std::endl;
            return ;
        }
        else
        {
            std::cout << "char: " << "impossible" << std::endl;
            return ;
        }
    }
    // else
    // {
    //     std::cout << "char: " << "impossible" << std::endl;
    //     return ;
    // }
}

void ScalarConverter::Int(double tod, int flag) // TO DO toxel void te poxel int?
{
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }

    if (flag == 1)
    {
        int i = static_cast<int>(tod);
        std::cout << "int: " << i << std::endl;
        return ;
    }
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);

        // if (tod >= INT_MIN && tod <= INT_MAX)
        // {
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            return ;
        // }
    }
    else if (flag == 3)
    {
        float f = static_cast<char>(tod);
        if (f >= INT_MIN && f <= INT_MAX)
        {
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            return ;
        }
        else 
        {
            std::cout << "int: " << "impossible" << std::endl;
            return ;
        }

    }
    else if (flag == 4)
    {
        if (tod >= INT_MIN && tod <= INT_MAX)
        {
            std::cout << "int: " << static_cast<int>(tod) << std::endl;
            return ;
        }
        else 
        {
            std::cout << "int: " << "impossible" << std::endl;
            return ;
        }
    }
    // else 
    // {
    //     std::cout << "int: " << "Non displayable" << std::endl;
    //     return ;
    // }
}

void ScalarConverter::Float(double tod, int flag)
{
        // std::cout << "offf\n";
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "float: " << tod << "f" << std::endl;
        return ;
    }

    if (flag == 1)
    {
        int i = static_cast<int>(tod);
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        // a = modf(f, &p);
        // if (a)
        //     std::cout << "float: " << f << "f" << std::endl;
        // else
        //     std::cout << "float: " << f << ".0f" << std::endl;
        // return ;
        return ;
    }
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);
        std::cout << "float: " << tod << static_cast<float>(c) << "0.f" << std::endl;
        return ;
    }
    else if (flag == 3)
    {
        float f = static_cast<float>(tod); // TO DO erevi aranc f 
        std::cout << "float: " << tod << f << std::endl;
        return ;
    }
    else if (flag == 4)
    {
        if (tod >= -FLT_MAX && tod <= FLT_MAX)
        {
            std::cout << "float: " << tod << "f" << std::endl;
            return ;
        }
        else 
        {
            std::cout << "float: " << "impossible" << std::endl;
            return ;
        }

    }
}

void ScalarConverter::Double(double tod, int flag)
{
    if (isnan(tod) || isinf(tod))
    {
        std::cout << "double: " << tod << std::endl;
        return ;
    }

    if (flag == 1)
    {
        int i = static_cast<int>(tod);
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
        return ;
    }
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return ;
    }
    else if (flag == 3) // TO DO esim ?
    {
        float f = static_cast<float>(tod);
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return ;
    }
    else if (flag == 4)
    {
        std::cout << "double: " << tod << std::endl;
        return ;
    }
    // double a = 0;
    // double p = 0;
    // a = modf(tod, &p);
    // if (a || isnan(tod) || isinf(tod))
    //     std::cout << "double: " << tod << std::endl;
    // else
    //     std::cout << "double: " << tod << ".0" << std::endl;
}

void ScalarConverter::checkType(std::string& str)
{
    double tod = 0;
    char *end;


    if (valid_string(str) == 1)
    {
        std::cout << "1: \n";
        double tod = strtod(str.c_str(), &end);

        Char(tod, 1);
        Int(tod, 1);
        Float(tod, 1);
        Double(tod, 1);
    }
    else if (valid_string(str) == 2)
    {
        std::cout << "2: \n";
        double tod = strtod(str.c_str(), &end);

        Char(tod, 2);
        Int(tod, 2);
        Float(tod, 2);
        Double(tod, 2);
    }
    else if (valid_string(str) == 3)
    {   
        std::cout << "3: \n";
        double tod = strtod(str.c_str(), &end);

        Char(tod, 3);
        Int(tod, 3);
        Float(tod, 3);
        Double(tod, 3);
    }
    else if (valid_string(str) == 4)
    {
        
        std::cout << "4: \n";
        double tod = strtod(str.c_str(), &end);

        Char(tod, 4);
        Int(tod, 4);
        Float(tod, 4);
        Double(tod, 4);
    }
    else
        std::cout << "sxal tox\n";
}


// void ScalarConverter::checkType(std::string& str)
// {
//     double tod = 0;
//     int toi = 0;
//     float tof = 0;
//     char toch = 0;
//     char *end;

//     if (valid_string(str) == 2)
//     {
//         tod = static_cast<double>(str.c_str()[0]);
//         toi = static_cast<int>(str.c_str()[0]);
//         tof = static_cast<float>(str.c_str()[0]);
//         // toch = static_cast<char>(str.c_str()[0]);

//         Char(tod);
//         Int(tod);
//         Float(tod);
//         Double(tod);
//     }
//     else if (valid_string(str) == 1)
//     {
//         tod = strtod(str.c_str(), &end);
//         Char(tod);
//         Int(tod);
//         Float(tod);
//         Double(tod);
//     }
//     else
//         std::cout << "sxal tox\n";
// }



// std::string ScalarConverter::check(std::string& str)
// {
//     size_t i = 0;
//     int point = 0;
//     // int f = 0;

//     while (str.c_str()[i] != '\0')
//     {
//         if (str.c_str()[i] == '.' )
//         {
//             point++;
//         }
//         i++;
//     }
//     if (str.c_str()[i - 1] == 'f' && point == 1)
//         return ("float\n");
//     else if (point)
//         return ("double\n");
//     else
//         return ("int\n");
// }
