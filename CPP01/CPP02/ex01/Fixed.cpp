#include "Fixed.h"

//Constructors 
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->RawBits = 0;
}

Fixed::Fixed(const int num)
{
    std::cout<< "Int constructor called"<<std::endl;
    this->RawBits = num << frac;
}

Fixed::Fixed(const float num)
{
    std::cout<< "float constructor called"<<std::endl;
    this->RawBits = roundf(num *  ( 1 << frac));
}

//copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->RawBits = fixed.RawBits;
}

//copy assignmnet operator 
Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->RawBits = fixed.getRawBits();
    return *this;
}

//deconstructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//getter
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->RawBits;
}

//setters
void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->RawBits = raw;
}

// float Fixed::toFloat( void )const
// {
//     float f = 0.0;
//     if(this->RawBits != 0)
//         f = this->RawBits / (1  >> (frac + 1));
//     return f;
// }

int Fixed::toInt(void) const
{
    return this->RawBits >> 8; 
}