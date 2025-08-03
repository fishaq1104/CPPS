#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> sc;
        std::string arg;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &s);
        RPN &operator=(const RPN &s);
        RPN(const std::string &s);
        int check();
        void calculate();
};