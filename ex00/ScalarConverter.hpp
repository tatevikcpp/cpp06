#include <iostream>

class ScalarConverter
{
    public:
        static int valid_string(std::string& str);
        static void checkType(std::string& str);

        // TO DO
        static void  Char(double tod, int flag);
        static void  Int(double tod, int flag);
        static void  Float(double tod, int flag);
        static void  Double(double tod, int flag);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& obj);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& obj);
};