#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
    int RawBits;
    static const int frac = 8;

    public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &fixed);
    Fixed& operator=(const Fixed &fixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};
std::ostream &operator<<(std::ostream &os,const Fixed &fixed);

#endif
