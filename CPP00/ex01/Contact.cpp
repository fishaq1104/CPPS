#include "Contact.hpp"

Contact::Contact()
{

}
Contact::Contact(std::string First_Name, std::string Last_Name, std::string Nick_Name, std::string Phone_Number,std::string Darkest_Secret)
{
  this->FirstName = First_Name;
  this->LastName = Last_Name;
  this->NickName = Nick_Name;
  this->PhoneNumber = Phone_Number;
  this->DarkestSecret = Darkest_Secret;
}

void Contact::setFirstName(std::string str)
{
  FirstName = str;
}

void Contact::setLastName(std::string str)
{
  LastName = str;
}
void Contact::setNickName(std::string str)
{
  NickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
  PhoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
  DarkestSecret = str;
}

std::string Contact::getFirstName()
{
  return this->FirstName;
}
std::string Contact::getLastName()
{
  return this->LastName;
}
std::string Contact::getNickName()
{
  return this->NickName;
}
std::string Contact::getPhoneNumber()
{
  return this->PhoneNumber;
}
std::string Contact::getDarkestSecret()
{
  return this->DarkestSecret;
}

