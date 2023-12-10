#include <iostream>

class ScalarConverter
{
    public:
        static int valid_string(std::string& str);
        static void checkType(std::string& str);

        // TO DO
        // static void  Char(const std::string& str);
        // static void  Int(const std::string& str);
        // static void  Float(const std::string& str);
        // static void  Double(const std::string& str);

        static void  Char(double tod, int flag);
        // static int  Int(double tod);
        static void  Int(double tod, int flag);
        static void  Float(double tod, int flag);
        static void  Double(double tod, int flag);
        // static std::string check(std::string& str);

    private:
        // ScalarConverter();
        // ScalarConverter(const ScalarConverter& obj);
        // ScalarConverter(const std::string& argv);
        // ~ScalarConverter();
        // ScalarConverter& operator=(const ScalarConverter& obj);
};