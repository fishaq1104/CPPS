#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits> 
#include <cstdlib>

class ScalarConverter{
    public:
        static void convert(const std::string &StringLiteral);
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &s);
        ScalarConverter& operator=(const ScalarConverter &s);
};
