#include "ScalarConverter.hpp"
#include  <cstdlib>
#include <limits.h>
// #include <bits/stdc++.h>
#include <math.h> // nan inf

int ScalarConverter::valid_string(std::string& str)
{
    int point = 0;
    int flt = 0;

    if (str == "inf" || str == "inff" || str == "+nan" || str == "-nan") //TO DO inchu ?
    {
        return (0);
    }
    
    if (str == "+inff" || str == "nanf" || str == "-inff")
    {
        return (3);
    }

    if (str == "+inf" || str == "nan" || str == "-inf")
    {
        return (4);
    }

    if (isnan(strtod(str.c_str(), NULL)) || isinf(strtod(str.c_str(), NULL)))
    {
        return (4);
    }

    int i = 0;
    if (str.c_str()[i] == '-' || str.c_str()[i] == '+')
    {
        if (str.c_str()[i + 1] == '\0')
        {
            return (2);
        }
        i++;
    }

    if (str.c_str()[i] == '0' && str.c_str()[i + 1] != '.' )
    {
        if (str.c_str()[i + 1] == '\0')
        {
            return (1);
        }

        return (0);
    }

    if (str.c_str()[i] == '0' && str.c_str()[i + 1] == '\0')
    {
        return (1);
    }
    
    // if (isalpha(str[i]) && str[i + 1] == '\0')
    // {
    //     return (2);
    // }

    if ((str[i - 1] != '+' || str[i - 1] == '-') && (!isdigit(str[i]) && str[i + 1] == '\0'))
    {
        std::cout << "ch digit\n";
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
    if (flag == 1)
    {
        int i = static_cast<int> (tod);
        if (i >= 32 && i <= 126)
        {
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
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);
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
        if (tod >= 32 && tod <= 126)
        {
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
}

void ScalarConverter::Int(double tod, int flag)
{
    if (flag == 1)
    {
        if (tod >= INT_MIN && tod <= INT_MAX)
        {
            int i = static_cast<int>(tod);
            std::cout << "int: " << i << std::endl;
            return ;
        }
        else 
        {
            std::cout << "int: " << "impossible" << std::endl;
            return ;
        }
    }
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        return ;
    }
    else if (flag == 3)
    {
        if (tod >= INT_MIN && tod <= INT_MAX)
        {
            float f = static_cast<float>(tod);
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
}

void ScalarConverter::Float(double tod, int flag)
{
    if (flag == 1)
    {
        int i = static_cast<int>(tod);
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        return ;
    }
    else if (flag == 2)
    {
        char c = static_cast<char>(tod);
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        return ;
    }
    else if (flag == 3)
    {
        double a = 0;
        double p = 0;
        float f = static_cast<float>(tod);
        a = modf(f, &p);
        if (a)
            std::cout << "float: " << f << "f" << std::endl;
        else
            std::cout << "float: " << f << ".0f" << std::endl;
        return ;
    }
    else if (flag == 4)
    {
        // if (tod >= -FLT_MAX && tod <= FLT_MAX)
        // {
            double a = 0;
            double p = 0;
            float f = static_cast<float>(tod);
            a = modf(f, &p);
            if (a || isinf(tod))
                std::cout << "float: " << f << "f" << std::endl;
            else 
                std::cout << "float: " << f << ".0f" << std::endl;
            return ;
        // }
        // else 
        // {
        //     std::cout << "float: " << "impossible" << std::endl;
        //     return ;
        // }

    }
}

void ScalarConverter::Double(double tod, int flag)
{
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
    else if (flag == 3)
    {
        double a = 0;
        double p = 0;
        float f = static_cast<float>(tod);
        a = modf(f, &p);
        if (a)
            std::cout << "double: " << f << std::endl;
        else
            std::cout << "double: " << f << ".0" << std::endl;
        return ;
    }
    else if (flag == 4) //TO DO nan? nanf? +nanf? +inff?
    {
        double a = 0;
        double p = 0;
        a = modf(tod, &p);
        if (a || isinf(tod))
            std::cout << "double: " << tod << std::endl;
        else
            std::cout << "double: " << tod << ".0" << std::endl;
        return ;
    }
}

void ScalarConverter::checkType(std::string& str)
{
    double tod = 0;
    char *end;

    if (valid_string(str) == 1)
    {
        std::cout <<  "----- " << "int" << " -----" << std::endl;
        double tod = strtod(str.c_str(), &end);
        if (tod >= INT_MIN && tod <= INT_MAX)
        {
            Char(tod, 1);
            Int(tod, 1);
            Float(tod, 1);
            Double(tod, 1);
        }
        else
        {
            std::cout << "int: impossible" << std::endl;
            return ;
        }

    }
    else if (valid_string(str) == 2)
    {
        std::cout <<  "----- " << "char" << " -----" << std::endl;
        double tod = static_cast<double>(str.c_str()[0]);

        Char(tod, 2);
        Int(tod, 2);
        Float(tod, 2);
        Double(tod, 2);

    }
    else if (valid_string(str) == 3)
    {   
        std::cout <<  "----- " << "float" << " -----" << std::endl;
        double tod = strtod(str.c_str(), &end);

        Char(tod, 3);
        Int(tod, 3);
        Float(tod, 3);
        Double(tod, 3);
    }
    else if (valid_string(str) == 4)
    {
        std::cout <<  "----- " << "double" << " -----" << std::endl;
        double tod = strtod(str.c_str(), &end);

        Char(tod, 4);
        Int(tod, 4);
        Float(tod, 4);
        Double(tod, 4);
    }
    else
        std::cout << "Non displayable" << std::endl;
}
