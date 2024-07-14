#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _fixedN(0)
{
}

Fixed::Fixed(const int n) : _fixedN(n << _fract_bits)
{
}

Fixed::Fixed(const float floatN) : _fixedN(roundf(floatN * (1 << _fract_bits)))
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& ref)
{
	*this = ref;
}

/*  =================== operator overloading ====================*/

Fixed&	Fixed::operator=(const Fixed& ref)
{
	if (this == &ref)
		return *this;

	this->_fixedN = ref._fixedN;
	return *this;
}

bool	Fixed::operator>(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN > ref._fixedN;
}

bool	Fixed::operator<(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN < ref._fixedN;
}

bool	Fixed::operator>=(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN >= ref._fixedN;
}

bool	Fixed::operator<=(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN <= ref._fixedN;
}

bool	Fixed::operator==(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN == ref._fixedN;
}

bool	Fixed::operator!=(const Fixed& ref) const
{
	if (this == &ref)
		return false;
	return this->_fixedN != ref._fixedN;
}

Fixed	Fixed::operator+(const Fixed& ref) const
{
	Fixed temp = *this;
	temp._fixedN = (this->_fixedN + ref._fixedN);
	return temp;
}

Fixed	Fixed::operator-(const Fixed& ref) const
{
	Fixed temp = *this;
	temp._fixedN = (this->_fixedN - ref._fixedN);
	return temp;
}

Fixed	Fixed::operator*(const Fixed& ref) const
{
	Fixed temp = *this;
	temp._fixedN = (this->_fixedN * ref._fixedN) / (1 << this->_fract_bits);
	return temp;
}

Fixed	Fixed::operator/(const Fixed& ref) const
{
	Fixed temp = *this;
	temp._fixedN = (this->_fixedN / ref._fixedN) * (1 << this->_fract_bits);
	return temp;
}

Fixed&	Fixed::operator++()
{
	this->_fixedN += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedN += 1;
	return temp;
}

Fixed&	Fixed::operator--()
{
	this->_fixedN -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedN -= 1;
	return temp;	
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

int		Fixed::getRawBits() const
{
	return this->_fixedN;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedN = raw;
}

int		Fixed::toInt(void) const
{
	return _fixedN >> _fract_bits;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_fixedN) / (1 << _fract_bits);
}

const Fixed& Fixed::min(const Fixed &r1, const Fixed &r2)
{
	return (r1 < r2 ? r1 : r2);
}

Fixed& Fixed::min(Fixed &r1,  Fixed &r2)
{
	return (r1 < r2 ? r1 : r2);
}

const Fixed& Fixed::max(const Fixed &r1, const Fixed &r2)
{
	return (r1 > r2 ? r1 : r2);
}

Fixed& Fixed::max(Fixed &r1, Fixed &r2)
{
	return (r1 > r2 ? r1 : r2);
}
