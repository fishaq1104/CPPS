#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iostream>

class Fixed 
{
    private :
    int RawBits;
    static const int frac = 8;

    public:
    Fixed();
    Fixed(const Fixed &fixed);
    Fixed& operator=(const Fixed &fixed);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif