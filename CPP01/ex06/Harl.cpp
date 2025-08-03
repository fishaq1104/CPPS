#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
    std::cout<<"[DEBUG] ";
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info(void)
{
    std::cout<<"[INFO] ";
    std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning(void)
{
    std::cout<<"[Warning] ";
    std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error(void)
{
    std::cout<<"[Error] ";
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

int getLogLevel(std::string level) 
{
        if (level == "DEBUG") return 0;
        if (level == "INFO") return 1;
        if (level == "WARNING") return 2;
        if (level == "ERROR") return 3;
        return -1;
}

void Harl::complain(std::string level) 
{
        int Level = getLogLevel(level);
        
    switch (Level) {

        case 0:
            std::cout << "[ DEBUG ]\nI love having extra bacon.\n";
        case 1:
            std::cout << "[ INFO ]\nAdding bacon costs more but it's worth it.\n";
        case 2:
            std::cout << "[ WARNING ]\nI think I deserve extra bacon for free.\n";
        case 3:
            std::cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n";
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
                break;
    }
}

