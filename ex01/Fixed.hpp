
#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <stdint.h>
#include <iostream>
#include <string>
#include <limits>
#include <stdbool.h>
#include <cmath>

class Fixed 
{
private:
    int value;
    static const int fractionalBits = 8;

public:

    Fixed();
    Fixed(const Fixed &other);
    ~Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed &operator=(const Fixed &other);
    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
