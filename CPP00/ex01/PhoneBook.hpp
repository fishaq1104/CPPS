#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <string>
#include <iomanip>

class PhoneBook
{
    private :
        Contact contacts[8];
        int contact_count;
    public:
        PhoneBook();
        void Add();
        void Search();
};

#endif