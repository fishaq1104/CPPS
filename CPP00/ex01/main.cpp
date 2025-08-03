#include"PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;

    while(1)
    {
        if(std::cin.eof())
            break;
        std::cout<<"Enter Either ADD or SEARCH or EXIT: ";
        std::getline(std::cin,input);
        if(input == "ADD")
            phonebook.Add();
        else if(input == "SEARCH")
            phonebook.Search();
        else if(input == "EXIT" || std::cin.eof())
        {
            if(input == "EXIT")
                std::cout << "Exiting :)\n";
            break;
        }
        else
            std::cout<<"Invalid input. Please enter ADD, SEARCH, or EXIT.\n";
    }
    return 0;
}