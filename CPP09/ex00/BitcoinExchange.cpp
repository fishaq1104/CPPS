#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const std::string &c) : file(c){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &c) :file(c.file), btcprices(c.btcprices){    
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &c)
{
    if(this != &c)
    {
        this->btcprices = c.btcprices;
        this->file = c.file;
    }
    return *this;
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream file("data.csv");
    if (!file.is_open()) 
    {
        std::cout << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    float rate;
    std::string date , rateStr;  

    while (std::getline(file, line)) 
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        date = line.substr(0, comma);
        rateStr = line.substr(comma + 1);
        char* endptr;
        double val = std::strtod(rateStr.c_str(), &endptr);
        if (*endptr != '\0')
            std::cout << "Error: no price" << std::endl;
        rate = static_cast<float>(val);
        this->btcprices[date] = rate;
    }
    file.close();
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

int toInt(const std::string& str)
{
    char* end;
    long value = std::strtol(str.c_str(), &end, 10);
    
    if (*end != '\0')
        return -1;
    if (value < 0 || value > 9999)
        return -1;
    return static_cast<int>(value);
}

void getCurrentDate(int &year, int &month, int &day)
{
    time_t now = time(NULL);
    struct tm *ltm = localtime(&now);
    
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
}

int getMaxDayOfMonth(int year, int month)
{
    bool isLeap = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        isLeap = true;
    if (month == 2)
    {
        if (isLeap)
            return 29;
        else
            return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}

int checkValidDate(const std::string &s)
{
    std::string cleaned = trim(s);
    if(cleaned.size() != 10)
    {
        std::cout << "Error: bad input =>  " << cleaned << std::endl;
        return -1;
    }
    if(cleaned[4] != '-' || cleaned[7] != '-')
    {
        std::cout << "Error: bad input =>  " << cleaned << std::endl;
        return -1;
    }
    
    std::string year,month, day;

    year = cleaned.substr(0, 4);
    month = cleaned.substr(5, 2);
    day = cleaned.substr(8, 2);

    int year_i = toInt(year);
    int month_i = toInt(month);
    int day_i =  toInt(day);
    if (year_i == -1 || month_i < 1 || month_i > 12|| day_i < 1 || day_i > 31 || year_i < 2009)
    {
        std::cout << "Error: bad input =>  " << cleaned << std::endl;
        return -1;
    }
    int currentYear, currentMonth, currentDay;
    getCurrentDate(currentYear, currentMonth, currentDay);
    
    if (year_i > currentYear || (year_i == currentYear && month_i > currentMonth) 
    || (year_i == currentYear && month_i == currentMonth && day_i > currentDay))
    {
        std::cout << "Error: bad input =>  " << cleaned << std::endl;
        return -1;
    }
    int maxDay = getMaxDayOfMonth(year_i, month_i); 
    if (day_i > maxDay)
    {
        std::cout << "Error: bad input =>  " << cleaned << std::endl;
        return -1;
    }
    return 1;
}

bool isValidPrice(const std::string& priceStr, float& outPrice)
{
    if (priceStr.empty())
    {
        std::cout << "Error: not a valid price" << std::endl;
        return false;
    }
    char* endptr;
    double val = std::strtod(priceStr.c_str(), &endptr);
    if (*endptr != '\0')
    {
        std::cout << "Error: not a valid price" << std::endl;
        return false;
    }
    if (val < 0.0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (val > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    outPrice = static_cast<float>(val);
    return true;
}

void BitcoinExchange::calculate()
{
    std::ifstream inputFile((this->file).c_str());
    bool foundValidLine = false;
    if(!inputFile.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }
    if (inputFile.peek() == EOF) 
    {
        std::cout << "Error: input file is empty." << std::endl;
        return ;
    }
    this->loadDatabase();
    std::string line;
    std::getline(inputFile, line);
    
    while(std::getline(inputFile, line))
    {
        line = trim(line);
        if(line.empty())
            continue ;
        foundValidLine = true;
        size_t delim = line.find('|');
        if(delim == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0,delim);
        std::string price = line.substr(delim + 1);
        // if(date.empty() || price.empty())
        // {
        //     std::cout << "Error : Missing price or date"<< std::endl;
        //     continue; 
        // }
        float f_price;
        if(checkValidDate(date) == -1)
            continue ;
        if(!isValidPrice(price, f_price))
            continue ;
        std::map<std::string,float>::iterator t = btcprices.upper_bound(date);
        if (t == btcprices.begin()) 
        {
            std::cout << "Error: no earlier date available for " << date << std::endl;
            continue;
        }
        --t;
        float amount = f_price * t->second;
        std::cout << date <<" => " << price << " = " << amount << std::endl;
    }
    if (!foundValidLine)
        std::cout << "Error: input file has no valid data lines." << std::endl;
    inputFile.close();
}
