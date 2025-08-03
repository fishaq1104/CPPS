#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contact_count = 0;
}

int check_valid(std::string str)
{
    if (str.empty())
        return 0; 
    for(size_t i = 0; i < str.length(); i++)
    {
        if(!std::isalpha(str[i]) && !std::isspace(str[i]))
            return 0;
    }
    return 1;
}
int check_num(std::string str)
{
    if (str.empty())
        return 0; 
    for(size_t i = 0; i < str.length(); i++)
    {
        if(!std::isdigit(str[i]))
            return 0;
    }
    return 1;
}
void PhoneBook::Add(void)
{
    std::string FirstName, LastName, NickName, PhoneNumber, DarkestSecret;
    while (1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter First Name :";
        if (!std::getline(std::cin, FirstName) || std::cin.eof()) 
            break;
        if(check_valid(FirstName) || std::cin.eof())
            break;
        else
            std::cout<<"Invalid Input. Only Letters are allowed. Please try agian.\n";
    }
    if (std::cin.eof()) return; 
    while(1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter Last Name :";
        std::getline(std::cin,LastName);
        if(check_valid(LastName) || std::cin.eof())
            break;
        else
            std::cout<<"Invalid Input. Only Letters are allowed. Please try agian.\n";
    }
    while(1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter NickName :";
        std::getline(std::cin,NickName);
        if(!NickName.empty() || std::cin.eof())
            break;
        else
            std::cout<<"Invalid Input. Only Letters are allowed. Please try agian.\n";
    }
    while(1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter PhoneNumer :";
        std::getline(std::cin,PhoneNumber);
        if((check_num((PhoneNumber)) && (PhoneNumber.length() == 10)) || std::cin.eof())
            break;
        else if(check_num(PhoneNumber) && PhoneNumber.length() != 10)
            std::cout<<"Invalid Input.It shoulhd have 10 numbers. Please try agian.\n";
        else
            std::cout<<"Invalid Input.Only Numbers are allowed. Please try agian.\n";
    }
    while(1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter DarketSecret :";
        std::getline(std::cin,DarkestSecret);
        if(!DarkestSecret.empty() || std::cin.eof())
            break;
        else
            std::cout<<"Invalid Input.\n";
    }
    Contact newContact(FirstName, LastName, NickName,PhoneNumber, DarkestSecret);
    contacts[contact_count] = newContact;
    contact_count = (contact_count + 1) % 8;
    return ;
}
std::string formatField(std::string str) 
{
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return std::string(10 - str.length(), ' ') + str;
}
int check_index(std::string str)
{
    if (str.empty())
        return 0; 
    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '7')
        return 1;
    }
    return 0;
}

int stringToInt(std::string s) 
{
    int result = 0;
    int sign = 1;
    size_t i = 0;

    if (s[i] == '-') 
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
        i++;

    for (; i < s.size(); i++) 
    {
        if (s[i] < '0' || s[i] > '9') {
            return(0);
        }
        result = result * 10 + (s[i] - '0');
    }

    return sign * result;
}

void PhoneBook::Search(void)
{
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";  
    std::cout <<"----------------------------------------------\n";

    for(size_t i = 0; i < 8 ; i++)
    {
        std::cout<<"|"<< std::setw(10) << i << "|"
        <<formatField(contacts[i].getFirstName()) << "|"
        <<formatField(contacts[i].getLastName()) << "|"
        <<formatField(contacts[i].getNickName()) << "|\n";
    }
    int index;
    std::string s;
    while(1)
    {
        if (std::cin.eof())
            break;
        std::cout<<"Enter the index of the contact to display :";
        std::getline(std::cin,s);
        if((check_num((s)) && (s.length() == 1) && check_index(s)) || std::cin.eof())
            break;
        else if(check_num(s) && s.length() != 1)
            std::cout<<"Input Invalid: Number is not in Range. Please try agian.\n";
        else if((s.length() == 1) && !check_index(s))
            std::cout<<"Input Invalid: Enter a valid number between 0 and 7. Please try agian.\n";
        else
            std::cout<<"Invalid Input: Only Numbers are allowed. Please try agian.\n";
    }
     if (std::cin.eof())
        return ;
    index = stringToInt(s);
    if(index < 0 || index > 7 )
    {
        std::cout<<"Invalid Index. Enter a valid number between 0 and 7\n";
    }
    else if (!contacts[index].getFirstName().empty())
    {
        std::cout<<"\nContact Details: \n";
        std::cout<<"First Name : "<< contacts[index].getFirstName() << "\n";
        std::cout<<"Last Name : "<< contacts[index].getLastName() << "\n";
        std::cout<<"Nickname : "<< contacts[index].getNickName() << "\n";
        std::cout<<"Phone Number : "<< contacts[index].getPhoneNumber() << "\n";
        std::cout<<"Darkest Secret : "<< contacts[index].getDarkestSecret() << "\n";
    }
    else
    { 
        std::cout << "The index is empty!\n";
    }
    return ;
}
