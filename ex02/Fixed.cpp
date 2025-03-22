
#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::Fixed(const int n) : value(n << fractionalBits) {}

Fixed::Fixed(const float n)
{
    value = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        value = other.value;
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.value = value + other.value;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.value = value - other.value;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.value = ((long long)value * other.value) >> fractionalBits;
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return(Fixed());
    }
    Fixed result;
    result.value = ((long long)value << fractionalBits) / other.value;
    return (result);
}

Fixed& Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--()
{
    value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}

float Fixed::toFloat(void) const
{
    return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
    return (value >> fractionalBits);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}
