#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &s){
    *this = s;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &s)
{
    (void)s;
    return *this;
}


int isNumber(const std::string &s)
{
    size_t i = 0;
    if (s[0] == '-') {
        if (s.size() == 1) 
            return 0;
        i++;
    }
    for(; i < s.size(); i++)
        if(!std::isdigit(s[i]))
            return 0;
    return 1;
}

int isChar(const std::string &s)
{
    if(s.size() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
        return 1;
    if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
		return 1;
    return 0;
}

int isFloat(const std::string &s)
{
    unsigned int i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if(s[s.size()-1] != 'f')
        return 0;
    if (s[i] == '+' || s[i] == '-') 
    {
        i++;
        if (i >= s.size()) 
            return 0;
    }
    for (; i < s.size() - 1; ++i)
    {
        if (std::isdigit(s[i]))
            hasDigit = true;
        else if (s[i] == '.') 
        {
            if (hasDot) 
                return 0;
            hasDot = true;
        }
        else
            return 0;
    }
    if (!hasDigit) 
        return 0;
    return 1;
}

int isDouble(const std::string &s)
{
    size_t i = 0;
    bool hasDot = false, hasDigit = false;

    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        ++i;
    for (; i < s.size(); ++i)
    {
        if (std::isdigit(s[i]))
            hasDigit = true;
        else if (s[i] == '.' && !hasDot)
            hasDot = true;
        else
            return 0;
    }
    if (!hasDigit) 
        return 0;
    return 1;
}

static int	isOther(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 1;
	return 0;
}

void ScalarConverter::convert(const std::string &StringLiteral)
{
    if (StringLiteral.empty())
        throw std::invalid_argument("Empty input string");
    if (isChar(StringLiteral))
    {
        std::cout << std::fixed << std::setprecision(1);
        char c = static_cast<char>(StringLiteral[0]);
        std::cout << "char: "   << "'"  << c << "'" << std::endl;
        std::cout << "int: "    << static_cast<int>(c) << std::endl;
        std::cout << "float: "  << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (isNumber(StringLiteral))
    {
        std::cout << std::fixed << std::setprecision(1);
        char *ptr = 0;
        long i = std::strtol(StringLiteral.c_str(), &ptr, 10);

        if (i < 0   || i > 127)
            std::cout << "char: Impossible" << std::endl;
        else if (!std::isprint(i))
			std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
        if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
            std::cout << "int: Impossible" << std::endl ;
        else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << "float: "  << static_cast<float>(i)  << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else if (isFloat(StringLiteral))
    {
        std::cout << std::fixed << std::setprecision(1);

        char *endPtr = 0;
        double tmp   = std::strtod(StringLiteral.c_str(), &endPtr);
        float  f     = static_cast<float>(tmp);

        if (f < 0.0f || f > 127.0f)
            std::cout << "char: Impossible" << std::endl;
        else if (!std::isprint(f))
			std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
        if (f < static_cast<float>(std::numeric_limits<int>::min()) ||
            f > static_cast<float>(std::numeric_limits<int>::max()))
            std::cout << "int: Impossible" << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: "  << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(StringLiteral))
    {
        std::cout << std::fixed << std::setprecision(1);

        char *endPtr = 0;
        double d = std::strtod(StringLiteral.c_str(), &endPtr);

        if (d < 0.0  || d > 127.0)
            std::cout << "char: Impossible" << std::endl;
        else if (!std::isprint(d))
			std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(d) << std::endl;
        if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
            d > static_cast<double>(std::numeric_limits<int>::max()))
            std::cout << "int: Impossible"<< std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
    }
    else if (isOther(StringLiteral))
    {
        if (StringLiteral == "nan"  || StringLiteral == "nanf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (StringLiteral == "+inf"  || StringLiteral == "+inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
    else
        std::cout << "The format is not valid: " << StringLiteral << std::endl;
}
