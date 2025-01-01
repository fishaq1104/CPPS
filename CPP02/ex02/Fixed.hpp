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
    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;
    float operator+(const Fixed &fixed) const;
    float operator-(const Fixed &fixed) const;
    float operator*(const Fixed &fixed) const;
    float operator/(const Fixed &fixed) const;
    Fixed operator++();
    Fixed operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os,const Fixed &fixed);

#endif