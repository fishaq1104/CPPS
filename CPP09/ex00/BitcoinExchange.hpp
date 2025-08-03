#pragma once

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class BitcoinExchange
{
    private:
        std::string file;
        std::map<std::string,float> btcprices;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &c);
        BitcoinExchange &operator=(const BitcoinExchange &c);
        BitcoinExchange(const std::string &s);
        void loadDatabase();
        void calculate();
};