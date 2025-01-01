#include "Fixed.hpp"

//Constructors 
Fixed::Fixed()
{
    this->RawBits = 0;
}

Fixed::Fixed(const int num)
{
    this->RawBits = num << frac;
}

Fixed::Fixed(const float num)
{
    this->RawBits = roundf(num *  ( 1 << frac));
}

//copy constructor
Fixed::Fixed(const Fixed &fixed)
{
    this->RawBits = fixed.RawBits;
}

//copy assignmnet operator 
Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->RawBits = fixed.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &os,const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return this->RawBits > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->RawBits < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->RawBits >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->RawBits <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->RawBits == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->RawBits != fixed.getRawBits();
}

float Fixed::operator+(const Fixed &fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(const Fixed &fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(const Fixed &fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(const Fixed &fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
    this->RawBits++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->RawBits--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++this->RawBits;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --this->RawBits;
    return(temp);
}

//deconstructor
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

//getter
int Fixed::getRawBits( void ) const
{
    return this->RawBits;
}

//setters
void Fixed::setRawBits( int const raw )
{
    this->RawBits = raw;
}

//helper function
float Fixed::toFloat( void )const
{
    return ((float)this->RawBits / (float)(1 << this->frac));;
}

int Fixed::toInt(void) const
{
    return this->RawBits >> 8; 
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return b;
    else
        return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return a;
    else
        return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.toFloat() <= b.toFloat())
        return b;
    else
        return a;
}
