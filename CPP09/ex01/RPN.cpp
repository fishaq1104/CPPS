#include "RPN.hpp"

RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(const RPN &s) : sc(s.sc) , arg(s.arg){
}

RPN &RPN::operator=(const RPN &s)
{
    if(this != &s)
    {
        this->arg = s.arg;
        this->sc = s.sc;
    }
    return *this;
}


RPN::RPN(const std::string &s): arg(s){
}

int RPN::check()
{
    for(unsigned int i = 0; i < this->arg.size();i++)
    {
        if(!std::isdigit(arg[i]) && !std::isspace(arg[i]) && arg[i] != '+' && arg[i] != '-' && arg[i] != '*' && arg[i] != '/')
            return 0;
    }
    return 1;
}

void RPN::calculate()
{
    if(arg.empty())
    {
        std::cerr << "Error : Empty" << std::endl;
        return ;
    }
    if(check() == 0)
    {
        std::cerr << "Error : The format is invalid" << std::endl;
        return ;
    }
    int operandCount = 0;
    int operatorCount = 0;
    std::istringstream iss(arg.c_str());
    std::string token;
    while (iss >> token) 
    {
        if (token.size() == 1 && std::isdigit(token[0])) 
        {
            sc.push(token[0] - '0');
            operandCount++;
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            if (sc.size() < 2) 
            {
                std::cerr << "Error: Not enough operands" << std::endl;
                return;
            }
            int result;
            int j = sc.top();
            sc.pop();
            int i = sc.top();
            sc.pop();
            if(token == "+")
              result  = i + j;
            else if(token == "-")
                result  = i - j;
            else if(token == "*")
                result  = i * j;
            else if(token == "/")
            { 
                if (j == 0) 
                {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return;
                }
                result  = i / j;
            }
            sc.push(result);
            operatorCount++;
        }
        else 
        {
            std::cerr << "Error: Invalid  : '" << token << "'" << std::endl;
            return;
        }
    }
    if (operatorCount == 0) 
    {
        std::cerr << "Error: No operator provided." << std::endl;
        return ;
    }
    if (sc.size() != 1 || operatorCount != operandCount - 1) 
    {
        std::cerr << "Error: Incomplete or Invalid expression" << std::endl;
        return;
    }
    std::cout<< "The result :" << sc.top() << std::endl;
    while (!sc.empty()) 
        sc.pop();
}
