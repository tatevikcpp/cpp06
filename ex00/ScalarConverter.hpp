#include <iostream>

class ScalarConverter
{
    public:
        static void checkType(std::string& str);
    private:
        // ScalarConverter();
        // ScalarConverter(const ScalarConverter& obj);
        // ScalarConverter(const std::string& argv);
        // ~ScalarConverter();
        // ScalarConverter& operator=(const ScalarConverter& obj);
        static void  Char(const std::string& str);
        static void  Int(const std::string& str);
        static void  Float(const std::string& str);
        static void  Double(const std::string& str);
};